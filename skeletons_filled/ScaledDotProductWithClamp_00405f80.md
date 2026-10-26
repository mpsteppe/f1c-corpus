## ScaledDotProductWithClamp_00405f80 — ScaledOrientationAttenuationClamp

**Summary:** Computes orientation-based audio attenuation factor from scaled dot product ratio between source and listener orientation vectors. Clamps result to [0.125, 8.0] range. Part of 3D sound positioning system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_3DSoundPositioningUpdate (00405b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x54) | 0x7C | R | — | orientation vector X component for numerator |
| *(this+0x54) | 0x80 | R | — | orientation vector Y component for numerator |
| *(this+0x54) | 0x84 | R | — | orientation vector Z component for numerator |
| this | 0x34 | R | — | listener direction X component for denominator |
| this | 0x38 | R | — | listener direction Y component for denominator |
| this | 0x3C | R | — | listener direction Z component for denominator |
| this | 0x48 | RW | 1040187392 → 0.125f | gain/volume value, clamped output |
| this | 0x54 | R | — | pointer to orientation sub-struct |

**Written-by note (persistence):**
- this 0x48: written conditionally — set to 0.125f if computed result < 0.125; set to 8.0f if result > 8.0; otherwise set to computed value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e4dc | flt_59E4DC | R | FullResponseThreshold [DERIVED] (also: ` — full response threshold (float) |
| 0059e4e0 | flt_59E4E0 | R | ForceIncrementClamp [DERIVED] (also: ` — scroll auto-repeat threshold (delta time gate) |
| 0059e4e4 | flt_59E4E4 | R | SmallEpsilon [DERIVED] (also: Small epsilon/prevent-division-by-zero (~0.0f) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always executes the full computation and clamp
