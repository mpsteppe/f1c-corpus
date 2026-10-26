## ArithmeticComparison_c2a0_004bc2a0 — BoundedFloatArrayLookupAlt

**Summary:** Bounds-checked float array read using a different pointer field (this+0x90) compared to sub_4BC270; returns -1.0 if index is negative or >= either capacity bound. Uses two capacity fields at this+0x8 and this+0x88 as upper limits.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49BBB0 (0049bbb0), sub_4D24D0 (004d24d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | first capacity bound (max index) |
| this | 0x88 | R | — | second capacity bound (max index) |
| this | 0x90 | R | — | pointer to float array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** PASSES when a2 >= 0 AND a2 < this[2] AND a2 < this[34]; returns float at array[this+0x90][a2]. BLOCKED (returns -1.0) when index negative or >= either bound.
