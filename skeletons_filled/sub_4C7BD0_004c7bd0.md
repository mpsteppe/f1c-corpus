## sub_4C7BD0_004c7bd0 — IsPlayerVehicle

**Summary:** Returns true if this vehicle's grid slot index (offset 0x4894) matches the current player vehicle's starting grid position. Used as an "is this the player's car" check.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIVehicleDamageEvent (0041a170), OpponentProximityScanTeamRecognition (0042a7d0), SuspensionForceComputationWithPerCornerVirtualDi (004f8440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4894 | R | — | grid slot / starting position index |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — pure comparison, always returns true/false.
