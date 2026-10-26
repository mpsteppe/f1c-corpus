## SpatialNodeInit_d400_0044d400 — InitializeSpatialGridNodeGlobals

**Summary:** Initializes six spatial/grid globals: sets GridNodeElementCount to 14 and zeroes five other state fields (VideoMode_Index, CollisionZeroState, UnknownZeroedState, CollisionInitZeroed, CollisionInit6). Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccd38 | dword_7CCD38 | W | GridNodeElementCount [DERIVED] |
| 007ccd3c | dword_7CCD3C | W | VideoMode_Index [DERIVED] |
| 007ccd40 | dword_7CCD40 | W | CollisionZeroState [DERIVED] |
| 007ccd44 | dword_7CCD44 | W | UnknownZeroedState [DERIVED] |
| 007ccd48 | dword_7CCD48 | W | CollisionInitZeroed [DERIVED] |
| 007ccd4c | dword_7CCD4C | W | CollisionInit6 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
