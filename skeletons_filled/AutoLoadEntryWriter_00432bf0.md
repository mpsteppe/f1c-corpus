## AutoLoadEntryWriter_00432bf0 — AutoLoadEntryStringWriter

**Summary:** Writes a sequence of format strings (backup extension, format specifiers, and path components) into a buffer to compose an auto-load configuration entry. Used during config file parsing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConfigFileParser (004330d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | First DWORD of buffer struct (validity check and buffer pointer) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3f88 | off_5C3F88 | R | Off_ButtonBinding [DERIVED] |
| 005c3f8c | off_5C3F8C | R | Unknown_Ptr_5C3F8C [DERIVED] |
| 005c3f90 | off_5C3F90 | R | VTable_5C3F90 [DERIVED] |
| 005c3f94 | off_5C3F94 | R | vtable_UIWidget_00432a70 [DERIVED] |
| 005c3f98 | off_5C3F98 | R | MsgBoxVtable [DERIVED] |
| 005c4044 | asc_5C4044 | R | Asc_Unknown [DERIVED] |
| 005c4048 | aSD | R | SDFormat [DERIVED] |
| 005c4054 | aSS_4 | R | SSS_FormatString [DERIVED] |
| 005c4060 | asc_5C4060 | R | Str_FormatSpec_5C4060 [DERIVED] |
| 005c4064 | aS_7 | R | BackupExt [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566c30 | BufferWriteWithStringLengthCheck | Writes a string to buffer with length validation |

**Guard conditions:** a1 (buffer struct pointer) and *a1 must both be non-null for writing to proceed. If either is null, returns 1 (failure). Otherwise writes all format strings and returns 0 (success).
