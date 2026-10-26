## CollisionSubsystemInit_d880_0044d880 — InitializeRenderStateID26

**Summary:** Sets RenderStateID_C38 to 26 and zeroes five adjacent render state fields. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccc38 | dword_7CCC38 | W | RenderStateID_C38 [DERIVED] |
| 007ccc3c | dword_7CCC3C | W | Render state field slot 2 (zeroed) |
| 007ccc40 | dword_7CCC40 | W | Render state field slot 3 (zeroed) |
| 007ccc44 | dword_7CCC44 | W | Render state field slot 4 (zeroed) |
| 007ccc48 | dword_7CCC48 | W | Render state field slot 5 (zeroed) |
| 007ccc4c | dword_7CCC4C | W | Render state field slot 6 (zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
