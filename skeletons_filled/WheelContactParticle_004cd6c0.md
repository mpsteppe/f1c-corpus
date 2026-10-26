## WheelContactParticle_004cd6c0 — WheelContactParticleSpawn

**Summary:** Spawn a wheel contact particle (tire spray / smoke / dust). Allocates slot, sets particle lifetime and alpha based on surface type. Writes 4 quad vertices to texture buffer. Surface type 8 gets wet/smoke-specific color and alpha blending.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelSurfaceContactFriction (004ce110), sub_4CEFA0 (004cefa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | surface type identifier |
| this | 0x30 | R | — | particle lifetime duration |
| this | 0x40 | R | — | unknown scale factor |
| this | 0x58 | R | — | buffer capacity / max slot count |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005acebc | flt_5ACEBC | R | RainDropAlphaMult [DERIVED] |
| 005acec0 | flt_5ACEC0 | R | Flt_AlphaBlendFactor [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9ce0 | Delegation | delegate scoring query |
| 004b9cf0 | FloatDifference | compute float difference for scoring |
| 004b9e30 | VehicleDataAccessor | access vehicle data for scoring |
| 004cb540 | CircularBufferSlotAlloc | allocate particle slot from circular buffer |
| 00558e10 | PixelWriteToTextureBuffer | write vertex position + color to particle texture buffer |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | == | 8 | surface type (wet/smoke particle path) |

**Guard interpretation:** Passes slot capacity > 0 guard first. When surface type == 8, takes wet-particle path (sets lifetime, computes alpha from surface color with score-based reduction). When != 8, sets lifetime to max float (infinite) and skips alpha computation.
