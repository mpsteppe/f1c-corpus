## ConditionalRenderPipelineDispatch_00409970 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_409890 (00409890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004099e0 | sub_4099E0 | R | [LLM] |
| 0059e65c | flt_59E65C | R | CameraShakeMultiplier [DERIVED] (also: ` — camera shake multiplier / conversion factor (docs/09, 19) |
| 007cf680 | dword_7CF680 | R | CameraCenterTargetPos [DERIVED] (also: ` — camera center/target position) |
| 007cf6a4 | flt_7CF6A4 | R | CameraScaleFactorX [DERIVED] |
| 007cf6c8 | flt_7CF6C8 | R | CameraScaleFactorX [DERIVED] (also: ` — renderer camera scale factors) |
| 007cf6ec | dword_7CF6EC | R | CameraZoom [DERIVED] (also: ` — camera zoom/distance) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00541ca0 | sub_541CA0 | [LLM] |
| 00542050 | sub_542050 | [LLM] |
| 00542540 | PointerStorePair2 | [LLM] |
| 00542650 | Bit5FlagSetReset | [LLM] |
| 00542680 | ConditionalFloatSetter | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
