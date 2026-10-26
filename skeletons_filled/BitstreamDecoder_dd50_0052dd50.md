## BitstreamDecoder_dd50_0052dd50 — BitstreamMpegHeaderDecode

**Summary:** Decodes MPEG audio frame header from bitstream buffer. Reads 32-bit sync word from buffer at current bit position, processes via CMpegBase_ProcessHeader, then advances bit position by frame size + 32 bits on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2498 | R | — | frame size in bytes (from previous header parse) |
| this | 0x24A4 | R | — | bitstream buffer pointer |
| this | 0x24A8 | RW | — | temporary copy of current bit position before processing |
| this | 0x24AC | RW | — | current bit position in bitstream buffer |
| this | 0x24F0 | R | — | default header sync word (used when no buffer) |

**Written-by note (persistence):**
- this 0x24A8: written once per decode call; external poke survives until next decode
- this 0x24AC: advanced on successful header decode; external poke overwritten by position update

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052da30 | CMpegBase_ProcessHeader | parse and validate MPEG audio frame header |

**Guard conditions:** does not advance bit position if CMpegBase_ProcessHeader returns -1 (invalid header)
