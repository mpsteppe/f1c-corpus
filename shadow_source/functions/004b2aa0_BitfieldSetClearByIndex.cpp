// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2AA0
// Canonical corpus name: BitfieldSetClearByIndex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitfieldSetClearByIndex_004b2aa0.c

void UnknownObject::BitfieldSetClearByIndex()
{
    // Bitfield single-bit set/clear helper. Writes the low bit of value a3 into bit position a2 of the 32-bit word at this+0x30 (mask 1 << a2): a set bit installs a 1, a clear bit installs a 0, other bits are preserved. Returns the unchanged this pointer. Structural twin of ConditionalSetter0x30 (004980c0).
    // ASSIGNMENT: Read the current 32-bit word at this+0x30 as the base of the bit manipulation. [field:this:0x00000030, source:raw]
    // CALCULATION: Build a single-bit mask selecting position a2: 1 << a2. [source:raw]
    // CALCULATION: Clear bit a2 of the current word: this[12] & ~(1 << a2). [field:this:0x00000030, source:raw]
    // CALCULATION: Shift the low bit of a3 into position a2: (a3 & 1) << a2; OR the result into the cleared word. [source:raw]
    // ASSIGNMENT: Store the combined bitfield value back into this[12]. [field:this:0x00000030, source:raw]
    // RETURN: Return the original this pointer unchanged. [abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   void* BitfieldSetClearByIndex(unsigned word*, int bitIndex, int value) {
    //     unsigned mask = 1u << bitIndex;
    //     word[12] = (word[12] & ~mask) | ((value & 1) << bitIndex);
    //     return word;
    //   }
    // UNRESOLVED: Which lighting/render flag bit a2 corresponds to is caller-supplied (SetupCarLightingAndRender 0x004C71C0 drives it) and not recoverable here.
    // UNRESOLVED: Semantics of a3 beyond its low bit, and the identity of the +0x30 bitfield owner, are unknown.
}
