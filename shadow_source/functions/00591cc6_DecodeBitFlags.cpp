// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00591CC6
// Canonical corpus name: BitFlagDecoderViaBitTests
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitFlagDecoderViaBitTests_00591cc6.c

void UnknownObject::DecodeBitFlags()
{
    // Bit-flag decoder: maps the low bits of a1 to an integer index via priority-ordered bit tests. Bit 0x20 yields 5, bit 0x08 yields 1, bit 0x04 yields 2, bit 0x01 yields 3; when none of those are set the result is 2 * (a1 & 0x02) (4 when bit 1 is set, else 0). No fields, globals, guards or callees were recovered in the packet.
    // GUARD: If (a1 & 0x20) != 0, return 5. [source:raw]
    // GUARD: If (a1 & 0x08) != 0, return 1. [source:raw]
    // GUARD: If (a1 & 0x04) != 0, return 2. [source:raw]
    // GUARD: If (a1 & 0x01) != 0, return 3. [source:raw]
    // RETURN: Return 2 * (a1 & 0x02), i.e. 4 when bit 1 is set, else 0. [source:raw]
    // CALL: Called by ConditionalMathWithDAT005e9ad0Flag (0x0059168F) to decode a flag byte into an index; consistent with the abi:lead label Bit_Flag_Decoder_via_Bit_Tests. [caller:0x0059168F, function:0x00591CC6, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   int sub_591CC6(char a1) {
    //     if ((a1 & 0x20) != 0) return 5;
    //     if ((a1 & 0x08) != 0) return 1;
    //     if ((a1 & 0x04) != 0) return 2;
    //     if ((a1 & 0x01) != 0) return 3;
    //     return 2 * (a1 & 0x02);
    //   }
    // UNRESOLVED: Semantic meaning of the returned index (0-5) is unknown; the packet has no enum or constant evidence for it.
    // UNRESOLVED: Meaning of each flag bit and the caller context at 0x0059168F are not established.
}
