## MSVCCRTFileClose_00587d33 — MSVCCRTFileCloseInternal

**Summary:** Flushes the write buffer, frees the internal buffer heap allocation, closes the OS file handle, and resets the file state flags. Implements MSVC CRT `_close`-like behavior.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** FileCloseWithLock (00587d02)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 0 | File state flags (bits: 0x80=write, 0x2=writeable, 0x1=open) |
| this | 0x10 | R | — | OS file handle |
| this | 0x1C | RW | 0 | Pointer to internal heap-allocated buffer |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a05a | BufferFlushWrite | Flush buffered data to OS |
| 0058aa6f | sub_58AA6F | Free heap-allocated memory |
| 0058c331 | sub_58C331 | Close OS file handle |
| 0058c411 | sub_58C411 | Release file lock |

**Guard conditions:** Checks if (flags & 0x83) is non-zero at a1+12. PASSES when file is open/writeable — flushes buffer, releases lock, closes handle, frees buffer. BLOCKED (returns -1) when flags indicate file not open.
