## GlobalFieldReader_00495120 — ReadRenderDeviceFields

**Summary:** Reads two DWORD fields at offsets 0x1C and 0x20 from the render device struct (dword_8B8DC8) into caller-supplied output pointers. Provides viewport or render-surface dimension retrieval for the UI/render system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIScrollViewRender (00486ac0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | First output parameter (pointer to DWORD), receives render device field at +0x1C |

**Written-by note (persistence):**
- this 0x0: written unconditionally by dereference; caller owns buffer, no external persistence

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr (D3D device/renderer interface); source of renderer state fields |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — function executes unconditionally. No early return or check.
