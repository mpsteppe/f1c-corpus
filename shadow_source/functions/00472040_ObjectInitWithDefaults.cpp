// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00472040
// Canonical corpus name: ObjectInitWithDefaults
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitWithDefaults_00472040.c

void UnknownObject::ObjectInitWithDefaults()
{
    // Minimal object/UI-component constructor. Runs the base initializer ShortComputation_6d60 with flag 1, nulls the pointer field at this+0x31C and the field at this+0x328, installs the vtable pointer off_5A1A40 at this+0x0, then writes the literal fields 32, 1, 1, 252 at this+0x324, +0x32C, +0x330, +0x334. Unconditional sequence with no guards; returns this.
    // CALL: Call the base initializer ShortComputation_6d60(this, 1) with flag 1 before any field is written. [callee:0x00466D60, source:raw]
    // ASSIGNMENT: Write 0 into this+0x31C (this[199]), leaving the pointer field null. [field:this:0x0000031C, source:raw]
    // ASSIGNMENT: Write 0 into this+0x328 (this[202]). [field:this:0x00000328, source:raw]
    // ASSIGNMENT: Install the vtable pointer off_5A1A40 at this+0x0. [field:this:0x00000000, global:0x005A1A40, source:raw]
    // ASSIGNMENT: Write literal 32 into this+0x324 (this[201]). [field:this:0x00000324, source:raw]
    // ASSIGNMENT: Write literal 1 into this+0x32C (this[203]). [field:this:0x0000032C, source:raw]
    // ASSIGNMENT: Write literal 1 into this+0x330 (this[204]). [field:this:0x00000330, source:raw]
    // ASSIGNMENT: Write literal 252 into this+0x334 (this[205]). [field:this:0x00000334, source:raw]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   ObjectInitWithDefaults(this) {
    //     ShortComputation_6d60(this, 1);
    //     this[199] = 0;
    //     this[202] = 0;
    //     this[0] = &off_5A1A40;
    //     this[201] = 32;
    //     this[203] = 1;
    //     this[204] = 1;
    //     this[205] = 252;
    //     return this;
    //   }
    // UNRESOLVED: Roles of the literal fields at this+0x324 (32), +0x328 (0), +0x32C (1), +0x330 (1) and +0x334 (252) are not established by this packet.
    // UNRESOLVED: Whether the null write at this+0x31C corresponds to an unbound external data source is inferred from existing analysis (component ID 252, option count 32) and not proven here.
    // UNRESOLVED: The owning class is UnknownObject; this packet lists no callers and the function is not on a frame path.
}
