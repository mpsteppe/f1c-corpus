## CollisionGlobalsInit1_0044d9a0 — InitializeCollisionParam42

**Summary:** Sets CollisionParam42 to 42 and zeroes five adjacent collision counter/parameter fields. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccf30 | dword_7CCF30 | W | CollisionParam42 [DERIVED] (also: ` — collision init value (42) |
| 007ccf34 | dword_7CCF34 | W | CollisionCounterBlock [DERIVED] (also: 44` — collision counters zeroed) |
| 007ccf38 | dword_7CCF38 | W | Collision counter field slot 3 (zeroed) |
| 007ccf3c | dword_7CCF3C | W | Collision counter field slot 4 (zeroed) |
| 007ccf40 | dword_7CCF40 | W | Collision counter field slot 5 (zeroed) |
| 007ccf44 | dword_7CCF44 | W | Collision counter field slot 6 (zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
