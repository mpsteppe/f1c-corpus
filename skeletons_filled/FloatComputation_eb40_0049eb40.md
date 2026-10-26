## FloatComputation_eb40_0049eb40 — Float computation / secondary quad render

**Summary:** Renders a second 2D textured quad using audio node (this+0xC) as resource. Calls SingleFieldFreeWrapper then renders 4 vertices with UV coordinates. Mirror of F_2DRectangleRender but stores at this+0xC and this+0x3C-0x48.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49CD80 (0049cd80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | audio/resource node pointer (this[3]) |
| this | 0x3C | RW | — | stored float param X (converted from a2) |
| this | 0x40 | RW | — | stored param Y (a3) |
| this | 0x44 | RW | — | stored param Width (a4) |
| this | 0x48 | RW | — | stored param Height (a5) |

**Written-by note (persistence):**
- this 0x3C-0x48: written every call when ObjectConstructor returns 0. Overwritten each frame.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049eca0 | SingleFieldFreeWrapper | frees/releases single field resource before re-render |
| 00553650 | sub_553650 | sets vertex with UV and color for quad |
| 00553980 | ObjectConstructorWithAllocationAndSubInit | object allocation/init (returns 0 on failure/skip) |

**Guard conditions:** Checks `*(this+12)` (0xC) non-null — blocks entirely if null. Calls ObjectConstructorWithAllocationAndSubInit — if it returns non-zero (success), skips quad rendering and returns early.
