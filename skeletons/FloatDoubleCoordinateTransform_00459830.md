## FloatDoubleCoordinateTransform_00459830 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateDependentUpdateDispatch (0040f130)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0xC0 | RW | — | [LLM] |
| this | 0xC4 | RW | — | [LLM] |
| this | 0xC8 | RW | — | [LLM] |
| this | 0xD0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xC0: [LLM: once/conditional? does external poke survive?]
- this 0xC4: [LLM: once/conditional? does external poke survive?]
- this 0xC8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b4d0 | sub_54B4D0 | [LLM] |
| 0054fae0 | BufferEntryClear | [LLM] |
| 005691d0 | F_3x3RotationTensorMatrixTransform | [LLM] |
| 00569280 | Copy6DwordsToStructCall | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
