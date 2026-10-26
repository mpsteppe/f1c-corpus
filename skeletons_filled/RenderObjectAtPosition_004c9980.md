## RenderObjectAtPosition_004c9980 — RenderObjectSetTransform

**Summary:** Sets the world transform/position on a render object by calling its vtable method (offset 4) with position data from this+0x8 and a DSP transform parameter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x4 | R | — | vtable entry at offset 4 (second method); called to set render position/transform |
| this | 0x1C | R | — | Pointer to a render object whose position is being updated |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cf2cc | flt_7CF2CC | R | DSPTransformParam [DERIVED] (also: ` — DSP transform parameter) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks `this[7]` (this+0x1C) for non-null. If null, returns 0 without action.
