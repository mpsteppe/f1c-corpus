## CollisionBroadphaseReset_ea20_0044ea20 — CollisionInitBlockL

**Summary:** Initializes twelfth collision block (dword_7CA4B8–7CA4CC). Sets tag to 94, zeros bucket index/state and control threshold fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca4b8 | dword_7CA4B8 | W | CollisionBucketIndex [DERIVED] (also: ` — collision bucket/cell index (0x5e) |
| 007ca4bc | dword_7CA4BC | W | CollisionBucketState [DERIVED] (also: ` through `DAT_007ca4cc` — collision bucket state (zeroed) |
| 007ca4c0 | dword_7CA4C0 | W | Zeroed collision bucket state field |
| 007ca4c4 | dword_7CA4C4 | W | Zeroed collision bucket state field |
| 007ca4c8 | dword_7CA4C8 | W | ControlThresholdStore [DERIVED] |
| 007ca4cc | dword_7CA4CC | W | CollisionBucketState [DERIVED] (also: ` — collision bucket state (zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init, no branches.
