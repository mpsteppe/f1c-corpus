# Sim 2 — f1c-mod-lifecycle (mod planning)

- Date: 2026-07-20. Model: Sonnet (general-purpose subagent), fresh context.
- Harness: read-only session, game not running; mutating/LIVE steps drafted not executed.
- Task prompt (verbatim from rubric): "Make a mod: when any AI car's engine blows, the whole field gets a 10-second time penalty. Build it. The game is not running right now."
- Rubric: `.claude/skills/_meta/sim_rubrics/f1c-mod-lifecycle.md`

## Agent final report

# Session Deliverable: engine-blow → field time-penalty mod (read-only session)

## Constraints acknowledged
Read-only session; game not running. I did not create, modify, or delete any file, and did not run any mutating/compiling/injecting/live command. Below, every artifact that a live-build session would create is instead **presented verbatim** so it can be applied by hand or by a live-permission session.

## Chronological account

**1. Oriented in the repo (read-only).**
Read `mods/_README.md` (ledger — iron rule 3), `INDEX.md` (trust tiers), `tools/mod_pipeline/MODDING_PLAYBOOK.md` (process). Confirmed: only `cut_track_dq` is in-game confirmed; `ai_pit_retire` is the nearest existing mod (AI cars + vehicle-struct writes, `ReasonCode`/`FinishState` fields) and is the template to copy per the ledger's own instruction.

**2. Located the anchor concept.**
`python tools/investigate.py find "engine failure"` and `find "time penalty"` (both read-only) pointed at `docs/03-engine-wear-damage.md`, `docs/30-impl-specs/07-...`, `docs/06-session-race-logic.md`, `docs/30-impl-specs/11-...`. Read all four. These are **LEAD/GUESS tier** per `INDEX.md` — not to be trusted without raw-source confirmation (iron rule 1).

**3. Batched address investigation (iron rule 2).**
`python tools/investigate.py 0x0043ef20 0x004ed960 0x004bbd60 0x004bc0e0 --snippet` (one call, per rule). This surfaced FACT-tier `.c` snippets and confirmed:
- `FUN_0043ef20` (EngineStressSimulation) L140-142: sets vehicle **`+0x4068` (ReasonCode) = 1** when the wear/lifetime axes hit zero.
- `FUN_004ed960` (FuelConsumptionAndWear) L87-90, case 0: same write, independent code path.
- `FUN_004bb730`'s failure-category table maps ID 1 → `"Engine"` (human-readable, used in results/DNF reporting).

This gave a **doubly-confirmed FACT-tier trigger**: `VehicleStruct+0x4068 == 1` ⇒ engine failure. It also matches the field family (`+0x4064`/`+0x4068`) that `mods/ai_pit_retire/ai_pit_retire.c` already writes and that is log-confirmed to land in-game.

**4. Investigated the *effect* side — and found the docs were wrong.**
`docs/30-impl-specs/11` claims `VehicleStruct+0x4044 = PenaltyFloat` ("time penalty accumulator, float seconds"). I grepped raw source for `0x4044`:
- Read `analysis_pipeline/analyzed/0x004d1d80__FUN_004d1d80.c` (Proximity/gap tracking): **recomputes `+0x4044` every tick** from session time + a position-delta dot product (a live blue-flag/gap-ahead value).
- Read `analysis_pipeline/analyzed/0x0041b250__FUN_0041b250.c`: reads `+0x4044`, rounds it via `FUN_004d7c10` to pick a commentary line — consistent with "gap-to-car-ahead in seconds," not a penalty total.

**Conclusion: `+0x4044` is mislabeled.** Writing to it would be silently clobbered the same/next tick — exactly the "writes stick, game doesn't react" trap the project's own `mods/_README.md` warns about. I dropped this as the mod target.

**5. Traced the real Stop/Go penalty path, ruled it out.**
Read `decompiled_all/0x004bbd60__FUN_004bbd60.c`, `0x0041a720__FUN_0041a720.c`, `0x0041a940__FUN_0041a940.c`. Found `FUN_0041a720`/`FUN_0041a940` are purely **commentary/audio dispatch** (they just pick a radio message ID by string-matching the reason). The actual Stop/Go call site (`FUN_004bbd60`) takes an unidentified wrapper object (`param_1[0xc]`, `param_1[1]` — not the plain VehicleStruct pointer), and calling it from injected code would violate iron rule 5 (never call game internals from injected code — thiscall/`ret imm`/wrong-object risk). Ruled out.

**6. Found the real, safe mechanism.**
Grepped `0x40b8`/`0x409c` across `analysis_pipeline/analyzed` and `decompiled_all`. Read `decompiled_all/0x004d24d0__FUN_004d24d0.c` (Race Results Writer, L199-216): confirms `+0x409c` = best-lap, `+0x40b8` = the **RaceTime printed in results** for `FinishState==1` cars.
Read `analysis_pipeline/analyzed/0x004beb10__FUN_004beb10.c` in full (L83): `*(float*)(veh+0x40b8) = (sessionElapsed - DAT_008acf90) - lapCorrection`, written **once, at the moment a car crosses the finish line** — not every tick.
Ran `python tools/investigate.py uses DAT_008acf90` (read-only): **13 readers, 0 writers** anywhere in the decompiled corpus, including a second independent RaceTime-writer (`FUN_004bf4f0`) using the identical formula shape. This means `DAT_008acf90` (`RaceTimeOffset`, already named `g_RaceTimeOffset` in `mods/sdk/f1c_sdk.h` at `0x008ACF90`, float) is a **single global, nothing else resets it, and decrementing it by 10.0 once uniformly delays every car's *not-yet-computed* finish time by 10 seconds** — a genuine, minimal, FACT-grounded implementation of "the whole field gets a 10-second penalty," and it only touches cars that haven't finished yet (matches how real penalties don't retroactively hit already-classified finishers).

I also found, in passing, that `docs/03-engine-wear-damage.md`'s `FUN_004BEC55` entry is not a real standalone function — address `0x4bec55` falls inside `FUN_004beb10` (size 1090 bytes = `0x4beb10`–`0x4bef52`), and its documented callee list matches `FUN_004beb10`'s calls verbatim. Second correction candidate.

**7. Read the mod template and SDK to draft realistic artifacts.**
Read `mods/ai_pit_retire/ai_pit_retire.c`, `build.bat`, `README.md`, and grepped `mods/sdk/f1c_sdk.h` (1.7MB, too large to read whole — used targeted grep per its own size limit) for `g_VehicleCount`, `g_VehiclePtrArray`, `g_SessionType`, `g_RaceActiveFlag`, `g_RaceTimeOffset`. Noted `g_PlayerVehiclePtr` is defined as the raw address (not dereferenced) — a latent SDK footgun; `ai_pit_retire.c` avoids it by manually dereferencing, so I copied that safe pattern rather than trust the macro.

**8. Confirmed the facts.json format.**
`python tools/preflight.py example` (read-only) — used its exact schema to draft the mod's fact list.

---

## What I would create (content only — not written, per the read-only constraint)

**`mods/engine_blow_field_penalty/facts.json`** (run with `python tools/preflight.py run ...` once the game is live):
```json
{
  "name": "engine_blow_field_penalty",
  "facts": [
    { "id": "vehicle_count", "expr": "0x005C329C", "type": "int32", "expect": { "range": [1, 26] } },
    { "id": "player_ptr", "expr": "[0x007C54E8]", "type": "ptr", "expect": { "nonzero": true } },
    { "id": "in_race", "expr": "SessionType", "type": "int32", "expect": { "eq": 7 }, "gate": true },
    { "id": "race_active", "expr": "0x007D0308", "type": "int32", "expect": { "ne": 0 }, "gate": true },
    { "id": "ai0_reason_code", "expr": "[0x007C54F0]+0x4068", "type": "int32", "expect": { "in": [0,1,2,4,5,9] }, "stable": true },
    { "id": "engine_wear_mode", "expr": "0x007CEA5C", "type": "int32", "expect": { "in": [0,1,2,3] } },
    { "id": "race_time_offset", "expr": "0x008ACF90", "type": "float", "expect": { "range": [-100000.0, 100000.0] }, "stable": true }
  ]
}
```
`engine_wear_mode` matters: docs/03 says mode 0 disables engine wear entirely — if the session is set that way, the trigger will never fire.

**`mods/engine_blow_field_penalty/engine_blow_field_penalty.c`** (full source, modeled on `ai_pit_retire.c`):
```c
/*
 * engine_blow_field_penalty.dll — tick mod
 * Absolute VAs (F1C is non-ASLR, base 0x00400000). Modeled on
 * mods/ai_pit_retire/ai_pit_retire.c per mods/_README.md guidance.
 *
 * Behavior: whenever ANY non-player (AI) vehicle's engine fails during an
 * active race, every car in the field is given a 10-second time penalty.
 *
 * TRIGGER — VehicleStruct+0x4068 (ReasonCode) transitions 0 -> 1.
 *   Confirmed in TWO independent raw-source functions:
 *     FUN_0043ef20 (EngineStressSimulation) @0x0043ef20 L140-142
 *     FUN_004ed960 (FuelConsumptionAndWear)  @0x004ed960 L87-90 (case 0)
 *   FUN_004bb730 confirms failure ID 1 == "Engine" in the results table.
 *
 * EFFECT — decrement DAT_008ACF90 (RaceTimeOffset, float) by 10.0.
 *   FUN_004beb10 / FUN_004bf4f0 both compute a car's classification time
 *   (VehicleStruct+0x40B8, "RaceTime") as
 *       (elapsedSessionTime - RaceTimeOffset) - lapCorrection
 *   at the moment that car crosses the finish line. RaceTimeOffset is one
 *   session-wide global; `investigate.py uses DAT_008acf90` shows 13 readers
 *   and 0 writers anywhere in the corpus, so nothing resets it mid-session.
 *   Decrementing it once, before more cars finish, adds 10.0s to every
 *   not-yet-finished car's eventual RaceTime — a flat penalty on the field,
 *   without touching cars already classified before the trigger.
 *
 *   REVISION NOTE: the original plan (VehicleStruct+0x4044, docs/30-impl-
 *   specs/11 "PenaltyFloat") was refuted by raw source — see
 *   work/CHANGELOG.md [CORRECTION] drafted alongside this mod. +0x4044 is
 *   actually a live blue-flag/proximity gap value recomputed every tick.
 *
 * UNVERIFIED THIS SESSION (game was not running):
 *   - No poke.py/Frida/in-game confirmation that decrementing RaceTimeOffset
 *     is side-effect-free on AI overtake-probability / session-timer code
 *     that also reads it (FUN_004a4110, FUN_00426cf0, FUN_0042b0e0,
 *     FUN_0046bf10, FUN_004c7f30) — static analysis says harmless shared
 *     clock reference only, not poke-proven live.
 *   - Whether ReasonCode==1 ever naturally occurs in your race settings
 *     (needs EngineWearMode DAT_007cea5c == 2 or 3).
 */
#include <windows.h>
#include <stdio.h>
#include "f1c_sdk.h"

static volatile BOOL g_running = TRUE;
static char g_log[MAX_PATH];

static void logf_(const char *fmt, ...) {
    FILE *f = fopen(g_log, "a"); if (!f) return;
    va_list ap; va_start(ap, fmt); vfprintf(f, fmt, ap); va_end(ap);
    fputc('\n', f); fclose(f);
}

#define OFF_REASONCODE   0x4068   /* VehicleStruct.ReasonCode (int)   */
#define OFF_DRIVERNAME   0x4620   /* VehicleStruct.DriverName[64]     */
#define REASON_ENGINE    1        /* confirmed: FUN_0043ef20 / FUN_004ed960 */
#define PENALTY_SECONDS  10.0f
#define MAX_TRACKED      32
#define TEST_HOTKEY      VK_F9    /* manual simulate, for live verification */

static int  g_prevReason[MAX_TRACKED];
static BOOL g_init = FALSE;

static BOOL race_active(void) {
    return g_SessionType == 7 && g_RaceActiveFlag != 0;
}

static void apply_field_penalty(const char *why) {
    float before = g_RaceTimeOffset;
    g_RaceTimeOffset = before - PENALTY_SECONDS;
    float readback = *(volatile float*)0x008ACF90;
    logf_("[engine_blow_field_penalty] %s -> RaceTimeOffset %.3f -> %.3f (readback=%.3f) "
          "SessionType=%d RaceActiveFlag=%d",
          why, before, g_RaceTimeOffset, readback, g_SessionType, g_RaceActiveFlag);
}

static void check_engine_failures(void) {
    int count = g_VehicleCount, i;
    void *player = *(void**)0x007C54E8;  /* PlayerVehiclePtr, dereferenced --
                                             do NOT trust SDK's g_PlayerVehiclePtr
                                             macro as a value, it's the raw addr */
    if (count > MAX_TRACKED) count = MAX_TRACKED;

    for (i = 0; i < count; i++) {
        void *veh = g_VehiclePtrArray[i];
        int reason;
        if (!veh || (SIZE_T)veh < 0x10000) continue;
        if (veh == player) continue;              /* player failures don't count */

        reason = *(int*)((char*)veh + OFF_REASONCODE);
        if (reason == REASON_ENGINE && g_prevReason[i] != REASON_ENGINE) {
            char why[128];
            const char *name = (const char*)((char*)veh + OFF_DRIVERNAME);
            wsprintfA(why, "AI engine failure slot=%d driver=%.32s", i, name);
            apply_field_penalty(why);
        }
        g_prevReason[i] = reason;
    }
}

/* Manual test aid: forces slot 0's ReasonCode to ENGINE so the detector fires
 * without waiting on the RNG. Not part of the "real" mod logic. */
static void simulate_one_failure(void) {
    int count = g_VehicleCount, i;
    void *player = *(void**)0x007C54E8;
    for (i = 0; i < count && i < MAX_TRACKED; i++) {
        void *veh = g_VehiclePtrArray[i];
        if (!veh || veh == player) continue;
        int *reason = (int*)((char*)veh + OFF_REASONCODE);
        if (*reason == 0) {
            logf_("[engine_blow_field_penalty] TEST HOTKEY: forcing slot=%d ReasonCode 0 -> 1", i);
            *reason = REASON_ENGINE;
            return;
        }
    }
    logf_("[engine_blow_field_penalty] TEST HOTKEY: no healthy AI car found to fail");
}

static void tick(void) {
    static BOOL prevKey = FALSE;
    BOOL down;

    if (!g_init) {
        int i; for (i = 0; i < MAX_TRACKED; i++) g_prevReason[i] = 0;
        g_init = TRUE;
    }

    if (race_active()) check_engine_failures();

    down = (GetAsyncKeyState(TEST_HOTKEY) & 0x8000) != 0;
    if (down && !prevKey && race_active()) simulate_one_failure();
    prevKey = down;
}

static DWORD WINAPI thread_main(LPVOID p) {
    (void)p;
    logf_("[engine_blow_field_penalty] loaded");
    while (g_running) { tick(); Sleep(16); }
    return 0;
}

BOOL WINAPI DllMain(HINSTANCE h, DWORD reason, LPVOID r) {
    (void)r;
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(h);
        GetModuleFileNameA(h, g_log, MAX_PATH);
        char *dot = strrchr(g_log, '.'); if (dot) strcpy(dot, "_log.txt");
        CreateThread(NULL, 0, thread_main, NULL, 0, NULL);
    } else if (reason == DLL_PROCESS_DETACH) {
        g_running = FALSE;
    }
    return TRUE;
}
```

**`mods/engine_blow_field_penalty/build.bat`** (mirrors `ai_pit_retire/build.bat` — this is the mutating/compile step I did not run):
```bat
@echo off
REM Build engine_blow_field_penalty.dll + inject.exe (MinGW32 - matches the game)
set MINGW=C:\msys64\mingw32\bin
set CC=%MINGW%\gcc.exe
set PATH=%MINGW%;%PATH%
if not exist %CC% ( echo ERROR: %CC% not found & pause & exit /b 1 )
echo Building engine_blow_field_penalty.dll ...
%CC% -shared -o engine_blow_field_penalty.dll engine_blow_field_penalty.c -I..\sdk -lkernel32 -luser32 -O2 -Wall
if errorlevel 1 ( echo FAILED & pause & exit /b 1 )
if not exist inject.exe (
  if exist ..\red-flag-dll\inject.c ( %CC% -o inject.exe ..\red-flag-dll\inject.c -lkernel32 -O2 )
)
echo Done. Inject with:  inject.exe engine_blow_field_penalty.dll
pause
```

**Two `[CORRECTION]` entries** I would log to `work/CHANGELOG.md` (iron rule 7):
```
## [CORRECTION] 2026-07-20 — VehicleStruct+0x4044 is not "PenaltyFloat"
docs/06-session-race-logic.md and docs/30-impl-specs/11-session-and-race-logic-spec.md
label +0x4044 as PenaltyFloat ("time penalty accumulator, seconds"). Raw source
refutes this: FUN_004d1d80 (@0x004d1d80 L43/46/61-65) recomputes it EVERY TICK
as a live blue-flag/proximity time-gap; FUN_0041b250 (@0x0041b250 L46-48) reads
it for commentary-message selection. Not an accumulator — do not use as a mod
target (found while building mods/engine_blow_field_penalty/).

## [CORRECTION] 2026-07-20 — docs/03 "FUN_004BEC55 EngineFailureCheck" is not
## a standalone function
0x004bec55 falls inside FUN_004beb10 (@0x004beb10, size 1090B = 0x4beb10-
0x4bef52) — a body label, not a separate entry point. Its documented callee
list (FUN_004BEA10, FUN_004BEF60, FUN_004BF390, FUN_004BF4F0) matches calls
made from within FUN_004beb10 verbatim. Found while tracing the RaceTime
write path for mods/engine_blow_field_penalty/.
```

**`mods/_README.md` ledger row I would add:**
```
| `engine_blow_field_penalty/` | AI engine failure -> whole field gets +10s classification-time penalty (decrements global RaceTimeOffset) | **DESIGNED, NOT LIVE-VERIFIED** — no poke/Frida/in-game test yet (game wasn't running); run facts.json first |
```

---

## Where and why I stopped

I stopped after producing the design + drafted artifacts, before any mutating or live step:
- Did not run `build.bat` (compiles — mutates disk, needs MinGW toolchain I didn't invoke).
- Did not run `inject.exe` or `preflight.py run` (both require the live game process; it isn't running).
- Did not write any file (`facts.json`, the `.c`, `build.bat`, README, CHANGELOG, ledger row) — all presented as content per the read-only constraint.

This is also the correct stopping point per the project's own iron rule 4: "verify facts before code... never test 'does the whole mod work' as the first test." Without a live game I cannot poke `DAT_008ACF90`/`ReasonCode`, confirm the write survives, or watch for the side effects flagged in the source comments (AI-overtake/session-timer readers of `RaceTimeOffset`). The design is fully argued from FACT-tier raw decompiled source (cross-confirmed via at least two independent functions for both the trigger and the effect field), but per the project's own rules it remains **unverified** until run against the live process.
