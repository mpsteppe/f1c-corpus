## CollisionDamageDecayProcessor_0045b840 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x31C | R | — | [LLM] |
| this | 0x320 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x320: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059f078 | flt_59F078 | R | PenaltyScaleFactor [DERIVED] |
| 005d6d64 | dword_5D6D64 | R | ScreenWidth [DERIVED] (also: input device parameters) |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045b430 | PerIndexStructFieldResetter | [LLM] |
| 0045b660 | UICursorSelectionRectangleRenderWithInterpolatio | [LLM] |
| 0045bb00 | FloatArrayThresholdSearch | [LLM] |
| 004dcf30 | TwinFieldGetter_cf30 | [LLM] |
| 004dd030 | TextRenderDispatcher | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
