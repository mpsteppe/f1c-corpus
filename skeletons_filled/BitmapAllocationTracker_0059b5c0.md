## BitmapAllocationTracker_0059b5c0 — AllocateBitmapRange

**Summary:** Allocates a range of `a2` units in a bitmap tracker: clears bits (marks used) in underlying bitmap, records allocation in element array with cumulative counter, returns slot index via `*a3`.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SEHProtectedDirectXRenderStateSetup (00586700)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Bitmap byte array pointer (bits mark allocation state) |
| this | 0x8 | R | — | Element array pointer (records each allocation: cumulative_count, size) |
| this | 0x10 | RW | — | Cumulative allocated-unit counter (incremented by a2) |
| this | 0x14 | RW | — | Element index / count of allocations (incremented by 1) |

**Written-by note (persistence):**
- this 0x10: incremented by a2 every call
- this 0x14: incremented by 1 every call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059b490 | sub_59B490 | Grow bitmap buffer if new range exceeds 8x current capacity |
| 0059b530 | GrowDynamicElementArray | Grow element array if current count+1 exceeds capacity |

**Guard conditions:** No early returns; both growth helpers are called unconditionally (their failure return is ignored). Allocation always succeeds from caller's perspective (returns 1).
