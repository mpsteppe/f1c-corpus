## sub_4DEF70_004def70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RepeatedPositionOffsetTransform (004e3940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x4 | R | — | [LLM] |
| *(this+0x4) | 0x8 | R | — | [LLM] |
| *(this+0x4) | 0xC | R | — | [LLM] |
| *(this+0x4) | 0x42 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dedb0 | SortedArrayInsertWithLRUEviction | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
