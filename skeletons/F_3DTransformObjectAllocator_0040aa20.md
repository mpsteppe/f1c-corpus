## F_3DTransformObjectAllocator_0040aa20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40C140 (0040c140)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x1C | R | — | [LLM] |
| this | 0x10 | RW | 1135869952 → 360.0f | [LLM] |
| this | 0x14 | RW | 1135869952 → 360.0f | [LLM] |
| this | 0x18 | RW | 1135869952 → 360.0f | [LLM] |
| this | 0x1C | RW | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0xA8 | RW | 1135869952 → 360.0f | [LLM] |
| this | 0xAC | RW | 1135869952 → 360.0f | [LLM] |
| this | 0xB0 | RW | 1135869952 → 360.0f | [LLM] |

**Written-by note (persistence):**
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0xA8: [LLM: once/conditional? does external poke survive?]
- this 0xAC: [LLM: once/conditional? does external poke survive?]
- this 0xB0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00456170 | F_3DSoundEmitter | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
