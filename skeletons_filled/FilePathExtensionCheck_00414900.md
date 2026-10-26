## FilePathExtensionCheck_00414900 — FileExistenceCheckWithExtension

**Summary:** Appends a 5-byte extension (from global constants) to a file path and checks if the file exists via GetFileAttributes (FILE_ATTRIBUTE_NORMAL). Returns 0 if file exists (writes struct fields), 1 if missing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_414600 (00414600), sub_414A90 (00414a90), CommentaryTVPWSPathBuilder (00414e60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 18446744073709551615 | Output — file identifier/value pair 1 (set to -1 on success) |
| this | 0xC | RW | 18446744073709551615 | Output — file identifier/value pair 2 (set to -1 on success) |
| this | 0x10 | RW | 0 | Output — flags byte (cleared to 0 on success) |

**Written-by note (persistence):**
- this 0x8: written unconditionally when file exists; set to -1
- this 0xC: written unconditionally when file exists; set to -1
- this 0x10: written unconditionally when file exists; set to 0

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be868 | dword_5BE868 | R | StrncpyFillPattern [DERIVED] — first 4 bytes of file extension to append |
| 005be86c | byte_5BE86C | R | ` — 1-byte extension suffix byte [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Copies and reallocates the filename string buffer |
| 00587dd0 | sub_587DD0 | Safe string copy with max length (250 chars) |
| 0058ba36 | ToggleFileReadOnlyAttributeViaWin32API | Called with FILE_ATTRIBUTE_NORMAL (128) to check file existence via GetFileAttributes; returns -1 on failure |

**Guard conditions:** If a1 (input path) is null, returns 1 immediately. If ToggleFileReadOnlyAttributeViaWin32API returns -1 (file not found), returns 1. PASSES: file exists at constructed path; BLOCKED: null input or file not found.
