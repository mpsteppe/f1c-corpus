## BufferedStreamReadWithFallbackVtableCall_00599081 — BufferedReadSingleByte

**Summary:** Reads one byte from buffered input stream. Returns buffered byte directly if available; otherwise calls vtable[5] (underflow) then vtable[2] (sputc) to refill and process.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x0 | R | — | buffered byte value read via pointer at this+0x1C |
| obj | 0x8 | R | — | vtable slot index 2 — sputc/process single byte |
| obj | 0x14 | R | — | vtable slot index 5 — underflow/refill buffer |
| this | 0x0 | R | — | vtable pointer |
| this | 0x1C | R | — | current read pointer within internal buffer |
| this | 0x2C | R | — | remaining byte count in internal buffer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if buffer pointer (this+0x1C) is non-null AND current position < end (position + remaining count at this+0x2C), return buffered byte. Otherwise call vtable[5] then vtable[2] for refill.
