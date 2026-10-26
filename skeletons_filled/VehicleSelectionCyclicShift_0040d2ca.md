## VehicleSelectionCyclicShift_0040d2ca — Cyclic vehicle selection shift

**Summary:** Shifts current player index forward (a1=1) or backward (a1=0), wraps around vehicle count. Dispatches game state for newly selected vehicle and refreshes all vehicle visual entries via sub_4F0D20.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d240 | GameStateDispatchChain | dispatch game state for newly selected vehicle |
| 004f0d20 | sub_4F0D20 | update/refresh vehicle visual entry |

**Guard conditions:** none — always executes, no early return guard
