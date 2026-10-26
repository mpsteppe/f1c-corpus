## CollisionMaterialCoefficientsSet1_0044d5e0 — InitializeCollisionMaterialCoefficientsSet1

**Summary:** Sets first material ID to 19 and zeroes five adjacent material coefficient/parameter fields (CollisionMaterialCoeff_group, and four unnamed coefficient slots). Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccc80 | dword_7CCC80 | W | CollisionMaterialID_19 [DERIVED] |
| 007ccc84 | dword_7CCC84 | W | CollisionMaterialCoeff_group [DERIVED] |
| 007ccc88 | dword_7CCC88 | W | Material coefficient slot 2 (zeroed) |
| 007ccc8c | dword_7CCC8C | W | Material coefficient slot 3 (zeroed) |
| 007ccc90 | dword_7CCC90 | W | Material coefficient slot 4 (zeroed) |
| 007ccc94 | dword_7CCC94 | W | Material coefficient slot 5 (zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
