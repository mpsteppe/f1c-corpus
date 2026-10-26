## sub_4DEF70_004def70 — PositionOffsetAndLRUInsert

**Summary:** Builds 9-float entry with position-offset vector from a3 relative to object's stored position (subtracted if flag at offset 0x42 set), computes magnitude of a4 as LOD/distance value, then inserts into sorted LRU array via SortedArrayInsertWithLRUEviction when magnitude positive. Spatial cache population.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RepeatedPositionOffsetTransform (004e3940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x4 | R | — | position X offset for coordinate subtraction |
| *(this+0x4) | 0x8 | R | — | position Y offset for coordinate subtraction |
| *(this+0x4) | 0xC | R | — | position Z offset for coordinate subtraction |
| *(this+0x4) | 0x42 | R | — | flag byte, when set enables position offset subtraction |
| this | 0x4 | R | — | pointer to sub-struct with position data |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dedb0 | SortedArrayInsertWithLRUEviction | insert 9-float entry into sorted LRU cache array |

**Guard conditions:** If magnitude (vector length of a4) > 0.0, insert; otherwise skip insertion.
