## QuadFunctionEval_0043bb30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SolverDispatch (0043b930), sub_43BC20 (0043bc20), SuspensionDamperForceAccumulation (0043e890), PhysicsForceVelocityClamping (0043ec80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x17A8 | R | — | [LLM] |
| this | 0x17B0 | R | — | [LLM] |
| this | 0x17B8 | R | — | [LLM] |
| this | 0x17C0 | R | — | [LLM] |
| this | 0x17C8 | R | — | [LLM] |
| this | 0x17D0 | R | — | [LLM] |
| this | 0x1930 | RW | — | [LLM] |
| this | 0x19E8 | RW | — | [LLM] |
| this | 0x1C00 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1930: recalc every frame — external poke does NOT persist
- this 0x19E8: recalc every frame — external poke does NOT persist
- this 0x1C00: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
