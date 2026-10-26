## QuaternionToRotationMatrix_fb1e_0051fb1e — QuaternionToRotationMatrixNR

**Summary:** Converts a quaternion (a2) to a 4x4 rotation matrix (a1) using SSE intrinsics. Loads quaternion, applies bitmask, normalizes via Newton-Raphson refined inverse sqrt, then computes 4 rotation matrix rows from quaternion component products using precomputed constants. Part of SSE math library.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output rotation matrix row 0 |
| this | 0x10 | RW | — | Output rotation matrix row 1 |
| this | 0x20 | RW | — | Output rotation matrix row 2 |
| this | 0x30 | RW | — | Output rotation matrix row 3 |

**Written-by note (persistence):**
- this 0x0: unconditionally written with matrix row 0; persists as output
- this 0x10: unconditionally written with matrix row 1; persists as output
- this 0x20: unconditionally written with matrix row 2; persists as output
- this 0x30: unconditionally written with matrix row 3; persists as output

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d8b50 | xmmword_5D8B50 | R | Quaternion-to-matrix additive constant for row 3 |
| 005d8b60 | xmmword_5D8B60 | R | Quaternion-to-matrix constant for row 2 |
| 005d8b70 | xmmword_5D8B70 | R | Quaternion-to-matrix constant for row 1 |
| 005d8b80 | xmmword_5D8B80 | R | Quaternion-to-matrix constant for row 0 (bias) |
| 005d8b90 | xmmword_5D8B90 | R | Quaternion product scaling factor |
| 005d8ba0 | dword_5D8BA0 | R | Newton-Raphson subtractive coefficient |
| 005d8bb0 | dword_5D8BB0 | R | Newton-Raphson scale factor (source constant) |
| 005d8bc0 | xmmword_5D8BC0 | R | Bitmask for quaternion component extraction |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always converts quaternion to rotation matrix unconditionally.
