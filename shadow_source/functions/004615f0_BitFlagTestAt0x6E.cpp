// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004615F0
// Canonical corpus name: BitFlagTestAt0x6E
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitFlagTestAt0x6E_004615f0.c

void UnknownObject::BitFlagTestAt0x6E()
{
    // __thiscall getter: returns whether bit a2 of the byte field at this[110] (offset 0x6E) is set. Computes (1 << a2) truncated to unsigned byte, ANDs it with this[110], and returns nonzero when the bit is set. No side effects.
    // CALCULATION: Build the single-bit mask 1 << a2 truncated to an unsigned byte. [source:raw]
    // CALCULATION: AND the mask with the byte at this[110] (offset 0x6E) and test for nonzero. [source:raw, field:this:0x0000006E]
    // RETURN: Return the boolean result of the bit test. [source:raw]
    // CALL: Called by SessionConfigWriteback (0x00461900), DriverEntrantSetupEntry (0x00462550), MultiplayerPasswordValidation (0x0046DD30) and sub_475150 (0x00475150) to test an individual flag bit on an unknown owner object. [caller:0x00461900, caller:0x00462550, caller:0x0046DD30, caller:0x00475150, source:raw]

    // Conservative worker pseudocode:
    //   BOOL sub_4615F0(BYTE *this, char a2) {
    //     return ((unsigned char)(1 << a2) & this[110]) != 0;
    //   }
    // UNRESOLVED: Semantic meaning of the bit flags stored at this[110] (offset 0x6E) and of the bit index a2 is unknown; each caller decides what flag it is asking about.
    // UNRESOLVED: Identity and purpose of the owner object are unknown.
}
