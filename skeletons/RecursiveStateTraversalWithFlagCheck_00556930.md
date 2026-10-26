## RecursiveStateTraversalWithFlagCheck_00556930 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneRenderTransform (00548c20), sub_556E70 (00556e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x38 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8e34 | dword_8B8E34 | R | RenderVisibilityMask [DERIVED] (also: ` — renderer state/flag mask (not in docs/12; likely renderer visibility or active-state mask) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00556930 | RecursiveStateTraversalWithFlagCheck | [LLM] |
| 00556980 | AnimationDispatchWithSkipFlag | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
