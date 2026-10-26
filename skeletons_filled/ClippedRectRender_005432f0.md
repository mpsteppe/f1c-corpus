## ClippedRectRender_005432f0 — Clipped2DRectangleRender

**Summary:** Renders a clipped 2D rectangle surface using F_2DSurfaceCompositing. Applies clipping bounds via sub_543540, converts float dimensions to integers, and clears the 0x400 compositing flag on the target surface.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49D5D0 (0049d5d0), sub_49DE40 (0049de40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | width dimension (X), used as source for rectangle calculation |
| this | 0x20 | R | — | height dimension (Y), used as source for rectangle calculation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager singleton pointer, passed to F_2DSurfaceCompositing |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540250 | F_2DSurfaceCompositing | perform 2D surface compositing with clipping coordinates |
| 00543540 | sub_543540 | validate/clamp rectangle bounds (ensures non-negative dimensions) |
| 00587bdc | CRTFtol | convert float to int (rounds toward zero) |

**Guard conditions:** BLOCKED when a10 < 0 → uses float parameters directly (non-scaled path). BLOCKED when a4[6] clip result has negative width or height (a3 <= 0 or a5 <= 0) → skips F_2DSurfaceCompositing and returns.
