## QuadraticSpringEval_00436470 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SolverDispatch (0043b930), sub_43BC20 (0043bc20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x34: recalc every frame — external poke does NOT persist
- this 0x3C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
