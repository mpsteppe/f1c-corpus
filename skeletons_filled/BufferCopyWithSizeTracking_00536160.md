## BufferCopyWithSizeTracking_00536160 — BufferCopyWithTracking

**Summary:** Copies min(source_remaining, dest_remaining) bytes from source to destination buffer. Advances both read and write pointers, decrements remaining sizes, and accumulates total copied count. Part of compression/decompression data pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_535E80 (00535e80), DecompressionBufferFlush (00536300), ZlibInflateDecompressionCore (005365d0), InflateDecompressionLoop (00536a70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | destination buffer write pointer, advanced after copy |
| this | 0x10 | RW | — | remaining destination size, decremented by copied bytes |
| this | 0x14 | RW | — | total bytes copied so far (accumulated) |
| this | 0x1C | R | — | source object pointer (sub-object v2) |
| this | 0x24 | R | — | source buffer total size/limit, used to reload when source exhausted |
| this | 0x2C | RW | — | source buffer read pointer, advanced after copy |
| this | 0x30 | RW | — | remaining source size, decremented by copied bytes |
| this | 0x38 | R | — | source field read during reset condition check (sub-object state) |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x2C: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- Source remaining (`v2[5]`, this+0x30) and dest remaining (`this[4]`, this+0x10) compared: copy size = min(source_rem, dest_rem)
- If min size == 0: BLOCKED (skip copy, no data to transfer)
- After copy: if source remaining becomes 0 (`result[5]==0`, this+0x30), reload source remaining from source buffer size limit (`result[2]`, this+0x24)
