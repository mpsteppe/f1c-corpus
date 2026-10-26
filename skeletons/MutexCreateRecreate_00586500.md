## MutexCreateRecreate_00586500 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BA10 (0057ba10), sub_5837F0 (005837f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | [LLM] |
| this | 0xC | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a8 | CloseHandle | R | [LLM] |
| 0059e1ac | CreateMutexA | R | [LLM] |
| ff00000000005450 | byte_FF00000000005450 | W | [LLM] |
| ff00000000005451 | byte_FF00000000005451 | W | [LLM] |
| ff00000000005452 | byte_FF00000000005452 | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
