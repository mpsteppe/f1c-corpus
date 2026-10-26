## CollisionGlobalInit_d700_0044d700 — InitializeCollisionGlobals22

**Summary:** Sets CollisionCountInit to 22 and zeroes five adjacent collision global fields (CollisionGlobalsInitBlock, three unnamed slots, CollisionZeroField). Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccc98 | dword_7CCC98 | W | CollisionCountInit [DERIVED] (also: ` — collision global, int count = 0x16) |
| 007ccc9c | dword_7CCC9C | W | CollisionGlobalsInitBlock [DERIVED] |
| 007ccca0 | dword_7CCCA0 | W | Collision global field slot 3 (zeroed) |
| 007ccca4 | dword_7CCCA4 | W | Collision global field slot 4 (zeroed) |
| 007ccca8 | dword_7CCCA8 | W | Collision global field slot 5 (zeroed) |
| 007cccac | dword_7CCCAC | W | CollisionZeroField [DERIVED] (also: ` — collision globals, zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
