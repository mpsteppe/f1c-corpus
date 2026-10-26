## VehicleControlEnabled_004a6db0 — Vehicle control enable check

**Summary:** Evaluates whether vehicle controls should be enabled by checking session type, damage/health status fields, car control mode, and force feedback state. Returns false if car is non-operational.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIStateMachineWithModeDispatch (004a5d10), PitStateUpdateMachine (004a6e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x834 | R | — | Health/damage indicator dword — pair 1 (front) |
| obj | 0x874 | R | — | Health/damage indicator byte — pair 1 |
| obj | 0x95C | R | — | Health/damage indicator dword — pair 2 |
| obj | 0x99C | R | — | Health/damage indicator byte — pair 2 |
| obj | 0xA84 | R | — | Health/damage indicator dword — pair 3 |
| obj | 0xAC4 | R | — | Health/damage indicator byte — pair 3 |
| obj | 0xBAC | R | — | Health/damage indicator dword — pair 4 |
| obj | 0xBEC | R | — | Health/damage indicator byte — pair 4 |
| obj | 0x4064 | R | — | Car control status mode (1/3 = disabled, 2 = enabled) |
| this | 0x0 | R | — | Pointer to obj struct |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007ce814 | dword_7CE814 | R | QualifyingDSQEnabled [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d21d0 | sub_4D21D0 | Check force feedback state for control enable |

**Guard conditions:** All conditions must be true for controls to be enabled: SessionType is 0 or 7; AND all 8 health/damage fields are non-zero (or DSQ mode enabled); AND car control mode (0x4064) is not 1 or 3; AND force feedback check passes. If any condition fails, BLOCKED — returns false (controls disabled).
