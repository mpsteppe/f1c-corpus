## AnimationFrameTimer_00469dd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA0 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x174 | RW | — | [LLM] |
| this | 0x178 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x174: [LLM: once/conditional? does external poke survive?]
- this 0x178: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 007d2dcc | dword_7D2DCC | R | AnimationFrameWrapLimit [DERIVED] (also: ` — animation frame count wrap limit) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00498730 | FloatFieldAccessor | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
