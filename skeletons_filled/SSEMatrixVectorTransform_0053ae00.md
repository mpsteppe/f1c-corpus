## SSEMatrixVectorTransform_0053ae00 — SSE 4×4 matrix × 4-component vector transform

**Summary:** SSE-accelerated 4x4 matrix transformation of integer 3-component vector with implicit w=1. Copies input vector and 4 matrix columns to working buffers, sets 4th component to 1.0f, computes full 4-component dot product via SSE shuffle/mul/add, stores result as 3 integers. Used for 3D transform with translation (affine matrix).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10) | 0x0 | RW | — | output vector X component in working buffer |
| *(this+0x10) | 0x4 | R | — | input vector Y component, read for copy to buffer |
| *(this+0x30) | 0x0 | RW | — | matrix column 0 (first __m128), copied from a4[0] |
| *(this+0x30) | 0x10 | RW | — | matrix column 1 (second __m128), copied from a4[1] |
| *(this+0x30) | 0x20 | RW | — | matrix column 2 (third __m128), copied from a4[2] |
| *(this+0x30) | 0x30 | RW | — | matrix column 3 (fourth __m128, translation column), copied from a4[3] |
| this | 0x10 | R | — | pointer to output vector buffer (*(a1+16)) |
| this | 0x30 | R | — | pointer to matrix buffer (*(a1+48)), holds 4 __m128 columns |

**Written-by note (persistence):**
- *(this+0x10) 0x0: overwritten each call with transform result
- *(this+0x30) 0x0/0x10/0x20/0x30: overwritten each call with new matrix columns

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No branches. Always computes transform unconditionally. 4th component of input vector hardcoded to 1065353216 (1.0f as float) for affine translation.
