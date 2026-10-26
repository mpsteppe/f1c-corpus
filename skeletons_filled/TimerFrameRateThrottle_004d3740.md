## TimerFrameRateThrottle_004d3740 — Timing event dispatch with flag-based indexing

**Summary:** Dispatches LapSplitTimeEvent and AICommandMessageQueueDispatcher for the vehicle identified by flag property index 2048. Clears buffer entry at this+0x14.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Buffer handle/pointer passed to BufferEntryClear for cleanup |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput — base indexed by flag result for AI command dispatch |
| 005f070c | unk_5F070C | R | VEH[0].0x4034 — base indexed for split time event dispatch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00424cd0 | AICommandMessageQueueDispatcher | Dispatches AI command message to vehicle's queue |
| 004bc390 | LapSplitTimeEvent | Handles lap/split time event for a vehicle |
| 0054c150 | FlagPropertyGetter | Gets property value by flag index (2048) — returns driver/vehicle ID |
| 0054fae0 | BufferEntryClear | Clears/releases buffer entry at this+0x14 |

**Guard conditions:** None — all calls are unconditional.
