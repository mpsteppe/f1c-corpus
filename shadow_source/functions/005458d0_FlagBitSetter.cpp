// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005458D0
// Canonical corpus name: FlagBitSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagBitSetter_005458d0.c

void UnknownObject::FlagBitSetter()
{
    // Two-bit flag selector on the flag dword this[59] (offset 0xEC). Mask 0xFF9FFFFF clears both flag bits (0x200000 and 0x400000); a2==0 clears the flags, a2==1 sets bit 0x200000, a2==2 sets bit 0x400000. Returns the input a2 unchanged. The cluster_copy prelabel marks it as a structural twin of ByteFieldSetter (004888F0), which is DERIVED and unverified. Called by video/init callers VidMan_Init (004FA320), sub_53EB70 and sub_555E50.
    // ASSIGNMENT: Initialize result to a2 (the requested flag selector). [source:raw]
    // GUARD: Branch on a2: zero clears the flag bits, one sets bit 0x200000, two sets bit 0x400000. [source:raw]
    // ASSIGNMENT: a2 == 0: clear the two flag bits by ANDing this[59] (offset 0xEC) with 0xFF9FFFFF. [field:this:0x000000EC, source:raw]
    // ASSIGNMENT: a2 == 1: clear the two flag bits with 0xFF9FFFFF, OR in bit 0x200000, and store the result back to this[59]. [field:this:0x000000EC, source:raw]
    // ASSIGNMENT: a2 == 2: clear the two flag bits with 0xFF9FFFFF, OR in bit 0x400000, and store back to this[59]. [field:this:0x000000EC, source:raw]
    // RETURN: Return the original flag selector a2 in every branch. [source:raw]
    // CALL: Invoked by video/init callers VidMan_Init, sub_53EB70 and sub_555E50. [caller:0x004FA320, caller:0x0053EB70, caller:0x00555E50]

    // Conservative worker pseudocode:
    //   unsigned int sub_5458D0(unsigned int* this, unsigned int a2) {
    //     unsigned int result = a2;
    //     if (a2) {
    //       if (a2 == 1)      { result = this[59] & 0xFF9FFFFF | 0x200000; this[59] = result; }
    //       else if (a2 == 2) { this[59] = this[59] & 0xFF9FFFFF | 0x400000; }
    //     } else {
    //       this[59] &= 0xFF9FFFFF;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of the two flag bits (0x200000 and 0x400000) in this+0xEC is unknown.
    // UNRESOLVED: Twin relationship to ByteFieldSetter (004888F0) comes from a DERIVED cluster copy and is not independently verified.
    // UNRESOLVED: The returned selector a2 (never modified) is probably for chaining; its consumer is not evidenced here.
}
