## SSEMatrixConstructionFrom44Data_005208fe — SSEMatrix44FromData

**Summary:** Constructs a 4x4 matrix (4 rows at 0, 0x10, 0x20, 0x30) at output (a1) from input (a2) via EmptyStub_8bd0. Applies AND/shuffle operations with SSE constants (xmmword_8D61E0/F0/200/210) to compute row data, XOR for sign adjustment, and stores pre-defined constants for remaining rows. Part of SSE math library.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output matrix row 0 (computed from EmptyStub result with AND/XOR) |
| this | 0x10 | RW | — | Output matrix row 1 (set from xmmword_8D61F0 constant) |
| this | 0x20 | RW | — | Output matrix row 2 (shuffled from AND result) |
| this | 0x30 | RW | — | Output matrix row 3 (set from xmmword_8D61E0 constant) |

**Written-by note (persistence):**
- this 0x0: written with computed row 0; persists as output
- this 0x10: written with xmmword_8D61F0 constant; persists as output
- this 0x20: written with shuffled row 2; persists as output
- this 0x30: written with xmmword_8D61E0 constant; persists as output

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d61e0 | xmmword_8D61E0 | R | SSE constant stored as matrix row 3 |
| 008d61f0 | xmmword_8D61F0 | R | SSE constant stored as matrix row 1 |
| 008d6200 | xmmword_8D6200 | R | SSE constant for XOR operation on row 0 |
| 008d6210 | xmmword_8D6210 | R | SSE constant for AND mask on EmptyStub result |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00528bd0 | EmptyStub_8bd0 | Returns __m128 result from input parameters; used as source for AND/shuffle/XOR row computation |

**Guard conditions:** No guard — always constructs matrix unconditionally.
