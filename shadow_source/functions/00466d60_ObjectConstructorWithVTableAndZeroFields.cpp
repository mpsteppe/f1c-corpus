// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466D60
// Canonical corpus name: ShortComputation_6d60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_6d60_00466d60.c

void UnknownObject::ObjectConstructorWithVTableAndZeroFields()
{
    // Object initializer: invokes sub_48C070(a2) on the passed parameter, zeroes six state fields at this+0x31C through this+0x330, installs the vtable pointer off_59F438 at this+0x0, and returns this. Called from 33 UI/widget constructor paths.
    // CALL: Call sub_48C070(a2) with the second parameter before field initialization. [callee:0x0048C070, source:raw]
    // ASSIGNMENT: Zero field this+0x31C (this[199]). [field:this:0x0000031C]
    // ASSIGNMENT: Zero field this+0x32C (this[203]). [field:this:0x0000032C]
    // ASSIGNMENT: Zero field this+0x330 (this[204]). [field:this:0x00000330]
    // ASSIGNMENT: Zero field this+0x328 (this[202]). [field:this:0x00000328]
    // ASSIGNMENT: Zero field this+0x324 (this[201]). [field:this:0x00000324]
    // ASSIGNMENT: Set vtable pointer *this = &off_59F438. [field:this:0x00000000, global:0x0059F438]
    // RETURN: Return this as the initialized object pointer. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_466D60(_DWORD *this, int a2) {
    //     sub_48C070(a2);
    //     this[199] = 0;
    //     this[203] = 0;
    //     this[204] = 0;
    //     this[202] = 0;
    //     this[201] = 0;
    //     *this = &off_59F438;
    //     return this;
    //   }
    // UNRESOLVED: Identity of the owner class behind vtable off_59F438 is not determinable here.
    // UNRESOLVED: Semantics of parameter a2 and of sub_48C070(a2) are caller-side.
}
