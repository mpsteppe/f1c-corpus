// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004084B0
// Canonical corpus name: ShortComputation_84b0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_84b0_004084b0.c

void UnknownObject::LargeStructConstructorWithVTable()
{
    // Object constructor for a managed type. Installs the vtable pointer off_59E60C at offset 0x0, zeroes the fields at offsets 0x4 through 0x30 and 0x38 through 0x4C, sets offset 0x34 to -1 (sentinel/id marker) and offset 0x50 to 2 (count/enum), then returns the this pointer. Straight-line initialization with no branches.
    // ASSIGNMENT: Install the vtable pointer: *this = &off_59E60C at offset 0x0. [field:this:0x00000000, global:0x0059E60C, function:0x004084B0, abi:lead, source:raw]
    // ASSIGNMENT: Zero the fields at offsets 0x4 through 0x30 (this[1]..this[12]). [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, source:raw]
    // ASSIGNMENT: Set the field at offset 0x34 to -1 (uninitialized sentinel/id marker). [field:this:0x00000034, source:raw]
    // ASSIGNMENT: Zero the fields at offsets 0x38 through 0x4C (this[14]..this[19]). [field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, source:raw]
    // ASSIGNMENT: Set the field at offset 0x50 to 2 (count or enum value). [field:this:0x00000050, source:raw]
    // RETURN: Return the this pointer (result = this). [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_4084B0(_DWORD *this) {
    //     _DWORD *result = this;
    //     this[0] = &off_59E60C;
    //     this[1] = 0; this[2] = 0; ... this[12] = 0;
    //     this[13] = -1;
    //     this[14] = 0; ... this[19] = 0;
    //     this[20] = 2;
    //     return result;
    //   }
    // UNRESOLVED: Purpose of the -1 sentinel at offset 0x34 and the constant 2 at offset 0x50 is unknown without inspecting the caller or later consumers.
    // UNRESOLVED: Concrete type of the object (vtable off_59E60C) and the exact set of construction-time invariants it establishes are unknown.
    // UNRESOLVED: Semantics of the sole caller sub_40C140 are not analyzed here.
}
