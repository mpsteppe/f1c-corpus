#!/usr/bin/env python3
r"""Harvest the F1C "source atlas" from baked trace/assert call sites.

The source TEXT is not in the binary (compiled away). But every TRACE/assert call
site bakes in a (source_path, line_number) pair plus a message naming the operation,
and — for the common wrapper pattern — the address of the real function it guards:

    void FUN_0042c130(void) {                         # trace wrapper
      cVar1 = FUN_004d7a50(2, "...\dynman.cpp", 0x1fb) # threshold, FILE, LINE
      if (cVar1) FUN_004d7aa0(&DAT, "Entered DynMan::Enter()")   # MESSAGE
      FUN_0042bd60();                                  # the REAL DynMan::Enter body
    }

This mines ALL such sites statically (incl. ones that never run at runtime) from the
decompiled .c and produces work/source_atlas.csv:
    wrapper_addr, target_addr, file, line, class, method, message, threshold

file:line lets you order functions within each real .cpp; message gives the real name;
target_addr names the anonymous function the wrapper guards.

Usage: python tools/harvest_source_atlas.py
"""
import csv, os, re, glob

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
STRINGS = os.path.join(ROOT, "tools", "ida_strings.csv")
SRC_DIRS = [os.path.join(ROOT, "analysis_pipeline", "analyzed"),
            os.path.join(ROOT, "decompiled_all")]
OUT = os.path.join(ROOT, "work", "source_atlas.csv")

# trace/emit function addresses (FUN_004d7960 init, a50 guard, aa0 emit)
GUARD = "FUN_004d7a50"   # (threshold, file_str, line)
EMIT  = "FUN_004d7aa0"   # (ctx, message_str)
TRACE_FUNCS = {"FUN_004d7960", "FUN_004d7a00", GUARD, EMIT}

HEX8 = re.compile(r"_([0-9a-fA-F]{8})\b")
INT  = re.compile(r"^(?:0x[0-9a-fA-F]+|\d+)$")
FUNCALL = re.compile(r"\b(FUN_[0-9a-fA-F]{8})\s*\(")
ADDR_IN_NAME = re.compile(r"0x([0-9a-fA-F]{8})__")


def load_strings():
    m = {}
    with open(STRINGS, encoding="utf-8", errors="replace") as f:
        for row in csv.DictReader(f):
            try:
                m[int(row["addr"], 16)] = row["value"]
            except (ValueError, KeyError):
                pass
    return m


def resolve_str(token, strings):
    """token like s_..._005c3334 or &DAT_005c3334 -> text, or None."""
    hits = HEX8.findall(token)
    for h in hits:
        va = int(h, 16)
        if va in strings:
            return strings[va]
    return None


def split_args(call_text):
    """split top-level comma args of a call given text after '('."""
    depth, cur, args = 0, "", []
    for ch in call_text:
        if ch in "([": depth += 1
        elif ch in ")]":
            if depth == 0:
                args.append(cur.strip()); return args
            depth -= 1
        if ch == "," and depth == 0:
            args.append(cur.strip()); cur = ""
        else:
            cur += ch
    if cur.strip():
        args.append(cur.strip())
    return args


def call_args(body, func):
    """yield arg-lists for each call to `func` in body."""
    for m in re.finditer(re.escape(func) + r"\s*\(", body):
        yield split_args(body[m.end():])


def parse_line_num(tok):
    tok = tok.strip()
    try:
        return int(tok, 16) if tok.lower().startswith("0x") else int(tok)
    except ValueError:
        return None


def wrapper_addr(path):
    m = ADDR_IN_NAME.search(os.path.basename(path))
    return "0x" + m.group(1) if m else ""


def main():
    strings = load_strings()
    rows = []
    files = []
    for d in SRC_DIRS:
        files += glob.glob(os.path.join(d, "*.c"))

    for path in files:
        try:
            body = open(path, encoding="utf-8", errors="replace").read()
        except OSError:
            continue
        if GUARD not in body:
            continue
        waddr = wrapper_addr(path)

        # message(s) emitted in this function
        messages = []
        # positions of every EMIT call -> its message (for nearest-following pairing)
        emit_at = []
        for m in re.finditer(re.escape(EMIT) + r"\s*\(", body):
            args = split_args(body[m.end():])
            if len(args) >= 2:
                txt = resolve_str(args[1], strings)
                if txt:
                    emit_at.append((m.start(), txt))
        # the guarded target: first FUN_ call that is not a trace function
        # and not the wrapper's own definition (header line `void FUN_xxxx(void)`)
        own = "FUN_" + waddr[2:] if waddr else ""
        target = ""
        for m in FUNCALL.finditer(body):
            fn = m.group(1)
            if fn not in TRACE_FUNCS and fn != own:
                target = "0x" + fn[4:]
                break

        for m in re.finditer(re.escape(GUARD) + r"\s*\(", body):
            args = split_args(body[m.end():])
            if len(args) < 3:
                continue
            fpath = resolve_str(args[1], strings)
            line = parse_line_num(args[2])
            thr = parse_line_num(args[0])
            if not fpath or line is None:
                continue
            fbase = fpath.split("\\")[-1]
            # message = nearest EMIT after this guard (position-based, correct for multi-site funcs)
            msg = ""
            for pos, txt in emit_at:
                if pos >= m.start():
                    msg = txt
                    break
            cls = meth = ""
            mm = re.search(r"(\w+)::(\w+)", msg)
            if mm:
                cls, meth = mm.group(1), mm.group(2)
            rows.append(dict(wrapper_addr=waddr, target_addr=target, file=fbase,
                             full_path=fpath, line=line, cls=cls, method=meth,
                             message=msg, threshold=thr if thr is not None else ""))

    rows.sort(key=lambda r: (r["file"], r["line"]))
    with open(OUT, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["file", "line", "cls", "method",
                          "target_addr", "wrapper_addr", "message", "full_path", "threshold"])
        w.writeheader()
        for r in rows:
            w.writerow({k: r[k] for k in w.fieldnames})

    # summary
    from collections import Counter
    perfile = Counter(r["file"] for r in rows)
    named = sum(1 for r in rows if r["method"])
    print(f"{len(rows)} trace sites  |  {len(perfile)} source files  |  {named} with Class::Method")
    print(f"-> {OUT}")
    for fn, n in perfile.most_common():
        print(f"   {n:4d}  {fn}")


if __name__ == "__main__":
    main()
