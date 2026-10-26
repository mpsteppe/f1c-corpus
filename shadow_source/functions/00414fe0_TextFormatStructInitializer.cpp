// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00414FE0
// Canonical corpus name: TextFormatStructInitializer_4fe0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextFormatStructInitializer_4fe0_00414fe0.c

void UnknownObject::TextFormatStructInitializer()
{
    // Resets a text-format struct by reinitializing the global path string buffer (StringCopyWithBufferRealloc on byte_5EA438) between writes, and clearing groups of DWORD pairs to -1 with a following byte cleared to 0 across four slot groups (base + 8..0x10, + 0x14..0x1C, + 0x28..0x30, + 0x3C..0x44), then a final slot group written after this += 72. Returns the result of the last StringCopyWithBufferRealloc call.
    // CALL: Reinitialize the global path/buffer string via StringCopyWithBufferRealloc(&byte_5EA438) before each slot group is reset (4 calls total). [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Slot 0: reset the DWORD pair at this + 8 and this + 0xC to -1 and clear the byte at this + 0x10 to 0. [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Slot 1: reset the DWORDs at this + 0x14 and this + 0x18 to -1 and clear the byte at this + 0x1C to 0. [field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Slot 2: reset the DWORDs at this + 0x28 and this + 0x2C to -1 and clear the byte at this + 0x30 to 0. [field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, source:raw]
    // ASSIGNMENT: Slot 3: with v2 = this + 52, reset the DWORDs at v2 + 8 (this + 0x3C) and v2 + 12 (this + 0x40) to -1 and clear the byte at v2 + 16 (this + 0x44) to 0. [field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, source:raw]
    // ASSIGNMENT: Final slot group: after this += 72, reset the DWORDs at this + 8 and this + 0xC to -1 and clear the byte at this + 0x10 to 0, following the same triple pattern as the earlier slots. [source:raw]
    // RETURN: Return the result of the final StringCopyWithBufferRealloc call (the buffer reinitialization status). [source:raw]
    // CALL: Invoked from MultiPointerFree, DrawableResourceCleanup, SceneListBuilderFromGlobalArray and ShortComputation_8cf0, i.e. from resource teardown and scene/texture construction paths. [caller:0x00414420, caller:0x004150C0, caller:0x00415C40, caller:0x00418CF0]

    // Conservative worker pseudocode:
    //   int TextFormatStructInitializer(int this) {
    //     StringCopyWithBufferRealloc(&byte_5EA438);
    //     *(int*)(this+0x8) = -1; *(int*)(this+0xC) = -1; *(char*)(this+0x10) = 0;
    //     StringCopyWithBufferRealloc(&byte_5EA438);
    //     *(int*)(this+0x14) = -1; *(int*)(this+0x18) = -1; *(char*)(this+0x1C) = 0;
    //     StringCopyWithBufferRealloc(&byte_5EA438);
    //     *(int*)(this+0x28) = -1; *(int*)(this+0x2C) = -1; *(char*)(this+0x30) = 0;
    //     v2 = this + 52;
    //     StringCopyWithBufferRealloc(&byte_5EA438);
    //     *(int*)(v2+8) = -1; *(int*)(v2+12) = -1; *(char*)(v2+16) = 0;
    //     this += 72;
    //     int result = StringCopyWithBufferRealloc(&byte_5EA438);
    //     *(int*)(this+8) = -1; *(int*)(this+12) = -1; *(char*)(this+16) = 0;
    //     return result;
    //   }
    // UNRESOLVED: The raw source writes a final slot group after this += 72, but the packet field list ends at 0x44, so the final group has no packet field evidence reference.
    // UNRESOLVED: Raw source writes to this + 0x14/0x18/0x1C and 0x28/0x2C/0x30 differ in placement from the field list's 0xC/0x10 triple pattern; extraction appears to interpret slots as (DWORD, DWORD, BYTE) triples.
    // UNRESOLVED: Meaning of the -1 sentinel values and the per-slot byte (flag/active marker) is not established statically.
}
