## SmoothstepInterpolation_00406020 — AttenuationSmoothstepThreshold

**Summary:** Computes smoothstep-style interpolation for audio attenuation with a threshold. Returns base scale value when linear parameter below 1.0; applies inverse-blend attenuation when above. Part of 3D sound positioning system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_3DSoundPositioningUpdate (00405b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | interpolation rate scaler (multiplies input a2) |
| this | 0x20 | R | — | interpolation offset (added to scaled input) |
| this | 0x24 | R | — | blend factor for smoothstep interpolation curve |
| this | 0x40 | R | — | base scale value (returned unmodified when v2 < 1.0) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always executes the full interpolation
