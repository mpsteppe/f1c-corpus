## LightFrustumClosestPoint_0040e480 — LightFrustumClosestPoint

**Summary:** Computes bounding box, calculates center point and radius. Then performs a 5x5x5 grid search (125 sample points) across the bounding box volume, finding the point with minimum distance to the nearest element in a packed array. Returns closest point in a2 and radius in *a3.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StructSetupWithTwoCalls (0040e8b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | output closest point X, updated during search |
| this | 0x4 | RW | — | output closest point Y, updated during search |
| this | 0x8 | RW | — | output closest point Z, updated during search |

**Written-by note (persistence):**
- this 0x0: written with final closest X position
- this 0x4: written with final closest Y position
- this 0x8: written with final closest Z position

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e6ec | flt_59E6EC | R | ShortIntToWorldScale [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dd550 | BoundingBoxComputation | compute bounding box min/max from global data |
| 0054c230 | LinkedListIndexedAccessor_c230 | get linked list by index 0 |
| 0054e100 | PackedArrayTotalSize | get total element count in packed array |
| 0054e120 | PackedArrayIndexLookup | get element at index from packed array |

**Guard conditions:** packed array size <= 0 → skip inner loop (no elements to compare)
