## EmptyStub_004579c0 — VectorAddSquaredLength3D

**Summary:** Computes squared Euclidean distance between two 3D vectors (element-wise sum of this[31..33] and a2[0..2], then sum of squares).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MinimumDistanceSearch (0040acd0), ShortComputation_b630 (0040b630)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x7C | R | — | element [31] — X component of first vector |
| this | 0x80 | R | — | element [32] — Y component of first vector |
| this | 0x84 | R | — | element [33] — Z component of first vector |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none (pure computation, no branches).
