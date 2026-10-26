## CollisionGridInit16x16_0044d4c0 — InitializeCollisionGrid16x16

**Summary:** Sets collision grid size to 16 and zeroes five related state/parameter variables (SpatialGridState, CollisionGridParam, AudioState2Block, CollisionGridZeroBlock, CollisionGridState1). Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cccd8 | dword_7CCCD8 | W | CollisionGridSize [DERIVED] (also: ` — grid size (16) |
| 007cccdc | dword_7CCCDC | W | SpatialGridState [DERIVED] |
| 007ccce0 | dword_7CCCE0 | W | CollisionGridParam [DERIVED] |
| 007ccce4 | dword_7CCCE4 | W | AudioState2Block [DERIVED] |
| 007ccce8 | dword_7CCCE8 | W | CollisionGridZeroBlock [DERIVED] |
| 007cccec | dword_7CCCEC | W | CollisionGridState1 [DERIVED] (also: ` — grid state (zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
