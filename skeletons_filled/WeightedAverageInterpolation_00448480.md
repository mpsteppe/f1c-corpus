## WeightedAverageInterpolation_00448480 — WeightedAverage

**Summary:** Computes element-wise average (midpoint) of two input structures containing float + double + float fields, writing results into output structure. Used in collision and mesh subdivision code.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TriangleMeshAdjacencyBuilder (004493a0), CollisionContactResponse (00449700), RecursiveTriangleEdgeSubdivisionForCollision (0044aae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | output float: average of inputs' float at offset 0 |
| this | 0x4 | RW | — | output double: average of inputs' double at offset 4 |
| this | 0xC | RW | — | output float: average of inputs' float at offset 12 |

**Written-by note (persistence):**
- this 0x0: overwritten every call; external poke survives (not re-read)
- this 0x4: overwritten every call; external poke survives
- this 0xC: overwritten every call; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard. Unconditional element-wise average of two input pointers (a2, a3) into output (this).
