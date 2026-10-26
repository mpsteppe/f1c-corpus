// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048E3A0
// Canonical corpus name: FontResourceLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FontResourceLoader_0048e3a0.c

void UnknownObject::FontResourceLoader()
{
    // Loads a font resource for the UI: frees any existing resource at this+0xE4, builds the font path from the directory string at this+0xB0, the base directory dword_5EC3F0 and the font name at this+0xB8 (each falling back to byte_5EA438), creates the resource via ObjectCreationWithRollbackOnFailure with the accumulated path, clears the metric fields at this+0xE8/this+0xEC, and on the failure branch clears the active byte at this+0xF8, copies the glyph width/height from the created object into this+0xF0/this+0xF4, and configures a DSP parameter via sub_551EB0(flt_7CF2CC). Returns 1 on success, 0 otherwise.
    // GUARD: If the resource pointer at this+0xE4 is non-zero, release it via ConditionalFreeWithBinkClose. [field:this:0x000000E4, callee:0x00551F80, guard:0]
    // CALL: Copy the font directory path string at this+0xB0 (falling back to byte_5EA438 when null) via StringCopyWithBufferRealloc. [field:this:0x000000B0, callee:0x00566650, global:0x005EA438]
    // ASSIGNMENT: Allocate a 128-byte path buffer via OperatorNewNhMallocWrapper and clear its first byte. [callee:0x00587C03, source:raw]
    // CALL: Copy the base directory dword_5EC3F0 (or the byte_5EA438 fallback) via StringCopyWithBufferRealloc. [global:0x005EC3F0, global:0x005EA438, callee:0x00566650]
    // CALL: Append the font name string at this+0xB8 (or the byte_5EA438 fallback) via sub_5665B0. [field:this:0x000000B8, callee:0x005665B0, global:0x005EA438]
    // CALL: Create the font resource object via ObjectCreationWithRollbackOnFailure, passing the accumulated path buffer (or the byte_5EA438 fallback) and writing the result through the this+0xE4 slot. [callee:0x00551F10, field:this:0x000000E4, global:0x005EA438, source:raw]
    // ASSIGNMENT: Clear the metric fields at this+0xEC and this+0xE8 to 0. [field:this:0x000000EC, field:this:0x000000E8, source:raw]
    // GUARD: On creation success, clear the resource pointer at this+0xE4 and set the success flag (return 1). [field:this:0x000000E4, source:raw]
    // ASSIGNMENT: On creation failure, clear the active byte at this+0xF8; when a resource object is still present at this+0xE4, copy the glyph width from its +0xC into this+0xF0 and the glyph height from its +0x10 into this+0xF4. [field:this:0x000000F8, field:*(this+0xE4):0x0000000C, field:*(this+0xE4):0x00000010, field:this:0x000000F0, field:this:0x000000F4, source:raw]
    // CALL: On the failure branch with a resource object present, configure the DSP parameter via sub_551EB0(flt_7CF2CC). [callee:0x00551EB0, global:0x007CF2CC]
    // CALL: Free the 128-byte path buffer via FreeWrapper_7bcf when it was allocated. [callee:0x00587BCF, source:raw]
    // RETURN: Return the success flag (1 when the resource was created, 0 otherwise). [source:raw]

    // Conservative worker pseudocode:
    //   int FontResourceLoader(char* this) {
    //       if (*(void**)(this + 0xE4)) ConditionalFreeWithBinkClose(*(void**)(this + 0xE4));
    //       char* dir = *(char**)(this + 0xB0); if (!dir) dir = byte_5EA438;
    //       StringCopyWithBufferRealloc(dir);
    //       char* path = (char*)OperatorNewNhMallocWrapper(128); *path = 0;
    //       char* base = (char*)dword_5EC3F0; if (!base) base = byte_5EA438;
    //       StringCopyWithBufferRealloc(base);
    //       char* name = *(char**)(this + 0xB8); if (!name) name = byte_5EA438;
    //       sub_5665B0(name);
    //       char* path_arg = path ? path : byte_5EA438;
    //       int created = ObjectCreationWithRollbackOnFailure((int*)(this + 0xE4), path_arg, 0, 0);
    //       *(int*)(this + 0xEC) = 0;
    //       *(int*)(this + 0xE8) = 0;
    //       int result = 0;
    //       if (created) { *(int*)(this + 0xE4) = 0; result = 1; }
    //       else {
    //           *(BYTE*)(this + 0xF8) = 0;
    //           if (*(int*)(this + 0xE4)) {
    //               *(int*)(this + 0xF0) = *(int*)(*(int*)(this + 0xE4) + 12);
    //               *(int*)(this + 0xF4) = *(int*)(*(int*)(this + 0xE4) + 16);
    //               sub_551EB0(flt_7CF2CC);
    //           }
    //       }
    //       if (path) FreeWrapper_7bcf(path);
    //       return result;
    //   }
    // UNRESOLVED: The contract of ObjectCreationWithRollbackOnFailure is unclear: the glyph metrics are read from the resource object on the failure branch, which suggests partial creation on failure.
    // UNRESOLVED: The meaning of the DSP parameter configured by sub_551EB0(flt_7CF2CC) is unknown.
    // UNRESOLVED: The roles of the metric fields this+0xF0/this+0xF4 and the active byte at this+0xF8 (beyond being cleared) are not established by this packet.
    // UNRESOLVED: The exact path concatenation contract between StringCopyWithBufferRealloc and sub_5665B0 is not established; they may append into separate buffers.
}
