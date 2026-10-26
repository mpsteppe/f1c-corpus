## SeasonScoringReset_0042bd60 — ResetSeasonScoring

**Summary:** Resets season scoring state: clears InitStateFlag, calls TeamIDSetter and SessionStateTransition for each vehicle up to CurrentVehicleIndex.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DynMan_Post (0042c9f0), sub_4A0490 (004a0490)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec6e4 | unk_5EC6E4 | R | VEH[0].0xC — start address for vehicle iteration loop |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c5690 | byte_7C5690 | W | InitStateFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c6960 | TeamIDSetter | Set team ID for vehicle at given index |
| 004ef5a0 | SessionStateTransition | Transition session state to initial/idle state with parameter -1 |

**Guard conditions:** No guard conditions — unconditional reset of all vehicles up to CurrentVehicleIndex.
