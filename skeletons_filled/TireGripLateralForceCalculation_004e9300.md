## TireGripLateralForceCalculation_004e9300 — lateral tire grip force with multi-contact iteration

**Summary:** Computes lateral tire grip force using friction-circle model, iterates over wheel contact patches to accumulate individual slip forces, limits by friction circle and contact capacity. Part of tire dynamics system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsNodePropagationWithDistanceFalloff (00401c90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3514 | R | — | sprung mass factor (vertical/normal force scaling) |
| this | 0x3518 | R | — | tire force output multiplier |
| this | 0x3800 | R | — | alternative struct base (selected when 0x39B4 == 2, accessed at offset +0x90) |
| this | 0x3998 | R | — | slip ratio threshold for contact iteration break |
| this | 0x39A4 | R | — | EngineMaxRPM [CONFIRMED] — pointer to external 8-byte-entry lookup table |
| this | 0x39B4 | R | — | struct base selector (!=2 → 0x3580, ==2 → 0x3770) |
| this | 0x39D0 | R | — | start of per-iteration wheel contact parameter array |
| this | 0x39F8 | R | — | contact patch iteration count (max ~7) |
| this | 0x3A70 | R | — | force coefficient for squared slip velocity |
| this | 0x3C3C | R | — | positive-force table branch selector threshold |
| this | 0x3C40 | R | — | start of 14-entry positive force lookup table |
| this | 0x3C7C | R | — | negative-force table branch selector threshold |
| this | 0x3C80 | R | — | start of 14-entry negative force lookup table |
| this | 0x3CBC | R | — | aerodynamic force table selector threshold |
| this | 0x3CC0 | R | — | start of 14-entry aerodynamic force lookup table |
| this | 0x3D44 | R | — | additional lateral force coefficient |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059ed18 | flt_59ED18 | R | ForceReductionFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005895a2 | sub_5895A2 | unknown — called with computed force values, return not used |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x39B4 | != | 2 | struct base selector — selects base address for offset +0x90 access |

**Guard interpretation:** 0x39B4 != 2 → v21 base = this+0x3580 (default wheel struct). 0x39B4 == 2 → v21 base = this+0x3770 (alternative struct). NOT an early-return guard; both paths proceed. Friction-circle check v48 <= 0.0 → BLOCKED (returns 0 lateral force). Loop break on v22 < threshold at 0x3998.
