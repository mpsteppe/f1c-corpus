// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9830
// Canonical corpus name: sub_4B9830
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B9830_004b9830.c

void UnknownObject::BuildPathWithVcrExtension()
{
    // File-path constructor: selects the current directory pointer lpPathName, falling back to the byte_5EA438 default path when it is null, copies the chosen path into a reallocating buffer via StringCopyWithBufferRealloc, then returns sub_5665B0(aVcrTmp) which appends the ".vcr" extension. Part of the file/settings path construction used by GameDataFileIO and FileSettingExistenceCheck.
    // ASSIGNMENT: Start with the global directory pointer lpPathName as the source path. [global:0x005EC410, source:raw]
    // GUARD: When lpPathName is null, fall back to the byte_5EA438 default application directory path. [global:0x005EA438, source:raw]
    // CALL: Copy the selected path with StringCopyWithBufferRealloc(v1), reallocating the destination buffer as needed. [callee:0x00566650, source:raw]
    // RETURN: Return the result of sub_5665B0(aVcrTmp), which appends the ".vcr" extension to the copied path. [callee:0x005665B0, global:0x005D2474, source:raw]

    // Conservative worker pseudocode:
    //   int BuildPathWithVcrExtension(int unused) {
    //     char *src = lpPathName;
    //     if (!lpPathName)
    //       src = byte_5EA438;
    //     StringCopyWithBufferRealloc(src);
    //     return sub_5665B0(aVcrTmp);
    //   }
    // UNRESOLVED: Parameter a1 is never referenced in the decompiled source; its role is unknown.
    // UNRESOLVED: StringCopyWithBufferRealloc's destination buffer and how sub_5665B0 consumes it are not visible in this function alone.
}
