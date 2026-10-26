## FormatStringWithArgs_005116d4 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x70) | 0x0 | R | — | [LLM] |
| obj | 0x14 | R | — | [LLM] |
| obj | 0x18 | RW | — | [LLM] |
| obj | 0x1C | R | — | [LLM] |
| obj | 0x20 | R | — | [LLM] |
| obj | 0x24 | R | — | [LLM] |
| obj | 0x28 | R | — | [LLM] |
| obj | 0x2C | R | — | [LLM] |
| obj | 0x30 | R | — | [LLM] |
| obj | 0x34 | R | — | [LLM] |
| obj | 0x70 | R | — | [LLM] |
| obj | 0x74 | R | — | [LLM] |
| obj | 0x78 | R | — | [LLM] |
| obj | 0x7C | R | — | [LLM] |
| obj | 0x80 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x18: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(obj+0x70) | 0x0 | != | 115 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
