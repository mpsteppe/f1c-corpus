## FileHandleDestructorWithModeCheck_00534ee0 — File handle destructor with mode-specific cleanup

**Summary:** Frees a file stream context: calls mode-appropriate cleanup ('w' → sub_5361D0 flush/close, 'r' → GuardedFunctionCallCleanup), closes file handle, frees buffers, and deallocates the struct. File I/O system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_534B10 (00534b10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | Byte at +92: access mode character ('r'=114, 'w'=119) |
| this | 0x38 | R | — | Error code (this[14]); if negative, overrides return value |
| this | 0x40 | R | — | File handle (this[16]) to close |
| this | 0x44 | R | — | Write buffer (this[17]) to free |
| this | 0x48 | R | — | Read buffer (this[18]) to free |
| this | 0x50 | R | — | Copied filename string (this[20]) to free |
| this | 0x54 | R | — | Allocator pointer (this[21]) to free |
| this | 0x5C | R | — | Read buffer for decompression (this[23]) |
| this | 0x5C | R | — | Offset +92, part of mode handling |
| this | (indirect) | R | — | Offset +92 mode byte checked for 'r' vs 'w' |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00535660 | GuardedFunctionCallCleanup | Read-mode cleanup (decompress context teardown) |
| 005361d0 | sub_5361D0 | Write-mode cleanup (compress context teardown/flush) |
| 00587d02 | FileCloseWithLock | Close file handle with mutex lock |
| 0058aa6f | sub_58AA6F | Free heap-allocated memory |
| 0058afcf | TLSOffsetGetter | Get TLS offset to check for specific error code (29) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x38 | < | 0 | Error code (this[14]): if negative, overrides return value |

**Guard interpretation:** If `lpMem` is NULL → return -2. Mode byte at +92 == 'w' (119) → call sub_5361D0. Mode byte == 'r' (114) → call GuardedFunctionCallCleanup. Other modes skip both. If file handle close fails AND TLS error != 29 → return -1. If error code `(int)this[14] < 0` → override return value with error code.
