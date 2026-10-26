## QuadraticForceTorqueCalculator_0043bb80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SolverDispatch (0043b930), sub_43BC20 (0043bc20), PhysicsAccumulatorIntegrate (0043eae0), PhysicsForceVelocityClamping (0043ec80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x17D8 | R | — | [LLM] |
| this | 0x17E0 | R | — | [LLM] |
| this | 0x17E8 | R | — | [LLM] |
| this | 0x17F0 | R | — | [LLM] |
| this | 0x17F8 | R | — | [LLM] |
| this | 0x1800 | R | — | [LLM] |
| this | 0x1A0C | RW | — | [LLM] |
| this | 0x1ABC | RW | — | [LLM] |
| this | 0x1C38 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1A0C: recalc every frame — external poke does NOT persist
- this 0x1ABC: recalc every frame — external poke does NOT persist
- this 0x1C38: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
