## UIComboListRender_00495580 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_496E90 (00496e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x156C)+0x0) | 0x8 | R | — | [LLM] |
| *(this+0x156C) | 0x0 | R | — | [LLM] |
| *(this+0x156C) | 0xC0 | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0xCC | R | — | [LLM] |
| this | 0xD0 | R | — | [LLM] |
| this | 0xD4 | R | — | [LLM] |
| this | 0x156C | R | — | [LLM] |
| this | 0x1570 | RW | 0 | [LLM] |
| this | 0x1588 | R | — | [LLM] |
| this | 0x158C | RW | — | [LLM] |
| this | 0x1590 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1570: [LLM: once/conditional? does external poke survive?]
- this 0x158C: [LLM: once/conditional? does external poke survive?]
- this 0x1590: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac9c0 | flt_5AC9C0 | R | QuaternionSlerpEpsilon [DERIVED] (also: ` — near-unity epsilon for dot product) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490920 | Accessor | [LLM] |
| 004918d0 | RenderSurfaceFillCopy | [LLM] |
| 00497ec0 | DriverNameStringHandler | [LLM] |
| 004983b0 | TextRenderToSurface | [LLM] |
| 00498550 | ShortComputation_8550 | [LLM] |
| 00498560 | sub_498560 | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
