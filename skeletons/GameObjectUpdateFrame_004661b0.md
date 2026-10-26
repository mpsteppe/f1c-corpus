## GameObjectUpdateFrame_004661b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | [LLM] |
| obj | 0xA8 | R | — | [LLM] |
| obj | 0xAC | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0xE8 | R | — | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0xF5 | R | — | [LLM] |
| this | 0x124 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x124: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466350 | sub_466350 | [LLM] |
| 00466650 | sub_466650 | [LLM] |
| 00496750 | DoublyLinkedListAppend_6750 | [LLM] |
| 00498730 | FloatFieldAccessor | [LLM] |
| 004988a0 | FieldSetterCall | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
