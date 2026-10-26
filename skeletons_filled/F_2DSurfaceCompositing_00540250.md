## F_2DSurfaceCompositing_00540250 — 2D surface compositing with clip regions

**Summary:** Composites source surface region (a3,a4,a8,a9) onto destination surface region (a6,a7,a8,a9), selecting surfaces by flag bitmask (1/2/4/8). Handles clipping (if a10==-2 or depth>8), calls vtable[28] for clipped path or vtable[9] for direct blit. Releases temporary surfaces via vtable[2] call.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ClippedRenderRegion (00543250), ClippedRectRender (005432f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0x70 | R | — | vtable[28] (offset 112) on sub-object — clipped compositing call |
| this | 0x0 | RW | — | stores return values from all vtable calls |
| this | 0x1100 | R | — | sub-object pointer (index 1088) for compositing dispatch |

**Written-by note (persistence):**
- this 0x0: overwritten by each vtable call — last error code persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005401a0 | AudioPlaybackDispatcher | dispatches audio playback for composited region |

**Guard conditions:** Source surface selected from a2[6] flag bits (1→a2[2], 2→a2[3], 4→a2[4] vtable[15], 8→a2[5] vtable[15]). Fallthrough: if direct pointer null, tries vtable[15] getter. Same logic for destination from a5[6] flags. If a10==-2 or a2[12]/a5[12] > 8 → uses clipped compositing path.
