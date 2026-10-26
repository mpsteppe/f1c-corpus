## SceneObjectLoaderStateMachine_0040f1c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** LoopWithConditionalSkipFunction (00410980)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x20)+0x0) | 0x48BC | R | — | [LLM] |
| *(this+0x20) | 0x0 | R | — | [LLM] |
| *(this+0x20) | 0x34D4 | R | — | [LLM] |
| *(this+0x20) | 0x34D8 | R | — | [LLM] |
| *(this+0x20) | 0x34DC | R | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040f2d8 | jpt_40F1D0 | R | [LLM] |
| 008ab710 | dword_8AB710 | R | UIWidgetList [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040f600 | CameraShakeRingBufferWrite | [LLM] |
| 0045a8e0 | sub_45A8E0 | [LLM] |
| 004bde20 | sub_4BDE20 | [LLM] |
| 004e4930 | VehiclePhysicsModeDispatcher | [LLM] |
| 004e9600 | SuspensionStateUpdate | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
