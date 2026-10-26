// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00467260
// Canonical corpus name: ObjectConstructorWithParameterSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructorWithParameterSetup_00467260.c

void UnknownObject::ConstructorWithDataTableIndex()
{
    // __thiscall constructor. Calls sub_48C070(0) for base setup, installs vtable off_59F4F8, stores parameter a2 as the object index (this[201], +0x324), derives a per-object data table pointer from global base unk_7C6270 using a 64-byte stride indexed by a2 (this[200], +0x320), stores a3 at this[199] (+0x31C), initializes two fields to 11 and 4 (this[202]/this[203], +0x328/+0x32C), clears the byte flag at +0x305, and returns this. Object class is unknown; the skeleton analysis labels it a window-manager constructor (DERIVED prose only).
    // CALL: Base-initialization sub_48C070 invoked with argument 0 before any field setup. [callee:0x0048C070]
    // ASSIGNMENT: Store index parameter a2 into this[201] at offset 0x324. [field:this:0x00000324]
    // ASSIGNMENT: Install vtable pointer: *this = &off_59F4F8 at offset 0x0. [field:this:0x00000000, global:0x0059F4F8]
    // CALCULATION: Compute per-object data table pointer as (char*)unk_7C6270 + 64 * a2, a 64-byte-strided table addressed by the index a2. [global:0x007C6270]
    // ASSIGNMENT: Store the computed data table pointer into this[200] at offset 0x320. [field:this:0x00000320]
    // ASSIGNMENT: Store parameter a3 (count/size candidate) into this[199] at offset 0x31C. [field:this:0x0000031C]
    // ASSIGNMENT: Initialize this[202] at offset 0x328 to the literal 11. [field:this:0x00000328]
    // ASSIGNMENT: Initialize this[203] at offset 0x32C to the literal 4. [field:this:0x0000032C]
    // ASSIGNMENT: Clear the byte flag at this + 0x305 to 0. [field:this:0x00000305]
    // RETURN: Return the constructed this pointer. [function:0x00467260, source:raw]

    // Conservative worker pseudocode:
    //   void* sub_467260(void* this, int a2, int a3) {
    //     sub_48C070(0);
    //     this->slot201 = a2;
    //     this->vtable = &off_59F4F8;
    //     this->slot200 = (char*)&unk_7C6270 + 64 * a2;
    //     this->slot199 = a3;
    //     this->slot202 = 11;
    //     this->slot203 = 4;
    //     this->flagByte0x305 = 0;
    //     return this;
    //   }
    // UNRESOLVED: Object class is unknown (owner packet trust UNKNOWN); the window-manager label is DERIVED skeleton prose, not evidence.
    // UNRESOLVED: Semantics of parameter a3 stored at +0x31C (candidate size/count) are unproven.
    // UNRESOLVED: Meaning of the literals 11 and 4 at +0x328/+0x32C and the cleared flag byte at +0x305 is unknown.
    // UNRESOLVED: Element layout and purpose of the unk_7C6270 64-byte-strided table are unresolved here.
}
