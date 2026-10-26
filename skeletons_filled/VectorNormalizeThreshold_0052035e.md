## VectorNormalizeThreshold_0052035e — Vec3NormalizeThresholdB

**Summary:** Normalizes a 3-component float vector with squared-length threshold. If squared length >= dword_8D6180, applies Newton-Raphson refined inverse sqrt and scales components; otherwise zeroes output. Uses distinct global constants (dword_8D6180/84/88). Part of SSE math library.

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
- this 0x0: written with normalized X or 0.0; persists as output
- this 0x4: written with normalized Y or 0.0; persists as output
- this 0x8: written with normalized Z or 0.0; persists as output

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d6180 | dword_8D6180 | R | Squared-length threshold for normalization |
| 008d6184 | dword_8D6184 | R | Newton-Raphson scale factor |
| 008d6188 | dword_8D6188 | R | Newton-Raphson subtractive coefficient |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks squared length against dword_8D6180. PASSES (normalizes) when v5 >= dword_8D6180. BLOCKED (zeroes output) when v5 < dword_8D6180.
