## F_3x3MatrixTransformVector_0053ad80 — SSE 3x3 matrix × vector transform

**Summary:** SSE-accelerated 3x3 matrix transformation of integer 3-component vector. Copies input vector and 3 matrix columns to working buffers, computes dot product via SSE shuffle/mul/add, stores result as 3 integers. Used for 3D coordinate transform without translation.

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
| this | 0x10 | R | — | pointer to output vector buffer (*(a1+16)) |
| this | 0x30 | R | — | pointer to matrix buffer (*(a1+48)), holds 3 __m128 columns |

**Written-by note (persistence):**
- *(this+0x10) 0x0: overwritten each call with transform result
- *(this+0x30) 0x0/0x10/0x20: overwritten each call with new matrix columns

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No branches. Always computes transform unconditionally.
