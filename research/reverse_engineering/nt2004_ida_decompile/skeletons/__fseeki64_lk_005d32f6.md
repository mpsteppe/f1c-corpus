## __fseeki64_lk_005d32f6 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __fseeki64 (005d32c7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x18 | RW | 512 | [LLM] |

**Written-by note (persistence):**
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c130a | BufferFlushWrite [structural] | [LLM] |
| 005c1a3c | __errno | [LLM] |
| 005c4244 | __ftelli64_lk | [LLM] |
| 005cd59e | __lseeki64 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
