// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00411680
// Canonical corpus name: ShortArrayInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortArrayInit_00411680.c

void UnknownObject::ShortPairArrayInitializer()
{
    // Array initializer (thiscall): fills 537 consecutive word-pairs with (1, 0), writing 1 to the first word of each pair (this+0x0) and 0 to the second word (this+0x2), advancing the pointer by two words per iteration, then returns the array base this. Unconditional do-while countdown; no branches.
    // ASSIGNMENT: Seed the pair counter v3 = 537 before the loop. [source:raw]
    // LOOP: do-while countdown over 537 iterations; element pointer v2 advances by two words per pass, covering 537 word-pairs in total. [field:this:0x00000000, field:this:0x00000002, source:raw]
    // ASSIGNMENT: Write the first word of each pair at this+0x0 to 1 (enabled/active flag per existing analysis). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write the second word of each pair at this+0x2 to 0 (counter/state per existing analysis). [field:this:0x00000002, source:raw]
    // RETURN: Return the array base pointer this. [source:raw]
    // CALL: Called by UtilityFunction_84b0 (0x004184B0) to initialize its word-pair table. [caller:0x004184B0, source:raw]

    // Conservative worker pseudocode:
    //   _WORD *sub_411680(_WORD *this) {
    //     _WORD *p = this;
    //     int n = 537;
    //     do { p[0] = 1; p[1] = 0; p += 2; --n; } while (n);
    //     return this;
    //   }
    // UNRESOLVED: Semantic meaning of the (1, 0) word pairs (enabled flag + counter) is a DERIVED proposal from existing analysis, not grounded here.
    // UNRESOLVED: Caller UtilityFunction_84b0 (0x004184B0) is not examined; the role of this 537-entry table is unknown.
}
