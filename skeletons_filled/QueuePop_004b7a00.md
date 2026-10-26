## QueuePop_004b7a00 — Queue Pop Processor

**Summary:** Drains the circular buffer via sub_4B7860 until empty, then extracts first and last data values from the result linked list into accumulators at 0xF30/0xF34. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B7500 (004b7500), LoadingPhase1 (004b87c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x714) | 0x0 | R | — | Head node data pointer (first result value) |
| *(this+0x718) | 0x0 | R | — | Tail node data pointer (last result value) |
| this | 0x714 | R | — | Result list head pointer |
| this | 0x718 | R | — | Result list tail pointer |
| this | 0x71C | RW | — | Result list temp pointer (updated during extraction) |
| this | 0x720 | R | — | Result list entry count (guard against empty) |
| this | 0xF30 | RW | 0 | First result value accumulator (head data) |
| this | 0xF34 | RW | 0 | Last result value accumulator (tail data) |

**Written-by note (persistence):**
- this 0x71C: Updated during head/tail extraction; per-call.
- this 0xF30: Set to head node's first DWORD; per-call.
- this 0xF34: Set to tail node's first DWORD; per-call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b7860 | sub_4B7860 | Process circular buffer entries into result list |
| 00566d70 | FileSizeQueryWithFallback | Query file size or init fallback |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x720 | <= | 0 | Result list entry count |

**Guard interpretation:** After draining circular buffer, if result list count (this+0x720) is <= 0, zero accumulators and return 0 immediately — no data available.
