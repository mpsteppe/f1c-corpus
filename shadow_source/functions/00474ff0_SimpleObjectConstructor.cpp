// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00474FF0
// Canonical corpus name: SimpleObjectConstructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SimpleObjectConstructor_00474ff0.c

void UnknownObject::SimpleObjectConstructor()
{
    // UI-object constructor: delegates to the base constructor ConstructorWithByteParams with two zeroed byte parameters, stores the caller-supplied integer a2 into field at offset 0xE4, then installs the vtable pointer off_5A42C0.
    // CALL: Call base constructor ConstructorWithByteParams(this, 0, 0) with zeroed byte initialization parameters [callee:0x00487220, source:raw]
    // ASSIGNMENT: Store the integer parameter a2 into this[57], the DWORD field at offset 0xE4 [field:this:0x000000E4, source:raw]
    // ASSIGNMENT: Install the vtable pointer by writing the address of off_5A42C0 to the object header at offset 0x0 [field:this:0x00000000, global:0x005A42C0, source:raw]
    // RETURN: Return this, completing the constructor [source:raw]

    // Conservative worker pseudocode:
    //   ConstructorWithByteParams(this, 0, 0);
    //   this[57] = a2;
    //   *this = &off_5A42C0;
    //   return this;
    // UNRESOLVED: Semantic role of the integer a2 stored at 0xE4 is not evident from this function alone
    // UNRESOLVED: The identity and purpose of the off_5A42C0 vtable are not verifiable from this packet
}
