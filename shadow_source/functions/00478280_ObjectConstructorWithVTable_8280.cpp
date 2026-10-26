// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00478280
// Canonical corpus name: ObjectConstructorWithVTable_8280
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructorWithVTable_8280_00478280.c

void UnknownObject::ObjectConstructorWithVTable_8280()
{
    // Object constructor: calls the sub-initializer ShortComputation_fb70 on this, installs the vtable pointer off_5A48C0 at offset 0x0, and initializes the DWORD field at offset 0xE8 to -1.
    // CALL: Call the sub-initializer ShortComputation_fb70 on this before field initialization [callee:0x0048FB70, source:raw]
    // ASSIGNMENT: Install the vtable pointer by writing the address of off_5A48C0 to the object header at offset 0x0 [field:this:0x00000000, global:0x005A48C0, source:raw]
    // ASSIGNMENT: Initialize this[58], the DWORD field at offset 0xE8, to -1 (all-bits-set sentinel) [field:this:0x000000E8, source:raw]
    // RETURN: Return this, completing the constructor [source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_fb70(this);
    //   *this = &off_5A48C0;
    //   this[58] = -1;
    //   return this;
    // UNRESOLVED: Semantic role of the -1 sentinel stored at offset 0xE8 (candidate: limit/max marker) is not verifiable from this packet
    // UNRESOLVED: The identity and purpose of the off_5A48C0 vtable and the ShortComputation_fb70 sub-initializer are not established here
}
