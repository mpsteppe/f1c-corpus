## ConstraintEnforce_004380b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_442C90 (00442c90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1E8 | RW | — | [LLM] |
| this | 0x1F0 | RW | — | [LLM] |
| this | 0x1F8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x1E8: recalc every frame — external poke does NOT persist
- this 0x1F0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00436610 | PiecewiseFunctionEval | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
