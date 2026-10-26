## VectorNormalizeWithThreshold_0051ee7e — Vec4NormalizeWithThreshold

**Summary:** Normalizes a 4-component float vector with squared-length threshold. If squared length >= global constant at dword_8D600C, computes unit vector using Newton-Raphson refined reciprocal sqrt, including W component; otherwise zeroes all four components. Part of 3D math library.

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
- this 0x0: written either with normalized X or 0.0; survives as output
- this 0x4: written either with normalized Y or 0.0; survives as output
- this 0x8: written either with normalized Z or 0.0; survives as output
- this 0xC: written either with normalized W or 0.0; survives as output

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d600c | dword_8D600C | R | Squared-length threshold for 4-component normalization |
| 008d6010 | dword_8D6010 | R | Newton-Raphson refinement scale factor |
| 008d6014 | dword_8D6014 | R | Newton-Raphson refinement subtractive coefficient |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks squared length of input vector against dword_8D600C. PASSES (normalizes) when v5 >= dword_8D600C. BLOCKED (returns zero vector) when v5 < dword_8D600C.
