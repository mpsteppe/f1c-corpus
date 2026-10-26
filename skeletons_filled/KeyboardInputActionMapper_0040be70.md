## KeyboardInputActionMapper_0040be70 — KeyboardInputToCameraActionMapper

**Summary:** Iterates array of input action codes (word_7CB21C) and maps each to a camera action: target race leader, track current vehicle, or switch camera mode. Gated by CameraLockCheck and GameActionStateMachine per action.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MainCameraDirectorUpdate (0040ca30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x18) | 0x40 | R | — | field at offset 0x40 of sub-structure at this+0x18, used in case 210 validity check |
| this | 0x8 | R | — | pointer to current tracked vehicle/entity |
| this | 0x18 | R | — | pointer to sub-structure (vehicle/entity), compared with this+0x8 for validity |
| this | 0x24 | R | — | byte flag; if non-zero, entire keyboard processing loop is skipped |
| this | 0x2C | RW | 0 | byte flag; set to 1 if any action processed, zeroed on exit, returns 1 |

**Written-by note (persistence):**
- this 0x2C: set during processing if any action triggered; zeroed at function exit if non-zero

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040bfc4 | jpt_40BEB0 | R | jump table for switch on input action codes |
| 0040bfe4 | byte_40BFE4 | R | unknown (referenced near jump table) |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007cb218 | dword_7CB218 | R | InputDeviceCount [DERIVED] — count of entries in input action map array |
| 007cb21c | word_7CB21C | R | InputActionMap [DERIVED] — array of 16-bit input action codes |
| 007cfe88 | byte_7CFE88 | R | unknown (found in 0x0040cde0) [DERIVED] — checked as gate in case 201 path |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c720 | CameraLockCheck | checks if camera mode/lock is available for given action index |
| 0040cde0 | GameActionStateMachine | transitions game action state for given mode, returns success |
| 0040d290 | CameraTargetRaceLeader | sets camera target to race leader (arg 1) or clears it (arg 0) |
| 0040d340 | CameraTargetCurrentTrackedVehicle | updates camera target to currently tracked vehicle |

**Guard conditions:** if this+0x24 (byte at offset 36) is non-zero, entire input processing loop is skipped; function returns 0 unless this+0x2C (byte at offset 44) was set. Each action case additionally gated by CameraLockCheck + GameActionStateMachine return values.
