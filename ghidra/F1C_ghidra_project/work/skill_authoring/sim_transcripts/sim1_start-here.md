# Sim 1 — f1c-start-here (cold orientation)

- Date: 2026-07-20. Model: Sonnet (general-purpose subagent), fresh context.
- Harness: read-only session, game not running; mutating/LIVE steps drafted not executed.
- Task prompt (verbatim from rubric): "You are new to this repo. The user says: 'I want the AI cars to get a penalty when they speed in the pit lane. Where do we even start?' Orient yourself and begin correctly."
- Rubric: `.claude/skills/_meta/sim_rubrics/f1c-start-here.md`

## Agent final report

## Orientation complete — chronological account

**Read (in order):**

1. **CLAUDE.md** (already in system context) — iron rules: LOCATE via `tools/investigate.py`, mods start at `mods/_README.md`, verify facts before code, strategy ladder, never call game internals from injected code, log read-backs, never re-document.
2. **Skill `f1c-start-here`** — router. Confirmed a "change game behavior" request routes to `f1c-mod-lifecycle`, not straight to code.
3. **`%USERPROFILE%\Desktop\F1C_ghidra_project\INDEX.md`** — trust tiers table, repo map. Noted line 22-24: cross-binary analysis lists "penalty detection" among portable features F1C's siblings have that F1C lacks — a hint this is a real gap, not just a config toggle.
4. **`%USERPROFILE%\Desktop\F1C_ghidra_project\mods\_README.md`** — the ledger (iron rule 3, Gate 1 of the mod lifecycle). No existing mod touches pit-lane speeding. Nearest analogs: `cut_track_dq` (in-game confirmed, byte-redirects a call in the same penalty-dispatch cluster) and `ai_pit_retire` (confirmed vehicle-array iteration primitives: `VehiclePtrArray` 0x007C54F0, count `0x005C329C`, stride 0x48C0, `PlayerVehiclePtr` 0x007C54E8).
5. **Skill `f1c-mod-lifecycle`** — the 8-gate spine. Read fully; Gate 1 done, moved to Gate 2 (decompose facts) and Gate 4 (strategy-ladder rung selection), which is as far as a read-only, game-not-running session can go.

**Commands run (read-only, `tools/investigate.py`):**

- `find "pit lane speed"` / `find "pit lane"` — surfaced global `DAT_005c271c` = `Str_SpeedingInPitL...` referenced by two functions, plus `docs/07-pit-system.md`, `docs/30-impl-specs/12-pit-system-spec.md`.
- `find "penalty"` — threw a `UnicodeDecodeError` in a stdout-reader thread (cp1252 can't decode a byte in one doc's mojibake) but still printed usable results before dying; worth flagging to whoever owns `tools/investigate.py`, not fixing here (read-only). Surfaced the penalty-dispatch cluster: `0x004bbd60` Stop/Go Penalty Handler, `0x004bc9b0` Jumped Start/Grid Penalty, `0x004a5f20`/`0x004a5ea0` Exiting/Entering Pits Under Red, global `DAT_007cef84` = `PenaltiesEnabled`.
- Dossiers on `0x004e3360`, `0x004bbd60`, `0x004bc9b0`, `0x004a5f20`, `0x004a5ea0`, `0x0041a720`, `0x004bccc0`, `0x0042c690` — batched per iron rule 2.
- `find "AI pit lane speed limiter"` / `"pit lane speed limiter"` — nothing. Absence isn't proof (docs are GUESS/LEAD tier and may simply not name it), left as an open question below.

**Grep on docs:** `docs/22-modding-reference.md` (§14 Hardcoded Values — "Pit lane speed limits" listed only as a generic hardcoded-constants note, no address), `docs/35-mod-targets.md` (Rank-5 race_rule cluster), `docs/07-pit-system.md` (no direct hit on the speeding string).

### The key finding (FACT tier — raw decompiled C)

`FUN_004bccc0` (0x004bccc0, `decompiled_all/0x004bccc0__FUN_004bccc0.c`) is the function that actually fires the "Speeding In Pitlane" penalty:

```c
if (*(char *)(*param_1 + 0x344c) == '\0') {
    if (((char)param_1[0x2a] != '\0') && (_DAT_0059e8f4 < (float)param_1[0x2b]) && (DAT_007cef84 != 0)) {
        if (DAT_007c56a4 == 7) {
            FUN_004bbd60(s_Speeding_In_Pitlane_005c271c, 10);   // Stop/Go penalty, race session
        } else {
            FUN_004bba90(s_Speeding_In_Pitlane_005c271c, ...);  // warning message only, practice/quali
        }
    }
}
```
(gated on `DAT_007cef84` = PenaltiesEnabled, `DAT_007c56a4` = SessionType==7 for race).

This function is `__thiscall FUN_004bccc0(int *param_1, float param_2)` — `param_1` is a per-vehicle pointer. It is called from exactly **one** site: `FUN_0042c690` ("Main Game Tick Update", `dynman.cpp`, `analysis_pipeline/analyzed/0x0042c690__FUN_0042c690.c`), and that call site is:

```c
if (*(int *)(DAT_007c54e8 + 13000) == 0) {
    FUN_004bccc0();
}
```

`DAT_007c54e8` is `PlayerVehiclePtr`. Critically, this call is **not** inside any of the `for (iVar2 = 0; iVar2 < DAT_005c329c; iVar2++)` loops that the same function uses elsewhere to update every AI vehicle (`FUN_00424e70`, `FUN_004ee2d0`, `FUN_004ed810`, `FUN_004f1c40`, etc. all loop over `DAT_005c329c` / `VehiclePtrArray`). The penalty check is a single, player-only call.

**Conclusion: AI cars don't get a pit-lane-speeding penalty because the enforcement function is architecturally never invoked with an AI vehicle pointer — not because of a threshold, a config flag, or a difficulty setting.** This is a real, well-grounded starting point, not a guess: it's read directly from FACT-tier raw decompiled source, confirmed by the call-site gate literally testing the player pointer's own flag.

**Ledger cross-check** (`docs/35-mod-targets.md` rank-5 race_rule cluster): both `0x0041a720` and `0x004bccc0` are already flagged there as "Cut Track / Speeding In Pitlane" — status **candidate**, not confirmed. Only `0x004bc0e0` (Disqualified:) is in-game confirmed, via the existing `cut_track_dq` mod. So this repo already suspected these functions were mod-relevant; nobody had traced the AI-exclusion root cause before.

### Strategy-ladder read (Gate 4, written justification required for rung 3+)

1. **Data file** — doesn't apply; this is compiled logic, not a config value.
2. **Memory write** — a poke alone can't fix this. There's no AI-side "is speeding" flag to set; the flag that gates the penalty (`param_1[0x2a]`/`param_1[0x2b]`, offsets into the per-vehicle struct at `+0x2a`/`+0x2c`) is written *by* `FUN_004bccc0` itself, and that function simply never runs for AI. Poking the flag without the function running would do nothing (and would violate rule 6, no read-back path).
3. **Call-site byte redirect** — doesn't fit either. `cut_track_dq`-style redirects swap *one call for another call* at a fixed site; here we need to turn one call into an N-iteration loop over the vehicle array, which is new control flow, not a redirect.
4. **Vtable swap** — not applicable, no vtable involved.
5. **Detour/code-cave in `FUN_0042c690`** — the realistic rung. A cave patch would replace the single `if (...) FUN_004bccc0();` block with a small loop over `VehiclePtrArray`/`DAT_005c329c` (skip the player, skip inactive vehicles via the same `+13000`/`0x32c8` flag) that calls `FUN_004bccc0` per AI car with the correct thiscall convention (ECX = vehicle ptr) — **and this must execute inline on the game's own thread as part of the tick, not be called from an externally injected DLL thread**, per the iron rule against calling game internals from injected code (thiscall `this`, `ret imm` cleanup, wrong thread).

### Where I stopped, and why

- Gate 1 (ledger) is done — no existing mod, confirmed above.
- Gate 2 (decompose to facts) is drafted but not written to disk (read-only session forbids creating `mods/ai_pit_speeding_penalty/facts.json`). Draft, to be created and run once live:

```jsonc
{ "name": "ai_pit_speeding_penalty",
  "facts": [
    {"id":"in_race","expr":"SessionType","type":"int32","expect":{"eq":7},"gate":true},
    {"id":"penalties_enabled","expr":"0x007cef84","type":"int32","expect":{"nonzero":true},"gate":true},
    {"id":"vehicle_count","expr":"0x005c329c","type":"int32","expect":{"range":[1,26]}},
    {"id":"player_ptr","expr":"[0x007c54e8]","type":"ptr","expect":{"nonzero":true}},
    {"id":"vehicle_ptr_array_slot0","expr":"[0x007c54f0]","type":"ptr","expect":{"nonzero":true}},
    {"id":"tick_call_gate","expr":"[[0x007c54e8]+0x32c8]","type":"int32","expect":{"in":[0,1]},
     "note":"the flag gating whether FUN_004bccc0 runs at all for a given vehicle — confirm it means active/in-race, not something else, before assuming it works the same for AI slots"}
  ]}
```

- Gate 3 (LIVE preflight against the running game) **cannot run**: the game is not running, and this session is read-only (no file writes, no mutating commands) — both independently block it. This is the correct, explicit stop point per the mod-lifecycle skill's own STOP conditions ("Game not running but the gate is LIVE → stop; report which gates passed and which facts remain unverified").
- One open question I flagged but didn't chase further (would need either live probing or more decompiled reading, both beyond "orient and begin correctly"): **does the AI even physically exceed the pit-lane speed target today?** No doc names an "AI pit lane speed limiter." If AI's own throttle/speed-target logic already caps it below the limit in the pit lane, this penalty-wiring mod alone would never trigger — worth a live check (Frida trace of an AI car through the pit lane, watching `param_1[0x2b]`/`+0x2c` on an AI slot) before investing in the detour.

### Next actions (not taken, since they need the live game / are mutating)

1. Get the game running, then run `python tools/preflight.py run mods/ai_pit_speeding_penalty/facts.json` (after creating that file) to validate the facts above, especially the `+0x32c8` flag meaning for AI slots.
2. Frida-trace (`f1c-frida-trace`) an AI vehicle driving fast through the pit lane to confirm whether it can currently exceed `TrackRefSpeed` (`DAT_005ea3fc`) at all.
3. If confirmed, design the Gate-5 detour in `FUN_0042c690` (rung 5, written justification already above) via `f1c-byte-patch`/`f1c-dll-mod`, patch a COPY of the exe, test with Frida before baking, per rule 5.
4. Gate 6-8: read-back logging, in-game confirmation against the predicted observable ("AI car speeds in pit lane during a race → Stop/Go penalty message appears for that AI car"), then update `mods/_README.md` and log any `[CORRECTION]`s to `work/CHANGELOG.md`.
