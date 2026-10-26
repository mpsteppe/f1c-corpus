## SSEReciprocalSquareRootWithNewtonRaphsonQuaterni_00520c0e — QuaternionToRotationMatrixAlt

**Summary:** Converts a quaternion (a2) to a 4x4 rotation matrix (a1) using SSE intrinsics. Loads quaternion, applies bitmask (xmmword_5D8D20), normalizes via Newton-Raphson refined inverse sqrt using constants dword_5D8D00/D10, then computes 4 rotation matrix rows from quaternion component products with distinct constants (xmmword_5D8CB0-5D8CF0). Similar algorithm to QuaternionToRotationMatrix_fb1e but with different constants. Part of SSE math library.

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
| 005d8cb0 | xmmword_5D8CB0 | R | Quaternion-to-matrix additive constant for row 3 |
| 005d8cc0 | xmmword_5D8CC0 | R | Quaternion-to-matrix constant for row 2 |
| 005d8cd0 | xmmword_5D8CD0 | R | Quaternion-to-matrix constant for row 1 |
| 005d8ce0 | xmmword_5D8CE0 | R | Quaternion-to-matrix constant for row 0 (bias) |
| 005d8cf0 | xmmword_5D8CF0 | R | Quaternion product scaling factor |
| 005d8d00 | dword_5D8D00 | R | Newton-Raphson subtractive coefficient |
| 005d8d10 | dword_5D8D10 | R | Newton-Raphson scale factor |
| 005d8d20 | xmmword_5D8D20 | R | Bitmask for quaternion component extraction |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always converts quaternion to rotation matrix unconditionally.
