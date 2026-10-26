## AudioRingBufferCopy_0053a660 — AudioRingBufferReadCopy

**Summary:** Copies audio data from ring buffer to destination buffer, handling ring buffer wrap-around when read pointer reaches the end. Updates buffer pointers (read, write, remaining sizes), invokes optional callback for each contiguous segment copied. Part of audio output data pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_537110 (00537110), sub_539870 (00539870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | destination write pointer (a2[3]), advanced after copy |
| this | 0x10 | RW | — | remaining destination size (a2[4]), decremented by copied bytes |
| this | 0x14 | RW | — | total bytes written accumulator (a2[5]), incremented by copied bytes |
| this | 0x30 | RW | — | callback result storage (a2[12]), written after each callback invocation |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- Ring buffer read pointer wraps: if `read_ptr + copy_size >= ring_end`, wrap to ring_start for second segment
- If copy size is 0: skip copy (no data available)
- If passthrough a3 == -5 and copy_size > 0: treat as non-error (set a3 = 0)
- Optional callback (a1[14]): if non-null, invoke for each contiguous segment copied
