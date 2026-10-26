## sub_59BBD9_0059bbd9 — StreamWriteWChar

**Summary:** Writes a WCHAR character to an output stream buffer; in wide mode stores directly, in narrow mode converts to multibyte sequence via sub_596030 before writing each byte.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ThreeStepStreamQuery (0059bbaf)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e7898 | unk_5E7898 | R | DefaultBufferDescriptor [DERIVED] — used when no file index is set |
| 008d4920 | dword_8D4920 | R | CriticalSectionArray (stride 0x24) — file state array for status check |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058afcf | TLSOffsetGetter | Get TLS slot for error code storage |
| 0058cf35 | sub_58CF35 | Handle buffer full / flush and write byte |
| 00596030 | sub_596030 | Convert WCHAR to multibyte byte sequence (returns byte count 1 or 2, or -1 on error) |
| 0059c1e7 | sub_59C1E7 | Handle buffer full / flush for wide-character write |

**Guard conditions:** Stream in narrow mode and sub_596030 returns -1 (conversion error): sets TLS error 42, returns -1. Buffer-full conditions delegated to sub_58CF35 (narrow) or sub_59C1E7 (wide); if those return -1, propagates -1 return.
