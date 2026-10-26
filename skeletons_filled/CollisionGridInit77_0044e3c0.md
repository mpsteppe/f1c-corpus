## CollisionGridInit77_0044e3c0 — init 77-wide spatial grid

**Summary:** Initializes a spatial collision grid with dimension 77, zeroes three grid state fields, and sets max distance to 27000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd130 | dword_7CD130 | W | SpatialGridDimension [DERIVED] (also: ` — grid size (77) |
| 007cd134 | dword_7CD134 | W | CollisionGridState2 [DERIVED] |
| 007cd138 | dword_7CD138 | W | unknown — zeroed grid field |
| 007cd13c | dword_7CD13C | W | unknown — zeroed grid field |
| 007cd140 | dword_7CD140 | W | CollisionGridState [DERIVED] (also: ` — grid state (zeroed) |
| 007cd144 | dword_7CD144 | W | CollisionMaxDistance [DERIVED] (also: ` — max distance (27000) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — function always executes all writes unconditionally
