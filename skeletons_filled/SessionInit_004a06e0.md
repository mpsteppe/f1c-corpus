## SessionInit_004a06e0 — SessionInit

**Summary:** Initializes session state: resets sound system and buffer, calls sub-init with parameter 4, sets session init flag to 1, stores scoring gate flag, initializes array and init state flag, then conditionally places multiplayer vehicles based on tire wear data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cc9e8 | dword_5CC9E8 | W | SessionInitState [CONFIRMED] (also: ` — multiplayer active flag) |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005eb10c | dword_5EB10C | R | SoundSystemPtr [DERIVED] (also: ` — engine interface pointer) |
| 007c5690 | byte_7C5690 | W | InitStateFlag [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007d0038 | dword_7D0038 | R | ScoringGateFlag [DERIVED] (also: ` — global flag) |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |
| 008ab6e4 | dword_8AB6E4 | W | ScoringGate [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004186a0 | BufferInitWith10fDefaults | Initializes buffer with 10f default values |
| 0042cf10 | MultiplayerVehiclePlacement | Places multiplayer vehicles using phase from tire wear |
| 004b0ef0 | sub_4B0EF0 | Sub-initializer called with parameter 4 |
| 004c11c0 | TireWearGetter | Gets tire wear value from vehicle struct for phase selection |
| 004c2810 | ArrayCheckInit | Initializes array bounds check structure |
| 004c2850 | LinkedListDereference | Dereferences linked list to access vehicle data |

**Guard conditions:** dword_5EB10C sound guard — non-null calls sound interface vtable+12; LinkedListDereference result non-null PASSES (tire wear + vehicle placement), null BLOCKS
