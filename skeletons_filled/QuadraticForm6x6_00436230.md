## QuadraticForm6x6_00436230 — 6x6 quadratic form evaluation

**Summary:** Evaluates a quadratic form for 3-axis spring-damper force with sign-dependent stiffness selection and anti-symmetric damping. Produces 3-element force and 3-element moment output arrays. Part of the suspension force computation system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** DamperSpringForceComputationWithAntiRoll (004432f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x90 | R | — | Stiffness coefficient for compression (axis 0) |
| this | 0x98 | R | — | Stiffness coefficient for compression (axis 1) |
| this | 0xA0 | R | — | Stiffness coefficient for compression (axis 2) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes. Sign-dependent stiffness selection based on whether each input component is <= 0.0.
