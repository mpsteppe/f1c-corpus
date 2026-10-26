## RotationMatrixToAxisAngleConversion_0051fd90 — MatrixToAxisAngle

**Summary:** Converts a 3x3 rotation matrix (a2) to axis-angle representation (a1). Computes matrix trace; if trace exceeds threshold (flt_8D611C), uses trace-based formula for axis (Rzy-Ryz, Rxz-Rzx, Ryx-Rxy) and angle = sqrt(trace + 1) * scale. Otherwise selects largest diagonal element and computes axis/angle from corresponding off-diagonals. Part of 3D math / SVD library.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output axis X component (or first component of selected axis) |
| this | 0x4 | RW | — | Output axis Y component |
| this | 0x8 | RW | — | Output axis Z component |
| this | 0xC | RW | — | Output angle (rotation magnitude) |

**Written-by note (persistence):**
- this 0x0: unconditionally written with axis/angle component; persists as output
- this 0x4: unconditionally written with axis/angle component; persists as output
- this 0x8: unconditionally written with axis/angle component; persists as output
- this 0xC: unconditionally written with angle; persists as output

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d6110 | dword_8D6110 | R | Index table for selecting largest diagonal element |
| 008d611c | flt_8D611C | R | Trace threshold; selects between trace-based and largest-diagonal formula |
| 008d6120 | flt_8D6120 | R | Constant added to trace before sqrt (typically 1.0) |
| 008d6124 | flt_8D6124 | R | Scale factor for angle from trace-based formula |
| 008d6128 | flt_8D6128 | R | Reciprocal of twice sine (1/(2*sin(theta))) for axis scaling |
| 008d6130 | flt_8D6130 | R | Constant for largest-diagonal formula (typically 1.0) |
| 008d6134 | flt_8D6134 | R | Scale factor for largest-diagonal angle calculation |
| 008d6138 | flt_8D6138 | R | Reciprocal scale for largest-diagonal axis calculation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks matrix trace (v3 = a2[0]+a2[5]+a2[10]) against flt_8D611C. PASSES (trace-based formula) when trace > flt_8D611C. BLOCKED (largest-diagonal formula) when trace <= flt_8D611C.
