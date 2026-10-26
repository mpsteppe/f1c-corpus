## BufferedByteReader_0058ef2e — ReadNextByteFromBuffer

**Summary:** Reads the next byte from a buffered I/O context. Decrements remaining count; if exhausted (negative), calls sub_58C255 to refill; otherwise returns byte at cursor and advances cursor.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_58E4D2 (0058e4d2), IncrementWrapperAroundCallLoop (0058ef5f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | current read cursor pointer (next byte to consume) |
| this | 0x4 | R | — | remaining byte count in buffer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058c255 | sub_58C255 | refill buffer when remaining count goes negative (buffer exhausted) |

**Guard conditions:** No early guard; always executes. If `--*(_DWORD*)(a1+4) < 0` (buffer exhausted), calls sub_58C255 refill which may return -1/EOF. Otherwise returns the byte at cursor and advances pointer.
