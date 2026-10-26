## CollisionBroadphaseReset_db20_0044db20 — InitializeCollisionBucketIndex46

**Summary:** Sets CollisionBucketIndex to 46 (0x2e) and zeroes five adjacent collision bucket state fields. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccf00 | dword_7CCF00 | W | CollisionBucketIndex (0x2e) [DERIVED] |
| 007ccf04 | dword_7CCF04 | W | CollisionBucketState2 [DERIVED] (also: ` through `_DAT_007ccf14` — collision bucket state (zeroed) |
| 007ccf08 | dword_7CCF08 | W | Bucket state field slot 3 (zeroed) |
| 007ccf0c | dword_7CCF0C | W | Bucket state field slot 4 (zeroed) |
| 007ccf10 | dword_7CCF10 | W | Bucket state field slot 5 (zeroed) |
| 007ccf14 | dword_7CCF14 | W | CollisionBucketState [DERIVED] (also: ` — collision bucket state (zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
