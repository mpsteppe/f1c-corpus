## SSEVectorMatrixInit_0052087e — SSEMatrixInitFromVector

**Summary:** Initializes a matrix/struct at output (a1) using SSE constants (xmmword_8D61B0/C0/D0) and result from EmptyStub_8bd0 called with input (a2). Writes pre-defined constants and computed shuffle/XOR results to various offsets, constructing a matrix or transform structure. Part of SSE math library.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output matrix row 0 (set from xmmword_8D61D0) |
| this | 0x10 | RW | — | Output field at +0x10 (partial write from v6 component) |
| this | 0x2C | RW | — | Output field at +0x2C (partial write from v6 component) |
| this | 0x30 | RW | — | Output matrix row 3 (set from v6 constant) |

**Written-by note (persistence):**
- this 0x0: written with xmmword_8D61D0 constant; persists as output
- this 0x10: written with first component of v6; persists as output
- this 0x2C: written with first component of v6; persists as output
- this 0x30: written with v6 __m128 constant; persists as output

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d61b0 | xmmword_8D61B0 | R | SSE constant for XOR operation on shuffle result |
| 008d61c0 | xmmword_8D61C0 | R | SSE constant used for partial matrix writes |
| 008d61d0 | xmmword_8D61D0 | R | SSE constant stored as first row of output matrix |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00528bd0 | EmptyStub_8bd0 | Returns __m128 result from input parameters; used as source for shuffle/XOR computation |

**Guard conditions:** No guard — always initializes matrix unconditionally.
