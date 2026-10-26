## OutputStreamWriteWithBufferFlushAbstraction_00598d6d — BufferedWriteWithFlush

**Summary:** Writes bytes to buffered output stream. Copies to internal buffer if space available; otherwise calls vtable function at index 1 to flush buffer or write single byte. Returns total bytes written.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | vtable function pointer at index 1 — flush/write method |
| this | 0x0 | R | — | vtable pointer |
| this | 0x20 | RW | — | current write pointer within internal buffer |
| this | 0x30 | RW | — | remaining space in internal buffer |

**Written-by note (persistence):**
- this 0x20: incremented each time bytes written to buffer; external poke to buffer pointer would corrupt writes
- this 0x30: decremented each time bytes written; external poke to remaining count would corrupt writes

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058cc00 | MemoryCopy_cc00 | copy bytes from source to internal buffer |

**Guard conditions:** if buffer pointer (this+0x20) is NULL OR remaining space (this+0x30) <= 0, skip buffered copy path and call vtable[1] to flush/write byte. If vtable[1] returns -1 (error), return early with bytes written so far. Otherwise loop continues.
