// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00472D00
// Canonical corpus name: ConstructorWithVTableAndFieldInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorWithVTableAndFieldInit_00472d00.c

void UnknownObject::ConstructorWithVTableAndFieldInit()
{
    // Constructor for a UI element object: calls the base initialization helper sub_48C070(this, 2), installs the vtable pointer off_5A2400 at this+0x0, zeroes the dword at this+0x31C (source expression this[199]), and returns this. Straight-line, no branches.
    // CALL: Call base initialization helper sub_48C070(this, 2) [callee:0x0048C070, source:raw]
    // ASSIGNMENT: Set the vtable pointer at this+0x0 to off_5A2400 [field:this:0x00000000, global:0x005A2400, source:raw]
    // ASSIGNMENT: Zero the dword field at this+0x31C (source expression this[199]) [field:this:0x0000031C, source:raw]
    // RETURN: Return this as the constructed object [function:0x00472D00, source:raw]

    // Conservative worker pseudocode:
    //   sub_48C070(this, 2);
    //   *this = &off_5A2400;
    //   this[199] = 0;
    //   return this;
    // UNRESOLVED: The contract of base initialization helper sub_48C070 (meaning of parameter 2) is not evidenced at this site
    // UNRESOLVED: The concrete UI element type named by vtable off_5A2400 is not evidenced here
    // UNRESOLVED: The role of the zeroed field at this+0x31C is inferred as an index/pointer, not confirmed
}
