## ParticlePositionSetup_004c9d60 — ParticlePositionInitNoise

**Summary:** Initializes a particle's position, direction, color, and attributes using noise-perturbed values from the weather noise table. Computes position from input parameters a2-a5 with noise scaling, normalizes direction vector, packs ARGB color, and generates random index.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4CB120 (004cb120)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | X position coordinate (noise-perturbed * a2) |
| this | 0x14 | RW | — | Y position coordinate (noise-perturbed * a3) |
| this | 0x18 | RW | — | Z position coordinate (this+0x14 + noise-perturbed * a4) |
| this | 0x1C | RW | — | Extended position bound (this+0x18 + noise-perturbed * a5) |
| this | 0x20 | RW | 0 | Reciprocal of Y-component (1/this+0x14), 0 if Y is zero |
| this | 0x24 | RW | 0 | Reciprocal of extended component (1/v23), 0 if v23 is zero |
| this | 0x28 | RW | — | Lifespan or size parameter (noise*40 + 214) |
| this | 0x48 | RW | 0 | Direction vector X component (normalized) |
| this | 0x4C | RW | 1065353216 → 1.0f | Direction vector Y component (normalized); defaults to 1.0 (up) |
| this | 0x50 | RW | 0 | Direction vector Z component (normalized) |
| this | 0x54 | RW | — | Random index (0-15) from RandLCGRandomNumberGenerator |
| this | 0x60 | RW | — | ARGB color packed: upper 8 bits alpha from this+0x28, lower 24 bits = 0xFFFFFF (white) |
| this | 0x68 | RW | — | Noise scale factor (noise*0.2 + 1.0) |

**Written-by note (persistence):**
- this 0x10: Written once per call with noise-perturbed position. Persists until overwritten.
- this 0x14: Written once per call with noise-perturbed position. Persists until overwritten.
- this 0x18: Written once per call with noise-perturbed position. Persists until overwritten.
- this 0x1C: Written once per call. Persists until overwritten.
- this 0x20: Written once per call (1/this+0x14 or 0). Persists until overwritten.
- this 0x24: Written once per call (1/v23 or 0). Persists until overwritten.
- this 0x28: Written once per call. Persists until overwritten.
- this 0x48: Written once per call (normalized direction X, or 0 if degenerate). Persists.
- this 0x4C: Written once per call (normalized direction Y, or 1.0 if degenerate). Persists.
- this 0x50: Written once per call (normalized direction Z, or 0 if degenerate). Persists.
- this 0x54: Written once per call with random 0-15. Persists until overwritten.
- this 0x60: Written once per call. Persists until overwritten.
- this 0x68: Written once per call. Persists until overwritten.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e86c | flt_59E86C | R | FloatToInt64Scale [DERIVED] |
| 005ace90 | flt_5ACE90 | R | ParticleColorOffset [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005884ed | RandLCGRandomNumberGenerator | Generates random value for particle index (modulo 16) |

**Guard conditions:** Checks v8 (Y position component) for zero — if zero, reciprocal field at this+0x20 is set to 0 instead of dividing. Same for v23 (extended component) at this+0x24. Checks if direction vector flags indicate degenerate case — if so, direction defaults to (0, 1.0, 0) instead of normalized vector.
