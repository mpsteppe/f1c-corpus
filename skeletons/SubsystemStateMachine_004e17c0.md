## SubsystemStateMachine_004e17c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsTimeStep (004c73f0), UIElementIterateUpdate (004e19a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x628 | R | — | [LLM] |
| this | 0x668 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004e18a0 | jpt_4E17D6 | R | [LLM] |
| 004e18b0 | byte_4E18B0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e0d00 | LazyInitCallback | [LLM] |
| 004e0d70 | ConditionalResourceRelease | [LLM] |
| 004e0e20 | ArrayEntryCleanup | [LLM] |
| 004e0e70 | SubslotCleanup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
