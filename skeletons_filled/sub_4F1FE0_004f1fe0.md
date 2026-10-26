## sub_4F1FE0_004f1fe0 — VehicleYawRecoveryStateMachine

**Summary:** Manages yaw recovery state for a vehicle: accumulates time since last check, monitors postProcessInput state, validates qualifying/disqualifying conditions, computes vehicle position relative to track, and triggers recovery (position reset + audio + AI path tracking) when vehicle is off-track beyond timeout. Vehicle physics/recovery system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleYawRotationRecoveryController (004f1c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3450 | R | — | postProcessInput state field at index 3348 — checked != 3 to allow recovery processing |
| obj | 0x4064 | R | — | postProcessInput main state at byte offset 16484 — 0=active processing, 2=inactive, other=simple accumulation |
| obj | 0x4170 | R | — | postProcessInput float field at offset 16752 — compared against FLT_MAX as guard |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] — base pointer for all obj indirections |
| this | 0x828 | R | — | start of 4-slot vehicle/entity array (index 522, 74 dwords per slot) |
| this | 0x868 | R | — | slot entry byte+64 field — checked for non-zero (within 74-dword slot) |
| this | 0x1048 | R | — | audio sound parameter (index 1042) — passed to AudioSoundEffectController |
| this | 0x1051 | RW | 0 | audio trigger flag byte (offset 4177) — set to 0 when recovery fires and session==7 |
| this | 0x32BC | R | — | qualifying/race type flag (index 3247) — 1 triggers special recovery path; 0 triggers DSQ check |
| this | 0x34D4 | R | — | source vector X (index 3381) — vehicle position component |
| this | 0x34D8 | R | — | source vector Y (index 3382) — vehicle position component |
| this | 0x34DC | R | — | source vector Z (index 3383) — vehicle position component |
| this | 0x3994 | R | — | lateral deviation value (index 3685) — checked with fabs against 0.1 threshold |
| this | 0x3A9C | RW | — | result pointer (index 3751) — set from sub_403640, holds track position data |
| this | 0x3D48 | RW | 0 | recovery counter 1 (index 3922) — zeroed on recovery trigger |
| this | 0x3D4C | RW | 0 | recovery counter 2 (index 3923) — zeroed on recovery trigger |
| this | 0x3D50 | RW | 0 | recovery counter 3 (index 3924) — zeroed on recovery trigger |
| this | 0x3D60 | RW | — | recovery state (index 3928) — set to 2 when recovery conditions met |
| this | 0x3FF8 | RW | — | destination vector X (index 4094) — receives source vector copy |
| this | 0x3FFC | RW | — | destination vector Y (index 4095) — receives source vector copy |
| this | 0x4000 | RW | — | destination vector Z (index 4096) — receives source vector copy |
| this | 0x4004 | RW | 0 | time accumulator float (index 4097) — accumulates delta time, triggers recovery when > threshold |

**Written-by note (persistence):**
- this 0x1051: recalc every frame — external poke does NOT persist
- this 0x3A9C: recalc every frame — external poke does NOT persist
- this 0x3D48: recalc every frame — external poke does NOT persist
- this 0x3D4C: recalc every frame — external poke does NOT persist
- this 0x3D50: recalc every frame — external poke does NOT persist
- this 0x3D60: recalc every frame — external poke does NOT persist
- this 0x3FF8: recalc every frame — external poke does NOT persist
- this 0x3FFC: recalc every frame — external poke does NOT persist
- this 0x4000: recalc every frame — external poke does NOT persist
- this 0x4004: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e864 | flt_59E864 | R | ColorQuantScale [DERIVED] (also: ` — Quantization scale for color channels) |
| 0059e8d8 | flt_59E8D8 | R | BrakingSpeedThreshold3 [DERIVED] |
| 0059eae0 | flt_59EAE0 | R | FLT_MAX_Infinity [DERIVED] (also: ` — infinity/FLT_MAX return value) |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] — passed to sub_403640 for track position lookup |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] — checked for value 7 (race session) to enable audio and AI recovery |
| 007ce258 | dword_7CE258 | W | InitZeroFieldSet [DERIVED] — set to 1 when recovery fires in qualifying mode (3247==0) |
| 007ce814 | dword_7CE814 | R | QualifyingDSQEnabled [DERIVED] — if set in qualifying mode, blocks recovery processing |
| 007d0a8c | flt_7D0A8C | R | PitTimerFloat [DERIVED] — recovery time threshold; accumulator must exceed this to trigger |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403640 | sub_403640 | retrieves track position/spline data for current vehicle position — returns pointer to position struct |
| 0041b250 | sub_41B250 | processes/resets postProcessInput state for recovery |
| 004a5c80 | StateChangeNotify | notifies state change system with index 3248 and value 0 |
| 004bc060 | sub_4BC060 | updates offset at postProcessInput+4109 with value 1 after recovery |
| 004d1140 | RenderCallWithGuard | renders with guard — called during recovery when session==7 |
| 004d21d0 | sub_4D21D0 | gate check — must return true to proceed with recovery processing |
| 004e0ed0 | AudioSoundEffectController | plays audio sound effect when recovery fires and session==7 |
| 004ef7c0 | AIVehiclePathPositionTracking | updates AI vehicle path position tracking after recovery |
| 004effd0 | DistanceComparison | compares vehicle distance — must return false (vehicle is off-track) to allow recovery |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x3450 | != | 3 | postProcessInput state field — must not be 3 to allow recovery processing |
| this | 0x32BC | == | 1 | qualifying/race type flag — 1 enables simplified recovery path (vector copy + time accumulation) |

**Guard interpretation:** 
1. obj+0x4064 (postProcessInput state) == 0: PASSES into full recovery processing chain with multiple sub-checks (slot iteration, DSQ check, distance comparison, gate check).
2. obj+0x4064 != 0 and != 2: BLOCKED from full processing — only simple vector copy/time accumulation path if this+0x32BC == 1.
3. obj+0x4064 == 2: BLOCKED entirely — no action taken.
4. this+0x32BC == 1 AND state != 0/2: PASSES simplified path (copies source→dest vectors if condition flags allow, otherwise accumulates time).
5. obj+0x3450 == 3: BLOCKED — DistanceComparison not even called, recovery skipped.
6. dword_7CE814 (DSQ enabled) set in qualifying mode: BLOCKED — early return.
7. 4-slot check: all 4 slots occupied with byte+64 set AND fabs(this+0x3994) > 0.1: BLOCKED — all slots active, recovery suppressed.
8. sub_4D21D0() returns false: BLOCKED — gate not passed.
9. Time accumulator > flt_7D0A8C (pit timer threshold): PASSES — triggers recovery action (position reset, audio, AI tracking).
