## MediaFileDecodeHeader_0052dc90 — MpegFileDecodeHeader

**Summary:** Reads 4-byte MPEG sync word from I/O interface, byte-swaps, and processes via CMpegBase_ProcessHeader. Validates frame size; on corruption sets flag and zeros frame size field.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x2D34)+0x0) | 0x8 | R | — | I/O virtual read function (vtable+8) |
| *(this+0x2D34) | 0x0 | R | — | I/O interface vtable pointer |
| this | 0x2498 | R | — | computed frame size from header parse |
| this | 0x24A4 | R | — | destination buffer for raw header read |
| this | 0x24A8 | RW | 0 | frame size field (zeroed on corruption) |
| this | 0x2D34 | R | — | I/O interface pointer |
| this | 0x2D3C | RW | 0 | flag byte: 1 = header read needed (set on corruption) |

**Written-by note (persistence):**
- this 0x24A8: written to 0 on corruption; external poke overwritten by error path
- this 0x2D3C: written to 1 on corruption, 0 on success; external poke overwritten on each decode

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005da5fc | aCmpegfileplaye | R | format string for corrupted MPEG header error message |
| 005da65c | aWaitingForCdAc | R | "waiting for CD..." error string for I/O failure |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052da30 | CMpegBase_ProcessHeader | parse and validate MPEG audio frame header |
| 00588821 | FileOpWithGlobalBuffer | display error message string |

**Guard conditions:** skips header read if flag at this+0x2D3C is clear (0 = already valid); returns -1 if I/O read fails or frame size < 4; on frame size corruption sets flag=1 and zeros frame size
