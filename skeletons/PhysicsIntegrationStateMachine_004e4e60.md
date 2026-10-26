## PhysicsIntegrationStateMachine_004e4e60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsModeDispatcher (004e4930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3498 | R | — | [LLM] |
| this | 0x349C | R | — | [LLM] |
| this | 0x34A0 | R | — | pitTime[0] [CONFIRMED] |
| this | 0x34A4 | R | — | [LLM] |
| this | 0x34A8 | RW | — | [LLM] |
| this | 0x34AC | RW | — | [LLM] |
| this | 0x3508 | R | — | [LLM] |
| this | 0x35F0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x34A8: recalc every frame — external poke does NOT persist
- this 0x34AC: recalc every frame — external poke does NOT persist
- this 0x35F0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e4f40 | SuspensionSpringDampingRateReset | [LLM] |
| 004e51a0 | sub_4E51A0 | [LLM] |
| 004e5470 | WheelForceCalculationSpringDamperTorque | [LLM] |
| 004e58d0 | sub_4E58D0 | [LLM] |
| 004e5ae0 | sub_4E5AE0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
