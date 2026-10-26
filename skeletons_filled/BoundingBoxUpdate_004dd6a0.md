## BoundingBoxUpdate_004dd6a0 — MergeBoxIntoMinMaxBounds

**Summary:** Computes bounding box from object via BoundingBoxComputation and position offset via TripleFieldQuery, then merges result into existing min (a2) and max (a3) extents. Scene bounding volume update for graphics.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleGraphicsSceneLoader (004dfce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | object position/extent X, read by BoundingBoxComputation |
| this | 0x4 | RW | — | object position/extent Y, read by BoundingBoxComputation |
| this | 0x8 | RW | — | object position/extent Z, read by BoundingBoxComputation |

**Written-by note (persistence):**
- this 0x0: not written by this function; external poke survives
- this 0x4: not written by this function; external poke survives
- this 0x8: not written by this function; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dd550 | BoundingBoxComputation | compute min/max bounding box extents from object data |
| 0054b420 | TripleFieldQuery | query 3-float position offset value |

**Guard conditions:** None — function body always executes fully, no early return or skip.
