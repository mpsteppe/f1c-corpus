## DeltaUpdateTracking_0043bb00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsInitializer (00439210), SolverDispatch (0043b930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xD4C | RW | — | [LLM] |
| this | 0x1428 | RW | — | [LLM] |
| this | 0x1430 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xD4C: recalc every frame — external poke does NOT persist
- this 0x1428: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
