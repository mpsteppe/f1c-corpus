## AIDriverCountSetup_004bfd90 — AI driver count and team setup

**Summary:** Configures AI opponent count and assigns team/nationality data per driver based on game mode (championship vs other). Handles single-player override, random AI count generation, and per-driver team assignment.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DynMan_Init (0042c1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | RW | VehicleCount — number of active vehicles |
| 005ea438 | byte_5EA438 | R | default application directory path |
| 005ec6d0 | unk_5EC6D0 | R | start of vehicle data array |
| 005ec6d8 | unk_5EC6D8 | R | first vehicle entry (offset 0x8 from array base) |
| 005ec6e4 | unk_5EC6E4 | R | vehicle entry field at offset 0xC from VEH[0] |
| 007ce64c | dword_7CE64C | R | game filter data path string pointer |
| 007d00c8 | dword_7D00C8 | R | flag controlling single-vehicle override in championship |
| 007d0410 | dword_7D0410 | R | championship mode flag (1 = championship) |
| 008aae70 | dword_8AAE70 | R | ring buffer counter used as random seed |
| 008ac388 | unk_8AC388 | R | vehicle file path buffer |
| 008ac38c | dword_8AC38C | R | current font handle / nationality lookup parameter |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bc10 | ScoringGateCheck | check if scoring gate is active (affects driver count) |
| 0042bc80 | BuildActiveVehiclePointerArray | rebuild active vehicle pointer array from vehicle data |
| 004b3c60 | DeterministicHashPseudoRandomGenerator | generate deterministic random AI count |
| 004bf630 | ZeroInit4Ints | zero-initialize local list structure |
| 004bf640 | LinkedListDestruction_f640 | destroy temporary linked list |
| 004bf790 | AIOpponentSelection | build sorted opponent candidate list |
| 004bfd40 | IndexedListLookup | look up opponent data by list index |
| 004c3f80 | VehicleLookupByName | look up vehicle by name from path |
| 004c6960 | TeamIDSetter | assign team ID to driver slot |
| 004c78f0 | NationalityDriverInfoLoader | load nationality info for driver |
| 004ef5a0 | SessionStateTransition | transition session state for driver setup |
| 00587dd0 | sub_587DD0 | build path string from data directory |

**Guard conditions:** Returns 0 if VehicleCount (dword_5C329C) <= 0. Championship mode (dword_7D0410 == 1): if dword_7D00C8 is set, forces VehicleCount = 1 and skips AI selection loop. AIOpponentSelection must return exactly v4 (the target count), otherwise driver setup loop is skipped entirely.
