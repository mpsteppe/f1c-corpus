## AIRacingLinePathFollowing_004e9ca0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4BB8E0 (004bb8e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4040 | R | — | [LLM] |
| obj | 0x4094 | RW | 1 | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x3440 | R | — | [LLM] |
| this | 0x34D4 | RW | — | [LLM] |
| this | 0x34D8 | RW | — | [LLM] |
| this | 0x34DC | RW | — | [LLM] |
| this | 0x34E0 | RW | — | [LLM] |
| this | 0x34E4 | RW | — | [LLM] |
| this | 0x34E8 | RW | — | [LLM] |
| this | 0x3A9C | RW | — | [LLM] |

**Written-by note (persistence):**
- obj 0x4094: recalc every frame — external poke does NOT persist
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
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea3f0 | dword_5EA3F0 | R | RaycastMaxIterMult [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008ad07c | dword_8AD07C | R | TrackFollowStatePtr [DERIVED] |
| 008ad080 | dword_8AD080 | R | Unknown_Game_Setup_AD080 [DERIVED] |
| 008ad084 | dword_8AD084 | R | PathNodeCount [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403640 | sub_403640 | [LLM] |
| 004bc340 | sub_4BC340 | [LLM] |
| 004d1140 | RenderCallWithGuard | [LLM] |
| 004e9600 | SuspensionStateUpdate | [LLM] |
| 004e9a40 | VehicleBodyToWheelContactDistanceComputation | [LLM] |
| 004e9bd0 | F_3x3MatrixTransformWithTranslation | [LLM] |
| 004ef6c0 | CoordinateTransformWithOffset | [LLM] |
| 004efb20 | F_3DTransformWithMatrixMultiplication | [LLM] |
| 0054f7a0 | UIFocusChange | [LLM] |
| 0054fae0 | BufferEntryClear | [LLM] |
| 0054fb40 | SceneNodeVisibilityToggle | [LLM] |
| 00566e40 | EulerToRotationMatrix | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
