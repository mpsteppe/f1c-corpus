// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1410
// Canonical corpus name: NameCompareAndFormat
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NameCompareAndFormat_004b1410.c

void UnknownObject::NameCompareAndFormat()
{
    // Compares an input name against the stored name at this+0x1F9C. On match, builds a season-directory + name path string, performs an object-ID lookup, loads and decodes the audio file for the name, then runs settings-file init, a string-buffer copy, and the 5-step session init. Returns 1 on success, 0 on any guard or format/load failure.
    // GUARD: Load the stored-name pointer at this+0x1F9C; if null, substitute the default directory string byte_5EA438. [field:this:0x00001F9C, global:0x005EA438, source:raw]
    // GUARD: Compare input name a2 against the stored name via sub_588410; if it returns 0 (name mismatch), return 0. [callee:0x00588410, source:raw]
    // RETURN: Return 0 on name mismatch. [source:raw]
    // CALCULATION: Initialize path buffer v9: copy byte_5EA438[0], zero-fill the remainder (0xFC bytes), clear the trailing v10/v11 terminator fields. [global:0x005EA438, source:raw]
    // ASSIGNMENT: Pick the format components: v5 = stored name at this+0x1F9C (or byte_5EA438 default); v6 = dword_5EC3D8 season directory (or byte_5EA438 default). [field:this:0x00001F9C, global:0x005EC3D8, global:0x005EA438, source:raw]
    // CALL: StringFormatProcessingWithNullTerm(v9, 255, "%s%s", seasonDir, name) builds the season path + name, using path-format-string global aSS; if the result is < 0, return 0. [callee:0x0058969D, global:0x005BE860, global:0x005EC3D8, source:raw]
    // CALL: ObjectIDLookupAcross9Arrays(v9): perform the object-ID lookup on the formatted name/path. [callee:0x005684A0, source:raw]
    // CALL: Re-format with the input name: StringFormatProcessingWithNullTerm(v9, 255, "%s%s", seasonDir, a2); if the result is < 0, return 0. [callee:0x0058969D, global:0x005EC3D8, source:raw]
    // CALL: AudioFileLoadDecode(v9, 0): load/decode the audio file for the name; if the unsigned result != 1, return 0. [callee:0x00567F40, source:raw]
    // CALL: SettingsFileInit(this): initialize the settings file. [callee:0x004B0930, source:raw]
    // CALL: StringCopyWithBufferRealloc(a2): copy the input name into a managed buffer. [callee:0x00566650, source:raw]
    // CALL: F_5StepInit(this): run the 5-step session initialization sequence. [callee:0x004B0720, source:raw]
    // RETURN: Return 1 on success. [source:raw]

    // Conservative worker pseudocode:
    //   name = this->stored_name; if (!name) name = byte_5EA438;
    //   if (!CompareName(a2, name)) return 0;
    //   pathbuf = clear_buffer(byte_5EA438);
    //   if (StringFormatProcessingWithNullTerm(pathbuf, 255, "%s%s", seasonDir, name) < 0) return 0;
    //   ObjectIDLookupAcross9Arrays(pathbuf);
    //   if (StringFormatProcessingWithNullTerm(pathbuf, 255, "%s%s", seasonDir, a2) < 0) return 0;
    //   if ((unsigned char)AudioFileLoadDecode(pathbuf, 0) != 1) return 0;
    //   SettingsFileInit(this); StringCopyWithBufferRealloc(a2); F_5StepInit(this);
    //   return 1;
    // UNRESOLVED: dword_8AD3B4 appears in the packet globals table (R) but has no visible access in the raw source text; its role (GameDataDir per the fill, DERIVED) is not evidenced here.
    // UNRESOLVED: aSS (0x005BE860) is the path format string per the fill (PathFormatString, DERIVED); the raw source renders it only as the literal "%s%s".
    // UNRESOLVED: memset is an implicit CRT call evidenced only by source:raw.
    // UNRESOLVED: Literals 255, 0xFC, and index 2023 (0x1F9C/4) come only from the raw source / field table.
}
