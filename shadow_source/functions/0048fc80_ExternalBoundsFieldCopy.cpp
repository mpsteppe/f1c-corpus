// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048FC80
// Canonical corpus name: StructFieldCopy_fc80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructFieldCopy_fc80_0048fc80.c

void UnknownObject::ExternalBoundsFieldCopy()
{
    // Copies rectangle dimensions from a nested external source struct into local fields. Stores the source pointer at this+0x38, reads the width from the struct pointed at by *(a2+12) at offset +28 into this+0xC, and reads the height from *(a2+12) at offset +32 into this+0x10. Returns the nested source struct pointer (value of *(a2+12)). Unconditional, no branches.
    // ASSIGNMENT: Store the source pointer a2 into this+0x38 (this[14]). [field:this:0x00000038, source:raw]
    // ASSIGNMENT: Read the nested struct pointer *(a2+12), dereference offset +28 and write the resulting width into this+0xC (this[3]). [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Hold the nested struct pointer *(a2+12) in result for reuse. [source:raw]
    // ASSIGNMENT: Read offset +32 of the nested struct pointer and write the resulting height into this+0x10 (this[4]). [field:this:0x00000010, source:raw]
    // RETURN: Return the nested struct pointer result (value of *(a2+12)). [source:raw, caller:0x00477830, caller:0x00477CB0]

    // Conservative worker pseudocode:
    //   int __thiscall sub_48FC80(_DWORD *this, int a2) {
    //     this[0x38/4] = a2;
    //     this[0x0C/4] = *(*(a2 + 12) + 28);
    //     int nested = *(a2 + 12);
    //     this[0x10/4] = *(nested + 32);
    //     return nested;
    //   }
    // UNRESOLVED: Class identity of `this` (0x38/0xC/0x10 owner) is unproven; only callers GameFilterSetup (00477830) and ProfileBitmapBrowser (00477CB0) constrain it.
    // UNRESOLVED: Semantic meaning of the +28/+32 reads inside the nested source struct is not documented.
}
