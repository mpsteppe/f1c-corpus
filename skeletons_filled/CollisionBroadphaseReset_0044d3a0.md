## CollisionBroadphaseReset_0044d3a0 — ResetCollisionBroadphaseGlobals

**Summary:** Initializes collision broadphase globals: sets bucket/cell index to 13 (0xd) and zeroes five collision bucket state/configuration fields. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccd50 | dword_7CCD50 | W | CollisionShape_13 [DERIVED] (also: ` — collision bucket/cell index (0xd) |
| 007ccd54 | dword_7CCD54 | W | CollisionBucketState [DERIVED] (also: ` through `_DAT_007ccd64` — collision bucket state (zeroed) |
| 007ccd58 | dword_7CCD58 | W | CollisionGridInitZero [DERIVED] |
| 007ccd5c | dword_7CCD5C | W | CollisionGridZeroField [DERIVED] |
| 007ccd60 | dword_7CCD60 | W | CollisionConfigField5 [DERIVED] |
| 007ccd64 | dword_7CCD64 | W | CollisionBucketState [DERIVED] (also: ` — collision bucket state (zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
