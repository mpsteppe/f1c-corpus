// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004702A0
// Canonical corpus name: InitWithVTableSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitWithVTableSet_004702a0.c

void UnknownObject::InitWithVTableSet()
{
    // Object constructor: delegates to ConstructorWithStringCopy(this, 0, 0, 0, 0, 1, 0) as base initializer, stores integer parameter a2 at offset 0x304 (this[193]), assigns vtable pointer off_5A0308 at offset 0x0, then returns this.
    // CALL: ConstructorWithStringCopy(this, 0, 0, 0, 0, 1, 0) - base initializer called with zeros and a trailing 1 flag; string-copy capable constructor. [callee:0x0048B420, source:raw]
    // ASSIGNMENT: this[193] = a2 - store integer constructor parameter a2 at offset 0x304. [field:this:0x00000304, source:raw]
    // ASSIGNMENT: *this = &off_5A0308 - set vtable pointer at offset 0x0 to off_5A0308. [field:this:0x00000000, global:0x005A0308, source:raw]
    // RETURN: Return the constructed object pointer (this). [function:0x004702A0, source:raw]

    // Conservative worker pseudocode:
    //   ConstructorWithStringCopy(this, 0, 0, 0, 0, 1, 0);
    //   this[193] = a2;
    //   *this = &off_5A0308;
    //   return this;
    // UNRESOLVED: Purpose of the stored parameter at offset 0x304 is unknown; no consumer is referenced in this packet.
    // UNRESOLVED: The trailing 1 flag passed to ConstructorWithStringCopy has unproven meaning (enable-string-copy flag proposed, not confirmed).
    // UNRESOLVED: No static callers recorded, so object type and lifetime are unproven.
}
