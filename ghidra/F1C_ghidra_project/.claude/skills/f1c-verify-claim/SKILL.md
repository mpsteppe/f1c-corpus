---
name: f1c-verify-claim
description: Verify a single doc claim (struct offset, global label, enum value, behavior) against FACT-tier evidence — raw .c cross-read, then a live-game probe — before relying on it. Use when a task says "is this offset/label/value correct", before any GUESS/LEAD doc fact enters a mod or precise conclusion, or when f1c-locate returns a label you must build on. Do NOT use to find where something lives — use f1c-locate; to gate a whole mod fact-set — use f1c-mod-lifecycle (preflight run); to audit a whole doc and log corrections — use f1c-doc-audit.
---

# Verify one doc claim before building on it

## When to use / when not

One claim, one verdict. Docs are ~90% accurate PER FACT — so a conclusion resting on
7 unverified doc facts is right only ~0.9⁷ ≈ 48% of the time: a coin flip. Verifying
each fact individually converges in about 2 passes. Verbatim, `CLAUDE.md` §Iron rules:

> 4. **Mods: verify facts before code.** Decompose the mod into individual claims and
>    check each against the live game: `python tools/preflight.py run <facts.json>`
>    (template: `preflight.py example`; ad-hoc: `preflight.py probe <expr>`).
>    Never test "does the whole mod work" as the first test — 1-bit feedback over
>    GUESS-tier facts is a coin flip; per-fact verification converges in 2 passes.

Trust-tier terms (FACT/CONFIRMED/DERIVED/GUESS/LEAD/SCRATCH) are used here exactly as
defined in `INDEX.md` §Trust tiers — READ THIS BEFORE TRUSTING ANY FILE.

## Prerequisites

| Prerequisite | Check command | Expected |
|---|---|---|
| preflight.py runnable | `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/preflight.py example` | Template facts.json printed to stdout (not LIVE, safe) |
| SDK json exists (needed for name tokens + LIVE steps) | `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/poke.py list` | List of known globals |

If instead poke.py exits with `mods/sdk/f1c_sdk.json missing — run: python tools/gen_sdk.py`
→ the SDK must be regenerated; warn the user first (gen_sdk.py executes on bare
invocation and overwrites both SDK files).

## Procedure

### Step 1: state the claim precisely

Write down: source doc + entry, the address/expression, the claimed type, and the
claimed value/behavior. Example shape: "docs/13 claims field F at +0xNNN of the vehicle
struct, type float". A claim you cannot state this precisely cannot be verified.

### Step 2: pull the FACT-tier source

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/investigate.py <addr> --snippet
```
Expected output: dossier with decisive source lines, auto-decoded offset table, globals.
If instead you have no address yet → route through `f1c-locate` first.

### Step 3: cross-read the raw code against the claim

Check, in the actual `.c` lines (red-flag list per REFERENCE.md §Verification
Methodology (Architect role)):
- Claimed global actually appears; claimed READ is not actually only a WRITE.
- Claimed type matches the cast (`double` claimed but `*(int *)(ptr + ...)` shown = REFUTED).
- Claimed offset appears as `*(type *)(ptr + 0xNNN)` — beware `↳` pointer-chain rows in
  the dossier (offset into a sub-object, not the base struct).
- Claimed strings/calls actually present.
Verdict so far: static-SUPPORTED, static-REFUTED, or static-SILENT (code neither shows
nor contradicts — e.g. runtime-only values).

### Step 4: LIVE: probe the running game

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/preflight.py probe <expr> --type <T>
```
`<expr>` grammar (full spec in `reference.md`): SDK name (`SessionType`), raw hex addr,
`[expr]` deref, `+0xNN` offset, `:type` suffix. Types: `float double int32 uint32 int
int16 uint16 int8 uint8 byte ptr`. Defaults: `--type int32 --secs 2.0 --hz 30.0`.
Expected output: sampled value(s) for the expression over the sampling window; exit 0.
If instead `'F1 Challenge Online.exe' is not running — start the game first` → STOP the
live step; record the verdict as static-only and report the fact as unverified-live.
If instead `OpenProcess failed (run as admin?) — pid <N>` → re-run shell as Administrator.

For a claim with an expectation (eq/in/range/nonzero) or a stability requirement, write
a one-fact `facts.json` and run `python tools/preflight.py run <facts.json>` instead —
output is `PASS`/`FAIL`/`GATE` per fact, then `<N> hard failure(s).`; exit code = number
of FAILs. Schema and worked examples: `reference.md`.

### Step 5: record the verdict

- Static-SUPPORTED + live agrees → **CONFIRMED** (it becomes FACT only when the claim
  IS the raw source content or an exe byte-read, per `INDEX.md` §Trust tiers).
- Static or live contradicts → **REFUTED** → route to `f1c-doc-audit` to log a
  `[CORRECTION]` in `work/CHANGELOG.md`. Never silently fix or ignore.
- Game unavailable → **UNVERIFIED-LIVE (static-<verdict>)** — usable for planning only;
  say so explicitly in whatever you hand off.

## STOP — do not proceed if

- Any `preflight.py` fact FAILs → fix the fact, not the code. Do not proceed to
  implementation with a failing fact.
- The game is not running and the step is `LIVE:` → stop there; report which facts
  remain unverified. The skill is still useful up to this point (static verdicts).
- The claim's source is LEAD tier (docs/30-impl-specs/, docs/31-call-chains/) and
  Step 3 is static-SILENT → treat as possibly hallucinated; do not propagate it into
  any doc, mod, or conclusion.
- You are about to skip verification "because the doc says so" → forbidden; docs are
  GUESS tier (`INDEX.md` §Trust tiers).

## Failure modes and recovery

| Symptom | Tool + likely cause | Action |
|---|---|---|
| `unknown name '<tok>' (not in SDK; run tools/gen_sdk.py?)` | preflight probe/run: name resolution is case-insensitive EXACT match — no substrings | get the exact name via `poke.py list <substring>`, retry; do NOT reflexively regen the SDK despite the hint |
| `unreadable at 0x00000000` on a deref expr | preflight: the pointer is NULL (menus / not in a session) | LIVE: enter a session; model "in-session" as a `gate:true` fact |
| `unknown global '<tok>' — try: poke.py list <tok>` | poke.py (Step-0 prereq check only): wrong/stale SDK name | `poke.py list <substring>`; regen SDK only after a docs merge, with user awareness |
| `ambiguous '<tok>' — matches:` + list | poke.py: substring matched several globals (poke allows substrings; preflight does not) | use the full unique name from the list |
| value prints `<unreadable>` | poke.py read: bad address / not mapped | claim's address is wrong tier — back to Step 2/3 |
| `player vehicle pointer is NULL (not in session?)` | poke.py `veh` outside a session | LIVE: enter a session, re-probe |
| FAIL on a `stable:true` fact | preflight run: game rewrites the value every tick | the write-target claim is unusable as-is; note it — this is the "writes stick ≠ game reacts" trap |

(Messages quoted verbatim from the tools' output; canonical syntax and message list:
`.claude/skills/_meta/toolfacts.md`.)

## Deep reference

Read `reference.md` in this skill's directory for the full expression grammar, the
facts.json schema, and 5 worked probes including a failing one.

---
Canonical sources: CLAUDE.md §Iron rules; REFERENCE.md §Verification Methodology (Architect role); INDEX.md §Trust tiers — READ THIS BEFORE TRUSTING ANY FILE; docs/_README.md §Rule
Last validated: 2026-07-18 against 6bcccfe
