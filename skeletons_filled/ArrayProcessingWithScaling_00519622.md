## ArrayProcessingWithScaling_00519622 — ArrayProcessingWithScaling

**Summary:** Processes element data arrays with scaling and modulo-based offset calculation. Computes per-element size from descriptors, applies modulo wrap for data positioning, and copies mirrored data between buffers. Part of rendering/animation buffer management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioStreamBufferFill (00519720)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | R | — | element count |
| this | 0xC4 | R | — | pointer to element descriptor array |
| this | 0xD0 | R | — | element data buffer pointer |
| this | 0xE8 | R | — | unknown read-only field |
| this | 0xF0 | R | — | unknown read-only field |
| this | 0x114 | R | — | stride/frame dimension |
| this | 0x180 | R | — | pointer to buffer descriptor struct |
| this | 0x1C0 | R | — | buffer descriptor field at offset +64 (double-buffer selector) |
| this | 0x1C8 | RW | — | buffer descriptor field at offset +72 (output row size) |

**Written-by note (persistence):**
- this 0x1C8: written once per call with computed output row size; external poke survives

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

**Guard interpretation:** If this->0x20 > 0 (PASSES), iterates elements, computes per-element size, applies modulo wrapping for data positioning, and copies mirrored data blocks of 2*v6 size. If 0 (BLOCKED), skips loop and returns.
