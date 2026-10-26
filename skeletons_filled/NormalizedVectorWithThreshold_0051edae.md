## NormalizedVectorWithThreshold_0051edae — Vec3NormalizeWithThreshold

**Summary:** Normalizes a 3-component float vector with squared-length threshold. If squared length >= global constant at dword_8D6000, computes unit vector using Newton-Raphson refined reciprocal sqrt; otherwise zeroes output. Part of 3D math library.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output vector X component |
| this | 0x4 | RW | — | Output vector Y component |
| this | 0x8 | RW | — | Output vector Z component |

**Written-by note (persistence):**
- this 0x0: written either with normalized X or 0.0; survives as output
- this 0x4: written either with normalized Y or 0.0; survives as output
- this 0x8: written either with normalized Z or 0.0; survives as output

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d6000 | dword_8D6000 | R | Squared-length threshold; normalization only occurs if input norm² >= this value |
| 008d6004 | dword_8D6004 | R | Newton-Raphson refinement scale factor |
| 008d6008 | dword_8D6008 | R | Newton-Raphson refinement subtractive coefficient |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks squared length of input vector against dword_8D6000. PASSES (normalizes) when v5 >= dword_8D6000. BLOCKED (returns zero vector) when v5 < dword_8D6000.
