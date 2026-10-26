## NetworkPacketSend_0052ddc0 — IOReadMpegHeaderDecode

**Summary:** Reads 4-byte MPEG sync word from I/O interface vtable read function, byte-swaps, and processes via CMpegBase_ProcessHeader. Returns 0 on valid header, -1 on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x2D34) | 0x8 | R | — | I/O virtual read function (vtable+8) |
| this | 0x2D34 | R | — | I/O interface pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052da30 | CMpegBase_ProcessHeader | parse and validate MPEG audio frame header |

**Guard conditions:** none — single read-and-process call
