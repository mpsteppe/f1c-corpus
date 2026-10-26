## CollisionRegionInit4_0044ec00 — CollisionInitBlockQ

**Summary:** Initializes seventeenth collision block (dword_7CA3F8–7CA40C). Sets tag to 99, zeros region/render fields, sets region threshold to 9000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca3f8 | dword_7CA3F8 | W | CollisionShape_63 [DERIVED] (also: ` — region type (99) |
| 007ca3fc | dword_7CA3FC | W | Zeroed region field |
| 007ca400 | dword_7CA400 | W | Zeroed region field |
| 007ca404 | dword_7CA404 | W | Zeroed region field |
| 007ca408 | dword_7CA408 | W | RenderStateIntPair [DERIVED] |
| 007ca40c | dword_7CA40C | W | RegionThreshold [DERIVED] (also: ` — region threshold (9000) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init, no branches.
