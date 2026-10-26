## CameraLockCheck_0040c720 — CameraLockCheck

**Summary:** Returns whether camera lock is allowed for given mode index. Mode 3 specifically blocked when player differs from vehicle occupant and both byte_7CFE88 and PlayerVehiclePtr+13388 flags are set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** KeyboardInputActionMapper (0040be70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | 18446744073709551615 | camera lock mode; set to -1 when player and vehicle occupant differ and lock is allowed |

**Written-by note (persistence):**
- this 0x14: written to -1 when player and vehicle occupant differ and lock passes; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: PlayerVehiclePtr, +13388 checked for mode 3 gate) |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007cfe88 | byte_7CFE88 | R | unknown (found in 0x0040cde0) [DERIVED] — gating flag for mode 3 block |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if PlayerVehicle occupant ID equals CurrentVehicle occupant ID (same entity): returns 1 (PASS). If they differ: if !byte_7CFE88 && *(PlayerVehiclePtr+13388) && a2==3: returns 0 (BLOCKED); otherwise sets this+0x14=-1 and returns 1 (PASS).
