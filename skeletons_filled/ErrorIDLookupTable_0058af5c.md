## ErrorIDLookupTable_0058af5c — OS error code to CRT errno mapper

**Summary:** CRT error mapping function that translates Windows GetLastError codes to CRT errno values. Uses a two-column lookup table (error code → errno) with range-based fallbacks for common error families. Stores both original OS error code and resulting errno in TLS.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CreateDirectoryAWrapper (00589671), FileDeleteWithErrorHandling (0058986e), MoveFileAWrapperWithErrorHandling (005898d3), ToggleFileReadOnlyAttributeViaWin32API (0058ba36), FileAttributeCheckWithErrorHandling (0058ba75), HandleCloseWithErrorReporting (0058c38e), FileSeekViaSetFilePointer (0058c789), sub_58CA19 (0058ca19), sub_58E290 (0058e290), sub_595AF9 (00595af9), FilePointerSeekWithErrorHandling (00595f82), sub_59B650 (0059b650), sub_59B760 (0059b760), sub_59B9F3 (0059b9f3), sub_59BA1D (0059ba1d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e65c0 | unk_5E65C0 | R | Base of error-code-to-errno lookup table (pairs of DWORDs) |
| 005e65c4 | dword_5E65C4 | R | Errno values column (offset +4 from each table entry) |
| 005e6728 | dword_5E6728 | R | End address bound of the lookup table |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058afcf | TLSOffsetGetter | Get TLS pointer for CRT errno slot; writes mapped errno value |
| 0058afd8 | TLSOffsetGetter_afd8 | Get TLS pointer for _doserrno slot; writes original OS error code |

**Guard conditions:** Searches lookup table for exact match against input error code. If found, returns mapped errno. If not found, applies range rules: 0x13-0x24 → errno 13 (EACCES); 0xBC-0xCA → errno 8 (possibly ENOEXEC); all others → errno 22 (EINVAL).
