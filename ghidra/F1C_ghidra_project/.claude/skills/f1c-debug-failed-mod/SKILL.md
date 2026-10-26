---
name: f1c-debug-failed-mod
description: Diagnose a mod that compiles, injects, and logs — but the game does not react, or crashes. Walk a frequency-ordered triage tree from stale-ledger facts to wrong-rung choices, and exit with a bits-not-vibes report. Use when a task says "the mod runs but nothing happens", "writes land but no effect", "the DLL injects then the game crashes", or "my patch does not change behavior". Do NOT use to design a new mod (use f1c-mod-lifecycle), to prove a single write live (use f1c-live-probe), or to log a refuted doc fact (route to f1c-doc-audit for the [CORRECTION] format).
---

# Debug a failed / no-effect mod

## When to use / when not

- Use when a mod is BUILT and RUNS (injects / patches / logs) but the game does not produce
  the predicted observable, or it crashes. This is the post-failure triage, not the build.
- Route out: designing/gating a mod → `f1c-mod-lifecycle`. Proving one write live →
  `f1c-live-probe`. A refuted doc fact needs a `[CORRECTION]` → hand the fact to
  `f1c-doc-audit` for the exact format.

## The rule this skill enforces

A landed write is NOT a working mod. Only an in-game confirmed reaction upgrades a mod's
status (ledger vocabulary — see `INDEX.md` trust tiers); a log read-back does not.
Most failures here are not compiler bugs — they are FACT failures: a GUESS-tier offset, a
stale ledger, or a value the game re-derives each tick. So debugging = re-verifying facts
against the live game per the strategy in `f1c-live-probe` / `f1c-verify-claim`, not editing C.

## Prerequisites

| Prerequisite | Check command | Expected |
|---|---|---|
| A failure log with read-backs | (open) `mods/<name>/<name>_log.txt` | shows writes + read-backs + gate states; if only "loaded" → you cannot debug, re-instrument first |
| Ledger status of this mod | (open) read the Current-contents ledger in `mods/_README.md` and find this mod's row | its real Status column ("LOG-CONFIRMED ONLY" ≠ confirmed) |
| SDK fresh | `ls mods/sdk/f1c_sdk.json` | exists; regen after any docs merge (`python tools/gen_sdk.py`) |

## Procedure

### Step 1: Re-read the ledger critically

Open the Current-contents ledger in `mods/_README.md` and read THIS mod's Status. The ledger has itself
been wrong (see `case-studies.md` case 2). Cross-check the mod's own artifacts — the
`apply_*.py` header and any `README.md` — against the ledger claim. If they disagree, the
artifacts win, and the ledger gets a `[CORRECTION]` (Step 4).

### Step 2: Walk the triage tree in order

Open `triage-tree.md` in this skill's directory and work top to bottom — it is ordered by
HISTORICAL FREQUENCY, so the earliest node is the likeliest cause. The nodes:
1. Stale-ledger facts — re-read the ledger, re-run preflight per fact.
2. Log-confirmed-only trap — writes land, game ignores (value re-derived each tick? gate wrong?).
3. GUESS-tier offset in the chain — never live-probed.
4. Calling-convention / stack — thiscall, `ret N` imbalance after a redirect.
5. Wrong thread / tick timing / race gate never true.
6. Wrong rung — should have started lower on the ladder.

Each node names the exact `LIVE:` command to confirm or eliminate it. Do not skip ahead;
early nodes are cheap and common.

### Step 3: LIVE — re-verify the suspect fact(s) per node

`LIVE:` For a suspected stale/GUESS fact, verify against the running game. For a stability
suspicion (value re-derived each tick — node 2), run the stability check:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/preflight.py probe "[<ptr-expr>]+<offset>:<field-type>" --secs 3
```
Use the field's SDK/docs type for `<field-type>` (e.g. `int32`, `float`), not a guessed one.
Expected output: a stable value if the game leaves it alone; a changing value means the game
rewrites it every tick and YOUR write is clobbered → the field is not the lever.
If a fact FAILs → fix the FACT (find the right offset/global), not the code (see STOP).
Detailed per-node commands are in `triage-tree.md`.

### Step 4: Mandatory exit — update ledger + log corrections

You MAY NOT close a failed-mod session without both:
1. **Ledger update** — set this mod's Status in the `mods/_README.md` Current-contents ledger to what
   the evidence shows (e.g. "GUESS offset 0x…: refuted, real field unknown").
2. **`[CORRECTION]` per refuted fact** — every doc fact you proved wrong gets a `[CORRECTION]`
   entry. Route to `f1c-doc-audit` for the exact `work/CHANGELOG.md` format; do not invent one.

### Step 5: Write the failure report in BITS, not vibes

The report must carry: the logged writes (addr → value), the read-backs (what the re-read
returned), and the gate states at the moment of action (SessionType, RaceActiveFlag, any
`stable:` result). "Nothing happened" is not a report. A bits report lets the next session
(or `f1c-mod-lifecycle`) resume without re-deriving. Template + worked reports are in
`case-studies.md`.

## STOP — do not proceed if

- A `preflight.py` fact FAILs and you are tempted to edit the C to work around it → STOP; fix
  the FACT, not the code. The failing fact is the bug.
- You are about to CALL a game-internal function to "make it react" → forbidden; re-read the
  strategy ladder in `mods/_README.md` (the "strategy ladder (why mods fail)" section).
- The log shows only "loaded" (no write/read-back/gate lines) → STOP; you cannot debug blind.
  Re-instrument the mod to log read-backs (iron rule 6), reproduce, then return.
- Game not running but the step is `LIVE:` → STOP; report which facts remain unverified.
- About to close the session without a ledger update or the `[CORRECTION]`s → STOP; those are mandatory exits.

## Failure modes and recovery

| Symptom | Likely cause | Action |
|---|---|---|
| writes land, no in-game effect | log-confirmed-only trap | triage node 2; `preflight.py probe ... --secs 3` for stability; check the gate |
| value in log keeps changing on its own | game re-derives it each tick | your write is clobbered; the field is not the lever — find the real one |
| crash on inject / after hotkey | called game code, or bad detour prologue | triage node 4; you violated the state-writes-only rule |
| offset gives garbage (huge/NaN) | GUESS-tier offset is wrong | triage node 3; probe raw bytes to locate the real field |
| gate never fires | race gate condition wrong | triage node 5; confirm SessionType/RaceActiveFlag live via `f1c-live-probe` |

## Deep reference

- `triage-tree.md` (this directory) — the frequency-ordered decision tree with a `LIVE:`
  command per node.
- `case-studies.md` (this directory) — three verbatim postmortems (safety_car GUESS offset,
  replay-ai-fix 3-failure + stale-ledger, ai_pit_retire log-confirmed trap). **Marked
  HISTORICAL SNAPSHOT — pedagogy, not live status. Check `mods/_README.md` for current state.**

---
Canonical sources: mods/_README.md §Current contents, §The strategy ladder (why mods fail); INDEX.md §Trust tiers — READ THIS BEFORE TRUSTING ANY FILE; tools/mod_pipeline/MODDING_PLAYBOOK.md §Gotchas learned the hard way; work/CHANGELOG.md ([CORRECTION] classes); CLAUDE.md §Iron rules, rules 4–6
Last validated: 2026-07-18 against 6bcccfe
