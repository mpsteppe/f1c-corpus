## SpatialNodeInit_db80_0044db80 — InitializeCollisionNodeElements47

**Summary:** Sets CollisionNodeElements to 47 and zeroes five adjacent node element fields. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccee8 | dword_7CCEE8 | W | CollisionNodeElements [DERIVED] (also: ` — node element count) |
| 007cceec | dword_7CCEEC | W | Node element field slot 2 (zeroed) |
| 007ccef0 | dword_7CCEF0 | W | Node element field slot 3 (zeroed) |
| 007ccef4 | dword_7CCEF4 | W | Node element field slot 4 (zeroed) |
| 007ccef8 | dword_7CCEF8 | W | Node element field slot 5 (zeroed) |
| 007ccefc | dword_7CCEFC | W | Node element field slot 6 (zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
