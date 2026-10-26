## FilePathResolverWithExtensionAppend_004793ec — FilePathResolverWithExtensionAppend

**Summary:** Resolves and constructs full file path with track file extensions: extracts filename from input, builds extension strings from globals, copies to global buffers (byte_7CD718), resolves via sub_497AD0, copies resolved path or fallback, parses coordinate file via sub_479170.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c7190 | dword_5C7190 | R | FileExtensionMagic [DERIVED] — part of file extension string construction |
| 005c7194 | word_5C7194 | R | TrackExtMagic [DERIVED] — part of track file extension |
| 005c7196 | byte_5C7196 | R | FileExtSepByte [DERIVED] — separator byte in extension |
| 005c71c0 | dword_5C71C0 | R | FileExtensionDword [DERIVED] — part of file extension string |
| 005c71c4 | dword_5C71C4 | R | TrackNameSuffix [DERIVED] — suffix for track name |
| 005c71c8 | byte_5C71C8 | R | Byte_FileExtension [DERIVED] — extension byte |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cd618 | unk_7CD618 | R | FilePathBuffer_7CD618 [DERIVED] — destination for resolved path copy |
| 007cd717 | byte_7CD717 | W | FileCopied_Flag [DERIVED] — flag set to 0 during path resolution |
| 007cd718 | byte_7CD718 | R | FileDialog_SelectedPath [DERIVED] — working path buffer |
| 007cd817 | byte_7CD817 | W | FilePathNullTerminator [DERIVED] — null terminator written to path buffer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00478e80 | SingleCallWrapper_8e80 | wraps single-arg call return (result handler) |
| 00479170 | sub_479170 | parses coordinate file after path resolution |
| 00497ad0 | sub_497AD0 | file existence/type check on resolved path |
| 00566650 | StringCopyWithBufferRealloc | copies resolved path or fallback to destination buffer |
| 00587dd0 | sub_587DD0 | substring copy (copies N chars from source) |

**Guard conditions:** Input a2 must be non-null (returns SingleCallWrapper_8e80(0) if null). If sub_497AD0 returns non-zero (valid file), copies resolved path; otherwise copies default directory (byte_5EA438).
