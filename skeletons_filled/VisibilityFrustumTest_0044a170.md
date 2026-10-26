## VisibilityFrustumTest_0044a170 — View-space vertex coverage and overlap metric

**Summary:** Computes a 1D coverage/overlap metric between two vertex batches (stride 16 bytes). Tracks min/max extents of each batch, counts vertices that extend beyond the overlap region, and computes a normalized coverage score. Optionally links vertices into a chain when the update flag is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_44A2D0 (0044a2d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0.0 | Accumulated linked-list traversal value (y-coordinate from vertices) |
| this | 0x4 | RW | FLT_MAX | Min bound for first vertex batch (z/w axis) |
| this | 0x8 | RW | -FLT_MAX | Max bound for first vertex batch (z/w axis) |
| this | 0xC | RW | 0.0 | Linked-list traversal pointer/accumulator for second batch |
| this | 0x10 | RW | FLT_MAX | Min bound for second vertex batch |
| this | 0x14 | RW | -FLT_MAX | Max bound for second vertex batch |
| this | 0x18 | RW | FLT_MAX | Final coverage/overlap metric (normalized score + out-of-bounds ratio) |

**Written-by note (persistence):**
- All fields: Written each call, no external persistence expected

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a3 (first batch count) > 0 → process first batch. If a5 (linked-list flag) is set, link vertices into chain. v5 (a3) < a4 (second batch count) → process remaining vertices. Second pass over a3 vertices counts out-of-bounds entries.
