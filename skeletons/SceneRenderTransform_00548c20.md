## SceneRenderTransform_00548c20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioNodeIterator (00548dd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00541a70 | TransformWheelForcesToChassis | [LLM] |
| 00541b70 | CameraProjectionUpdate | [LLM] |
| 00541d10 | OrientationRotationMatrixUpdate | [LLM] |
| 00541db0 | RandomRotationMatrixFromEulerAngles | [LLM] |
| 0054b530 | DualMatrixTransformMultiply | [LLM] |
| 005550e0 | sub_5550E0 | [LLM] |
| 00556930 | RecursiveStateTraversalWithFlagCheck | [LLM] |
| 005572b0 | sub_5572B0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
