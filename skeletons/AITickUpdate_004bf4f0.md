## AITickUpdate_004bf4f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EngineFailureCheck (004bec55)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x354 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007d2e50 | dword_7D2E50 | W | SessionMsgCount [DERIVED] (also: ` — session message counter) |
| 007d2e54 | unk_7D2E54 | R | Unk_ScoringRingBuffer [DERIVED] |
| 0083ee54 | dword_83EE54 | W | SessionDataOffset (stride 0x1b0) [DERIVED] |
| 0083ee58 | dword_83EE58 | W | ScoringDataPtr [DERIVED] |
| 0083ee5c | dword_83EE5C | W | SeasonScoringQueuePtr [DERIVED] |
| 0083ee60 | dword_83EE60 | W | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 0083ee64 | unk_83EE64 | R | ScoringDataBuffer [DERIVED] |
| 008aae64 | dword_8AAE64 | W | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008aae68 | dword_8AAE68 | W | ScoringListHeadPtr [DERIVED] |
| 008aae6c | dword_8AAE6C | W | ScoringDataQueuePtr [DERIVED] |
| 008acf90 | flt_8ACF90 | R | RaceTimeOffset [DERIVED] |
| 008acfa0 | byte_8ACFA0 | W | HalfDistanceFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bf390 | AIDriverSorting | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
