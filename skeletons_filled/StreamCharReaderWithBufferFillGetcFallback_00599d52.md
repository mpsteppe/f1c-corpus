## StreamCharReaderWithBufferFillGetcFallback_00599d52 — Stream char reader with buffer fill and getc fallback

**Summary:** Reads wide characters from stream buffer using chunk copy (fast path) when internal buffer is available and non-empty; falls back to per-character virtual getc call (vtable slot 5) when buffer is exhausted. Returns total characters read.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x14 | R | — | running total of characters successfully read |
| this | 0x0 | R | — | vtable pointer (reads virtual function at slot 5 for single-char read) |
| this | 0x1C | R | — | pointer to internal read buffer |
| this | 0x2C | R | — | count of available characters in buffer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059a3f3 | PointerAdjustment | adjusts buffer pointer after reading chunk from buffer |

**Guard conditions:** Two-level guard. First: `*this[7]` (buffer at 0x1C) must be non-null AND `*this[11]` (available count at 0x2C) must be > 0 to take fast chunk-copy path. If either fails, falls back to virtual getc call at vtable[5]. If getc returns -1, function returns immediately with current count.
