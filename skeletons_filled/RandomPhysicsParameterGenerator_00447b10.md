## RandomPhysicsParameterGenerator_00447b10 — RandomPhysicsParameterGenerator

**Summary:** Generates a randomized physics parameter in [0.0, 1.0] range by interpolating between a lower bound (value+0.1) and upper bound (value+1.6) using a trig-table-based pseudo-random value. Returns 0 if inactive flag not set, 1.0 if input parameter >= 0.9, 0.0 if <= 0.0. Part of vehicle physics parameter randomization.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** Gearbox (00443b70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x19C | R | — | input parameter value (used for bounds + clamping) |
| this | 0x1C59 | R | — | active flag byte (must be non-zero to generate value) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059eb38 | dbl_59EB38 | R | Physics_Double_59EB38 [DERIVED] |
| 0059eba0 | dbl_59EBA0 | R | EnergyToDamageScaleFactor [DERIVED] (also: ` — energy-to-damage conversion factor) |
| 0059eef8 | dbl_59EEF8 | R | OilTempBlendFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00447ab0 | TrigTableLookup | provides pseudo-random interpolation value from trig table |

**Guard conditions:** if active flag byte (this+0x1C59) == 0, return 0.0 (BLOCKED). If input parameter (this+0x19C) >= 0.9, return 1.0 (clamped upper). If <= 0.0, return 0.0 (clamped lower). Otherwise generate interpolated random value in [input+0.1, input+1.6] range via TrigTableLookup, clamped to [0.0, 1.0].
