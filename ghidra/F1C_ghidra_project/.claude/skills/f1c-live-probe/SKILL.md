---
name: f1c-live-probe
description: Read, watch, and write live F1 Challenge game memory with tools/poke.py — confirm values, prove state writes, hunt unknown offsets via snapshot/diff. Use when a task says "check the live value", "poke-prove this write", "watch this global during a race", or "find which global changed when I did X". Do NOT use for pass/fail verification of a doc claim against expectations — use f1c-verify-claim. Do NOT use to build a whole mod — use f1c-mod-lifecycle. Do NOT use for function-call tracing or Frida agents — use f1c-frida-trace.
---

# Probe live game memory (read / watch / write / snapshot-diff)

## When to use / when not

Use to observe or mutate the running game process: read a named global, watch it
change, prove a state write lands, or diff-hunt an unknown offset. Route out:
verifying a single doc claim with pass/fail expectations → `f1c-verify-claim`;
building a mod end to end → `f1c-mod-lifecycle`; call tracing / watch agents →
`f1c-frida-trace`. A live read of a GUESS-tier address proves it is readable, not
that its doc label is true (trust tiers: `INDEX.md` §Trust tiers — READ THIS BEFORE
TRUSTING ANY FILE).

## Prerequisites

| Prerequisite | Check command | Expected |
|---|---|---|
| SDK json exists | `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && ls mods/sdk/f1c_sdk.json` | path printed. If missing → `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/gen_sdk.py` (WARNING: executes immediately on bare invocation; overwrites `mods/sdk/f1c_sdk.h` and `.json`) |
| SDK fresh | — | regenerate via the same `gen_sdk.py` command after EVERY docs merge |
| Game running (`LIVE:` steps only) | Step 2 read | a value, not the not-running error below |
| Admin shell (sometimes) | — | required if `OpenProcess failed (run as admin?)` appears |

## Procedure

### Step 1: Resolve the token name (no game needed)

Command:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/poke.py list <term>
```
Expected output: matching SDK globals (name, address, type, description).
If instead the list is empty → the global is not in the SDK; locate it with
`f1c-locate`, then use a raw-address token (grammar below) and treat its label as
GUESS until verified.

Token grammar (any read/write/watch step): SDK name (case-insensitive, unique
substring OK) | `DAT_<addr>` | `0x<addr>` | `0x<addr>:<type>` per-token override.
Types: `float double int32 uint32 int int16 uint16 int8 uint8 byte ptr`.

### Step 2: LIVE: read current value(s)

Command:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/poke.py read <tok> [tok2 ...]
```
Expected output: one line per token with its decoded value. Batch every token you
need in ONE call.
If instead `'F1 Challenge Online.exe' is not running — start the game first` →
STOP at this LIVE boundary; report which values remain unverified.
If `OpenProcess failed (run as admin?) — pid <N>` → rerun from an admin shell.
If `ambiguous '<tok>' — matches:` → pick one name from the printed list; never guess.
If a value prints as `<unreadable>` → wrong address or not in a session; re-verify
the address via `f1c-verify-claim`.

### Step 3: LIVE: watch a value change

Command:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/poke.py watch <tok> [tok2 ...] --hz 10
```
Expected output: a line each time a watched value changes (default rate 2.0 Hz if
`--hz` omitted); Ctrl+C to stop.
If instead nothing ever prints → the value did not change during your action;
either the trigger is wrong or the label is wrong — do not conclude "dead global"
from one quiet watch.

### Step 4: LIVE: write, then prove the write (poke-prove)

Save replays/setups first — this mutates the running game. Command:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/poke.py write <tok> <value>
```
Expected output: a before→after line (poke prints both). Record both values plus
the gate state you were in — CLAUDE.md iron rule 6, verbatim:

> 6. **Mods must log read-back values** (write, re-read, log both + gate states) so a
>    failure report carries bits, not "nothing happened".

If instead `write failed at 0x<addr>` → page not writable or bad address; STOP and
re-verify the fact.
Then observe the game for the predicted effect. **Log confirms write ≠ game
reacted.** A landed write the game ignores is the documented trap (ledger wording:
"Writes stick ≠ game reacts", `mods/_README.md` §Current contents). Only an
in-game observation earns the ledger status "in-game confirmed". If the write sticks but
re-reads show the game rewriting it each tick, the value is derived — a mod must
write it continuously (tick DLL, `f1c-dll-mod`) or patch the producer.

### Step 5: LIVE: player-vehicle field

Command:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/poke.py veh <field|offset>
```
Expected output: the field value (name search uses SDK type; a raw offset defaults
to `float`).
If instead `player vehicle pointer is NULL (not in session?)` → enter a session
first. For iterating ALL vehicles (array, count, player-skip, stride), copy the
confirmed recipe from `mods/_README.md` §Reusable primitives (copy these, don't
re-derive) — never re-derive it here.

### Step 6: LIVE: snapshot → act → diff (unknown-offset hunt)

Commands:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/poke.py snapshot before.json
# ... perform ONE in-game action ...
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/poke.py diff before.json --thresh 0.5
```
Expected output: `snapshot` writes a JSON of all known globals; `diff` prints only
globals that changed since the capture (default `--thresh 0.0`).
If instead the diff is huge → raise `--thresh`, repeat with a smaller action, and
intersect candidates across runs. Full worked transcript: read `reference.md` in
this skill's directory.

## STOP — do not proceed if

- Game not running but the next step is `LIVE:` → stop; report which values/facts
  remain unverified. Prepare tokens and predicted observables statically instead.
- `OpenProcess failed` persists in an admin shell → stop; report the exact message.
- A token resolves `ambiguous` or `unknown` → do not guess an address; go back to
  Step 1 / `f1c-locate`.
- You are about to treat a logged write as mod confirmation → forbidden. Log
  confirms write ≠ game reacted; route to `f1c-mod-lifecycle` gate 7 for the
  in-game confirmation gate.
- You are about to call a game-internal function from injected code → forbidden;
  re-read the strategy ladder (`mods/_README.md` §The strategy ladder (why mods fail)).

## Failure modes and recovery

| Symptom | Likely cause | Action |
|---|---|---|
| `mods/sdk/f1c_sdk.json missing — run: python tools/gen_sdk.py` | SDK never built / deleted | run gen_sdk.py as shown in Prerequisites |
| `'F1 Challenge Online.exe' is not running — start the game first` | game closed | start game; if authoring, stop at LIVE boundary |
| `OpenProcess failed (run as admin?) — pid <N>` | insufficient rights | admin shell |
| `unknown global '<tok>' — try: poke.py list <tok>` | wrong name | Step 1, or raw-address token |
| value `<unreadable>` | bad address / no session | re-verify address; enter session |
| write lands, game ignores it | value re-derived per tick, or wrong field | see Step 4; watch it, check for per-tick rewrites |

## Deep reference

Read `reference.md` in this skill's directory for the full snapshot→diff transcript
(hunting an unknown offset) and how to narrow candidates across runs.

---
Canonical sources: `_meta/toolfacts.md` §tools/poke.py; `_meta/toolfacts.md` §tools/gen_sdk.py; `mods/_README.md` §Reusable primitives (copy these, don't re-derive); `mods/_README.md` §Current contents; `CLAUDE.md` §Iron rules; `INDEX.md` §Trust tiers — READ THIS BEFORE TRUSTING ANY FILE
Last validated: 2026-07-18 against 6bcccfe
