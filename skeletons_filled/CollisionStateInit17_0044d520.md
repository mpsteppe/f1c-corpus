## CollisionStateInit17_0044d520 — InitializeCollisionStateBlock17

**Summary:** Sets collision state block type to 17 (0x11) and zeroes five related fields (CollisionCellOffsetY, Dword_Unknown_Render, CollisionGridInitZero, CollisionInitBlock, CollisionGridInitZero2). Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccd20 | dword_7CCD20 | W | CollisionStateBlock11 [DERIVED] (also: ` — collision state block (type=0x11) |
| 007ccd24 | dword_7CCD24 | W | CollisionCellOffsetY [DERIVED] |
| 007ccd28 | dword_7CCD28 | W | Dword_Unknown_Render [DERIVED] |
| 007ccd2c | dword_7CCD2C | W | CollisionGridInitZero [DERIVED] |
| 007ccd30 | dword_7CCD30 | W | CollisionInitBlock [DERIVED] |
| 007ccd34 | dword_7CCD34 | W | CollisionGridInitZero2 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
