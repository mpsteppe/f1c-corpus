## AIVehiclePathPositionTracking_004ef7c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteeringRacingLineCorrection (0042b0e0), sub_4C6B60 (004c6b60), SceneRenderUpdate (004c6d90), LoopOverTwoParallelArrays (004d1030), SessionStateTransition (004ef5a0), VehicleYawRotationRecoveryController (004f1c40), sub_4F1FE0 (004f1fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | [LLM] |
| this | 0x34B0 | R | — | [LLM] |
| this | 0x34B4 | R | — | [LLM] |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | [LLM] |
| this | 0x34C0 | R | — | [LLM] |
| this | 0x34C4 | R | — | [LLM] |
| this | 0x34C8 | R | — | [LLM] |
| this | 0x34CC | R | — | [LLM] |
| this | 0x34D0 | R | — | [LLM] |
| this | 0x34D4 | RW | — | [LLM] |
| this | 0x34D8 | RW | — | [LLM] |
| this | 0x34DC | RW | — | [LLM] |
| this | 0x34E0 | RW | — | [LLM] |
| this | 0x34E4 | RW | — | [LLM] |
| this | 0x34E8 | RW | — | [LLM] |
| this | 0x3A9C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x34D4: recalc every frame — external poke does NOT persist
- this 0x34D8: recalc every frame — external poke does NOT persist
- this 0x34DC: recalc every frame — external poke does NOT persist
- this 0x34E0: recalc every frame — external poke does NOT persist
- this 0x34E4: recalc every frame — external poke does NOT persist
- this 0x34E8: recalc every frame — external poke does NOT persist
- this 0x3A9C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043e4b0 | RigidBodyConstraintSolve | [LLM] |
| 004e9bd0 | F_3x3MatrixTransformWithTranslation | [LLM] |
| 004ef680 | RideHeightDelta | [LLM] |
| 00566e40 | EulerToRotationMatrix | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
