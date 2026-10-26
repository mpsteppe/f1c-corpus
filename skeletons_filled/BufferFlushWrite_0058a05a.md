## BufferFlushWrite_0058a05a — BufferFlushToOS

**Summary:** Flushes the internal write buffer to the OS file handle if the buffer contains data and the file is in write mode (flags & 3 == 2 and flags & 0x108 != 0). Resets buffer pointers after flush.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MSVCCRTFileClose (00587d33), FileTellSeekPositionQuery (00587f90), sub_5886A7 (005886a7), MemoryBlockValidationCheck (0058a02c), sub_58AFE1 (0058afe1), ClearStructFieldsIfFlagSet (0058e4a8), sub_59BB00 (0059bb00), FileSeekWithModeFlagValidation (0059c156)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Write pointer (current position in buffer) |
| this | 0x4 | RW | 0 | Buffer start pointer (reset to base after flush) |
| this | 0x8 | R | — | Buffer data start pointer |
| this | 0xC | RW | — | File state flags |
| this | 0x10 | R | — | OS file handle |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058e22b | sub_58E22B | OS-level write (WriteFile) |

**Guard conditions:** Checks if (flags & 3) == 2 (write mode) and (flags & 0x108) != 0 (initialized). PASSES when writeable and data exists (buffer start < write pointer) — calls sub_58E22B to write data to OS handle. BLOCKED (returns 0) when not in write mode or no buffered data. On write failure, sets error flag (bit 5) and returns -1.
