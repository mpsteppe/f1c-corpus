## SpringDamperCompute_0043bbd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SolverDispatch (0043b930), sub_43BC20 (0043bc20), ClampedSpringIntegrator (0043e980), PhysicsForceVelocityClamping (0043ec80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1808 | R | — | [LLM] |
| this | 0x1810 | R | — | [LLM] |
| this | 0x1818 | R | — | [LLM] |
| this | 0x1820 | R | — | [LLM] |
| this | 0x1828 | R | — | [LLM] |
| this | 0x1830 | R | — | [LLM] |
| this | 0x1ADC | RW | — | [LLM] |
| this | 0x1B94 | RW | — | [LLM] |
| this | 0x1C18 | RW | — | [LLM] |
| this | 0x1D9C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1ADC: recalc every frame — external poke does NOT persist
- this 0x1B94: recalc every frame — external poke does NOT persist
- this 0x1C18: recalc every frame — external poke does NOT persist
- this 0x1D9C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
