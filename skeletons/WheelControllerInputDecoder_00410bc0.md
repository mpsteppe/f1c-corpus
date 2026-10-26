## WheelControllerInputDecoder_00410bc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x34 | R | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x48 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x58 | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00410f44 | jpt_410D15 | R | [LLM] |
| 0059e774 | flt_59E774 | R | ShortToFloatScale [DERIVED] (also: ` — position scale factor) |
| 0059e778 | flt_59E778 | R | AngleToRadians [DERIVED] (also: ` — spread scale factor 2) |
| 0059e77c | flt_59E77C | R | ShortVertexScale [DERIVED] (also: ` — short-to-float scale/conversion factor) |
| 0059e780 | flt_59E780 | R | VertexScaleFactor [DERIVED] |
| 005ec6e4 | unk_5EC6E4 | R | VEH[0].0xC [LLM: field purpose] |
| 005ecf0c | dword_5ECF0C | R | VEH[0].0x834 [LLM: field purpose] |
| 005ed3ac | dword_5ED3AC | R | VEH[0].0xCD4 [LLM: field purpose] |
| 005ed3f0 | dword_5ED3F0 | R | VEH[0].0xD18 [LLM: field purpose] |
| 005ed434 | dword_5ED434 | R | VEH[0].0xD5C [LLM: field purpose] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e770 | ShortComputation_e770 | [LLM] |
| 0040ef70 | PhysicsStateVectorConversion | [LLM] |
| 004ed250 | RepairServiceStateDispatcher | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
