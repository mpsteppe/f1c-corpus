## sub_58AFE1_0058afe1 — fclose: flush and close file stream

**Summary:** CRT `fclose` implementation that flushes buffered writes, clears the file handle from critical section tracking, closes the OS handle via sub_58C724, and releases the stream structure.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_5354E0 (005354e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | Stream mode/flags; clears _IOCTRL bits and read/write direction on close |
| this | 0x10 | R | — | OS file handle index; -1 indicates no handle attached |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e7898 | unk_5E7898 | R | Default buffer descriptor used when handle is -1 |
| 008d4920 | dword_8D4920 | R | Critical section array for file handle tracking |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a05a | BufferFlushWrite | Flush any pending buffered write data |
| 0058c1b1 | StreamBufferLockViaCriticalSection | Lock the stream for exclusive access |
| 0058c203 | AddressRangeCriticalSectionLeave | Unlock, release stream, and free its critical section slot |
| 0058c724 | sub_58C724 | Close OS file handle (mode 0) |

**Guard conditions:** If handle (this+0x10) is -1, no OS close is performed and default buffer descriptor is used instead. If stream flags have bit 7 set (0x80 = _IOREAD), clears the lower 2 bits (read/write direction flags) before closing.
