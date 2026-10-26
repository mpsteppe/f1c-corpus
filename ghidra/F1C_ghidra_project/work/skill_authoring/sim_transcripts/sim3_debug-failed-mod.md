# Sim 3 — f1c-debug-failed-mod (ai_pit_retire triage)

- Date: 2026-07-20. Model: Sonnet (general-purpose subagent), fresh context.
- Harness: read-only session, game not running; mutating/LIVE steps drafted not executed.
- Task prompt (verbatim from rubric): "My ai_pit_retire DLL logs `retired 21 AI cars (count=22)` when I press F8, but the cars keep driving normally. It compiles and injects fine. Figure out why."
- Rubric: `.claude/skills/_meta/sim_rubrics/f1c-debug-failed-mod.md`

## Agent final report

## Summary of investigation (read-only session — no files modified)

**Question:** `ai_pit_retire` logs `retired 21 AI cars (count=22)` on F8, but cars keep driving. Why?

### What I read, in order

1. **Skill `f1c-debug-failed-mod`** (`.claude/skills/f1c-debug-failed-mod/{SKILL,triage-tree,case-studies}.md`) — this is literally the documented case study (Case 3: "ai_pit_retire: writes stick ≠ game reacts", Node 2 in the triage tree).

2. **`mods/_README.md`** — ledger row for `ai_pit_retire/` already states: **LOG-CONFIRMED ONLY** — "writes land... but desired in-game outcome NOT confirmed... suspect game logic never reads it, or reads a different field." So the ledger had already diagnosed the *shape* of the problem; my job was to pin down the actual mechanism.

3. **`mods/ai_pit_retire/README.md`** — documents an intended **3-field write**: pit flag (`0x005F073C+i*0x48C0`=3), `veh+0x4064` FinishState=2 (DNF), `veh+0x4068` ReasonCode=5.

4. **`mods/ai_pit_retire/ai_pit_retire.c`** (the actual shipped v3 code) — reveals the real bug: **the shipped code only writes `veh+0x4068` (ReasonCode=5). It never touches FinishState or the pit-flag array**, despite what the README describes. `retire_all_ai()` does exactly one write per car and logs the count of cars whose `ReasonCode` was 0→5.

5. `ls mods/ai_pit_retire/` + version logs — confirmed no `facts.json` exists for this mod (Node 1 requires creating one). Read `ai_pit_retire_v3_log.txt` (the log in the bug report), `ai_pit_retire_v2_log.txt` (an earlier version literally called `AI_CallPit` — a game-internal function call, the forbidden rung per iron rule 5) and `ai_pit_retire_dbg_log.txt` (a debug build showing FinishState was already `2` for all 21 AI cars *before* any write — a red flag that FinishState semantics/state near this offset are murkier than the docs table implies, though not central to this bug).

6. `git status --porcelain mods/` → `mods/` is untracked (`?? mods/`), consistent with README/case-studies framing.

7. **`docs/13-struct-offsets.md`** grep for `0x4064`/`0x4068`/FinishState/ReasonCode — found the offset is documented from many call sites but with **inconsistent DNF values across entries** (line 3955 says `3=DNF/excluded` while five other entries say `2=DNF`), a doc-quality red flag worth a follow-up audit but not this session's blocker.

8. **`tools/investigate.py`** (per iron rule 2, batched, read-only) on the three functions the mod's own comment cites as "verified" sources of the ReasonCode values (`FUN_00438690`, `FUN_0043ef20`, `FUN_00442060`). This produced the decisive FACT-tier evidence:
   - `FUN_00438690` ("Physics Collision Damage & DNF Detection") is the *exact* real-game function that sets `ReasonCode=5` (gearbox) — the same value/offset the mod copies. Its full decompiled body (`analysis_pipeline/analyzed/0x00438690__FUN_00438690.c`, lines 59-62) does **only** `if (reason==0) reason=5;` — it **never writes FinishState**, in the real game, either.
   - `tools/investigate.py uses 4068` → 6 writers, 5 readers of ReasonCode. None of the readers treat a nonzero ReasonCode as "retire this car now" — the only semantic reader (`FUN_0041b250`) just checks `==1` for a commentary string. **Nothing in the reachable code converts ReasonCode into an immediate FinishState transition** — it's a slow-building damage flag, not a kill switch.
   - `tools/investigate.py uses 4064` (FinishState) plus reading `FUN_004a6db0` ("VehicleControlEnabled", called from the AI state machine `FUN_004A5D10` and pit-state machine `FUN_004A6E50`) showed the AI-control gate is:
     ```c
     if (... && (*(int*)(iVar1+0x4064) != 1 && *(int*)(iVar1+0x4064) != 3)) {
         cVar3 = FUN_004d21d0();  // continue driving
     }
     ```
     i.e. **FinishState==2 (DNF) is NOT excluded** — only `1` (finished) and `3` (DSQ) stop AI control here. So even the README's originally-*intended* 3-write design (which the shipped code doesn't implement) would likely **still** not have stopped the cars via this gate.
   - A recurring, heavily-read sub-object field at offset `+0x32c8` (13000 decimal, dereferenced through the vehicle's inner struct pointer) gates pit-state and damage logic in multiple functions with values 0/2/3, and is currently only GUESS-tier named in docs/13 ("VehicleActiveFlag?"/"PitTireState?") — a stronger unexplored candidate for "the field the AI/pit machinery actually treats as retired," but unverified.

### Diagnosis (Node 2b — wrote the wrong field, confirmed by FACT-tier source, not just live probing)

The mod's log is accurate: writes to `ReasonCode` (`veh+0x4068`) land and read back exactly as written (5). But this is a **log-confirmed-only trap**: `ReasonCode` is not itself consumed anywhere as a "stop driving" signal — the identical real-game function it copies (`FUN_00438690`) treats `ReasonCode` purely as a damage marker with no accompanying state change. `FinishState` (`veh+0x4064`), the field the mod's own README describes as part of the design, is never written by the shipped v3 `.c` at all. And even if it were, the vehicle-control-enable gate (`FUN_004a6db0`) doesn't exclude `FinishState==2`, so a naive "just add the FinishState=2 write back" fix is not guaranteed to work either — it needs live verification, and possibly the `+0x32c8` field needs setting instead/also.

### Where I stopped and why

I could not execute any `LIVE:` step (`preflight.py probe`, `preflight.py run`, `poke.py read`) because **the game is not running and cannot be launched** in this session, and I was constrained to read-only actions (no file writes/mutating commands). Per the skill's STOP condition ("Game not running but the step is LIVE → STOP; report which facts remain unverified"), I stopped short of live verification and instead drafted everything the skill's mandatory exit requires, for the user (or a live-game session) to apply/run:

**Facts to verify live before touching any code** (`mods/ai_pit_retire/facts.json` — not created, contents below for the user to write/run):
```json
{
  "name": "ai_pit_retire",
  "facts": [
    { "id": "reason_code_stable", "expr": "[0x007C54F0][1]+0x4068", "type": "int32",
      "expect": { "in": [0,4,5,6,9] }, "stable": true },
    { "id": "finish_state_after_press", "expr": "[0x007C54F0][1]+0x4064", "type": "int32",
      "expect": { "in": [0,1,2,3] }, "stable": true },
    { "id": "vehicle_active_flag_0x32c8", "expr": "[[0x007C54F0][1]]+0x32c8", "type": "int32",
      "expect": { "in": [0,2,3] }, "stable": true }
  ]
}
```
Run live with `python tools/preflight.py run mods/ai_pit_retire/facts.json` right after pressing F8 in a race, then again 10-30s later — the "stable" flags will show whether `ReasonCode` gets silently reset (Node 2a) or genuinely never triggers anything (confirms Node 2b, my finding above).

**Ledger update I would apply** to `mods/_README.md` (row for `ai_pit_retire/`):
> `ai_pit_retire/` | Press F8 in a race → every AI car pits + DNFs (player untouched) | **REFUTED — wrong field.** v3 `.c` only writes `veh+0x4068` ReasonCode=5; never writes FinishState or the pit-flag array despite README's documented 3-write design. Verified against the real game function it copies (`FUN_00438690`): that function *also* only sets ReasonCode, never FinishState — so ReasonCode alone is a damage marker consumed nowhere as an instant trigger (`tools/investigate.py uses 4068`, no reader treats it as retire-now). Even FinishState=2 (DNF) is not excluded by the AI control-enable gate `FUN_004a6db0` (only 1=finished/3=DSQ stop control) — so simply adding the missing write may still not work; verify `+0x32c8` sub-object field live first. Next: run `facts.json` above.

**`work/CHANGELOG.md` `[CORRECTION]` I would log:**
> `[CORRECTION] mods/ai_pit_retire/README.md` describes a 3-field write (pit flag=3, FinishState=2, ReasonCode=5) but the shipped `ai_pit_retire.c` (v3) implements only the ReasonCode=5 write. Decompiled source of `FUN_00438690` (the real function the mod cites as verification for ReasonCode=5) confirms it too never touches FinishState — ReasonCode is a damage-accumulation flag, not a retire trigger. `docs/13-struct-offsets.md` also has an internal conflict on FinishState's DNF value (line 3955 says 3, five other entries say 2) — needs a `f1c-doc-audit` pass.

**Bits report (per case-studies.md template):**
```
MOD: ai_pit_retire   VERSION: v3   TRIAGE NODE: 2b (wrote the wrong field)
PREDICTED OBSERVABLE: AI cars pit + DNF, stop racing
ACTUAL: cars keep driving normally

WRITES (from ai_pit_retire_v3_log.txt):
  veh+0x4068 ReasonCode = 5 -> re-read 5 [landed: yes, 21/22 cars]
  veh+0x4064 FinishState: NOT WRITTEN (code omits it; README claims it is)
GATE STATES at action time: SessionType=7, RaceActiveFlag!=0 (both required, both presumably true — F8 fired)
STABILITY: not run — game not available this session
FACT (source code): FUN_00438690 (real gearbox-failure path) also writes only ReasonCode,
  never FinishState -> ReasonCode is not a retire trigger anywhere in the reachable code.
FACT (source code): FUN_004a6db0 (AI control-enable gate) excludes FinishState 1,3 only —
  NOT 2 (DNF) -> even the originally-designed FinishState=2 write may not stop AI control.

NEXT STEP: live-run the facts.json above; if finish_state/0x32c8 probes confirm, redesign
the write to set FinishState=3 (DSQ, proven-excluded) or locate the +0x32c8 sub-object
field's real name/semantics before rebuilding.
```

I did not modify `mods/_README.md`, `work/CHANGELOG.md`, or create `facts.json` — all three are presented above as exact content for you (or a live-game session) to apply, per the read-only constraint.
