// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2AE0
// Canonical corpus name: sub_4B2AE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B2AE0_004b2ae0.c

void UnknownObject::BitfieldXorSetter()
{
    // Masked XOR setter for a 3-bit window (bits 28-30, mask 0x70000000) of the 32-bit word at this+0x30. The low three bits of a2 (shifted by 28) replace that window; all other bits are preserved. Returns the isolated masked result (previous window value XOR a2's three bits).
    // ASSIGNMENT: Read the current word into v2: v2 = this[12]. [field:this:0x00000030, source:raw]
    // CALCULATION: Shift a2 so its low bits land in the 0x70000000 window: a2 << 28. [source:raw]
    // CALCULATION: XOR v2 with the shifted value and isolate the 3-bit window: (v2 ^ (a2 << 28)) & 0x70000000. [source:raw]
    // CALCULATION: Merge the masked result back by XOR against v2, toggling only the window bits while preserving the rest: result ^ v2. [source:raw]
    // ASSIGNMENT: Store the merged word back into this[12]. [field:this:0x00000030, source:raw]
    // RETURN: Return the isolated masked result (old window bits XOR a2's three low bits). [abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   int BitfieldXorSetter(unsigned word*, int value) {
    //     int v2 = word[12];
    //     int result = (v2 ^ (value << 28)) & 0x70000000;
    //     word[12] = result ^ v2;
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the three-bit value a2 written into bits 28-30 of +0x30 is caller-supplied and unknown.
    // UNRESOLVED: Purpose of the returned masked result (consumed or ignored by caller 0x004C71C0) is unknown.
}
