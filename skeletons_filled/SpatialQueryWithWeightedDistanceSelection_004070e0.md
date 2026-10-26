## SpatialQueryWithWeightedDistanceSelection_004070e0 — SpatialQueryBestCandidateByWeightedDistance

**Summary:** Queries an array of spatial entries to find the best candidate based on weighted distance comparison. Each 20-byte entry has an object pointer, LOD value (used as 2^LOD weight), and distance. Selects entry minimizing (2^LOD * inputDist^2) / (distance^2 * 2^a2).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MilesAudioSamplePlaybackSetup (00405900)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48 | R | — | pointer to array of 20-byte spatial entries |
| this | 0x4C | R | — | count of entries in the array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4C | <= | 0 | if count <= 0, returns 0 immediately |

**Guard interpretation:** When this[19] (offset 0x4C) <= 0, returns NULL immediately — no entries to query. Individual entries are also skipped if null or if filter parameter a4 is non-zero and vtable+28 returns 2.
