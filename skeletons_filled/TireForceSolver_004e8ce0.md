## TireForceSolver_004e8ce0 — tire force bisection solver with table lookups

**Summary:** Bisection-method root solver for tire contact force using table lookups with linear interpolation. Narrows bracket [lo,hi] until force function changes sign, returns interpolated root. Part of tire dynamics system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SweptSuspensionCollisionDetection (00401910), PhysicsNodePropagationWithDistanceFalloff (00401c90), sub_426430 (00426430), AIComputePassScore (0042a780)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3514 | R | — | sprung mass factor (multiplied with vertical force terms) |
| this | 0x3A70 | R | — | force coefficient for squared-deformation term |
| this | 0x3C3C | R | — | positive-force-table selector threshold (this[3855]) |
| this | 0x3C40 | R | — | start of 14-entry positive force lookup table (this[3856..3869]) |
| this | 0x3C7C | R | — | negative-force-table selector threshold (this[3871]) |
| this | 0x3C80 | R | — | start of 14-entry negative force lookup table (this[3872..3885]) |
| this | 0x3CFC | R | — | initial bracket scaling factor for input a4 (this[3903]) |
| this | 0x3D00 | R | — | start of 14-entry initial bracket lookup table (this[3904..3917]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e6fc | flt_59E6FC | R | RGBChannelMultiplier [DERIVED] (also: ` — RGB channel multiplier (~255.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005895a2 | sub_5895A2 | unknown — called with computed force values, return not used |

**Guard conditions:** Table index v7 >= 0 → PASS (access table). v7 >= 14 → clamped to 13 (table bounds). v8 > 128.0 → capped to 128.0. Bisection loop breaks on sign-cross (v30 * v54 <= 0.0). BLOCKED: v45 <= 0.0 → return 0.0; v44 >= 128.0 → return 128.0.
