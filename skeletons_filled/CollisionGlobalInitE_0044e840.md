## CollisionGlobalInitE_0044e840 — CollisionInitBlockG

**Summary:** Initializes seventh collision block (dword_7CD01C–7CD030). Sets tag to 89, zeros object index/data fields, sets collision limit to 27000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd01c | dword_7CD01C | W | CollisionObjectIndex [DERIVED] (also: ` — collision object index/type) |
| 007cd020 | dword_7CD020 | W | ZeroedField_1 [DERIVED] (also: ` through `DAT_007cd02c` — 4 zeroed fields) |
| 007cd024 | dword_7CD024 | W | Zeroed collision state field |
| 007cd028 | dword_7CD028 | W | Zeroed collision state field |
| 007cd02c | dword_7CD02C | W | CollisionDataBlock [DERIVED] (also: ` — 4 zeroed fields) |
| 007cd030 | dword_7CD030 | W | CollisionLimit [DERIVED] (also: ` — collision limit (set to 27000) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init, no branches.
