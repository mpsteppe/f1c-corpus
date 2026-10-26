## GuardedConditionalRenderCall_00486f00 — GuardedConditionalRenderDispatch

**Summary:** If enable flag a2 is set and sub-renderer at this+0x98 exists, dispatches rectangle render via GuardedSubRectangleRenderDispatch using bounds at offsets 4/8/C/10. Part of UI conditional rendering system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | left bound of rectangle to render |
| this | 0x8 | R | — | right bound of rectangle to render |
| this | 0xC | R | — | top bound of rectangle to render |
| this | 0x10 | R | — | bottom bound of rectangle to render |
| this | 0x98 | R | — | pointer to sub-renderer object (null when no texture/delegate) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00499050 | GuardedSubRectangleRenderDispatch | dispatch rectangle render to sub-renderer |

**Guard conditions:** 1) If a2 (enable flag) is zero → skip render entirely (return this). 2) If this[38] (sub-renderer at offset 0x98) is null → skip render (return this). Both must be non-zero for render dispatch.
