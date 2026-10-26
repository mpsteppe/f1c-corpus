## ConstraintProjectGramSchmidt_00438930 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionWheelDynamicsSolver (0043f7f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x15C | R | — | [LLM] |
| this | 0x178 | R | — | [LLM] |
| this | 0x190 | R | — | [LLM] |
| this | 0x1A8 | R | — | [LLM] |
| this | 0x2A8 | RW | — | [LLM] |
| this | 0x2B0 | RW | — | [LLM] |
| this | 0x2B8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x2A8: recalc every frame — external poke does NOT persist
- this 0x2B0: recalc every frame — external poke does NOT persist
- this 0x2B8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
