## NetworkColorIsDefault_0052de00 — BitstreamMpegHeaderCheck

**Summary:** Reads next MPEG sync word from bitstream buffer (or uses default) and tests whether CMpegBase_ProcessHeader accepts it. Returns TRUE (1) if header is invalid, FALSE (0) if valid.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24A4 | R | — | bitstream buffer pointer |
| this | 0x24F0 | R | — | default header sync word (used when buffer pointer is NULL) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052da30 | CMpegBase_ProcessHeader | parse and validate MPEG audio frame header |

**Guard conditions:** if buffer pointer at 0x24A4 is NULL, uses default header word at 0x24F0 instead
