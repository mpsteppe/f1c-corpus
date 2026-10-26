## AIDriverSorting_004bf390 — AI driver position sorting

**Summary:** Compares an AI driver's race progress against other drivers and swaps position values when the driver should overtake. Handles race session (lap+time comparison) vs other sessions (best-lap comparison).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EngineFailureCheck (004bec55), AIBehaviorInitialization (004bf0a0), AITickUpdate (004bf4f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x4060 | R | — | position [CONFIRMED] |
| this | 0x4098 | R | — | totalTimeOnFinishLine [CONFIRMED] |
| this | 0x409C | R | — | bestLap [CONFIRMED] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bc2f0 | ConditionalFieldSetter | write updated position value to vehicle field (subject to compare condition) |

**Guard conditions:** Early return if VehicleCount < 1. Outer loop iterates position slots (v13 from 1 to VehicleCount). Inner loop finds vehicle at slot v13. If found vehicle equals a1 (self), skip to next slot. If no swap yet (v10==0): for race session (SessionType==7), compares lap count then total time to determine if a1 should pass; for other sessions, compares best lap time. If a1 should pass, performs one swap per call (sets v10=1) by updating both vehicles' position fields via ConditionalFieldSetter. If swap already done (v10==1) and found vehicle differs from swapped vehicle, just increments the found vehicle's position.
