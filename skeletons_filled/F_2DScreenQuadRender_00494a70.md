## F_2DScreenQuadRender_00494a70 — Render 2D textured screen quad

**Summary:** Renders a clipped 2D textured quad on screen. Clamps width/height to [0,256], sets up rendering region, configures four-corner texture UV coordinates with 1/256 scale, and draws via sub_553700.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIScrollViewRender (00486ac0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac988 | flt_5AC988 | R | UVCoordScaleFactor [DERIVED] (also: ` — UV coordinate scale factor) |
| 007cde08 | dword_7CDE08 | R | DestSurface [DERIVED] (also: ` — Destination surface/context) |
| 007cde0c | dword_7CDE0C | R | CollisionSoundHandles (x8) [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f9f00 | ConditionalInit | Initializes a conditional timing/tracking variable |
| 004f9f30 | ConditionalStateReset | Resets conditional timing state |
| 00543250 | ClippedRenderRegion | Sets up the clipped rendering destination region on the surface |
| 00553650 | sub_553650 | Sets UV texture coordinates for one corner of quad |
| 00553700 | sub_553700 | Performs the actual draw/blit operation |

**Guard conditions:** Width (a4) clamped to [0, 256]; height (a5) clamped to [0, 256]. Render only proceeds if both width > 0 and height > 0. Otherwise, function returns without drawing.
