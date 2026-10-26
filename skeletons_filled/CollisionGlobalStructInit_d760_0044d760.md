## CollisionGlobalStructInit_d760_0044d760 — InitializeCollisionConfigBlock23

**Summary:** Sets first CollisionConfigBlock element to 23 and zeroes five adjacent collision configuration fields. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccc20 | dword_7CCC20 | W | CollisionConfigBlock [DERIVED] (also: ` through `_DAT_007ccc34` — collision configuration variables) |
| 007ccc24 | dword_7CCC24 | W | Config field slot 2 (zeroed) |
| 007ccc28 | dword_7CCC28 | W | Config field slot 3 (zeroed) |
| 007ccc2c | dword_7CCC2C | W | Config field slot 4 (zeroed) |
| 007ccc30 | dword_7CCC30 | W | Config field slot 5 (zeroed) |
| 007ccc34 | dword_7CCC34 | W | CollisionConfigVar2 [DERIVED] (also: ` — collision configuration variables) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
