## TextureRowCopy_0051941d — TextureRowCopy

**Summary:** Copies texture row data for each render element between source and destination buffers, applying horizontal expansion/interpolation and offset calculations. Part of rendering/animation playback pipeline.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlaybackStateController (0051984b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | R | — | number of elements/vertices to process |
| this | 0xC4 | R | — | pointer to element descriptor array |
| this | 0xD0 | R | — | element buffer data pointer (per-element) |
| this | 0xE8 | R | — | unknown read-only field |
| this | 0x114 | R | — | stride/frame dimension for row calculation |
| this | 0x180 | R | — | pointer to buffer descriptor struct |
| this | 0x188 | R | — | buffer descriptor field +8 (offset for source access) |
| this | 0x1B8 | R | — | source buffer pointer for element data |
| this | 0x1BC | R | — | destination buffer pointer for element data |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | > | 0 | element count |

**Guard interpretation:** If this->0x20 > 0 (PASSES), iterates all elements and copies row data with horizontal expansion. For each element, reads source buffer at computed offset, copies to destination, then mirrors/repeats data across adjacent positions. If element count == 0 (BLOCKED), skips entire loop and returns.
