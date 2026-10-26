## AIPushLap_0042a180 — AI Push-Lap Tire & Pit Strategy

**Summary:** Per-frame AI strategy for qualifying hot laps: adjusts target lap time based on remaining laps, selects optimal tire compound from track conditions, and forces a pit exit when tire wear or weather demands a change. Part of the AI race-strategy system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | vehicle-on-track flag (inPit status) |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x363C | R | — | tirePuncture_RR [CONFIRMED] |
| this | 0x3734 | R | — | tirePuncture_RL [CONFIRMED] |
| this | 0x382C | R | — | tirePuncture_FR [CONFIRMED] |
| this | 0x3924 | R | — | tirePuncture_FL [CONFIRMED] |
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x44C8 | R | — | target lap-time modifier (push lap delta) |
| this | 0x44D8 | R | — | remaining laps in session |
| this | 0x44F4 | R | — | current track grip multiplier |
| this | 0x453C | RW | — | recalculated lap target time (seconds) |
| this | 0x454C | R | — | callToBox [CONFIRMED] |
| this | 0x4580 | RW | — | tire compound recommendation result |
| this | 0x458C | R | — | nextChosenTires [CONFIRMED] |
| this | 0x45E0 | R | — | current tire compound ID (equipped) |

**Written-by note (persistence):**
- this 0x453C: recalc every frame — external poke does NOT persist
- this 0x4580: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e4e8 | flt_59E4E8 | R | PhysicsScale_E4E8 [DERIVED] (also: ` — physics/math scaling constant) |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e824 | flt_59E824 | R | AIDynamicsThreshold [DERIVED] |
| 0059e970 | flt_59E970 | R | TrackLayoutConstant [DERIVED] |
| 0059e974 | flt_59E974 | R | AI_TrackPosThreshold [DERIVED] |
| 0059e978 | flt_59E978 | R | Flt_AiGearShiftThreshold_9E978 [DERIVED] |
| 0059e97c | flt_59E97C | R | LapTimeDeltaScale [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 008afee8 | flt_8AFEE8 | R | TrackGripBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042a110 | ForcePitExit | force AI to enter pit lane (tire change or weather) |
| 004a4830 | TireCompoundNameIDMapping | map tire name string to compound ID number |
| 004f1630 | TireNameAccessor | retrieve tire name for current compound slot |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x32C8 | == | 1 | vehicle is on track (not in garage/pit) — only execute push-lap logic when racing |

**Guard interpretation:** The entire function body only executes when the vehicle is on track (0x32C8 == 1). If in pit/garage, the function returns immediately with no action. All push-lap adjustments, tire checks, and pit-exit decisions are BLOCKED for off-track AI cars.