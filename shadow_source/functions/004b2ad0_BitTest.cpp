// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2AD0
// Canonical corpus name: BitTest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitTest_004b2ad0.c

void UnknownObject::BitTest()
{
    // Getter with no side effects: reads field 0x30 (this[12]), shifts right by a2 and masks with 1 to test a single bit at position a2; returns 0 or 1. Template prelabel classifies it as a getter (DERIVED).
    // CALCULATION: Reads this[12] at offset 0x30, right-shifts by a2 and masks with 1 to isolate the bit at position a2. [abi:lead, field:this:0x00000030, function:0x004B2AD0, source:raw]
    // RETURN: Returns (this[12] >> a2) & 1, a boolean bit test. [source:raw]

    // Conservative worker pseudocode:
    //   int BitTest(_DWORD *this, char a2) {
    //       return (this[12] >> a2) & 1;
    //   }
    // UNRESOLVED: Semantic meaning of each tested bit position is not evidenced in this packet.
    // UNRESOLVED: Field 0x30 read-only here; writer elsewhere not identified from this packet.
}
