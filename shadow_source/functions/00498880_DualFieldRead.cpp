// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498880
// Canonical corpus name: DualFieldRead
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualFieldRead_00498880.c

void UnknownObject::DualFieldRead()
{
    // Reads two adjacent integer fields at offsets 0x5C (this[23]) and 0x60 (this[24]) and copies them into the output parameters a2 and a3 respectively, returning the second value as the function result.
    // ASSIGNMENT: Copy the integer field at offset 0x5C (this[23]) into the first output parameter a2. [field:this:0x0000005C, source:raw]
    // ASSIGNMENT: Copy the integer field at offset 0x60 (this[24]) into the second output parameter a3. [field:this:0x00000060, source:raw]
    // RETURN: Return the value read from the field at offset 0x60 (this[24]) as the function result. [field:this:0x00000060, source:raw]

    // Conservative worker pseudocode:
    //   int readDualFields(_DWORD* this, _DWORD* a2, _DWORD* a3) {
    //     *a2 = this[23];
    //     *a3 = this[24];
    //     return this[24];
    //   }
    // UNRESOLVED: Semantic meaning of the two adjacent fields (0x5C, 0x60) is not confirmed in this packet; prior analysis proposes computed width/height dimensions but that link is not grounded here.
    // UNRESOLVED: Owner object identity is unknown; the object exposing the two read-only fields is unidentified.
    // UNRESOLVED: Whether the outputs represent dimension, position, or other query data is not statically confirmed.
}
