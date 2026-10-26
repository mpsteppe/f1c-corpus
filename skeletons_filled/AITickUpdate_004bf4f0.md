## AITickUpdate_004bf4f0 — AI tick update per vehicle

**Summary:** Per-frame AI timing update: advances lap counters and race times for vehicles whose elapsed segment time exceeds zero. Resets scoring ring-buffer globals at end of tick.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EngineFailureCheck (004bec55)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x354 | R | — | accumulated time offset base for computing vehicle race time |

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
| 004bf390 | AIDriverSorting | re-sort driver positions after lap/time update |

**Guard conditions:** Iterates all vehicles (up to VehicleCount). Skips vehicle if AI state == 3 or AI state == 2. Within pass: checks if per-vehicle AI segment timing value > 0.0 — if not positive, skips the lap-advance and time-update sub-block for that vehicle. After main block (regardless of segment timing), if AI state == 0, forces AI state to 1 (active racing).
