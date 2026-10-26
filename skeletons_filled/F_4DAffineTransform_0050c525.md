## F_4DAffineTransform_0050c525 — 4D Affine Transform (Vector-Matrix Multiply)

**Summary:** Applies a 4x4 affine transformation matrix to a 3-component input vector, producing a 4-component homogeneous output vector. result = input_vec * transpose(matrix), where matrix is column-major.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output X component |
| this | 0x4 | RW | — | Output Y component |
| this | 0x8 | RW | — | Output Z component |
| this | 0xC | RW | — | Output W component |

**Written-by note (persistence):**
- this 0x0-0xC: written unconditionally each call; output buffer, ephemeral

**Globals referenced:** none

**Functions called:** none

**Guard conditions:** unconditional — no branches, no early return.
