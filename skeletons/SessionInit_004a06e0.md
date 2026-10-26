## SessionInit_004a06e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

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
| 004186a0 | BufferInitWith10fDefaults | [LLM] |
| 0042cf10 | MultiplayerVehiclePlacement | [LLM] |
| 004b0ef0 | sub_4B0EF0 | [LLM] |
| 004c11c0 | TireWearGetter | [LLM] |
| 004c2810 | ArrayCheckInit | [LLM] |
| 004c2850 | LinkedListDereference | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
