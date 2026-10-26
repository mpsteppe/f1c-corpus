## CollisionGlobalInit_d100_0044d100 — CollisionGlobalCount107Init

**Summary:** Initializes four collision globals: count field to 107, -1.0f sentinel, and two float fields to 0.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccf60 | dword_7CCF60 | W | CollisionGlobalCount107 [DERIVED] (also: ` — collision global, int = 0x6b) |
| 007ccf64 | flt_7CCF64 | W | Flt_Threshold_CF64 [DERIVED] |
| 007ccf68 | dword_7CCF68 | W | CollisionNegOne [DERIVED] (also: ` — collision global, float = -1.0f) |
| 007ccf6c | flt_7CCF6C | W | UIColorBias_CCF6C [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional writes to all four globals.
