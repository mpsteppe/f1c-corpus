## ConditionalMathDispatch_004f1860 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopOperationTimer (004a6340)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043b930 | SolverDispatch | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
