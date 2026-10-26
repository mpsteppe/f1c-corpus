## BitStreamWriter_00539690 — BitstreamFlushRegister

**Summary:** Flushes accumulated bitstream data to output buffer. If bit count is exactly 16, writes both bytes and resets accumulator. If bit count is 8-15, writes one byte and shifts remaining bits. Part of bitstream encoding pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** BitstreamEncoder (00537fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | output buffer base pointer |
| this | 0x14 | RW | — | output buffer byte offset/index |
| this | 0x16AB | RW | 0 | bit accumulation shift register (16-bit), read for flush, cleared at 16 |
| this | 0x16AC | R | — | high byte of shift register, read for single-byte flush |
| this | 0x16AD | RW | 0 | bit count in shift register, decremented by 8 on single flush, reset to 0 on full flush |

**Written-by note (persistence):**
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x16AB: recalc every frame — external poke does NOT persist
- this 0x16AD: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- `bit_count == 16`: write both bytes to output, reset register and count to 0
- `bit_count >= 8`: write low byte only, shift high byte into register, count -= 8
- `bit_count < 8`: no flush (return 0)
