## RepairServiceStateDispatcher_004ed250 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelControllerInputDecoder (00410bc0), CollisionSparkParticleEffects (004ec1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4068 | RW | 6 | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x32BC | R | — | [LLM] |
| this | 0x3A70 | RW | — | [LLM] |
| this | 0x3A80 | R | — | [LLM] |
| this | 0x3D60 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- obj 0x4068: recalc every frame — external poke does NOT persist
- this 0x3A70: recalc every frame — external poke does NOT persist
- this 0x3D60: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004ed360 | jpt_4ED268 | R | [LLM] |
| 004ed370 | byte_4ED370 | R | [LLM] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041afd0 | sub_41AFD0 | [LLM] |
| 0043e770 | WheelCollisionContactFlagSetter | [LLM] |
| 004a56b0 | StateTransition | [LLM] |
| 004e0d70 | ConditionalResourceRelease | [LLM] |
| 004e0e70 | SubslotCleanup | [LLM] |
| 004e8010 | TireBrushModelForceSolver | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
