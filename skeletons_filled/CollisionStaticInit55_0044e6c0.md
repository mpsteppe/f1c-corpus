## CollisionStaticInit55_0044e6c0 — CollisionStaticInitBlockC

**Summary:** Initializes third collision block (dword_7CD064–7CD078). Sets tag to 85, zeros mapping/sound fields, sets threshold to 27000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd064 | dword_7CD064 | W | CollisionObjectMapping [DERIVED] |
| 007cd068 | dword_7CD068 | W | Zeroed collision state field |
| 007cd06c | dword_7CD06C | W | Zeroed collision state field |
| 007cd070 | dword_7CD070 | W | Zeroed collision state field |
| 007cd074 | dword_7CD074 | W | SoundBank_VolumeFL [DERIVED] |
| 007cd078 | dword_7CD078 | W | Flt_Threshold_CD078 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init, no branches.
