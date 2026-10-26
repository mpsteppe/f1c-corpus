## ShortComputation_4990_00464990 — Squared distance computation

**Summary:** Computes squared Euclidean distance between entity position (offsets +0x75, +0x79, +0x7D) and reference point a2[3384..3386]. Stores result in this[1].

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EntityVisibilityGridManager (00465460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x75 | R | — | Entity position X component |
| obj | 0x79 | R | — | Entity position Y component |
| obj | 0x7D | R | — | Entity position Z component |
| this | 0x0 | R | — | Pointer to entity (dereferenced to read position) |
| this | 0x4 | RW | — | Squared distance result stored here |

**Written-by note (persistence):**
- this 0x4: overwritten every call with new squared distance

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always computes and stores squared distance.
