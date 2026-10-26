## BitstreamWriteBits_00537f30 — BitstreamShiftWrite

**Summary:** Writes 3 bits at a time into a bitstream shift register. When the accumulator exceeds 13 bits, flushes 2 bytes to the output buffer and shifts remaining bits. Always calls ChecksummedBufferWriter for output tracking. Part of bitstream encoding pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_535E80 (00535e80), HuffmanBitStreamEncoder (005381f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | output buffer base pointer |
| this | 0x14 | RW | — | output buffer byte offset/index |
| this | 0x16AB | RW | — | bit accumulation shift register (16-bit), accumulates incoming bits |
| this | 0x16AC | R | — | high byte of shift register, read when flushing to output |
| this | 0x16AD | RW | — | bit count in shift register (how many valid bits accumulated) |

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
| 005397a0 | ChecksummedBufferWriter | write output bytes with checksum tracking |

**Guard conditions:**
- `bit_count <= 13`: accumulate a3 bits into register, add 3 to count — no flush needed
- `bit_count > 13`: flush the 2-byte register to output buffer (at pointer+offset), advance offset by 2, keep remaining bits shifted
- PASSES both paths; always calls ChecksummedBufferWriter at end
