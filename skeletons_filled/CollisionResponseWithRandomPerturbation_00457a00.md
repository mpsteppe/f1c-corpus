## CollisionResponseWithRandomPerturbation_00457a00 — CollisionResponseRandomPerturbation

**Summary:** Generates a random-perturbation collision response vector: reads current position (x,y,z) from offsets 0x90,0x94,0x98, applies random sign flips via UtilityFunction_6010, scales by input parameters, and writes perturbed result back via VectorCopy.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraShake (0040adb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x90 | R | — | X position component |
| this | 0x94 | R | — | Y position component |
| this | 0x98 | R | — | Z position component |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics threshold constant |
| 0059e450 | flt_59E450 | R | degrees-to-radians conversion factor |
| 0059e670 | flt_59E670 | R | sentinel/saturation constant |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00456010 | UtilityFunction_6010 | random number generator (returns signed int) |
| 00456130 | VectorCopy | copies computed perturbed vector back to this |
| 00457b00 | StateActivatedPositionSaveRestore | saves/restores state activation flag |

**Guard conditions:** v15 = a2*a3*0.5; capped at 0.5 if > 0.5. No early-return guards.
