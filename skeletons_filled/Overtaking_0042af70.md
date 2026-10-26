## Overtaking_0042af70 — AIOvertakeDecision

**Summary:** Evaluates and executes AI overtaking maneuver. Compares speed, lap position, and pit state between two vehicles across different session types. Records overtake target and sets lateral speed offset (3.0 or -3.0) when conditions permit.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteering (004270a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x48A8 | R | — | postProcessOvertakeState |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x3984 | R | — | fuelRateFactor |
| this | 0x3D6C | R | — | carConditions [CONFIRMED] |
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x409C | R | — | bestLap [CONFIRMED] |
| this | 0x4420 | RW | — | overtakeSpeedOffset |
| this | 0x450C | RW | — | maxSharedSpeed |
| this | 0x45F8 | R | — | currentOvertakeTarget |
| this | 0x45FC | RW | — | newOvertakeTarget |

**Written-by note (persistence):**
- this 0x4420: recalc every frame — external poke does NOT persist
- this 0x450C: recalc every frame — external poke does NOT persist
- this 0x45FC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e600 | flt_59E600 | R | SteeringForceThreshold [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ae60 | ServerSessionGateCheck | Gate check for session type 5 |
| 004f1c20 | ReplayAIStateCheck | Returns non-zero if in replay mode (blocks overtaking) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3D6C | != | 2 | carConditions [CONFIRMED] |

**Guard interpretation:** ReplayAIStateCheck at entry blocks (returns 0) immediately if replay active. Main overtake execution (target recording and speed offset setting) requires that `v4` (overtake decision) is non-zero AND carConditions != 2 AND fuelRateFactor > 0.001. The overtake decision itself depends on session type: for type 5 both vehicles must pass ServerSessionGateCheck; for type 7 overtake occurs when local vehicle has pit advantage or speed advantage with higher lap count.
