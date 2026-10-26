## CollisionStaticInit18_0044d7c0 — InitializeRenderStateTable24

**Summary:** Sets RenderStateTable_7CCC08 to 24 and zeroes five adjacent render state table fields. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccc08 | dword_7CCC08 | W | RenderStateTable_7CCC08 [DERIVED] |
| 007ccc0c | dword_7CCC0C | W | Render state field slot 2 (zeroed) |
| 007ccc10 | dword_7CCC10 | W | Render state field slot 3 (zeroed) |
| 007ccc14 | dword_7CCC14 | W | Render state field slot 4 (zeroed) |
| 007ccc18 | dword_7CCC18 | W | Render state field slot 5 (zeroed) |
| 007ccc1c | dword_7CCC1C | W | Render state field slot 6 (zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
