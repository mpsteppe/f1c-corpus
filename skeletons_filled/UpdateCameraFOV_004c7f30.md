## UpdateCameraFOV_004c7f30 — UpdateCameraFOV

**Summary:** Updates camera FOV (this[2]) based on session type, race phase, elapsed race time, and lap progress. Smoothly interpolates current FOV toward computed target using frame-time delta.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C7DE0 (004c7de0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | Current camera FOV being interpolated toward target |

**Written-by note (persistence):**
- this 0x8: overwritten each call via interpolation; does not persist beyond normal update cycle

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004c8144 | jpt_4C7F4B | R | jump table for switch on SessionType (case 3-7 range) |
| 004c8158 | jpt_4C8011 | R | jump table for switch on RacePhase (case 1-8 range) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e4e0 | flt_59E4E0 | R | ForceIncrementClamp [DERIVED] (also: ` — scroll auto-repeat threshold (delta time gate) |
| 0059e4e8 | flt_59E4E8 | R | PhysicsScale_E4E8 [DERIVED] (also: ` — physics/math scaling constant) |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e97c | flt_59E97C | R | LapTimeDeltaScale [DERIVED] |
| 005acd40 | flt_5ACD40 | R | TireGripScaleFactor [DERIVED] |
| 005acd48 | flt_5ACD48 | R | TireGripThreshold [DERIVED] |
| 005acdfc | flt_5ACDFC | R | AudioMixScaler [DERIVED] |
| 005ace00 | flt_5ACE00 | R | RaceSpeedFactor [DERIVED] |
| 005ace04 | flt_5ACE04 | R | AISessionDiffMult [DERIVED] |
| 005ace08 | flt_5ACE08 | R | AIDifficultySessionMul [DERIVED] |
| 005ace0c | flt_5ACE0C | R | SessionDynamicsConst [DERIVED] |
| 005ace10 | flt_5ACE10 | R | RaceFuel_Consumption_Mult [DERIVED] |
| 005f0714 | dword_5F0714 | R | VEH[0].0x403C = lapNumber [CONFIRMED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |
| 008acf90 | flt_8ACF90 | R | RaceTimeOffset [DERIVED] |
| 008acf94 | flt_8ACF94 | R | RaceTimeThreshold [CONFIRMED] |
| 008acfb8 | flt_8ACFB8 | R | TimingsConst2 [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d1b50 | sub_4D1B50 | Returns player vehicle index (called with arg 0); used to index into lapNumber array for FOV calculation |

**Guard conditions:** No early-return guard. Switch on SessionType (dword_7C56A4) handles types 3-7; default/other types fall through to interpolation block with v2=0.25.

