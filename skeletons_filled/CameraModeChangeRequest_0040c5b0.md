## CameraModeChangeRequest_0040c5b0 — CameraModeChangeSubmit

**Summary:** Requests camera mode change to mode 5 when current player differs from current vehicle occupant. Queued mode (value 2) is gated by queued mode flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MainCameraDirectorUpdate (0040ca30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | requested camera mode change value (-1, 1, or 2) |
| this | 0x14 | RW | — | stores and applies the mode change; written with v2, then passed to GameActionStateMachine(5, 0) |

**Written-by note (persistence):**
- this 0x14: written when mode change is applied; set to the requested mode value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040c600 | jpt_40C5E1 | R | jump table for mode change request switch |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007cfcc8 | dword_7CFCC8 | R | QueuedModeFlag [DERIVED] — blocks mode 2 application when non-zero |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040cde0 | GameActionStateMachine | applies camera mode 5 with arg 0 |

**Guard conditions:** if VehiclePtrArray[CurrentPlayerIndex]+18580 equals VehiclePtrArray[CurrentVehicleIndex]+18580 (player same as vehicle occupant), returns early without mode change. If requested mode is 2 and dword_7CFCC8 (queued mode flag) is non-zero, mode change is blocked.
