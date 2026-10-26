## ArrayInitWithSentinelInLoop_00460c60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SynchronizeWithServer (00464290)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3E18 | RW | 18446744073709551615 | [LLM] |

**Written-by note (persistence):**
- this 0x3E18: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461480 | StructFieldZeroInitWithDefaults | [LLM] |
| 004fffa0 | ThunkWithStructInitSubCalls | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
