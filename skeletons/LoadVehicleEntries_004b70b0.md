## LoadVehicleEntries_004b70b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x724 | R | — | [LLM] |
| this | 0xF20 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | W | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 007c5690 | byte_7C5690 | W | InitStateFlag [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007cec90 | dword_7CEC90 | W | VehicleLoadState [DERIVED] |
| 007ced8c | dword_7CED8C | W | UIRacePhaseFlag [DERIVED] |
| 007cee88 | dword_7CEE88 | W | SessionInitFlags [DERIVED] |
| 007d0990 | dword_7D0990 | W | RaceSessionVehicleCount [DERIVED] |
| 007d2e48 | dword_7D2E48 | R | SeasonScoringDB (stride 0x48c0) [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bc80 | BuildActiveVehiclePointerArray | [LLM] |
| 0042cf10 | MultiplayerVehiclePlacement | [LLM] |
| 004b72a0 | LinkedListTraversalWithFilter | [LLM] |
| 004b87a0 | QueuePeek | [LLM] |
| 004c54f0 | AIW | [LLM] |
| 004c5690 | SceneDataParser | [LLM] |
| 004c6980 | SetDriverName | [LLM] |
| 004c7b20 | TwoCallDelegation | [LLM] |
| 004ef5a0 | SessionStateTransition | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
