## TriangleClosestPointOrNormal_00520ce0 — MatrixToAxisAngleAlt

**Summary:** Converts a 3x3 matrix (a2) to axis-angle representation (a1), algorithm identical to RotationMatrixToAxisAngleConversion_0051fd90 but with distinct global constants (flt_8D627C-8D6298, dword_8D6270). Computes matrix trace; if trace > flt_8D627C, uses trace-based formula for axis and angle; otherwise selects largest diagonal element via dword_8D6270 index LUT. Part of 3D math / SVD library.

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
| 008d6270 | dword_8D6270 | R | Index LUT for selecting largest diagonal element |
| 008d627c | flt_8D627C | R | Trace threshold; selects between trace-based and largest-diagonal formula |
| 008d6280 | flt_8D6280 | R | Constant added to trace before sqrt (typically 1.0) |
| 008d6284 | flt_8D6284 | R | Scale factor for angle from trace-based formula |
| 008d6288 | flt_8D6288 | R | Reciprocal of twice sine (1/(2*sin(theta))) for axis scaling |
| 008d6290 | flt_8D6290 | R | Constant for largest-diagonal formula (typically 1.0) |
| 008d6294 | flt_8D6294 | R | Scale factor for largest-diagonal angle calculation |
| 008d6298 | flt_8D6298 | R | Reciprocal scale for largest-diagonal axis calculation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks matrix trace (v3 = a2[0]+a2[5]+a2[10]) against flt_8D627C. PASSES (trace-based formula) when trace > flt_8D627C. BLOCKED (largest-diagonal formula) when trace <= flt_8D627C.
