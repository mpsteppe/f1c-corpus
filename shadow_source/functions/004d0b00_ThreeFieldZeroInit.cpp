// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D0B00
// Canonical corpus name: F_3FieldInitCall_0b00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3FieldInitCall_0b00_004d0b00.c

void UnknownObject::ThreeFieldZeroInit()
{
    // Struct field zeroing stub. Zeros three non-contiguous DWORD fields of the object (this+0x64, this+0x6C, this+0x74), then calls sub_4A2220 to perform a broader zero-initialization of the remaining struct memory. Returns the object pointer. Called by sub_4D0110.
    // ASSIGNMENT: Zeros this+0x64 (field offset 100) unconditionally [field:this:0x00000064, source:raw]
    // ASSIGNMENT: Zeros this+0x6C (field offset 108) unconditionally [field:this:0x0000006C, source:raw]
    // ASSIGNMENT: Zeros this+0x74 (field offset 116) unconditionally [field:this:0x00000074, source:raw]
    // CALL: sub_4A2220 called unconditionally on the object for full zero-initialization of the struct memory [callee:0x004A2220, source:raw]
    // RETURN: Returns this (the object pointer) to the caller [source:raw]
    // CALL: Invoked by sub_4D0110 as part of the surrounding construction sequence [caller:0x004D0110, source:raw]

    // Conservative worker pseudocode:
    //   this[100/4] = 0;
    //   this[108/4] = 0;
    //   this[116/4] = 0;
    //   sub_4A2220(this);
    //   return this;
    // UNRESOLVED: The semantic role of the three zeroed fields (this+0x64, +0x6C, +0x74) is not established from this packet alone
    // UNRESOLVED: Owner class and the effect of sub_4A2220 beyond 'full zero-initialization' are unknown from this packet
    // UNRESOLVED: The three zeroed offsets are not contiguous (0x64/0x6C/0x74), so no single array base is implied
}
