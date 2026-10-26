## MemoryAllocation_53ec_005053ec — Interpolation coordinate table allocator

**Summary:** Allocates and fills an interpolation coordinate table (16 bytes × count) for texture resampling. Computes fractional source coordinates from dest coordinate with sub_5895A2, storing adjacent source indices and blend weights for bilinear interpolation. Handles edge clamp/wrap modes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5054EC (005054ec), VertexBufferAllocationAndStageTransformation (005058d2)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] — float used in sub_5895A2 (possibly fractional part or trig) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] — conversion factor used in sub_5895A2 |
| 005adb14 | flt_5ADB14 | R | DegreeWrap360 [DERIVED] — 360.0 constant for degree wrapping |
| 008b0098 | dword_8B0098 | RW | SineLookupWorkspace [DERIVED] — temporary storage for sub_5895A2 computation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | allocates 16 × a1 bytes for coordinate table |
| 005895a2 | sub_5895A2 | computes fractional interpolation value from coordinate (likely sine-based or fractional part) |

**Guard conditions:** If allocation returns NULL → returns NULL immediately. PASS: fills table with {src_idx0, src_idx1, weight, 1.0-weight} per entry, handling edge clamp/wrap based on a3 parameter.
