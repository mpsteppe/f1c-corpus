## sub_59BE0C_0059be0c — StreamReadWChar

**Summary:** Reads one WCHAR from input stream; wide mode reads 2 bytes directly from buffer, narrow mode reads 1-2 multibyte bytes and converts to WCHAR via sub_596716.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** IOFormatWrapper (0059bde9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Stream buffer current position pointer (dereferenced to read) |
| this | 0x0 | RW | — | Same as obj — stream buffer position |
| this | 0x4 | RW | — | Remaining byte count in buffer (decremented each read) |
| this | 0xC | R | — | Stream flags (bit 6 = wide mode) |
| this | 0x10 | R | — | File index (-1 = default/no file) |

**Written-by note (persistence):**
- this 0x0: advanced by 2 (wide) or 1-2 (narrow) each read
- this 0x4: decremented by bytes consumed each read

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e69c8 | off_5E69C8 | R | CharTypeTable [DERIVED] — character type lookup (lead-byte detection) |
| 005e7898 | unk_5E7898 | R | DefaultBufferDescriptor [DERIVED] |
| 008d4920 | dword_8D4920 | R | CriticalSectionArray (stride 0x24) — file state array |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058afcf | TLSOffsetGetter | Get TLS slot for error code storage |
| 0058c255 | sub_58C255 | Read one byte from stream with buffer refill |
| 00596716 | sub_596716 | Convert multibyte byte sequence (v8, v4) to WCHAR |
| 0059685f | FileIOWrapperWithLock | Write single character on read error condition |
| 0059c30e | sub_59C30E | Refill buffer and read one WCHAR in wide mode |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | == | 18446744073709551615 | File index == -1: use default buffer unk_5E7898 |

**Guard interpretation:** File index at +0x10 compared against -1 (0xFFFFFFFFFFFFFFFF as 64-bit unsigned). If equal, uses unk_5E7898 as default file descriptor; otherwise indexes into dword_8D4920 file array. Status byte at +4 >= 0 is required for narrow mode to proceed (blocked if negative/error state).
