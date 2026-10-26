## ShortComputation_ec40_0049ec40 — Resource handle cleanup at offset 0

**Summary:** Releases a resource handle stored at this[0] via ResourceCascadeCleanup and clears it to 0. Called before re-render to clean up stale resources.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiStageCleanupWithRepeatedCallCycle (0049d150), F_2DRectangleRender (0049ea10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | resource handle pointer (cleared after cleanup) |

**Written-by note (persistence):**
- this 0x0: set to 0 after cleanup each call. If external pokers write here, value is lost on next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005539f0 | ResourceCascadeCleanup | cascade cleanup/release of resource handle |

**Guard conditions:** Checks *this (offset 0) non-null — skips cleanup if already null.
