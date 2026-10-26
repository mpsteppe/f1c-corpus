## ScrollOffsetUpdateWithConditionalDispatch_0049acc0 — ScrollOffsetUpdateWithConditionalRenderDispatch

**Summary:** Applies scroll offsets (a2, a3) to four scroll/position fields with overflow-aware clamping, conditionally dispatches a render surface fill copy if the scroll flag at 0x40 is set, then unconditionally accumulates raw offsets into the fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4992E0 (004992e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | Scroll offset top/Y |
| this | 0x8 | RW | — | Scroll offset bottom |
| this | 0xC | RW | — | Scroll offset left/X |
| this | 0x10 | RW | — | Scroll offset right |
| this | 0x40 | R | — | Render surface fill dispatch flag |

**Written-by note (persistence):**
- this 0x4: updated every call with a3; external poke overwritten
- this 0x8: updated every call with a3; external poke overwritten
- this 0xC: updated every call with a2; external poke overwritten
- this 0x10: updated every call with a2; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490920 | Accessor | Retrieves render surface pointer for fill copy |
| 004918d0 | RenderSurfaceFillCopy | Fills render surface region with current scroll bounds |

**Guard conditions:** this[0x40] (field at offset 0x40) nonzero → PASSES to render dispatch (Accessor + RenderSurfaceFillCopy). Zero → BLOCKED, skips render call. Scroll offset accumulation always executes regardless.
