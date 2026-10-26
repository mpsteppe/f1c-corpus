## LoadVehicleEntries_004b70b0 — Vehicle Entry Loader

**Summary:** Iterates 104 vehicle slots (18624 byte stride), looking up each via LinkedListTraversalWithFilter. Initializes driver names and state for found entries; sets absence flag for missing ones. Finalizes by building vehicle pointer arrays, parsing scene data, and initializing AI.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x724 | R | — | File path string pointer (for SceneDataParser, falls back to global) |
| this | 0xF20 | R | — | Parameter passed to MultiplayerVehiclePlacement |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | W | VehicleCount [FACT] (also: VehicleCount (set to 0 on join)) |
| 005ea438 | byte_5EA438 | R | Default application directory path (fallback) |
| 005ec6d0 | unk_5EC6D0 | R | unknown |
| 007c5690 | byte_7C5690 | W | InitStateFlag [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] |
| 007cec90 | dword_7CEC90 | W | VehicleLoadState [DERIVED] |
| 007ced8c | dword_7CED8C | W | UIRacePhaseFlag [DERIVED] |
| 007cee88 | dword_7CEE88 | W | SessionInitFlags [DERIVED] |
| 007d0990 | dword_7D0990 | W | RaceSessionVehicleCount [DERIVED] |
| 007d2e48 | dword_7D2E48 | R | SeasonScoringDB (stride 0x48c0) [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bc80 | BuildActiveVehiclePointerArray | Rebuild list of active vehicle pointers |
| 0042cf10 | MultiplayerVehiclePlacement | Initialize multiplayer vehicle grid placement |
| 004b72a0 | LinkedListTraversalWithFilter | Look up each vehicle slot entry |
| 004b87a0 | QueuePeek | Peek at queue for initialization parameters |
| 004c54f0 | AIW | Initialize AI world/path data |
| 004c5690 | SceneDataParser | Parse scene/level data file |
| 004c6980 | SetDriverName | Copy driver name string to entry |
| 004c7b20 | TwoCallDelegation | Delegate two initialization calls on entry |
| 004ef5a0 | SessionStateTransition | Set session state to 3 (active) or -1 (absent) |
| 00566650 | StringCopyWithBufferRealloc | Reallocate and copy string buffer for entry |

**Guard conditions:** No field-level guards on `this`. Loop iterates 104 times (0..1936896 step 18624). If LinkedListTraversalWithFilter returns NULL for a slot, set session state to -1 (absent). Otherwise set state to 3 (active) and initialize driver data.
