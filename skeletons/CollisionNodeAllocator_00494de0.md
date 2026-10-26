## CollisionNodeAllocator_00494de0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StringNormalizeLookup (00495810)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cddf0 | dword_7CDDF0 | RW | CollisionStateCounters [DERIVED] (also: ` through `_DAT_007cddfc` — collision state counters/flags (all zeroed) |
| 007cddf4 | dword_7CDDF4 | RW | CollisionListTailPointer [DERIVED] |
| 007cddf8 | dword_7CDDF8 | W | CollisionListTail [DERIVED] (also: ` — collision list iterator) |
| 007cddfc | dword_7CDDFC | W | CollisionContactCounter [DERIVED] (also: ` — collision state counters/flags (all zeroed) |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053cfe0 | sub_53CFE0 | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
