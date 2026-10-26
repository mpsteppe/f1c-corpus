// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00469630
// Canonical corpus name: SetupFileLoadAndFinalize
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetupFileLoadAndFinalize_00469630.c

void UnknownObject::SetupFileLoadAndFinalize()
{
    // Loads a setup file. Obtains an index/token via GuardedAccessor, retrieves a filename from the object's linked list via FilenameFromLinkedList, and returns 0 if the name is empty. Copies the name to a stack buffer, strips the extension at the last '.', and normalizes paths with StringCopyWithBufferRealloc. Resolves the season path global (dword_7D0434 or the default byte_5EA438), dispatches the file copy check via StringCopyFileCheckDispatch, and, when the resolved path differs from the default, builds a combined path with StringFormatProcessingWithNullTerm and looks the object up via ObjectIDLookupAcross9Arrays; a second formatted path is then used to load an audio file via AudioFileLoadDecode. Finally retrieves two sub-objects from this[16] through vtable method 28 (offsets 0x1C) with arguments 29 and 2, processes the first via sub_470190 and finalizes the second via loc_468640, then returns 1.
    // CALL: Obtain an index/token via GuardedAccessor and retrieve the setup filename from the object's linked list via FilenameFromLinkedList using this (field 0x40 as the list owner). [callee:0x0048D360, callee:0x004693E0, field:this:0x00000040, source:raw]
    // GUARD: If the filename is null or its strlen is zero, return 0. [source:raw]
    // CALCULATION: Copy the filename into the stack buffer v16 and strip the extension by truncating the string at the last '.' (ASCII 46), if present. [source:raw]
    // CALL: Normalize the stripped path with StringCopyWithBufferRealloc; resolve the season path base from global dword_7D0434 or the default byte_5EA438 and normalize it too; then dispatch the file copy check via StringCopyFileCheckDispatch(filename, 0). [callee:0x00566650, callee:0x004B04E0, global:0x007D0434, global:0x005EA438, source:raw]
    // GUARD: If the resolved season path differs from the default byte_5EA438: build a combined path buffer, format it with StringFormatProcessingWithNullTerm as "%s%s" from dword_5EC3D8 (or default) plus byte_5EA438, and look the combined path up via ObjectIDLookupAcross9Arrays. [global:0x005EC3D8, global:0x005EA438, callee:0x0058969D, callee:0x005684A0, source:raw]
    // CALL: Format a second combined path with StringFormatProcessingWithNullTerm as "%s%s" from dword_5EC3D8 (or default) plus the resolved dword_7D0434 (or default), and if formatting succeeds load and decode the audio file via AudioFileLoadDecode(path, 0). [callee:0x0058969D, callee:0x00567F40, global:0x005EC3D8, global:0x007D0434, global:0x005EA438, source:raw]
    // CALL: Invoke vtable method at offset 28 (0x1C) on the this[16] sub-object (field 0x40) with argument 29, and again with argument 2, retrieving two sub-objects to finalize. [field:this:0x00000040, field:*(this+0x40):0x0000001C, source:raw]
    // CALL: If the first retrieved sub-object is non-null, process it via sub_470190. [callee:0x00470190, source:raw]
    // CALL: If the second retrieved sub-object is non-null, finalize it via loc_468640. [source:raw]
    // RETURN: Return 1 to signal successful setup-file load and finalize. [source:raw]

    // Conservative worker pseudocode:
    //   bool SetupFileLoadAndFinalize(void** this) {
    //     const char* name = FilenameFromLinkedList(this, GuardedAccessor());
    //     if (!name || !strlen(name)) return false;
    //     char buf[1024]; strcpy(buf, name);
    //     char* dot = strrchr(buf, '.'); if (dot) *dot = 0;
    //     NormalizeString(buf);
    //     const char* base = dword_7D0434 ? dword_7D0434 : byte_5EA438;
    //     NormalizeString(base);
    //     StringCopyFileCheckDispatch(name, 0);
    //     if (strcmp(byte_5EA438, base)) {
    //       char path[253];
    //       const char* season = dword_5EC3D8 ? dword_5EC3D8 : byte_5EA438;
    //       if (Format(path, 255, "%s%s", season, byte_5EA438) >= 0) {
    //         ObjectIDLookupAcross9Arrays(path);
    //         if (Format(path, 255, "%s%s", season, base) >= 0)
    //           AudioFileLoadDecode(path, 0);
    //       }
    //     }
    //     void* a = GetObject(this[16], 29);
    //     void* b = GetObject(this[16], 2);
    //     if (a) ProcessObject(a);
    //     if (b) FinalizeObject(b);
    //     return true;
    //   }
    // UNRESOLVED: The sub-object lifecycle for the this[16] vtable calls (arg 29 and arg 2) is caller-side; what those objects are is unknown here.
    // UNRESOLVED: The exact role of the audio-file decode inside the path-comparison branch is not fully confirmed from the raw body alone.
    // UNRESOLVED: Several globals are read by this function per static analysis but do not appear literally in the raw body (aSS format string, auto-load flag, game-data directory).
}
