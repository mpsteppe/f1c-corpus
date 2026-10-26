## FloatToIntConversion_00489e90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DecrementCounterVirtualCall (00489500), UINavigationAdvanceHandler (00489530), StateUpdateWithDecrement (00489560), sub_4895B0 (004895b0), UIListSelectionHandler (00489ab0), sub_489D00 (00489d00), UIScrollbarThumbDragHandler (0048a650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14C | R | — | [LLM] |
| this | 0x150 | RW | 0 | [LLM] |
| this | 0x154 | R | — | [LLM] |
| this | 0x160 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x150: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
