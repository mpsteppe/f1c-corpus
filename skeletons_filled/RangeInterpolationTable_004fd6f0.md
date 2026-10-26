## RangeInterpolationTable_004fd6f0 — Range-to-Interpolation-Table Bucket Fill

**Summary:** Populates a 16-entry interpolation lookup table (offsets 0x64–0xA0) from a [min, max] range at fixed interpolation fractions (0.0, 0.01, 0.03, 0.05, 0.06, 0.14, 0.25, 0.37, 0.5, 0.63, 0.75, 0.86, 0.94, 0.99, 1.0). Used to precompute parameter curves for physics and audio subsystems.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StructInitWithFloatDefaults (004fc9c0), sub_4FCC30 (004fcc30), AudioADSREnvelope (004fdeb0), CarPositionTargetCheck (004fe060)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | R | — | range minimum value (table lower bound) |
| this | 0x2C | R | — | range maximum value (table upper bound) |
| this | 0x64 | RW | — | table slot 0: value at fraction 0.05 of range [min+(max-min)*0.05] |
| this | 0x68 | RW | — | table slot 1: value at fraction 0.03 |
| this | 0x6C | RW | — | table slot 2: value at fraction 0.01 |
| this | 0x70 | RW | — | table slot 3: value at fraction 0.00 (exact min) |
| this | 0x74 | RW | — | table slot 4: value at fraction 0.01 (duplicate of slot 2) |
| this | 0x78 | RW | — | table slot 5: value at fraction 0.06 |
| this | 0x7C | RW | — | table slot 6: value at fraction 0.14 |
| this | 0x80 | RW | — | table slot 7: value at fraction 0.25 |
| this | 0x84 | RW | — | table slot 8: value at fraction 0.37 |
| this | 0x88 | RW | — | table slot 9: value at fraction 0.50 (midpoint) |
| this | 0x8C | RW | — | table slot 10: value at fraction 0.63 |
| this | 0x90 | RW | — | table slot 11: value at fraction 0.75 |
| this | 0x94 | RW | — | table slot 12: value at fraction 0.86 |
| this | 0x98 | RW | — | table slot 13: value at fraction 0.94 |
| this | 0x9C | RW | — | table slot 14: value at fraction 0.99 |
| this | 0xA0 | RW | — | table slot 15: value at fraction 1.00 (exact max) |

**Written-by note (persistence):**
- this 0x64: written once per call — external poke does NOT survive recalculation
- this 0x68: written once per call — external poke does NOT survive recalculation
- this 0x6C: written once per call — external poke does NOT survive recalculation
- this 0x70: written once per call — external poke does NOT survive recalculation
- this 0x74: written once per call — external poke does NOT survive recalculation
- this 0x78: written once per call — external poke does NOT survive recalculation
- this 0x7C: written once per call — external poke does NOT survive recalculation
- this 0x80: written once per call — external poke does NOT survive recalculation
- this 0x84: written once per call — external poke does NOT survive recalculation
- this 0x88: written once per call — external poke does NOT survive recalculation
- this 0x8C: written once per call — external poke does NOT survive recalculation
- this 0x90: written once per call — external poke does NOT survive recalculation
- this 0x94: written once per call — external poke does NOT survive recalculation
- this 0x98: written once per call — external poke does NOT survive recalculation
- this 0x9C: written once per call — external poke does NOT survive recalculation
- this 0xA0: written once per call — external poke does NOT survive recalculation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e454 | flt_59E454 | R | PhysicsConstant_59E454 [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 005acd48 | flt_5ACD48 | R | TireGripThreshold [DERIVED] |
| 005acdc0 | flt_5ACDC0 | R | InterpFactor_5ACDC0 [DERIVED] |
| 005ad150 | flt_5AD150 | R | AITimerRandomScale [DERIVED] |
| 005ad2c0 | flt_5AD2C0 | R | InterpCoeff [DERIVED] |
| 005ad2c4 | flt_5AD2C4 | R | Flt_InterpolationCoeff [DERIVED] |
| 005ad2c8 | flt_5AD2C8 | R | CameraFOVCoeff [DERIVED] |
| 005ad2cc | flt_5AD2CC | R | WheelSpeedCoeff [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No branching guards — function always executes. The 16 table entries are unconditionally computed as `min + fraction * (max - min)` for each fixed fraction.
