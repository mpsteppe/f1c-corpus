## UtilityFunction_9160_004f9160 — ParticleIndexSetter

**Summary:** Sets the current particle array index (dword_8AFE6C) and stores the corresponding value (dword_8AFE68) when the requested index is within valid range retrieved from dword_8AFE64.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Setup (0042d5d0), MultiTableCoordinateSearch (004f9240), VidMan_Enter (004fa000)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe68 | dword_8AFE68 | W | ParticleLifeValue [DERIVED] (also: ` — value at that index) |
| 008afe6c | dword_8AFE6C | W | ParticleArrayCurrentIndex [DERIVED] (also: ` — current index) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0055bfc0 | SimpleFieldGetter_bfc0 | Gets upper bound/limit from dword_8AFE64 |
| 0055bfd0 | BoundedArrayAccessor_bfd0 | Reads value from array at given index |

**Guard conditions:** `a1 < result` — PASSES if requested index < array bound (set index and value), BLOCKED if out of range.
