## VertexClusteringLODGrouping_004e2d00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleGraphicsSceneLoader (004dfce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x150 | R | — | [LLM] |
| this | 0x1F4 | RW | 0 | [LLM] |
| this | 0x1F8 | RW | — | [LLM] |
| this | 0x890 | R | — | [LLM] |
| this | 0x8E4 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x1F4: [LLM: once/conditional? does external poke survive?]
- this 0x1F8: [LLM: once/conditional? does external poke survive?]
- this 0x8E4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ad15c | flt_5AD15C | R | WheelOffsetThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054c210 | SceneGraphChildCount | [LLM] |
| 0054c230 | LinkedListIndexedAccessor_c230 | [LLM] |
| 0054e100 | PackedArrayTotalSize | [LLM] |
| 0054e120 | PackedArrayIndexLookup | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
