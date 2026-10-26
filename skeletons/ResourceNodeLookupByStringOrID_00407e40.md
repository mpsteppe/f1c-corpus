## ResourceNodeLookupByStringOrID_00407e40 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_5050 (00405050), MemoryAllocation_5160 (00405160)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x38) | 0x4 | R | — | [LLM] |
| *(this+0x40) | 0x10 | R | — | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x44 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x40: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
