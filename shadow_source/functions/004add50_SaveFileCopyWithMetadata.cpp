// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004ADD50
// Canonical corpus name: sub_4ADD50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4ADD50_004add50.c

void UnknownObject::SaveFileCopyWithMetadata()
{
    // Copies a save/settings file and appends a metadata block to the destination filename. Builds the source path by safe-sprintf of a directory (dword_5EC440, falling back to byte_5EA438 when empty) plus a resource-name string at dword_5C5E60. Truncates the destination path to 238 characters, then appends four dwords (dword_5C5E60/5C5E64/5C5E68/5C5E6C) and one word (word_5C5E70) of metadata at the end of the destination filename. Performs the copy with CopyFileA and returns its BOOL result.
    // ASSIGNMENT: Initialize NewFileName[253]: copy the first byte of byte_5EA438, zero-fill the remaining 252 bytes, and null-terminate. [global:0x005EA438, source:raw]
    // ASSIGNMENT: Initialize ExistingFileName[253] the same way: copy the first byte of byte_5EA438, zero-fill the rest, null-terminate. [global:0x005EA438, source:raw]
    // GUARD: Choose the source directory prefix: dword_5EC440 when non-null, else fall back to byte_5EA438. [global:0x005EC440, global:0x005EA438, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(ExistingFileName, aSS, dir, &dword_5C5E60) builds the source path with a '%s%s' format string. [callee:0x0058815F, global:0x005BE860, global:0x005C5E60, source:raw]
    // CALL: PathTruncationUtility(NewFileName, 238) truncates or fixes the destination path to at most 238 characters. [callee:0x004B0220, source:raw]
    // CALCULATION: Append the metadata block to the end of the NewFileName string: dword_5C5E60, then dword_5C5E64, dword_5C5E68, dword_5C5E6C, and finally word_5C5E70. [global:0x005C5E60, global:0x005C5E64, global:0x005C5E68, global:0x005C5E6C, global:0x005C5E70, source:raw]
    // CALL: CopyFileA(ExistingFileName, NewFileName, 0) copies the file with overwrite enabled. [global:0x0059E19C, source:raw]
    // RETURN: Return the BOOL result of CopyFileA. [source:raw]

    // Conservative worker pseudocode:
    //   BOOL SaveFileCopyWithMetadata() {
    //     char NewFileName[253] = {0}; NewFileName[0] = byte_5EA438[0];
    //     char ExistingFileName[253] = {0}; ExistingFileName[0] = byte_5EA438[0];
    //     const char* dir = dword_5EC440 ? (const char*)dword_5EC440 : byte_5EA438;
    //     StringFormatWithBufferOverflowCheck(ExistingFileName, "%s%s", dir, (const char*)&dword_5C5E60);
    //     PathTruncationUtility(NewFileName, 238);
    //     char* p = &NewFileName[strlen(NewFileName) + 1];
    //     *(int*)(--p) = dword_5C5E60;
    //     *((int*)p + 1) = dword_5C5E64;
    //     *((int*)p + 2) = dword_5C5E68;
    //     *((int*)p + 3) = dword_5C5E6C;
    //     *((short*)p + 8) = word_5C5E70;
    //     return CopyFileA(ExistingFileName, NewFileName, 0);
    //   }
    // UNRESOLVED: Meaning of the four-dword-plus-one-word metadata block written into the destination filename is unknown.
    // UNRESOLVED: dword_5C5E60 is used both as the format argument (resource-name string) and as the first metadata dword; its dual role is unproven.
    // UNRESOLVED: Purpose of dword_5EC440 vs byte_5EA438 directory selection is unknown.
    // UNRESOLVED: Function called only from TextFileReader (0x004B09A0); call context not proven here.
}
