## VirtualFunctionDispatchWithStackFrames_0057a4f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DriverEntrantSetupEntry (00462550)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x68 | R | — | [LLM] |
| *(obj+0x0) | 0xC0 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x5D | RW | 0 | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x5D: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00584ff0 | StringCopyToBufferWithLengthCap | [LLM] |
| 00585030 | AllocationWrapper | [LLM] |
| 00585860 | SingleFieldSetter | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
