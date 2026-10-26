## VelocityFrictionClampWithStictionThreshold_0052042e — Vec4NormalizeThresholdC

**Summary:** Normalizes a 4-component float vector with squared-length threshold. If squared length >= dword_8D618C, applies Newton-Raphson refined inverse sqrt and scales all 4 components; otherwise zeroes output. Uses distinct global constants (dword_8D618C/90/94). Part of SSE math library.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output vector X component |
| this | 0x4 | RW | — | Output vector Y component |
| this | 0x8 | RW | — | Output vector Z component |
| this | 0xC | RW | — | Output vector W component |

**Written-by note (persistence):**
- this 0x0: written with normalized X or 0.0; persists as output
- this 0x4: written with normalized Y or 0.0; persists as output
- this 0x8: written with normalized Z or 0.0; persists as output
- this 0xC: written with normalized W or 0.0; persists as output

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d618c | dword_8D618C | R | Squared-length threshold for normalization |
| 008d6190 | dword_8D6190 | R | Newton-Raphson scale factor |
| 008d6194 | dword_8D6194 | R | Newton-Raphson subtractive coefficient |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks squared length against dword_8D618C. PASSES (normalizes) when v5 >= dword_8D618C. BLOCKED (zeroes output) when v5 < dword_8D618C.
