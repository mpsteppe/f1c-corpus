"""
preflight.py — verify a mod's factual claims against the LIVE game BEFORE
writing any code. Turns "build DLL -> launch race -> nothing happened -> guess"
into "fact 3 of 7 is wrong, fix that one".

Every mod is a composition of facts (addresses, types, strides, values, and the
assumption the game won't overwrite your write). Docs are GUESS tier: ~90%
accurate per fact means a 7-fact mod is a coin flip. This tool converts each
fact to FACT tier in seconds, so composition oneshots.

USAGE
-----
  python tools/preflight.py run mods/<name>/facts.json     # verify all facts
  python tools/preflight.py probe "[0x007C54F0]+0x4064" --type int32
  python tools/preflight.py probe SessionType "[PlayerVehiclePtr]+0x4064:int32"
  python tools/preflight.py example > mods/<name>/facts.json   # template

EXPRESSIONS
-----------
  SessionType                    SDK global name (mods/sdk/f1c_sdk.json)
  0x007C56A4                     raw address
  [0x007C54E8]                   deref: read u32 pointer at address
  [0x007C54F0]+0x4064            deref then offset (vehicle[0] FinishState)
  [[0x007C54F0]+0x10]+0x8        chains nest arbitrarily
  <expr>:float                   per-expr type override (probe mode)

FACTS FILE
----------
  {
    "name": "ai_pit_retire",
    "facts": [
      {"id": "vehicle_count", "expr": "0x005C329C", "type": "int32",
       "expect": {"range": [1, 26]}},
      {"id": "player_ptr",   "expr": "[0x007C54E8]", "type": "ptr",
       "expect": {"nonzero": true}},
      {"id": "finish_state", "expr": "[0x007C54F0]+0x4064", "type": "int32",
       "expect": {"in": [0, 1, 2, 3]}, "stable": true},
      {"id": "in_race",      "expr": "SessionType", "type": "int32",
       "expect": {"eq": 7}, "gate": true}
    ]
  }

  expect: {"eq": v} | {"in": [..]} | {"range": [lo, hi]} | {"nonzero": true}
  stable: true  -> sample for --stable-secs; FAIL if the game rewrites the value
                   (your memory write would be clobbered every frame)
  gate:   true  -> a precondition (e.g. must be in a race), reported as GATE
                   not FAIL, so you know the check needs a different game state

Exit code = number of FAILed facts (gates excluded). 0 = compose the mod.
"""

import argparse
import json
import os
import re
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from poke import Game, TYPES, load_sdk  # noqa: E402

if sys.platform == 'win32':
    sys.stdout.reconfigure(encoding='utf-8', errors='replace')


# ---------------------------------------------------------------------------
# expression evaluation
# ---------------------------------------------------------------------------
def resolve_name(sdk, tok):
    """SDK global name or hex literal -> address (no deref)."""
    m = re.match(r'(?:0x|dat_)?([0-9a-fA-F]{5,8})$', tok, re.I)
    if m and (tok.lower().startswith(('0x', 'dat_')) or not tok.isalpha()):
        return int(m.group(1), 16)
    gl = sdk['globals']
    if tok in gl:
        return gl[tok]['addr']
    exact = [n for n in gl if n.lower() == tok.lower()]
    if exact:
        return gl[exact[0]]['addr']
    raise ValueError(f"unknown name '{tok}' (not in SDK; run tools/gen_sdk.py?)")


def eval_expr(game, sdk, expr):
    """Evaluate an address expression. Returns (final_addr, trace_str).

    Grammar:  expr   := atom (('+'|'-') hex)*
              atom   := '[' expr ']' | name | hexaddr
    A deref reads a u32 pointer from the LIVE process.
    """
    expr = expr.replace(' ', '')
    pos = 0

    def parse():                     # returns (addr, trace)
        nonlocal pos
        if pos < len(expr) and expr[pos] == '[':
            pos += 1
            inner, tr = parse()
            if pos >= len(expr) or expr[pos] != ']':
                raise ValueError(f"unbalanced ']' in '{expr}'")
            pos += 1
            ptr = game.read_val(inner, 'ptr')
            if ptr is None:
                raise ValueError(f"deref failed: cannot read 0x{inner:08x}")
            addr, tr = ptr, f"[{tr}]=0x{ptr:08x}"
        else:
            m = re.match(r'[A-Za-z_0-9]+|0x[0-9a-fA-F]+', expr[pos:])
            if not m:
                raise ValueError(f"parse error at '{expr[pos:]}'")
            tok = m.group(0)
            pos += len(tok)
            addr = resolve_name(sdk, tok)
            tr = f"{tok}=0x{addr:08x}" if not tok.lower().startswith('0x') else tok
        while pos < len(expr) and expr[pos] in '+-':
            sign = 1 if expr[pos] == '+' else -1
            pos += 1
            m = re.match(r'0x[0-9a-fA-F]+|\d+', expr[pos:])
            if not m:
                raise ValueError(f"expected number after +/- in '{expr}'")
            off = int(m.group(0), 0)
            pos += len(m.group(0))
            addr += sign * off
            tr += f"{'+' if sign > 0 else '-'}0x{off:x}"
        return addr, tr

    addr, trace = parse()
    if pos != len(expr):
        raise ValueError(f"trailing garbage '{expr[pos:]}'")
    return addr, trace


# ---------------------------------------------------------------------------
# checks
# ---------------------------------------------------------------------------
def check_expect(val, expect):
    """-> (ok, reason)"""
    if expect is None:
        return True, "readable"
    if 'eq' in expect:
        return val == expect['eq'], f"expect =={expect['eq']}"
    if 'in' in expect:
        return val in expect['in'], f"expect in {expect['in']}"
    if 'range' in expect:
        lo, hi = expect['range']
        return lo <= val <= hi, f"expect [{lo}..{hi}]"
    if 'nonzero' in expect:
        return bool(val), "expect nonzero"
    return True, "readable"


def check_stability(game, addr, ptype, secs, hz):
    """Sample; return (n_changes, values_seen)."""
    seen, prev, changes = [], None, 0
    end = time.time() + secs
    while time.time() < end:
        v = game.read_val(addr, ptype)
        if prev is not None and v != prev:
            changes += 1
        if v not in seen:
            seen.append(v)
        prev = v
        time.sleep(1.0 / hz)
    return changes, seen[:6]


def fmt_val(v, ptype):
    if v is None:
        return "<unreadable>"
    if ptype == 'ptr':
        return f"0x{v:08x}"
    if isinstance(v, float):
        return f"{v:.6g}"
    return str(v)


# ---------------------------------------------------------------------------
# modes
# ---------------------------------------------------------------------------
def run_facts(path, stable_secs, stable_hz):
    with open(path, encoding='utf-8') as f:
        spec = json.load(f)
    sdk = load_sdk()
    game = Game()
    print(f"preflight: {spec.get('name', path)}  (pid {game.pid})\n")
    fails = 0
    w = max((len(f_['id']) for f_ in spec['facts']), default=8)
    for fact in spec['facts']:
        fid, expr = fact['id'], fact['expr']
        ptype = fact.get('type', 'int32')
        try:
            addr, trace = eval_expr(game, sdk, expr)
            val = game.read_val(addr, ptype)
            if val is None:
                ok, reason = False, f"unreadable at 0x{addr:08x}"
            else:
                ok, reason = check_expect(val, fact.get('expect'))
                reason += f", got {fmt_val(val, ptype)}"
            if ok and fact.get('stable'):
                changes, seen = check_stability(game, addr, ptype,
                                                stable_secs, stable_hz)
                if changes:
                    ok = False
                    reason += (f"; UNSTABLE — rewritten {changes}x in "
                               f"{stable_secs}s, values {seen} — a memory "
                               f"write here gets clobbered")
                else:
                    reason += f"; stable over {stable_secs}s"
            detail = f"{trace} -> 0x{addr:08x}"
        except ValueError as e:
            ok, reason, detail = False, str(e), expr
        if ok:
            tag = "PASS"
        elif fact.get('gate'):
            tag = "GATE"          # wrong game state, not a wrong fact
        else:
            tag = "FAIL"
            fails += 1
        print(f"  {tag:4} {fid:{w}}  {reason}")
        print(f"       {'':{w}}  {detail}")
    print(f"\n{fails} hard failure(s)."
          + ("  Fix the FAILed facts before writing any mod code."
             if fails else "  Facts hold — compose the mod."))
    return fails


def probe(exprs, default_type, secs, hz):
    sdk = load_sdk()
    game = Game()
    for e in exprs:
        e, _, forced = e.partition(':')
        ptype = forced or default_type
        if ptype not in TYPES:
            print(f"  {e}: unknown type '{ptype}'")
            continue
        try:
            addr, trace = eval_expr(game, sdk, e)
        except ValueError as err:
            print(f"  {e}: {err}")
            continue
        val = game.read_val(addr, ptype)
        line = f"  {trace} -> 0x{addr:08x} = {fmt_val(val, ptype)} ({ptype})"
        if val is not None and secs > 0:
            changes, seen = check_stability(game, addr, ptype, secs, hz)
            line += (f"  [stable {secs}s]" if not changes
                     else f"  [REWRITTEN {changes}x: {seen}]")
        print(line)


EXAMPLE = {
    "name": "example_mod",
    "facts": [
        {"id": "vehicle_count", "expr": "0x005C329C", "type": "int32",
         "expect": {"range": [1, 26]}},
        {"id": "player_ptr", "expr": "[0x007C54E8]", "type": "ptr",
         "expect": {"nonzero": True}},
        {"id": "finish_state", "expr": "[0x007C54F0]+0x4064", "type": "int32",
         "expect": {"in": [0, 1, 2, 3]}, "stable": True},
        {"id": "in_race", "expr": "SessionType", "type": "int32",
         "expect": {"eq": 7}, "gate": True},
    ],
}


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[1])
    sub = ap.add_subparsers(dest='cmd', required=True)
    r = sub.add_parser('run', help='verify a facts.json against the live game')
    r.add_argument('facts')
    r.add_argument('--stable-secs', type=float, default=2.0)
    r.add_argument('--stable-hz', type=float, default=30.0)
    p = sub.add_parser('probe', help='ad-hoc: read exprs + stability')
    p.add_argument('exprs', nargs='+')
    p.add_argument('--type', default='int32')
    p.add_argument('--secs', type=float, default=2.0)
    p.add_argument('--hz', type=float, default=30.0)
    sub.add_parser('example', help='print a template facts.json')
    a = ap.parse_args()
    if a.cmd == 'example':
        print(json.dumps(EXAMPLE, indent=2))
        return 0
    if a.cmd == 'probe':
        probe(a.exprs, a.type, a.secs, a.hz)
        return 0
    return run_facts(a.facts, a.stable_secs, a.stable_hz)


if __name__ == '__main__':
    sys.exit(main())
