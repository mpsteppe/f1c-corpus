// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004711A0
// Canonical corpus name: UIModeInitWithDefaults
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIModeInitWithDefaults_004711a0.c

void UnknownObject::UIModeInitWithDefaults()
{
    // UI-mode object constructor. First runs the base initializer ShortComputation_6d60 with flag 1, then installs the vtable pointer off_5A0B40 at this+0x0, stores the address of global dword_7D0A20 into this+0x31C, and writes the literal fields 99, 2, 1, 1 at this+0x324, +0x328, +0x32C, +0x330. Unconditional sequence with no guards; returns this.
    // CALL: Call the base initializer ShortComputation_6d60(this, 1) with flag 1 before any field is written. [callee:0x00466D60, source:raw]
    // ASSIGNMENT: Install the vtable pointer off_5A0B40 at this+0x0. [field:this:0x00000000, global:0x005A0B40, source:raw]
    // ASSIGNMENT: Store the address of global dword_7D0A20 into this+0x31C (this[199]). [field:this:0x0000031C, global:0x007D0A20, source:raw]
    // ASSIGNMENT: Write literal 99 into this+0x324 (this[201]). [field:this:0x00000324, source:raw]
    // ASSIGNMENT: Write literal 2 into this+0x328 (this[202]). [field:this:0x00000328, source:raw]
    // ASSIGNMENT: Write literal 1 into this+0x32C (this[203]). [field:this:0x0000032C, source:raw]
    // ASSIGNMENT: Write literal 1 into this+0x330 (this[204]). [field:this:0x00000330, source:raw]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   UIModeInitWithDefaults(this) {
    //     ShortComputation_6d60(this, 1);
    //     this[0] = &off_5A0B40;
    //     this[199] = &dword_7D0A20;
    //     this[201] = 99;
    //     this[202] = 2;
    //     this[203] = 1;
    //     this[204] = 1;
    //     return this;
    //   }
    // UNRESOLVED: Roles of the literal fields at this+0x324 (99), +0x328 (2), +0x32C (1) and +0x330 (1) are not established by this packet.
    // UNRESOLVED: Semantics of the pointer field at this+0x31C, which receives the address of global dword_7D0A20, are inferred from existing analysis (SessionVehicleCount) and not proven here.
    // UNRESOLVED: The owning class is UnknownObject; this packet lists no callers and the function is not on a frame path.
}
