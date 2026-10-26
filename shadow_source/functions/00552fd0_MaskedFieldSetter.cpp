// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00552FD0
// Canonical corpus name: MaskedFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MaskedFieldSetter_00552fd0.c

void UnknownObject::MaskedFieldSetter()
{
    // Writes two masked flag values into the this object: (a2 & 0x20) into this[19] at offset 0x4C and (a3 & 0xC0) into this[20] at offset 0x50. Returns the masked a2 value. No guards; both fields are always written.
    // CALCULATION: Mask parameter a2: result = a2 & 0x20 (isolates bit 5). [source:raw]
    // ASSIGNMENT: Store the masked a2 value into this[19] at offset 0x4C. [field:this:0x0000004C, source:raw]
    // CALCULATION: Mask parameter a3: a3 & 0xC0 (isolates bits 6-7). [source:raw]
    // ASSIGNMENT: Store the masked a3 value into this[20] at offset 0x50. [field:this:0x00000050, source:raw]
    // RETURN: Return the masked a2 value as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   int MaskedFieldSetter(_DWORD *this, char a2, char a3) {
    //     int masked = a2 & 0x20;
    //     this[19] = masked;        // offset 0x4C
    //     this[20] = a3 & 0xC0;     // offset 0x50
    //     return masked;
    //   }
    // UNRESOLVED: Semantic meaning of the two flag fields (0x4C bit 0x20 and 0x50 bits 0xC0) is not established here; the object type owning this is unknown.
    // UNRESOLVED: The two static callers sub_4D8AB0 and FontSurfaceLookupDispatch (0053d260) reach this setter, but their exact call context is not in this packet.
}
