## FileTellSeekPositionQuery_00587f90 — FileSeekPosition

**Summary:** Implements file seek/tell: validates file state, flushes buffer, computes absolute position from relative offset (supports seek_cur via sub_58AD08), calls OS-level seek via sub_58C724, and manages file error flags.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_587F64 (00587f64)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | File state flags |
| this | 0x10 | R | — | OS file handle |
| this | 0x18 | RW | 512 | Internal buffer size hint |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a05a | BufferFlushWrite | Flush buffered data before seek |
| 0058ad08 | sub_58AD08 | Get current file position (tell) |
| 0058afcf | TLSOffsetGetter | Get TLS storage for errno |
| 0058c724 | sub_58C724 | OS-level file seek (SetFilePointer) |

**Guard conditions:** Checks if (flags & 0x83) != 0 and a3 <= 2. PASSES when file is open/writeable and seek mode is valid (0,1,2) — flushes buffer, calls OS seek. BLOCKED (returns -1, sets errno=22=EINVAL) when file not open or invalid seek mode.
