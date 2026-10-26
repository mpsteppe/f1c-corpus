## TextBufferDecompressor_00536440 — Inflate input buffer refill

**Summary:** Refills the decompression input buffer for zlib inflate. Manages sliding window by shifting data when read position nears window end, updates hash chain offsets, reads more compressed data from stream via virtual call, and computes initial hash value from new bytes. Core buffer management helper for inflate.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DecompressionBufferFlush (00536300), ZlibInflateDecompressionCore (005365d0), InflateDecompressionLoop (00536a70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | vtable function pointer slot (called as DecompressionStreamRead) |
| this | 0x0 | R | — | vtable pointer |
| this | 0x22 | R | — | window size (WSIZE), sliding window capacity |
| this | 0x2E | R | — | output buffer base pointer (window start) |
| this | 0x32 | R | — | lookahead/available byte count target |
| this | 0x36 | R | — | hash chain array (head array) base |
| this | 0x3A | R | — | hash value array (prev array) base |
| this | 0x3E | RW | — | current hash value, updated per new byte |
| this | 0x42 | R | — | match offset adjust counter (used to decrement match positions on window shift) |
| this | 0x4A | R | — | hash update constant (shift/XOR mask) |
| this | 0x4E | R | — | hash bit shift amount |
| this | 0x52 | RW | — | bytes consumed / processed count |
| this | 0x62 | RW | — | current read position (input offset in window) |
| this | 0x66 | RW | — | window slide offset amount |
| this | 0x6A | RW | — | available bytes count in buffer |

**Written-by note (persistence):**
- this 0x3E: written with new hash each call
- this 0x52: updated when window slides
- this 0x62: updated on window shift
- this 0x66: updated on window shift
- this 0x6A: incremented by bytes read from stream

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00536560 | DecompressionStreamRead | read more compressed bytes from input stream |

**Guard conditions:** Reads this+34 (window size) and this+98 (read position) to decide if window needs sliding (when read position >= window_size + start - 262). Calls DecompressionStreamRead only when vtable function pointer at (this->vtable[1]) is non-null. Loop continues while vtable function is non-null and available bytes < 3. Loop exits early when available bytes >= 0x106 (262).
