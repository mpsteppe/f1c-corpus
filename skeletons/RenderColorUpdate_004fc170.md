## RenderColorUpdate_004fc170 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCEE0 (004fcee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x48 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x7C | R | — | [LLM] |
| this | 0x80 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x40: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059fec8 | flt_59FEC8 | R | AlphaChannelMultiplier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054c230 | LinkedListIndexedAccessor_c230 | [LLM] |
| 0054e100 | PackedArrayTotalSize | [LLM] |
| 0054e120 | PackedArrayIndexLookup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
