// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054C0B0
// Canonical corpus name: BitFlagReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitFlagReader_0054c0b0.c

void UnknownObject::BitFlagReader()
{
    // Conditional getter that reads two single-bit flags out of the complement of this[15] (dword field at offset 0x3C). If a2 is non-null it is set to bit 1 ((~this[15] >> 1) & 1); if a3 is non-null it is set to bit 2 ((~this[15] >> 2) & 1). Always returns a3.
    // GUARD: Guard on a2 being non-null before writing the first bit through it. [source:raw]
    // CALCULATION: Extract bit 1 of the complement of dword field this[15]: ((~this[15] >> 1) & 1). [field:this:0x0000003C, source:raw]
    // ASSIGNMENT: Store the extracted bit-1 value into *a2. [source:raw]
    // GUARD: Guard on a3 being non-null before writing the second bit through it. [source:raw]
    // CALCULATION: Extract bit 2 of the complement of dword field this[15]: ((~this[15] >> 2) & 1). [field:this:0x0000003C, source:raw]
    // ASSIGNMENT: Store the extracted bit-2 value into *a3. [source:raw]
    // RETURN: Return a3 (null-safe; no effect when a3 is null). [source:raw]

    // Conservative worker pseudocode:
    //   unsigned int *BitFlagReader(unsigned int *this, unsigned int *a2, unsigned int *a3) {
    //     if (a2)
    //       *a2 = ((~this[15] >> 1) & 1);
    //     if (a3)
    //       *a3 = ((~this[15] >> 2) & 1);
    //     return a3;
    //   }
    // UNRESOLVED: Semantic meaning of the two bit flags (active bit inversion is implied by the complement) and which callers interpret them how (callers: ConditionalAudioParamSetup, VehicleStateUpdate_19d0).
    // UNRESOLVED: Packet prelabel tags this as a DERIVED getter template reading field 0x3C; that template classification is not independent confirmation of the owning class.
}
