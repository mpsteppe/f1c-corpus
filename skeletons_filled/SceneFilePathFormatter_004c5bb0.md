## SceneFilePathFormatter_004c5bb0 — Build formatted scene file path and compute result

**Summary:** Constructs a file path from the default directory, input path, and global suffix constants, then calls `UtilityFunction_8a60` with parameter `a3` to compute a result value. Returns the computed result or -1 on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TrackFilePathBuilder (004c51a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5d24 | dword_5C5D24 | R | SeasonRacesSuffix1 [DERIVED] |
| 005c5d28 | byte_5C5D28 | R | SeasonRacesSuffix2 [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00568a60 | UtilityFunction_8a60 | Compute result from constructed path suffix and parameter a3; returns 1 on success |
| 00587dd0 | sub_587DD0 | Copy and normalize path string into buffer with size limit |

**Guard conditions:** Returns -1 if `UtilityFunction_8a60(a3, &v7)` returns anything other than 1. Otherwise returns the computed integer result from `v7`.
