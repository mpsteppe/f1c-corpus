// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2B60
// Canonical corpus name: BitfieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitfieldSetter_004b2b60.c

void UnknownObject::BitfieldSetter()
{
    // Multi-bit field setter. Writes a value into the 15-bit window (bits 15-29) of the 32-bit word at this+0x30: the word is cleared with mask 0xFFC07FFF, a2 shifted by 15 is ORed in, and the result is stored and returned.
    // ASSIGNMENT: Read the current 32-bit word at this+0x30 as the base value. [field:this:0x00000030, source:raw]
    // CALCULATION: Clear the 15-bit window (bits 15-29) of the current word: this[12] & 0xFFC07FFF. [field:this:0x00000030, source:raw]
    // CALCULATION: Shift a2 into the cleared window: a2 << 15. [source:raw]
    // CALCULATION: Combine the shifted value with the cleared word: (a2 << 15) | (this[12] & 0xFFC07FFF). [source:raw]
    // ASSIGNMENT: Store the combined result into this[12]. [field:this:0x00000030, source:raw]
    // RETURN: Return the stored combined value. [abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   unsigned BitfieldSetter(unsigned word*, int value) {
    //     unsigned result = (value << 15) | (word[12] & 0xFFC07FFF);
    //     word[12] = result;
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the 15-bit value a2 (which lighting/render parameter it encodes) is caller-supplied and unknown.
    // UNRESOLVED: Whether bits 0-14 and 30-31 of +0x30 carry independent flags is not established here.
}
