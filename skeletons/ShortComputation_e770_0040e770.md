## ShortComputation_e770_0040e770 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** StructInitWithFloatConstantsAndSubCalls (0040e8f0), StructInitWithFloatConstantsAndSubCalls_e990 (0040e990), sub_40EA30 (0040ea30), CameraProjectionMatrixInitWithFloatConstants (0040eb30), UtilityFunction_ebd0 (0040ebd0), StructInitializerWithFloatConstants (0040ec70), WheelControllerInputDecoder (00410bc0), ShortComputation_1330 (00411330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x0 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x2C | RW | — | [LLM] |
| this | 0xF0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x24: recalc every frame — external poke does NOT persist
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x2C: recalc every frame — external poke does NOT persist
- this 0xF0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040e83c | jpt_40E7C4 | R | [LLM] |
| 008ab710 | dword_8AB710 | R | UIWidgetList [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e2b0 | AudioPhysicsMixWithLerp | [LLM] |
| 0040ed10 | sub_40ED10 | [LLM] |
| 004be010 | sub_4BE010 | [LLM] |
| 0054b530 | DualMatrixTransformMultiply | [LLM] |
| 0054fb40 | SceneNodeVisibilityToggle | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
