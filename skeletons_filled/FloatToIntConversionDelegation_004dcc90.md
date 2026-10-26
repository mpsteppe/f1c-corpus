## FloatToIntConversionDelegation_004dcc90 — Convert proportional float coordinates to screen-space integers

**Summary:** Converts relative/proportional float parameters (a4-a8) to integer screen-space coordinates using screen dimensions (dword_5D6D60, dword_5D6D64) and delegates to sub_4DCBA0 for texture/object initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UtilityFunction_cfb0 (004dcfb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d6d60 | dword_5D6D60 | R | ScreenWidth [DERIVED] |
| 005d6d64 | dword_5D6D64 | R | ScreenHeight (labeled ScreenWidth in IDB; input device parameter) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dcba0 | sub_4DCBA0 | Initialize texture/object with computed screen-space integer coordinates |
| 00587bdc | CRTFtol | Convert double to long (float-to-int conversion) |

**Guard conditions:** None — function executes unconditionally.
