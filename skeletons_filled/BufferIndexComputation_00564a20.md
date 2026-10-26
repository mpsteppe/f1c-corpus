## BufferIndexComputation_00564a20 — buffer element search with binary/linear dispatch

**Summary:** Searches buffer for element matching key, returns index via (ptr - base) / stride. Two paths: binary search (arg4 true) or linear stride search (arg4 false). Early exit on null pointer or empty buffer. Audio buffer management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FunctionPointerCallWithErrorHandling (00564780), CallbackCheck (005647d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | element count or array size |
| this | 0x8 | R | — | element stride size |
| this | 0x14 | R | — | buffer base pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005648b0 | LinearInterpolation | computes start offset into buffer |
| 00564ab0 | CallbackBasedArrayStrideSearch | linear search over array elements |
| 00564b10 | BinarySearchWithCallbackComparator | binary search using comparator callback |

**Guard conditions:** Returns -1 if `this == NULL` or `*this == 0` (empty). Then dispatch on a4: if true → binary search; if false → linear stride search. Final result validated: only succeeds if `v6 != NULL && v12 != 0`.
