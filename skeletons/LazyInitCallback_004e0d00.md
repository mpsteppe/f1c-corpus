## LazyInitCallback_004e0d00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MultiSystemStructInitializer (004e0db0), ArrayEntryCleanup (004e0e20), SubsystemStateMachine (004e17c0), ActorMotionPostProcessingUpdate (004ed030)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x964 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e0ed0 | AudioSoundEffectController | [LLM] |
| 0054b4d0 | sub_54B4D0 | [LLM] |
| 0054ba00 | DoublyLinkedListNodeMover | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
