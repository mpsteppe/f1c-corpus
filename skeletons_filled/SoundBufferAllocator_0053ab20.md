## SoundBufferAllocator_0053ab20 — Sound buffer constructor

**Summary:** Initializes a sound buffer object. Stores size parameter, computes log2-based index via CRTFtol, allocates (8*size+16) byte buffer via OperatorNewNhMallocWrapper, zeroes counters, and calls CurveSplinePointGenerator for curve/spline setup. Constructor for sound/graphics buffer with logarithmic size indexing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListNodeAppend_89a0 (005489a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | size parameter (a2), stored as first field |
| this | 0x4 | RW | — | log2-based index, computed as CRTFtol(log2(a2) * 1.4427) |
| this | 0xC | RW | — | allocated buffer pointer (8*a2+16 bytes via OperatorNewNhMallocWrapper) |
| this | 0x10 | RW | 0 | counter/offset field, initialized to 0 |
| this | 0x14 | RW | 0 | counter/offset field, initialized to 0 |

**Written-by note (persistence):**
- this 0x0: written once by constructor
- this 0x4: written once by constructor
- this 0xC: written once by constructor (allocation)
- this 0x10: initialized to 0, modified by subsequent operations
- this 0x14: initialized to 0, modified by subsequent operations

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8908 | dbl_5B8908 | R | Unknown_dbl_5B8908 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053ab80 | CurveSplinePointGenerator | initialize curve/spline points for audio volume/pitch envelope |
| 00587bdc | CRTFtol | CRT _ftol (float-to-long) conversion for log2 index computation |
| 00587c03 | OperatorNewNhMallocWrapper | malloc wrapper allocating (8*a2+16) bytes for sample data |

**Guard conditions:** No branches. Always allocates buffer and initializes all fields unconditionally.
