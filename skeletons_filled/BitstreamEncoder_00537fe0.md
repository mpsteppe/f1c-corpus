## BitstreamEncoder_00537fe0 — BitstreamEndBlockEncode

**Summary:** Encodes end-of-block marker (binary '10' followed by zero padding) into the bitstream. Flushes accumulated bits to output buffer when shift register exceeds capacity. Resets buffer capacity to 7 at completion. Part of bitstream/audio encoding pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_535E80 (00535e80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | output buffer base pointer |
| this | 0x14 | RW | — | output buffer byte offset/index |
| this | 0x16A7 | RW | 7 | buffer capacity/size, set to 7 on completion |
| this | 0x16AB | RW | 0 | bit accumulation shift register (16-bit), holds bits being packed |
| this | 0x16AC | R | — | high byte of shift register, used during byte flush to output |
| this | 0x16AD | RW | — | bit count in shift register (how many valid bits) |

**Written-by note (persistence):**
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x16A7: recalc every frame — external poke does NOT persist
- this 0x16AB: recalc every frame — external poke does NOT persist
- this 0x16AD: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00539690 | BitStreamWriter | write/encode completed bitstream block to output |

**Guard conditions:**
- Accumulator bit_count threshold checks at 13 and 9 control whether bits accumulate or trigger 2-byte flush to output buffer
- Buffer capacity check: if `capacity - bit_count + 11 < 9`, write another EOB marker and flush again
- PASSES both paths; always calls BitStreamWriter and sets capacity=7 at end
