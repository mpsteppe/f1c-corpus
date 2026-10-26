## ConstraintForceSolver_0043ba20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SolverDispatch (0043b930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15C8) | 0x4 | R | — | [LLM] |
| *(this+0x15C8) | 0x8 | R | — | [LLM] |
| *(this+0x15C8) | 0xC | R | — | [LLM] |
| *(this+0x15C8) | 0x10 | R | — | [LLM] |
| *(this+0x15C8) | 0x18 | RW | — | [LLM] |
| *(this+0x15C8) | 0x20 | R | — | [LLM] |
| *(this+0x15C8) | 0x28 | RW | — | [LLM] |
| *(this+0x15C8) | 0x30 | RW | — | [LLM] |
| *(this+0x15C8) | 0x38 | RW | — | [LLM] |
| *(this+0x15F0) | 0x1C | R | — | [LLM] |
| *(this+0x15F0) | 0x24 | R | — | [LLM] |
| *(this+0x15F0) | 0x2C | R | — | [LLM] |
| *(this+0x15F0) | 0x34 | R | — | [LLM] |
| *(this+0x15F0) | 0x3C | R | — | [LLM] |
| *(this+0x15F0) | 0x44 | R | — | [LLM] |
| *(this+0x15F0) | 0x4C | R | — | [LLM] |
| *(this+0x15F0) | 0x54 | R | — | [LLM] |
| *(this+0x15F0) | 0x5C | R | — | [LLM] |
| this | 0x141C | R | — | [LLM] |
| this | 0x1420 | R | — | [LLM] |
| this | 0x15C4 | R | — | [LLM] |
| this | 0x15C8 | R | — | [LLM] |
| this | 0x15F0 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x15C8) 0x18: recalc every frame — external poke does NOT persist
- *(this+0x15C8) 0x28: recalc every frame — external poke does NOT persist
- *(this+0x15C8) 0x30: recalc every frame — external poke does NOT persist
- *(this+0x15C8) 0x38: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0056d1c0 | RelativeVelocityCompute | [LLM] |
| 0056d2d0 | sub_56D2D0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
