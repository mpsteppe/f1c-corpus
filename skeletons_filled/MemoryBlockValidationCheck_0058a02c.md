## MemoryBlockValidationCheck_0058a02c — FileBufferValidationAndFlush

**Summary:** Flushes the file write buffer, then checks flag at offset +13 for write error (bit 6); if error is set, validates the OS handle via sub_592891 to determine if the handle is invalid.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** LockCallUnlockWrapper (00589ffd), sub_58A0BF (0058a0bf)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xD | R | — | Error flag byte (bit 6 = write error) |
| this | 0x10 | R | — | OS file handle |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a05a | BufferFlushWrite | Flush buffered data to OS |
| 00592891 | sub_592891 | Validate OS file handle (check if invalid) |

**Guard conditions:** Always calls BufferFlushWrite first. PASSES if flush fails (returns -1). BLOCKED for error check path when (*(a1+13) & 0x40) == 0 — returns 0 (valid). When bit 6 is set, checks sub_592891 on the handle — returns -1 if handle is invalid, 0 if still valid.
