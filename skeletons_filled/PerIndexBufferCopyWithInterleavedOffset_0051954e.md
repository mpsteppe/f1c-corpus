## PerIndexBufferCopyWithInterleavedOffset_0051954e — PerIndexBufferCopyWithInterleavedOffset

**Summary:** Copies per-element buffer data between source and destination arrays with interleaved offset pattern. For each element, copies content from source to destination while mirroring/repeating across adjacent positions. Part of rendering/animation buffer management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioStreamBufferFill (00519720)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | R | — | element count (loop bound) |
| this | 0xC4 | R | — | pointer to element descriptor array |
| this | 0xD0 | R | — | element data buffer pointer |
| this | 0xE8 | R | — | unknown read-only field |
| this | 0x114 | R | — | stride/frame dimension |
| this | 0x180 | R | — | pointer to buffer descriptor struct |
| this | 0x1B8 | R | — | source offset array (start positions per element) |
| this | 0x1BC | R | — | destination offset array (end positions per element) |

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

**Guard interpretation:** If this->0x20 > 0 (PASSES), iterates all elements, computes per-element size from descriptors, and copies data between source and destination with interleaved offset pattern. If <= 0 (BLOCKED), skips entire loop.
