# docs/41-racephase-skip.md — Skipping RacePhase 2 (Pre-Race Presentation)

**Status:** LIVE-TESTED 2026-07-22. Deadline-poke approach (writing `0x007c5750`)
did NOT skip the presentation — see "Live test results" below. Direct write of
`RacePhase=3` does cut the camera to the car but has not been cleanly confirmed
to release the cars to drive (session got confounded by a crash mid-test; needs
a clean re-test). The real natural-transition finding is more useful: this
session's `DAT_007cee88` (`PhaseGateFlag`) stayed 0 the whole gridwalk, so the
game's own state machine drove RacePhase 2→4 directly (COOLDOWN), skipping
GREEN_FLAG (3) entirely — a known alternate path, already documented in
docs/15 as `state_full_race.log`'s 0→2→4→5→8 trace.

---

## Goal

Grid reorder mod (`mods/grid_reorder/gr26.c`) suppresses commentary audio during
the post-restart pre-race presentation (garage screen, pit walkthrough, grid walk),
but the presentation itself still plays out over ~15-30s before racing resumes.
Goal: skip the whole RacePhase==2 period so the restart goes straight to racing.

---

## RacePhase State Machine (confirmed, docs/15 + this session)

Struct base: **`0x007c569c`** (game state struct, "InternalState").

| Offset | Field | Notes |
|--------|-------|-------|
| `+0x0c` | RacePhase (`0x007c56a8`) | 0=PRE_START, 2=GRID_READY (formation+presentation), 3=GREEN_FLAG, 4=COOLDOWN, 5=FINISHING, 8=DONE |
| `+0xb0` | timer1 (`0x007c574c`) | float, purpose TBD (idx 0x2c in FUN_004d2e50) |
| `+0xb4` | **phase deadline** (`0x007c5750`) | float, idx 0x2d. Compared against SessionTime; phase advances once `SessionTime >= this value` |
| `+0xd8` | idx 0x36 field (`0x007c5774`) | set to `0x7f7fffff` (FLT_MAX) on some transitions |
| `+0xf4` | idx 0x3d field (`0x007c5790`) | |
| `+0x104` | idx 0x41 field (`0x007c57a0`) | |

Global: `SessionTime` = `0x008afea0` (float) — the game clock these deadlines are compared against.

---

## The transition function: `FUN_0042d140(this, newPhase)`

Address `0x0042d140`, thiscall. Confirmed via decompile (`decompiled_all/0x0042d140__FUN_0042d140.c`):

```c
void __thiscall FUN_0042d140(int param_1, int param_2) {
    if (*(int*)(param_1 + 0xc) != param_2) {
        *(int*)(param_1 + 0xc) = param_2;   // param_1+0xc = RacePhase
        ...
    }
}
```

This is THE function that writes RacePhase. Called with `this = 0x007c569c` throughout
`FUN_004d2e50` (Pit Timer / Race Phase State Machine, `0x004d2e50`) — confirmed because
`FUN_004d2e50`'s own struct offsets (`+0xb0`, `+0xb4`, `+0xd8`, `+0xf4`, `+0x104`) match
exactly what `FUN_0042d140` and `FUN_004d4580` (Steward Update Main Dispatch, `0x004d4580`)
operate on, all as the same implicit `this` pointer passed through thiscall/fastcall chains.

---

## RacePhase==2 handler (`FUN_004d2e50` case 2)

```c
case 2:
    if (*(char *)((int)param_1 + 0xc2) == '\0') {
        FUN_0040cde0(5,1);
        *(undefined1 *)((int)param_1 + 0xc2) = 1;
    }
    if (*param_1 == 2) {
        FUN_0040dd80();
    }
    FUN_0040de60();
    if (_DAT_008afea0 < (double)(float)param_1[0x2d]) break;   /* <-- THE GATE */
    *(undefined1 *)((int)param_1 + 0xc2) = 0;
LAB_004d30ab:
    if (DAT_007cee88 == 0) {
        param_1[0x36] = 0x7f7fffff;
        param_1[0x2c] = 0x7f7fffff;
        *(undefined1 *)((int)param_1 + 0xc2) = 0;
        FUN_0042d140(4);   /* -> COOLDOWN, skips racing entirely (wrong path) */
    } else {
        FUN_0042d140(3);   /* -> GREEN_FLAG (the path we want) */
    }
    break;
```

**The gate:** `if (SessionTime < deadline) break;` — i.e. as long as `0x008afea0 < *(float*)0x007c5750`,
phase 2 keeps re-running every tick and never advances. The moment `SessionTime >= deadline`,
next tick calls `FUN_0042d140(3)` (or `(4)` if `DAT_007cee88 == 0` — SessionInitFlags gate,
need to confirm this stays nonzero in a red-flag restart so we get GREEN_FLAG not COOLDOWN).

---

## Proposed fix (NOT YET LIVE-TESTED)

Pure memory write, safe from injected thread, following the "poke the timer" pattern
(same class as the confirmed HUD/commentary suppression fixes):

```c
#define PHASE_DEADLINE  (*(volatile float*)0x007c5750)
#define SESSION_TIME    (*(volatile float*)0x008afea0)
#define SESSION_INIT_FLAGS (*(volatile int*)0x007cee88)

/* Call every tick while RacePhase==2 during our post-restart phase 3. */
static void skip_racephase2(void) {
    if (RACE_PHASE == 2) {
        PHASE_DEADLINE = SESSION_TIME;   /* force gate to pass on next tick */
    }
}
```

This does NOT call `FUN_0042d140` directly (iron rule: never call game internals from
injected code). It just makes the deadline the game's OWN state machine already checks
arrive immediately — the game's own code performs the actual transition, camera resets,
grid setup etc. Much lower risk than forcing `RacePhase` itself.

**Risk / unknowns:**
- `DAT_007cee88` (SessionInitFlags) must be nonzero at this point or we get phase 4
  (COOLDOWN) instead of phase 3 (GREEN_FLAG) — untested which value it holds during
  a red-flag restart.
- `+0xc2` byte (a "latch" flag, set/cleared around the transition) — writing the deadline
  externally skips the normal accumulation the latch expects; unclear if this causes any
  visible glitch (camera/sound). Needs live test.
- `param_1[0x2c]` (`0x007c574c`, "timer1") also gets set to `0x7f7fffff` in the transition
  — not our concern, the game's own code does that once the gate passes.

---

## Live-verification plan (NOT DONE — next session should do this first)

1. Get game into RacePhase==2 (restart → garage/presentation screen).
2. `python tools/poke.py read RacePhase 0x007c5750:float 0x008afea0:float 0x007cee88:int32`
   — confirm deadline (`0x007c5750`) is a plausible small-ish float close to but above
   current `SessionTime` (`0x008afea0`), and note `SessionInitFlags` value.
3. `python tools/poke.py write 0x007c5750:float <SessionTime value>` — single poke, watch
   if the game immediately transitions to racing (or COOLDOWN — check RacePhase after).
4. If phase 3 (GREEN_FLAG) confirmed and no visible glitch, bake into `gr26.c`/next fork
   as `skip_racephase2()`, called every tick while `RacePhase==2` in phase 3 of the mod.
5. If `SessionInitFlags==0` causes wrong path (COOLDOWN), find where that flag is set/reset
   during red-flag restart and either poke it too, or gate our skip until it's nonzero.

---

## Live test results (2026-07-22)

Read-only watch (no writes) of a fresh, un-poked race start, sampled every 0.5s:

```
RacePhase 0 -> 2  @ +9.4s   (garage -> gridwalk/presentation)
RacePhase 2 -> 4  @ +29.5s  (gridwalk -> COOLDOWN, skips 3/GREEN_FLAG)
```

`DAT_007cee88` (`PhaseGateFlag`) read 0 on every single sample throughout. Matches
the raw decompile's else-branch exactly (`FUN_0042d140(4)` when `DAT_007cee88==0`,
see "RacePhase==2 handler" above) — confirms the decompile is FACT-tier accurate
here, not the earlier assumption that this doc's phase-name table was wrong (it
wasn't; it matches docs/15 lines 246-249).

Separately, an earlier prod poking session (before this clean baseline) corrupted
`0x008afea0`/adjacent memory after repeated mismatched-type writes to `0x007c5750`
and the game crashed ~15s later. Lesson: always restore/verify a poked address
before moving to a new test, and don't leave a deadline write in a denormal/garbage
state between test runs.

**Open question, not yet answered:** what normally sets `DAT_007cee88` nonzero
(i.e. what's different in the sessions where the game DOES reach GREEN_FLAG)?
Needs a Frida watch on writes to `0x007cee88` across a session that starts cleanly.

## Related

- Commentary suppression gate (RacePhase==2 based): [docs/40-hud-text-overlay.md](40-hud-text-overlay.md) is HUD, actual commentary gate work is in `mods/grid_reorder/gr26.c` (CommentaryEnabled byte `0x007c56a8+0x48`... actually `CONTROLLER+0xAF0`, see [docs/39](39-commentary-system.md)).
- F1CUI reverse-engineered confirmation: `isPreracePresentationRunning()` in F1CUILive.jar
  checks `stepOfRaceSession==2` where `stepOfRaceSession = baseModuleAddr + 0x3C56A8` = `0x007C56A8` = RacePhase. Confirms RacePhase is the right variable F1CUI itself keys off for the exact same "hide presentation" use case.
