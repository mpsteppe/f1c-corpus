## sub_59BCFC_0059bcfc — StreamUngetWChar

**Summary:** Pushes a WCHAR character back into input stream buffer (analogous to ungetwc); handles wide (direct WCHAR push) and narrow (multibyte conversion via sub_596030) modes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StreamReadWrapperWithLockUnlock (0059bcd2)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e7898 | unk_5E7898 | R | DefaultBufferDescriptor [DERIVED] |
| 008d4920 | dword_8D4920 | R | CriticalSectionArray (stride 0x24) — file state array |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058afcf | TLSOffsetGetter | Get TLS slot for error code storage |
| 005957bd | MemoryAllocatorInit | Initialize stream buffer if not yet allocated |
| 00596030 | sub_596030 | Convert WCHAR to multibyte byte sequence |

**Guard conditions:** If a1 == 0xFFFF (WEOF), returns -1. If stream state flags are invalid (bit0=0 AND (bit7=0 OR bit1=1)), returns -1. Wide mode: if buffer at limit and reserve count non-zero, returns -1 (no space). Narrow mode: if sub_596030 returns -1, sets TLS error 42 and returns -1.
