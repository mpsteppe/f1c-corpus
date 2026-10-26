## IndexedStructDataRead_00403fc0 — 2D-indexed struct data reader

**Summary:** Reads position (3 floats) and orientation (3 floats) from a 2D-indexed array of 28-byte (7-float) struct entries. Computes linear index as `a2 + a3 * width_stride` and copies the first 6 floats of the entry to two output buffers.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4C6F10 (004c6f10), RenderCallWithGuard (004d1140)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x158 | R | — | base pointer to 28-byte-per-entry data array |
| this | 0x164 | R | — | second-index width/stride for 2D-to-linear index calculation |

**Globals referenced:** none

**Functions called:** none

**Guard conditions:** None — no conditional checks; always reads and returns data at computed index.
