## CollisionMaterialInit_da60_0044da60 — InitializeMaterialStrideAndProperties

**Summary:** Sets MaterialStride to 44 (0x2c) and zeroes five adjacent material property fields. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cced0 | dword_7CCED0 | W | MaterialStride [DERIVED] (also: ` — material stride (0x2c = 44 bytes per material entry) |
| 007cced4 | dword_7CCED4 | W | CollisionMaterialPropertyBlock [DERIVED] (also: ` through `DAT_007ccee4` — material property fields (zeroed) |
| 007cced8 | dword_7CCED8 | W | Material property field slot 3 (zeroed) |
| 007ccedc | dword_7CCEDC | W | Material property field slot 4 (zeroed) |
| 007ccee0 | dword_7CCEE0 | W | Material property field slot 5 (zeroed) |
| 007ccee4 | dword_7CCEE4 | W | CollisionMatPropZero [DERIVED] (also: ` — material property fields (zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
