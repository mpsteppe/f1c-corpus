// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A930
// Canonical corpus name: ConstructorWith1Sentinels
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorWith1Sentinels_0049a930.c

void UnknownObject::ConstructorWithSentinelInit()
{
    // Object constructor: delegates initialization of a sub-object at dword index 9 to ThunkToFUN00491330, zeroes the fields at offsets 0x4, 0x8, 0xC, 0x10, 0x34 and the byte at 0x3C, fills the fields at offsets 0x14, 0x18, 0x1C, 0x20 and 0x38 with the -1 sentinel (empty/invalid marker), and installs the vtable pointer off_5ACAB0 at offset 0x0. Returns the constructed this pointer.
    // CALL: Initialize the sub-object at dword index 9 via ThunkToFUN00491330 before the scalar field initialization. [callee:0x004912F0, source:raw]
    // ASSIGNMENT: Zero the four consecutive DWORD fields at offsets 0x4, 0x8, 0xC and 0x10. [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010]
    // ASSIGNMENT: Zero the DWORD at offset 0x34 and the byte at offset 0x3C. [field:this:0x00000034, field:this:0x0000003C]
    // ASSIGNMENT: Set the DWORD at offset 0x38 to the -1 sentinel marker. [field:this:0x00000038]
    // ASSIGNMENT: Set the four consecutive DWORD fields at offsets 0x14, 0x18, 0x1C and 0x20 to the -1 sentinel marker. [field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020]
    // ASSIGNMENT: Install the vtable pointer off_5ACAB0 at offset 0x0, completing construction. [global:0x005ACAB0, field:this:0x00000000]
    // RETURN: Return the constructed this pointer; invoked by ShortComputation_5e30, InitWithVTableParam and FunctionCallWrapper_91e0. [function:0x0049A930, caller:0x00485E30, caller:0x00498D20, caller:0x004991E0, source:raw]

    // Conservative worker pseudocode:
    //   DWORD* sub_49A930(DWORD* this) {
    //     ThunkToFUN00491330(this + 9);
    //     this[1] = 0; this[2] = 0; this[3] = 0; this[4] = 0;
    //     this[13] = 0;
    //     *(BYTE*)this + 0x3C = 0;
    //     this[14] = -1;
    //     this[5] = -1; this[6] = -1; this[7] = -1; this[8] = -1;
    //     this[0] = (DWORD)&off_5ACAB0;
    //     return this;
    //   }
    // UNRESOLVED: Purpose of the sub-object at dword index 9 is determined by ThunkToFUN00491330, outside this function.
    // UNRESOLVED: Semantic role of the -1 sentinel fields (0x14-0x20, 0x38) versus the zeroed fields is not established.
}
