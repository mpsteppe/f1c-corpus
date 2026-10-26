## AudioMixing_005285f2 — AudioIMDCTSynthesisFilter

**Summary:** MDCT/IMDCT synthesis filter bank for MPEG audio decoding. Performs 8-sample inverse transform with standard trigonometric rotation constants (√2, cos(π/8), cos(3π/8)). Handles zero-sample short-circuit path. Writes 8 output bytes via CRTFtol float-to-int conversion.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x11C | R | — | Buffer offset from a1+284+128 used to index into output byte buffer via CRTFtol |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acea4 | flt_5ACEA4 | R | RotationFactor [DERIVED] |
| 005b0818 | flt_5B0818 | R | TexColorTransformConst [DERIVED] |
| 005b081c | flt_5B081C | R | Vertex_SkewMatrix [DERIVED] |
| 005b0820 | flt_5B0820 | R | ColorTransformConst [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | Convert float to integer (used for final output byte values) |

**Guard conditions:** Check if all 8 input samples at stride 8 (a3[0], a3[8], a3[16], a3[24], a3[32], a3[40], a3[48], a3[56]) are zero via bitwise OR. If all zero (BLOCKED from full transform): copy DC value (a3[0]*v6[0]) to all 8 output slots (short-circuit). If any non-zero (PASS): compute full MDCT/IMDCT synthesis butterfly transform with rotation constants.
