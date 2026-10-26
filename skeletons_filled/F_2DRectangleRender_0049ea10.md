## F_2DRectangleRender_0049ea10 — 2D textured quad render

**Summary:** Renders a 2D textured rectangle (quad) with computed UV coordinates. Stores rectangle parameters as floats, computes UV scale from texture dimensions, and renders 4 vertices with sub_553650.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49CD80 (0049cd80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x8)+0x54) | 0x1C | R | — | sub-sub-struct field read (via nested deref) |
| *(*(this+0x8)+0x54) | 0x20 | R | — | sub-sub-struct field read (via nested deref) |
| *(this+0x8) | 0x54 | R | — | sub-struct pointer from render data |
| this | 0x8 | R | — | render data pointer |
| this | 0x24 | RW | — | stored float param X (converted from a2) |
| this | 0x28 | RW | — | stored param Y (a3) |
| this | 0x2C | RW | — | stored float param Width (from a4) |
| this | 0x30 | RW | — | stored float param Height (from a5) |
| this | 0x34 | RW | — | computed U scale (Width / textureWidth) |
| this | 0x38 | RW | — | computed V scale (Height / textureHeight) |

**Written-by note (persistence):**
- this 0x24-0x38: written every call when ObjectConstructor returns 0. Persists between calls but overwritten each frame.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049ec40 | ShortComputation_ec40 | short computation (pre-render update) |
| 00553650 | sub_553650 | sets vertex with UV and color for quad |
| 00553980 | ObjectConstructorWithAllocationAndSubInit | object allocation/init (returns 0 on failure/skip) |

**Guard conditions:** Checks `*(this+8)` non-null — blocks entirely if null. Calls ObjectConstructorWithAllocationAndSubInit — if it returns non-zero (success), skips quad rendering and returns early.
