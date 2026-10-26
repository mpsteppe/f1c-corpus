// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005416A0
// Canonical corpus name: DirectXVertexBufferTextureCoordinateSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DirectXVertexBufferTextureCoordinateSetup_005416a0.c

void UnknownObject::DirectXVertexBufferTextureCoordinateSetup()
{
    // Builds a block of scaled texture-coordinate data from a descriptor object (a2) and submits it through a vtable call on the DirectX object held at this offset 0x1100. Guarded by the flag at this offset 0x13D8 and by a4 != 1. Stores vtable call results into *this (offset 0x0) and returns -1 on failure, 0 on success.
    // GUARD: Proceed only when the guard flag this[1270] (offset 0x13D8) is non-zero and a4 is not 1; otherwise return 0 without updating. [field:this:0x000013D8]
    // ASSIGNMENT: Zero-initialize a 26-dword (104-byte) local scratch array used to build the texture-coordinate block. [source:raw]
    // STATE_TRANSITION: Switch on the descriptor type (low 3 bits of the dword at a2): case 1 sets element 0 to 3 and element 19 to literal 1399379109; cases 2 and 4 set element 0 to 1 and element 19 to the dword at a2+80. [source:raw]
    // CALCULATION: Fill float elements of the scratch array with scaled products of descriptor fields: elements 1-3 are (a2+24, a2+28, a2+32) times (a2+36); elements 5-7 are (a2+40, a2+44, a2+48) times (a2+52); elements 9-11 are (a2+8, a2+12, a2+16) times (a2+20). Copy dwords from a2+56 through a2+76 into elements 13-18. [source:raw]
    // ASSIGNMENT: Set element 21 to literal 1065353216 (float 1.0) and elements 22 and 23 to zero. [source:raw]
    // CALL: Load the DX object from this[1088] (offset 0x1100), call its vtable slot 176 (offset 0xB0) as (object, a3, scratch array), and store the result into *this (offset 0x0). [field:this:0x00001100, field:*(this+0x1100):0x000000B0, field:this:0x00000000]
    // GUARD: If the vtable call returned non-zero, return -1 to signal failure. [field:this:0x00000000]
    // CALL: If the low bit of the descriptor dword at a2 is set, call vtable slot 184 (offset 0xB8) as (object, a3, 1) and store the result into *this (offset 0x0). [field:this:0x00000000, field:*(this+0x1100):0x000000B8]
    // RETURN: Return 0 on success. [source:raw]

    // Conservative worker pseudocode:
    //   if (!this[1270] || a4 == 1) return 0;
    //   memset(scratch, 0, 104);
    //   switch (*(int *)a2 & 7) { case 1: scratch[0]=3; scratch[19]=1399379109; break; case 2: case 4: scratch[0]=1; scratch[19]=*(int *)(a2+80); break; }
    //   fill scaled texture coordinates from a2 descriptor fields; scratch[21]=1065353216; scratch[22]=0; scratch[23]=0;
    //   result = call vtable[176](object, a3, scratch); *this = result; if (result) return -1;
    //   if ((*(char *)a2 & 1) != 0) *this = call vtable[184](object, a3, 1);
    //   return 0;
    // UNRESOLVED: The descriptor layout of a2 and the semantic meaning of each scratch element are not recoverable from this packet; the switch on the low 3 bits and the scaled products suggest a texture-coordinate or vertex-format block, but element semantics remain GUESS.
    // UNRESOLVED: The concrete DX interface whose vtable slots 176 and 184 are called through the object at this offset 0x1100 is not identified.
}
