## CollisionRegionInit1_0044d580 — InitializeCollisionRegionType18

**Summary:** Sets collision region type to 18 and zeroes five region parameter/configuration fields (CollisionRegionParams, CollisionGridField, CollisionConfigField3, VideoMode_Index_2). Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccd08 | dword_7CCD08 | W | CollisionRegionType [DERIVED] (also: ` — region type (18) |
| 007ccd0c | dword_7CCD0C | W | CollisionRegionParams [DERIVED] (also: ` through `DAT_007ccd1c` — region parameters) |
| 007ccd10 | dword_7CCD10 | W | CollisionGridField [DERIVED] |
| 007ccd14 | dword_7CCD14 | W | CollisionConfigField3 [DERIVED] |
| 007ccd18 | dword_7CCD18 | W | VideoMode_Index_2 [DERIVED] |
| 007ccd1c | dword_7CCD1C | W | CollisionRegionParams [DERIVED] (also: ` — region parameters) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
