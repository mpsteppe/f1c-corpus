// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00407EF0
// Canonical corpus name: BitfieldExtractFromStruct
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitfieldExtractFromStruct_00407ef0.c

void UnknownObject::BitfieldExtractFromStruct()
{
    // Getter with no side effects: reads the unsigned byte at offset 27 of the caller-supplied structure, shifts it right by 4 and masks with 2, returning either 0 or 2 depending on the single bit (bit 5) of that byte.
    // CALCULATION: Read the unsigned byte at a1 + 27 (offset 0x1B) of the structure. [source:raw, field:this:0x0000001B]
    // CALCULATION: Extract bit 5 of the byte by shifting right 4 then masking with 2. [source:raw]
    // RETURN: Return the extracted bit value, which is 0 or 2. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_407EF0(int this) {
    //     return (this[27] >> 4) & 2;
    //   }
    // UNRESOLVED: The meaning of the extracted bit in the containing structure is caller-specific and not established.
    // UNRESOLVED: The structure type and the identity of the object behind a1 are unknown.
}
