// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C54F0
// Canonical corpus name: AIW
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIW_004c54f0.c

void UnknownObject::BuildSceneScnAiwFilePaths()
{
    // Builds the .SCN and .AIW file path strings for the current scene entry. Reads the current scene index dword_8AC48C and the scene array base dword_8AC490 (stride 0x18C), copies the scene's base name into byte_8AC398, copies the base name into a local buffer, formats "%s.SCN" into byte_8AC3E8 and "%s.AIW" into byte_8AC438, then copies each buffer through StringCopyWithBufferRealloc, returning the result of the last copy.
    // CALCULATION: Compute scene entry pointer v1 = 396 * dword_8AC48C + dword_8AC490 from the current scene index and the scene array base. [global:0x008AC48C, global:0x008AC490, source:raw]
    // LOOP: Copy the scene name string starting at v1 + 260 into the byte_8AC398 buffer, terminating at the NUL byte. [global:0x008AC398, source:raw]
    // LOOP: Copy the base name string starting at v1 + 4 into the local v8 buffer, terminating at the NUL byte. [source:raw]
    // CALL: Format "%s.SCN" from the local base name into the byte_8AC3E8 buffer via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x008AC3E8, source:raw]
    // CALL: Format "%s.AIW" from the local base name into the byte_8AC438 buffer via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x008AC438, source:raw]
    // CALL: Copy the formatted SCN path buffer byte_8AC3E8 to persistent storage via StringCopyWithBufferRealloc. [callee:0x00566650, global:0x008AC3E8, source:raw]
    // CALL: Copy the track name buffer byte_8AC398 to persistent storage via StringCopyWithBufferRealloc. [callee:0x00566650, global:0x008AC398, source:raw]
    // CALL: Copy the formatted AIW path buffer byte_8AC438 to persistent storage via StringCopyWithBufferRealloc and return its result. [callee:0x00566650, global:0x008AC438, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C54F0(int a1) {
    //     char *entry = (char *)(396 * dword_8AC48C + dword_8AC490);
    //     strcpy(byte_8AC398, entry + 260);
    //     char base[128]; strcpy(base, entry + 4);
    //     StringFormatWithBufferOverflowCheck(&byte_8AC3E8, "%s.SCN", base);
    //     StringFormatWithBufferOverflowCheck(&byte_8AC438, "%s.AIW", base);
    //     StringCopyWithBufferRealloc(&byte_8AC3E8);
    //     StringCopyWithBufferRealloc(byte_8AC398);
    //     return StringCopyWithBufferRealloc(&byte_8AC438);
    //   }
    // UNRESOLVED: The integer argument a1 is declared but never used in the decompiled body; its purpose is unknown.
    // UNRESOLVED: Byte 0x007CE498 is read according to packet evidence but has no visible use in the decompiled source text.
    // UNRESOLVED: String literals at 0x005D31B8 and 0x005D31C0 are read according to packet evidence but do not appear in the decompiled source text; they may be the "%s.SCN"/"%s.AIW" format literals.
    // UNRESOLVED: No null/validity checks guard dword_8AC48C or dword_8AC490; caller must guarantee a valid scene entry.
}
