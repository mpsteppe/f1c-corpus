## InitializeCollisionGlobalsA_0044d8e0 — InitializeRenderStatePtr27

**Summary:** Sets RenderStatePtr_CDE0 to 27 and zeroes five adjacent render state pointer/field slots. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccde0 | dword_7CCDE0 | W | RenderStatePtr_CDE0 [DERIVED] |
| 007ccde4 | dword_7CCDE4 | W | Render state ptr field slot 2 (zeroed) |
| 007ccde8 | dword_7CCDE8 | W | Render state ptr field slot 3 (zeroed) |
| 007ccdec | dword_7CCDEC | W | Render state ptr field slot 4 (zeroed) |
| 007ccdf0 | dword_7CCDF0 | W | Render state ptr field slot 5 (zeroed) |
| 007ccdf4 | dword_7CCDF4 | W | Render state ptr field slot 6 (zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
