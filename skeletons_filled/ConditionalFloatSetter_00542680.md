## ConditionalFloatSetter_00542680 — ConditionalFloatSetter

**Summary:** Sets float field at this+0x88 (this[34]) to a2 if a2 is positive. Acts as guard against setting a value to zero or negative numbers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalRenderPipelineDispatch (00409970), CameraModeViewportUpdate (00409a00), CameraShake (0040adb0), CameraTransformComputation (0040b710), CarSelectionStateMachine (00434460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x88 | RW | — | Float field conditionally set to a2 when a2 > 0.0; likely a camera/transform parameter (FOV, distance, or scaling factor) |

**Written-by note (persistence):**
- this 0x88: written only when a2 > 0.0; retains previous value otherwise

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel (~0.0) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a2 <= 0.0, skips the write entirely — field retains previous value. Only positive values pass.

