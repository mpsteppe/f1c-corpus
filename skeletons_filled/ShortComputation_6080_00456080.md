## ShortComputation_6080_00456080 — FieldGetter_0x40_0x44

**Summary:** Copies struct fields at offsets 0x40 and 0x44 to output pointers if non-null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraViewSystem (00408e20), CameraModeViewportUpdate (00409a00), CameraShake (0040adb0), CameraTransformComputation (0040b710), CarSelectionStateMachine (00434460), sub_456670 (00456670), sub_457000 (00457000), sub_457670 (00457670), F_2DTransformStructCopy (00457b60), sub_458A60 (00458a60), sub_459330 (00459330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | first output field (element [16]) |
| this | 0x44 | R | — | second output field (element [17]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 and a3 are nullable pointers; writes only occur when non-null.
