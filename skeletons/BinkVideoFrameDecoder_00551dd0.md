## BinkVideoFrameDecoder_00551dd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** IndexedArrayLookupWithBoundsCheck (005504d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00551e94 | jpt_551E11 | R | [LLM] |
| 0059e340 | _BinkWait@4 | R | [LLM] |
| 0059e344 | _BinkDoFrame@4 | R | [LLM] |
| 0059e348 | _BinkNextFrame@4 | R | [LLM] |
| 0059e34c | _BinkCopyToBuffer@28 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00543210 | ThunkWithArgReorder | [LLM] |
| 00543230 | ArgumentReorderWrapper_3230 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
