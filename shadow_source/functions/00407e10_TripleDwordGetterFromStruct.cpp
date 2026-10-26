// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00407E10
// Canonical corpus name: ShortComputation_7e10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_7e10_00407e10.c

void UnknownObject::TripleDwordGetterFromStruct()
{
    // Reads three consecutive DWORDs from this+0x94, +0x98 and +0x9C and writes them through output pointers a2, a3 and a4. Unconditional getter; returns the third value (this[39]). Called by ShortComputation_6100 (00406100).
    // ASSIGNMENT: Write this[37] (offset 0x94) to output a2. [field:this:0x00000094, source:raw]
    // ASSIGNMENT: Write this[38] (offset 0x98) to output a3. [field:this:0x00000098, source:raw]
    // ASSIGNMENT: Write this[39] (offset 0x9C) to output a4 and seed the return value with it. [field:this:0x0000009C, source:raw]
    // RETURN: Return this[39], the third read DWORD. [function:0x00407E10, source:raw]
    // CALL: Invoked by ShortComputation_6100 (00406100) to pull the triple of values out of this object. [caller:0x00406100]

    // Conservative worker pseudocode:
    //   int sub_407E10(DWORD *this, DWORD *a2, DWORD *a3, DWORD *a4) {
    //     *a2 = this[37]; // +0x94
    //     *a3 = this[38]; // +0x98
    //     *a4 = this[39]; // +0x9C
    //     return this[39];
    //   }
    // UNRESOLVED: The meaning of the three values at +0x94/+0x98/+0x9C and the consuming context in caller ShortComputation_6100 are not described in the packet.
    // UNRESOLVED: The owning class of this method is unknown; the packet labels it UnknownObject.
}
