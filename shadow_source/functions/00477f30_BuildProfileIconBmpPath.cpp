// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00477F30
// Canonical corpus name: ProfileIconBmpLoader_7f30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ProfileIconBmpLoader_7f30_00477f30.c

void UnknownObject::BuildProfileIconBmpPath()
{
    // Builds an absolute file path for the "ProfileIcon.bmp" asset. It first invokes the virtual method at vtable offset 60 (field obj+0x3C) with argument 0, fills a 128-byte stack buffer with the base directory via PathTruncationUtility, then appends the 16-byte literal "ProfileIcon.bmp" (copied as four dword chunks from globals aProfileiconBmp, byte_5C6954, byte_5C6958 and byte_5C695C) at the position after the string's NUL terminator, and stores the combined path via StringCopyWithBufferRealloc. Returns 0.
    // CALL: Load the vtable pointer from *this and invoke the virtual method at vtable offset 60 (field obj+0x3C) with argument 0; this establishes the base directory/path provider state. [source:raw, field:this:0x00000000, field:obj:0x0000003C]
    // CALL: Compute the base directory into the 128-byte stack buffer via PathTruncationUtility. [source:raw, callee:0x004B0220]
    // CALCULATION: Position v1 one byte past the buffer's NUL terminator using strlen, then copy the 16-byte "ProfileIcon.bmp" literal backwards onto the path as four dword chunks loaded from aProfileiconBmp, byte_5C6954, byte_5C6958 and byte_5C695C. [source:raw, global:0x005C6950, global:0x005C6954, global:0x005C6958, global:0x005C695C]
    // CALL: Store the combined path into the persistent string buffer via StringCopyWithBufferRealloc. [source:raw, callee:0x00566650]
    // RETURN: Return the decimal literal 0. [source:raw]

    // Conservative worker pseudocode:
    //   int BuildProfileIconBmpPath(void *this)
    //   {
    //     char path[128];
    //     (*(void (**)(void *, int))(*(int *)this + 60))(this, 0);
    //     PathTruncationUtility(path, 128);
    //     char *p = &path[strlen(path) + 1];
    //     memcpy(p - 16, aProfileiconBmp, 16);
    //     StringCopyWithBufferRealloc(path);
    //     return 0;
    //   }
    // UNRESOLVED: Global byte_7CE498 is listed in the packet but absent from the raw source; any role it plays in this function is not evidenced.
    // UNRESOLVED: The identity of the object providing the vtable+60 base-path virtual method is not established.
    // UNRESOLVED: The literal split into four dword loads is a raw-source artifact of the string constant's layout, not four distinct semantic values.
}
