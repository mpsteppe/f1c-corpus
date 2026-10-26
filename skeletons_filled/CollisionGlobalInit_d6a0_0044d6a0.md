## CollisionGlobalInit_d6a0_0044d6a0 — InitializeCollisionSystemDataBlock21

**Summary:** Sets first CollisionSystemDataBlock element to 21 and zeroes five adjacent data block fields (including CollisionDataBlock at the end). Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cccc0 | dword_7CCCC0 | W | CollisionSystemDataBlock [DERIVED] |
| 007cccc4 | dword_7CCCC4 | W | Data block field slot 2 (zeroed) |
| 007cccc8 | dword_7CCCC8 | W | Data block field slot 3 (zeroed) |
| 007ccccc | dword_7CCCCC | W | Data block field slot 4 (zeroed) |
| 007cccd0 | dword_7CCCD0 | W | Data block field slot 5 (zeroed) |
| 007cccd4 | dword_7CCCD4 | W | CollisionDataBlock [DERIVED] (also: ` — collision system data block) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
