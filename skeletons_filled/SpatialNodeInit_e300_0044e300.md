## SpatialNodeInit_e300_0044e300 — init spatial node type 75

**Summary:** Initializes a spatial collision node with element count 75, zeroes three fields, and sets max search distance to 9000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd0b0 | dword_7CD0B0 | W | CollisionNodeElementCount [DERIVED] (also: ` — node element count) |
| 007cd0b4 | dword_7CD0B4 | W | unknown — zeroed node field |
| 007cd0b8 | dword_7CD0B8 | W | unknown — zeroed node field |
| 007cd0bc | dword_7CD0BC | W | unknown — zeroed node field |
| 007cd0c0 | dword_7CD0C0 | W | CollisionMaterialConfig [DERIVED] |
| 007cd0c4 | dword_7CD0C4 | W | CollisionMaxSearchDist [DERIVED] (also: ` — max search distance (9000) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — function always executes all writes unconditionally
