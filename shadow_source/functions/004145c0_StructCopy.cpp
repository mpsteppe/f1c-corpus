// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004145C0
// Canonical corpus name: StructCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructCopy_004145c0.c

void UnknownObject::StructCopy()
{
    // Plain field-by-field copy of an 8-DWORD (32-byte) struct: copies a2[0..7] into this[0..7] in a shuffled order (0,2,3,4,5,6,7,1) and returns the destination pointer this. No transformation, validation, or guard. Used as a helper when inserting driver-table entries and when compacting array slots.
    // ASSIGNMENT: Copy DWORD field 0x0: this[0] = a2[0]. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Copy DWORD field 0x8: this[2] = a2[2]. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Copy DWORD field 0xC: this[3] = a2[3]. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Copy DWORD field 0x10: this[4] = a2[4]. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Copy DWORD field 0x14: this[5] = a2[5]. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Copy DWORD field 0x18: this[6] = a2[6]. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Copy DWORD field 0x1C: this[7] = a2[7]. [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Copy DWORD field 0x4: this[1] = a2[1]. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Take result = this so the destination pointer is returned to the caller. [source:raw]
    // RETURN: Return the destination pointer this (the result). [function:0x004145C0, source:raw]
    // CALL: Used by InsertDriverTableEntry (0x00418560) and ArraySlotCompactionWithGapFilling (0x00418AC0) to copy a 32-byte entry during array insertion and slot compaction. [caller:0x00418560, caller:0x00418AC0, source:raw]

    // Conservative worker pseudocode:
    //   DWORD *sub_4145C0(DWORD *this, DWORD *a2) {
    //     this[0] = a2[0];
    //     this[2] = a2[2];
    //     this[3] = a2[3];
    //     this[4] = a2[4];
    //     this[5] = a2[5];
    //     this[6] = a2[6];
    //     this[7] = a2[7];
    //     this[1] = a2[1];
    //     return this;
    //   }
    // UNRESOLVED: Meaning of the 8 copied DWORDs is not documented in this function; field roles depend on the caller's struct layout (driver-table entries / array slots).
    // UNRESOLVED: Copy order (0,2,3,4,5,6,7,1) is a compiler artifact of the shuffled assignment sequence; no semantic ordering is implied.
}
