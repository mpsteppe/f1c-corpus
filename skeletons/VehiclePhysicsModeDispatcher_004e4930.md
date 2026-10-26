## VehiclePhysicsModeDispatcher_004e4930 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SceneObjectLoaderStateMachine (0040f1c0), MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | [LLM] |
| this | 0x34AC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x34AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00441650 | VehiclePhysicsIntegrationStep | [LLM] |
| 004a6e50 | PitStateUpdateMachine | [LLM] |
| 004e49b0 | VehicleSetupInitialization | [LLM] |
| 004e4e60 | PhysicsIntegrationStateMachine | [LLM] |
| 004f03e0 | TeamColorLoader | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
