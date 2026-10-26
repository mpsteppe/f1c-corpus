// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046F890
// Canonical corpus name: ShortComputation_f890
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_f890_0046f890.c

void UnknownObject::ByteParamConstructorWithVtable()
{
    // Object constructor: delegates to the base constructor ConstructorWithByteParams (00487220) with (this, 0, 0), stores the byte parameter a2 at this[228] (offset 0xE4), installs the vtable pointer off_5A0040 at this[0], and returns the initialized this pointer.
    // CALL: Initialize base state: ConstructorWithByteParams(this, 0, 0) (00487220) [callee:0x00487220, source:raw]
    // ASSIGNMENT: Store the byte parameter: this[228] = a2 at offset 0xE4 [field:this:0x000000E4, source:raw]
    // ASSIGNMENT: Install vtable: write the address of off_5A0040 (0x005A0040) into the object's first dword at offset 0 [field:this:0x00000000, global:0x005A0040, source:raw]
    // RETURN: Return the initialized this pointer to the caller [function:0x0046F890, source:raw]

    // Conservative worker pseudocode:
    //   ConstructorWithByteParams(this, 0, 0);
    //   this[228] = a2;
    //   *(_DWORD*)this = &off_5A0040;
    //   return this;
    // UNRESOLVED: The meaning of the byte stored at this[228] (offset 0xE4) and of the two zero base-constructor arguments is unknown
    // UNRESOLVED: The vtable off_5A0040 and the object class are unidentified; the derived owner type cannot be proposed
}
