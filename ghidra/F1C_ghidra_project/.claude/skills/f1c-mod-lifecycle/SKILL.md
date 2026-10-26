---
name: f1c-mod-lifecycle
description: The mandatory 8-gate sequence for building ANY new F1 Challenge game modification, from ledger check through preflight fact verification to in-game confirmation and ledger update. Use when a task says "make a mod", "change game behavior", "restore/add a feature", "make X happen in the game". Do NOT use for a single live memory read/write — use f1c-live-probe. Do NOT use to execute an already-designed byte patch — use f1c-byte-patch. Do NOT use when an existing mod misbehaves — use f1c-debug-failed-mod.
---

# Build a game mod — the 8-gate lifecycle (SPINE)

## When to use / when not

This is the spine: every new mod passes ALL eight gates in order; the other mod
skills are its sub-procedures. Route out: existing mod broken → `f1c-debug-failed-mod`;
one doc claim in doubt → `f1c-verify-claim`; raw live memory work → `f1c-live-probe`.
Print `checklist.md` (this directory) and tick gates as you pass them.

## Prerequisites

| Prerequisite | Check command | Expected |
|---|---|---|
| SDK json exists | `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && ls mods/sdk/f1c_sdk.json` | path printed; missing → `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/gen_sdk.py` (runs immediately, overwrites both SDK files) |

## Procedure

### Gate 1: Read the mod ledger FIRST

Read `mods/_README.md` §Current contents and §Related (not yet consolidated here).
CLAUDE.md iron rule 3, verbatim:

> 3. **Mods: read `mods/_README.md` (ledger) FIRST**, then
>    `tools/mod_pipeline/MODDING_PLAYBOOK.md`. Only `cut_track_dq` is in-game
>    confirmed — treat everything else as unproven.

Check whether the mod (or its facts) already exists and read status CRITICALLY:
"LOG-CONFIRMED ONLY" ≠ confirmed — log confirms write ≠ game reacted. The nearest
existing mod is the fastest start: copy it and change the write. The ledger has been
wrong before; a mod's own artifacts (apply script header, bug doc) carry ground truth.

### Gate 2: Decompose the mod into individual factual claims → facts.json

List every fact the mod stands on (address exists, field means X, value range, gate
condition). Get the template (prints a template facts.json; not LIVE):
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/preflight.py example
```
Schema and grammar, reproduced from `_meta/toolfacts.md` §tools/preflight.py — its addresses
are illustrative, NOT facts to reuse; take real ones from
`docs/12-globals-reference.md` / the SDK via `f1c-locate` (the `//` notes are
annotations, strip them for valid JSON):

```jsonc
{ "name": "mod_name",
  "facts": [
    {"id":"vehicle_count","expr":"0x005C329C","type":"int32","expect":{"range":[1,26]}},   // toolfacts example addr — do not reuse
    {"id":"player_ptr","expr":"[0x007C54E8]","type":"ptr","expect":{"nonzero":true}},      // toolfacts example addr — do not reuse
    {"id":"finish_state","expr":"[0x007C54F0]+0x4064","type":"int32","expect":{"in":[0,1,2,3]},"stable":true},   // toolfacts example — do not reuse
    {"id":"in_race","expr":"SessionType","type":"int32","expect":{"eq":7},"gate":true} ] }
```
Expression grammar: `expr := atom (('+'|'-') hex)*`, `atom := '[' expr ']' | name |
hexaddr` — SDK name | raw addr | `[...]` deref (read u32 ptr) | `+0x..` offset,
nests arbitrarily; `:type` suffix is probe-only (run uses each fact's `"type"`).
`expect` kinds: `{"eq":v}` | `{"in":[..]}` | `{"range":[lo,hi]}` | `{"nonzero":true}`
(omit = readable-only). `stable:true` = FAIL if the game rewrites it during
`--stable-secs` (your write would be clobbered). `gate:true` = precondition,
reported as GATE not FAIL. Disputed/novel claims go through `f1c-verify-claim` first.

### Gate 3: LIVE: preflight — zero FAILs before ANY code

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/preflight.py run mods/<name>/facts.json
```
Expected output: per-fact `PASS` / `FAIL` / `GATE` lines, then `<N> hard
failure(s).` **Exit code = number of FAILed facts, gates excluded; 0 = compose the
mod.** If instead any FAIL → fix the FACT, not the code (locate raw `.c`, correct
the claim, re-run). If a GATE is unmet → enter the right game state and re-run.
CLAUDE.md iron rule 4, verbatim:

> 4. **Mods: verify facts before code.** Decompose the mod into individual claims and
>    check each against the live game: `python tools/preflight.py run <facts.json>`
>    (template: `preflight.py example`; ad-hoc: `preflight.py probe <expr>`).
>    Never test "does the whole mod work" as the first test — 1-bit feedback over
>    GUESS-tier facts is a coin flip; per-fact verification converges in 2 passes.

### Gate 4: Choose the LOWEST workable rung on the strategy ladder

CLAUDE.md iron rule 5, verbatim:

> 5. **Mod strategy ladder:** data file > memory write (poke-proven, then tick DLL) >
>    call-site byte redirect > vtable swap > detour. **Never call game internals from
>    injected code** (thiscall `this`, `ret imm` stack cleanup, wrong thread).
>    Patch a COPY of the exe, verify original bytes first, test with Frida before baking.

Written justification is required for rung 3+: state why each lower rung fails
(rationale: `mods/_README.md` §The strategy ladder (why mods fail)).

### Gate 5: Implement — via the matching sub-skill

- Chosen rung = data-file/config change → find the field's parser and file with
  `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/investigate.py
  param <field-name>`; edit the data file, no binary work.
- Chosen rung = memory write → LIVE: poke-prove it first: open `f1c-live-probe` at
  Step 4 (write + prove) — if a hand poke doesn't produce the behavior, no DLL built
  on it will; once proven and it must persist → open `f1c-dll-mod` (tick DLL).
- Chosen rung = call-site byte redirect, constant flip, branch NOP, or vtable slot
  swap → open `f1c-byte-patch` at Step 1 (resolve target identity).
- Chosen rung = detour (last resort, ruled out in writing) → `f1c-dll-mod`, detour section.
- Rung 3/4 reversible test → the Frida twin IS `f1c-byte-patch` Step 5; open
  `f1c-frida-trace` only for deeper runtime observation or non-patch tracing.

### Gate 6: Read-back logging is built in

Whatever the rung, the mod must prove its own writes. CLAUDE.md iron rule 6, verbatim:

> 6. **Mods must log read-back values** (write, re-read, log both + gate states) so a
>    failure report carries bits, not "nothing happened".

### Gate 7: LIVE: in-game confirmation against a PREDICTED observable

Write the prediction down BEFORE testing ("cut a corner → instant DQ"), then
perform it in-game. Log confirms write ≠ game reacted — only the predicted
observable happening upgrades the mod to confirmed. Prediction fails or game
crashes → open `f1c-debug-failed-mod` with your logged bits (writes, read-backs,
gate states); a failed prediction usually means a doc oversimplification.

### Gate 8: Mandatory exit — update the ledger + log corrections

Update the mod's row/status in `mods/_README.md` §Current contents (exact wording:
"in-game confirmed" only after Gate 7; otherwise "LOG-CONFIRMED ONLY" / "UNTESTED").
For every doc fact preflight or testing refuted, add a `[CORRECTION]` entry to
`work/CHANGELOG.md` (format: `f1c-doc-audit`'s `correction-format.md`; do not
invent one). Never delete doc content — correct and log.

## STOP — do not proceed if

- Any `preflight.py` fact FAILs → fix the fact, not the code; re-run until 0 FAILs.
- You are about to write mod code before Gate 3 ran clean → forbidden; go back.
- You are about to call a game-internal function from injected code → forbidden; re-read Gate 4.
- `patch.py` reports FOREIGN bytes at any site → wrong exe or stale manifest; STOP
  and investigate (see `f1c-byte-patch`). Never force-write.
- You are about to patch the ORIGINAL exe (no `--out` copy) → STOP; COPY only.
- Game not running but the gate is `LIVE:` → stop; report which gates passed and
  which facts remain unverified — and still execute Gate 8: ledger row with status
  UNTESTED + any `[CORRECTION]`s. Dry-run/read-only does NOT lift Gate 3: no Gate-5+
  code (`.c`/bytes/build scripts) — deliverable is facts.json + report + Gate 8 row.
- The task is fixing an EXISTING mod → wrong skill; open `f1c-debug-failed-mod`.

## Failure modes and recovery

| Symptom | Likely cause | Action |
|---|---|---|
| preflight exits nonzero | that many FAILed facts | fix each fact vs raw `.c`; `f1c-verify-claim` |
| fact PASSes but `stable:true` FAILs | game rewrites the value per tick — a design signal, not a doc error | pick per-tick writer (`f1c-dll-mod`) or patch producer (`f1c-byte-patch`) at Gate 4; remove `stable:true` from that fact, record why in the mod notes, re-run to 0 FAILs |
| writes land, no in-game effect | wrong causal field / gate never true | `f1c-debug-failed-mod` triage tree |

## Deep reference

Read `checklist.md` (gate tick-list) and `reference.md` (cut_track_dq walkthrough
— in-game-confirmed example; status per `mods/_README.md`) in this skill's directory.

---
Canonical sources: `CLAUDE.md` §Iron rules; `mods/_README.md` §Current contents; `mods/_README.md` §The strategy ladder (why mods fail); `tools/mod_pipeline/MODDING_PLAYBOOK.md` §The process; `tools/mod_pipeline/MODDING_PLAYBOOK.md` §Iron rules (violate these and you break the game); `_meta/toolfacts.md` §tools/preflight.py
Last validated: 2026-07-18 against 6bcccfe
