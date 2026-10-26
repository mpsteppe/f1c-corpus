// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479CD0
// Canonical corpus name: ConstructorWithRangeInitAndFlag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorWithRangeInitAndFlag_00479cd0.c

void UnknownObject::ConstructorWithRangeInitAndFlag()
{
    // UI-object constructor: calls UIConstructorWithVTableParams with two large integer parameters (bit patterns 1101004800 and 1120403456), installs the vtable pointer off_5A5CD0 at offset 0x0, then sets the byte enable flag at offset 0xF0 to 1.
    // CALL: Call UIConstructorWithVTableParams(this, 1101004800, 1120403456) to initialize UI object fields with the two supplied integer parameters [callee:0x0048D3A0, source:raw]
    // ASSIGNMENT: Install the vtable pointer by writing the address of off_5A5CD0 to the object header at offset 0x0 [field:this:0x00000000, global:0x005A5CD0, source:raw]
    // ASSIGNMENT: Set this[240], the byte flag at offset 0xF0, to 1 (enabled/active) [field:this:0x000000F0, source:raw]
    // RETURN: Return this, completing the constructor [source:raw]

    // Conservative worker pseudocode:
    //   UIConstructorWithVTableParams(this, 1101004800, 1120403456);
    //   *(DWORD*)this = &off_5A5CD0;
    //   this[240] = 1;
    //   return this;
    // UNRESOLVED: The two large integer parameters 1101004800 and 1120403456 are treated as opaque; a float-range interpretation (matching ~20.0f and ~100.0f) is suggested by existing analysis but is not derivable from this packet alone
    // UNRESOLVED: The identity and purpose of the off_5A5CD0 vtable are not established here
}
