## DualFieldGetter_00456060 — DualFieldGetter

**Summary:** Reads two DWORD fields at offsets 0x38 and 0x3C from a struct and writes them to caller-supplied output pointers if non-null. Simple accessor / getter function.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** FloatKeyedFieldSelector (00408740), CameraModeViewportUpdate (00409a00), CameraShake (0040adb0), CameraTransformComputation (0040b710), CarSelectionStateMachine (00434460), SteeringInterpolationCameraFollow (00434d60), sub_456670 (00456670), sub_457000 (00457000), sub_457670 (00457670), F_2DTransformStructCopy (00457b60), sub_459330 (00459330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x38 | R | — | First output value (field index 14) |
| this | 0x3C | R | — | Second output value (field index 15) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Pointer null checks on output params: if a2 is NULL, skip writing first field. If a3 is NULL, skip writing second field. Both reads from this are unconditional.
