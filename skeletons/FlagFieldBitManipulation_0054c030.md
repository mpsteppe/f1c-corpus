## FlagFieldBitManipulation_0054c030 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_45A8E0 (0045a8e0), VehicleSceneLoadAndPositionTires (004681b0), ModeDependentSubsystemCall (004a2770), PitCrewAnimationLoader (004a2a90), ShortComputation_3fe0 (004a3fe0), UtilityFunction_4000 (004a4000), CollisionAvoidanceCheck (004a6b80), VehicleVisibilityCulling (004b3dc0), sub_4D1670 (004d1670), VehicleGraphicsSceneLoader (004dfce0), ConditionalResourceRelease (004e0d70), ArrayEntryCleanup (004e0e20), SubslotCleanup (004e0e70), AudioSoundEffectController (004e0ed0), VehicleStateUpdate_19d0 (004e19d0), CameraViewportRenderSetup (004fbd70), sub_5503A0 (005503a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3C | RW | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x3C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054c030 | FlagFieldBitManipulation | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
