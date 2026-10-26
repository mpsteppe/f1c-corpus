## CameraTransformComputation_0040b710 — Camera Transform Computation

**Summary:** Computes camera transform for current camera entry (stride-208 array at this+0xC, indexed by this+0x14). Applies vehicle velocity data, matrix transform, position/orientation processing, and camera angle updates. Part of camera processing pipeline.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Camera processing enable flag (must be non-zero to execute) |
| this | 0xC | R | — | Base pointer for stride-208 camera entry array |
| this | 0x14 | R | — | Index into camera entry array (selects current entry) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e65c | flt_59E65C | R | Camera shake multiplier / conversion factor |
| 007c54e0 | dword_7C54E0 | R | Post-process input structure (local player vehicle data, read velocity at +88) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004084a0 | ShortComputation_84a0 | Computes a float parameter for camera dispatch |
| 0040c780 | ScoringGateConditionCheck | Gets scoring gate condition |
| 00456060 | DualFieldGetter | Gets dual camera angle fields |
| 00456080 | ShortComputation_6080 | Gets two integer camera parameters |
| 004e1fd0 | F_3DTransformPointByMatrixAndTranslation | Transforms point by matrix and translation |
| 00541cd0 | UtilityFunction_1cd0 | Processes camera entry position/orientation data |
| 00542050 | sub_542050 | Applies camera rotation from angle factors |
| 005423c0 | TwoFieldSetterCall | Sets two camera fields |
| 00542680 | ConditionalFloatSetter | Sets float parameter from camera entry field at +72 |

**Guard conditions:** this[1] (offset 0x4) must be non-zero to process camera transform. If zero, function returns immediately.
