## CameraShake_0040adb0 — Camera Shake Computation

**Summary:** Computes camera shake reaction: retrieves current camera entry (stride-160 array at this+0xC, indexed by this+0x14), checks proximity to nearby vehicles, handles collision response if threshold exceeded, and updates camera rotation angles and float parameter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Shake processing enable flag (must be non-zero to execute) |
| this | 0xC | R | — | Base pointer for stride-160 camera entry array |
| this | 0x14 | R | — | Index into camera entry array (selects current entry) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | Float threshold for contact aging overflow |
| 0059e65c | flt_59E65C | R | Camera shake multiplier / conversion factor |
| 0059e670 | flt_59E670 | R | Sentinel flag constant |
| 0059e6a0 | flt_59E6A0 | R | Collision proximity scale |
| 0059e6a4 | flt_59E6A4 | R | Minimum velocity threshold |
| 0059e6a8 | flt_59E6A8 | R | Proximity threshold squared |
| 005c329c | dword_5C329C | R | Vehicle count (loop bound for proximity search) |
| 007c54e0 | dword_7C54E0 | R | Post-process input structure (local player vehicle data) |
| 007c54f0 | dword_7C54F0 | R | Vehicle pointer array (accessed by index) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004084a0 | ShortComputation_84a0 | Computes a float parameter for camera dispatch |
| 0040c780 | ScoringGateConditionCheck | Gets scoring gate condition for collision response |
| 00456060 | DualFieldGetter | Gets dual camera angle fields |
| 00456080 | ShortComputation_6080 | Gets two integer camera parameters |
| 00457a00 | CollisionResponseWithRandomPerturbation | Applies collision response with random perturbation |
| 00457b00 | StateActivatedPositionSaveRestore | Resets state-activated position (called when no nearby vehicle) |
| 00541cd0 | UtilityFunction_1cd0 | Processes camera entry position/orientation data |
| 00542050 | sub_542050 | Applies camera rotation from angle factors |
| 005423c0 | TwoFieldSetterCall | Sets two camera fields |
| 00542680 | ConditionalFloatSetter | Sets float parameter from camera entry field |

**Guard conditions:** this[1] (offset 0x4) must be non-null to process shake. Bit 2 (0x4) at entry offset +116 (v5[29]) must be set for vehicle proximity search. Vehicle loop iterates 0..dword_5C329C-1. If a vehicle within 250.0 units with velocity > 35.0 is found, collision response triggers; otherwise StateActivatedPositionSaveRestore(0) is called.
