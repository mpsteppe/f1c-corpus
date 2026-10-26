// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046F610
// Canonical corpus name: ConstructorWithVTableAndParamStore
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorWithVTableAndParamStore_0046f610.c

void UnknownObject::ConstructorWithVTableAndParamStore()
{
    // Object constructor: delegates to ConstructorWithByteParams(this, 0, 0) to zero-initialize the object, stores integer parameter a2 at offset 0xE4 (this[57]), assigns vtable pointer off_59FF80 at offset 0x0, then returns this.
    // CALL: ConstructorWithByteParams(this, 0, 0) - base initializer that zero-initializes the object with two zero byte parameters. [callee:0x00487220, source:raw]
    // ASSIGNMENT: this[57] = a2 - store integer constructor parameter a2 at offset 0xE4. [field:this:0x000000E4, source:raw]
    // ASSIGNMENT: *this = &off_59FF80 - set vtable pointer at offset 0x0 to off_59FF80. [field:this:0x00000000, global:0x0059FF80, source:raw]
    // RETURN: Return the constructed object pointer (this). [function:0x0046F610, source:raw]

    // Conservative worker pseudocode:
    //   ConstructorWithByteParams(this, 0, 0);
    //   this[57] = a2;
    //   *this = &off_59FF80;
    //   return this;
    // UNRESOLVED: Purpose of the stored parameter at offset 0xE4 is unknown; no consumer is referenced in this packet.
    // UNRESOLVED: No static callers recorded, so object type and lifetime are unproven.
}
