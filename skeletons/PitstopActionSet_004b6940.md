## PitstopActionSet_004b6940 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitStallProximityCheck (004b5da0), PitTimingUpdate (004b7a90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9B0 | R | — | [LLM] |
| this | 0x9B8 | RW | 0 | [LLM] |
| this | 0x9BC | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x9B8: [LLM: once/conditional? does external poke survive?]
- this 0x9BC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b4e10 | PhysicsObjectListManager | [LLM] |
| 004b69a0 | CircularCounterIncrement | [LLM] |
| 004b69f0 | CoordinateBoundCheck | [LLM] |
| 004b7860 | sub_4B7860 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
