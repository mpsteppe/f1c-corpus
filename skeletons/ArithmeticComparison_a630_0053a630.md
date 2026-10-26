## ArithmeticComparison_a630_0053a630 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_537110 (00537110)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005da998 | dword_5DA998 | R | GetterReturnConstant [DERIVED] |
| 005da99c | dword_5DA99C | R | StringTablePtr [DERIVED] |
| 005da9a0 | unk_5DA9A0 | R | D3D_Shader_StateFuncs [DERIVED] |
| 005db9a0 | unk_5DB9A0 | R | RenderLightingTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
