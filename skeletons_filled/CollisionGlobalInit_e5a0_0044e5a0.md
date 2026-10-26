## CollisionGlobalInit_e5a0_0044e5a0 — CollisionGlobalsInitBlockA

**Summary:** Initializes first block of collision system globals (dword_7CC9FC–7CCA10). Sets system block tag to 82, zeros state fields and grid data pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cc9fc | dword_7CC9FC | W | CollisionSystemData [DERIVED] |
| 007cca00 | dword_7CCA00 | W | Zeroed collision state field |
| 007cca04 | dword_7CCA04 | W | Zeroed collision state field |
| 007cca08 | dword_7CCA08 | W | Zeroed collision state field |
| 007cca0c | dword_7CCA0C | W | AudioMixThreshold [DERIVED] |
| 007cca10 | dword_7CCA10 | W | CollisionGridData [DERIVED] (also: ` — collision system data block) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init, no branches.
