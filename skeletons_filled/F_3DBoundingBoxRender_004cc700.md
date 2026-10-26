## F_3DBoundingBoxRender_004cc700 — Render 3D bounding box corners

**Summary:** Computes 4 corner points of a 3D bounding box centered at a1[11..13] with offset vectors a2/a3 and writes each corner as a pixel to texture buffer via PixelWriteToTextureBuffer. Debug/visualization rendering helper.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4CC970 (004cc970), ParticleEffectPhysics (004ccb30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | texture handle / render target identifier |
| this | 0x2C | R | — | bounding box center X coordinate |
| this | 0x30 | R | — | bounding box center Y coordinate |
| this | 0x34 | R | — | bounding box center Z coordinate |
| this | 0x60 | R | — | additional render parameter (e.g. color/alpha) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00558e10 | PixelWriteToTextureBuffer | write a pixel/corner point to texture render buffer at given coordinates |

**Guard conditions:** None — unconditional; always renders all 4 corners.
