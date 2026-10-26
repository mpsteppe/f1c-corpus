## ComputeSlipVelocityNorm_004e9980 — slip velocity vector norm with local-frame transform

**Summary:** Transforms position delta (reference minus current) into local frame via rotation matrix, computes Euclidean norm, adds constant bias 3.2, and clamps to minimum threshold. Part of tire slip velocity computation.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleEffectUpdateDispatch (004eb430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34B0 | R | — | rotation matrix row 0, column 0 (local X axis) |
| this | 0x34B4 | R | — | rotation matrix row 1, column 0 (local X axis) |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] — rotation matrix row 2, column 0 |
| this | 0x34BC | R | — | rotation matrix row 0, column 1 (local Y axis) |
| this | 0x34C0 | R | — | rotation matrix row 1, column 1 (local Y axis) |
| this | 0x34C4 | R | — | rotation matrix row 2, column 1 (local Y axis) |
| this | 0x34C8 | R | — | rotation matrix row 0, column 2 (local Z axis) |
| this | 0x34CC | R | — | rotation matrix row 1, column 2 (local Z axis) |
| this | 0x34D0 | R | — | rotation matrix row 2, column 2 (local Z axis) |
| this | 0x34D4 | R | — | current position X |
| this | 0x34D8 | R | — | current position Y |
| this | 0x34DC | R | — | current position Z |
| this | 0x3B60 | R | — | reference/contact patch position X |
| this | 0x3B64 | R | — | reference/contact patch position Y |
| this | 0x3B68 | R | — | reference/contact patch position Z |
| this | 0x3B6C | R | — | minimum clamp value for slip velocity norm |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad1d8 | flt_5AD1D8 | R | CollisionRadiusBias [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this[3803] (0x3B6C) > computed result → clamp return to this[3803] (minimum threshold). PASSES: computed norm larger → return computed norm.
