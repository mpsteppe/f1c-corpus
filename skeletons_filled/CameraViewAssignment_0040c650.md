## CameraViewAssignment_0040c650 — CameraViewAssignment

**Summary:** Assigns camera view mode based on comparison between target entity (a2) and current vehicle occupant. Modes 1-2 dispatch through gateway; mode 3 has special handling requiring a player vehicle flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameStateDispatchChain (0040d240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | requested camera view mode (1, 2, or 3) |
| this | 0x14 | RW | 3 | current applied mode; set to -1 to deactivate, or to 3 for mode 3 |
| this | 0x48A0 | R | — | unknown (not explicitly accessed by this function) |

**Written-by note (persistence):**
- this 0x14: written to -1 to clear current mode, or to 3 when mode 3 activated

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: PlayerVehiclePtr, +13388 checked for mode 3 gate) |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c610 | ConditionalModeDispatchWithGlobalGate | dispatches modes 1-2 based on queued mode flag |
| 0040cde0 | GameActionStateMachine | transitions camera action state with mode and immediate flag |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | <= | 2 | requested mode is 1 or 2 |
| this | 0xC | == | 3 | requested mode is 3 |

**Guard interpretation:** If a2 matches VehiclePtrArray[CurrentVehicleIndex]+18580 (same occupant), applies current this+0x14 mode via GameActionStateMachine then clears it to -1 (PASS). If no match and this+0xC <= 2, dispatches through ConditionalModeDispatchWithGlobalGate (PASS). Otherwise sets this+0x14 = -1 (BLOCKED). Mode 3 additionally requires byte at PlayerVehiclePtr+13388 to be non-zero to apply; routes to different GameActionStateMachine modes based on a2 vs occupant match.
