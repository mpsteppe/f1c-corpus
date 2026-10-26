## UIFullRenderPass_0048b030 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xF0) | 0x4 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0xEC | RW | 0 | [LLM] |
| this | 0xF0 | RW | 0 | [LLM] |
| this | 0xF4 | RW | 0 | [LLM] |
| this | 0xF8 | RW | 0 | [LLM] |
| this | 0x108 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xEC: [LLM: once/conditional? does external poke survive?]
- this 0xF0: [LLM: once/conditional? does external poke survive?]
- this 0xF4: [LLM: once/conditional? does external poke survive?]
- this 0xF8: [LLM: once/conditional? does external poke survive?]
- this 0x108: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f70 | ConditionalFreeWithBit0Flag | [LLM] |
| 00487060 | sub_487060 | [LLM] |
| 004870e0 | sub_4870E0 | [LLM] |
| 004983b0 | TextRenderToSurface | [LLM] |
| 00498560 | sub_498560 | [LLM] |
| 005665b0 | sub_5665B0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
