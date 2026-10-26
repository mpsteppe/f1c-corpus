## InputStreamReadWithBufferedFill_00598cf9 — BufferedReadWithFill

**Summary:** Reads bytes from buffered input stream. Copies from internal buffer if available; otherwise calls vtable function at index 5 to refill buffer or read single byte. Returns total bytes read.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x14 | R | — | vtable function pointer at index 5 — refill/read method |
| this | 0x0 | R | — | vtable pointer |
| this | 0x1C | RW | — | current read pointer within internal buffer |
| this | 0x2C | RW | — | remaining byte count in internal buffer |

**Written-by note (persistence):**
- this 0x1C: decremented each time bytes consumed from buffer; external poke to buffer pointer would corrupt reads
- this 0x2C: decremented each time bytes consumed; external poke to remaining count would corrupt reads

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058cc00 | MemoryCopy_cc00 | copy bytes from internal buffer to output buffer |

**Guard conditions:** if buffer pointer (this+0x1C) is NULL OR remaining count (this+0x2C) <= 0, skip buffered copy path and call vtable[5] to refill. If vtable[5] returns -1 (EOF/error), return early with bytes read so far. Otherwise loop continues.
