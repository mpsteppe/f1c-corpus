// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FC901
// Canonical corpus name: ObjectFieldInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectFieldInitializer_004fc901.c

void UnknownObject::InitThreeFloatFields()
{
    // Initializer that writes three consecutive dwords on an object (this in EAX, parameter passed via ECX): field 0xC is set from the ECX parameter, and fields 0x10 and 0x14 are both set to 1101004800 (20.0f). Returns this unchanged.
    // ASSIGNMENT: Set field at offset 0xC from the ECX parameter a2. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Set field at offset 0x10 to 1101004800, the bit pattern of 20.0f. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Set field at offset 0x14 to 1101004800, the bit pattern of 20.0f. [field:this:0x00000014, source:raw]
    // RETURN: Return this (result) unchanged after the writes. [function:0x004FC901, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *InitThreeFloatFields(_DWORD *this, int a2) {
    //     this[3] = a2;
    //     this[4] = 1101004800;
    //     this[5] = 1101004800;
    //     return this;
    //   }
    // UNRESOLVED: Meaning of the ECX parameter a2 and the identity of the owning object are unknown.
    // UNRESOLVED: Whether the 20.0f values are initialized positions or sizes is not evidenced.
}
