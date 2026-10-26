// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00405440
// Canonical corpus name: CameraViewStructInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CameraViewStructInitializer_00405440.c

void UnknownObject::CameraViewStructInitializer()
{
    // __thiscall default initializer for a camera/view struct. Sets the leading dword to -1 (sentinel/ID), copies the default directory path string via StringCopyWithBufferRealloc(&byte_5EA438), zeroes most dword fields while setting a few to -1, runs VirtualCleanup on the sub-object at this+0x30, zero-fills 44 bytes of the trailing block starting at index 17 with memset(0x2C), zeroes the byte at this+0x70, and returns 0. Called by ShortComputation_53e0 (004053E0).
    // ASSIGNMENT: this[0] = -1 (18446744073709551615 as unsigned): sentinel/ID field at offset 0x0 [field:this:0x00000000, source:raw]
    // CALL: StringCopyWithBufferRealloc(&byte_5EA438): copies the default directory path global into the struct buffer [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: this[3] = 0 at offset 0xC [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: this[4] = -1 at offset 0x10 [field:this:0x00000010, source:raw]
    // ASSIGNMENT: this[5] = 0 at offset 0x14 [field:this:0x00000014, source:raw]
    // ASSIGNMENT: this[6] = 0 at offset 0x18 [field:this:0x00000018, source:raw]
    // ASSIGNMENT: this[7] = -1 at offset 0x1C [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: this[8] = 0 at offset 0x20 [field:this:0x00000020, source:raw]
    // ASSIGNMENT: this[9] = 0 at offset 0x24 [field:this:0x00000024, source:raw]
    // ASSIGNMENT: this[10] = 0 at offset 0x28 [field:this:0x00000028, source:raw]
    // ASSIGNMENT: this[11] = 0 at offset 0x2C [field:this:0x0000002C, source:raw]
    // CALL: VirtualCleanup(this + 12): virtual-table-backed cleanup of the sub-object at this+0x30 [callee:0x0052D990, source:raw]
    // ASSIGNMENT: this[14] = 0 at offset 0x38 [field:this:0x00000038, source:raw]
    // CALCULATION: memset(this + 17, 0, 0x2C): zero-fills 44 bytes of the trailing block starting at index 17 [source:raw]
    // ASSIGNMENT: byte at this+0x70 = 0, the field just past the memset range [field:this:0x00000070, source:raw]
    // RETURN: returns 0 [function:0x00405440, source:raw]
    // CALL: Invoked by ShortComputation_53e0 (004053E0) [caller:0x004053E0]

    // Conservative worker pseudocode:
    //   this[0]  = -1;
    //   StringCopyWithBufferRealloc(&byte_5EA438);
    //   this[3]  = 0;
    //   this[4]  = -1;
    //   this[5]  = 0;
    //   this[6]  = 0;
    //   this[7]  = -1;
    //   this[8]  = 0;
    //   this[9]  = 0;
    //   this[10] = 0;
    //   this[11] = 0;
    //   VirtualCleanup(this + 12);
    //   this[14] = 0;
    //   memset(this + 17, 0, 0x2C);
    //   *(_BYTE *)this + 112 = 0;
    //   return 0;
    // UNRESOLVED: StringCopyWithBufferRealloc is called with only &byte_5EA438 visible; which destination buffer it writes into is not evident from the raw source
    // UNRESOLVED: The exact roles of the -1 sentinel fields (0x0, 0x10, 0x1C) versus the zeroed fields are inferred only from their init literals
}
