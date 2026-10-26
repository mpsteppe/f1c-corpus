## ShadowVolumeExtrusion_00448730 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionTreeTraversal (00448da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1C)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x1C)+0x0) | 0x8 | R | — | [LLM] |
| *(*(this+0x1C)+0x0) | 0xC | R | — | [LLM] |
| *(this+0x1C) | 0x0 | R | — | [LLM] |
| *(this+0x1C) | 0x4 | R | — | [LLM] |
| *(this+0x1C) | 0x8 | R | — | [LLM] |
| *(this+0x1C) | 0xC | R | — | [LLM] |
| *(this+0x1C) | 0x10 | R | — | [LLM] |
| *(this+0x1C) | 0x14 | R | — | [LLM] |
| *(this+0x1C) | 0x18 | R | — | [LLM] |
| *(this+0x1C) | 0x19 | R | — | [LLM] |
| *(this+0x1C) | 0x1A | R | — | [LLM] |
| *(this+0x1C) | 0x1C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x10: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00448d80 | jpt_44890C | R | [LLM] |
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e830 | dbl_59E830 | R | TempWarningThreshold [DERIVED] (also: ` — dot product comparison threshold) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ec60 | dbl_59EC60 | R | SuspensionTravelOffset [DERIVED] |
| 0059ef18 | dbl_59EF18 | R | TransformMathConstant [DERIVED] |
| 0059ef20 | dbl_59EF20 | R | VertexTransformConst [DERIVED] |
| 0059ef28 | dbl_59EF28 | R | VehicleDynamicsDoubleConst [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
