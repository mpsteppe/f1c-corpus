// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2A30
// Canonical corpus name: BitfieldExtract
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitfieldExtract_004b2a30.c

void UnknownObject::BitfieldExtract()
{
    // Getter with no side effects: reads field 0x2C (this[11]), extracts the 4-bit nibble at bit offset 8 via (>> 8) & 0xF, and returns that value minus 1. Template prelabel classifies it as a getter (DERIVED).
    // CALCULATION: Reads this[11] at offset 0x2C, right-shifts by 8 and masks with 0xF to extract the 4-bit field at bits 8..11, then subtracts 1. [abi:lead, field:this:0x0000002C, function:0x004B2A30, source:raw]
    // RETURN: Returns ((this[11] >> 8) & 0xF) - 1. [source:raw]

    // Conservative worker pseudocode:
    //   int BitfieldExtract(_DWORD *this) {
    //       return ((this[11] >> 8) & 0xF) - 1;
    //   }
    // UNRESOLVED: Meaning of the extracted nibble (and the -1 adjustment) is not evidenced in this packet.
    // UNRESOLVED: Field 0x2C read-only here; writer elsewhere not identified from this packet.
}
