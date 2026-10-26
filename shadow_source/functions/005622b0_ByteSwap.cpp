// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005622B0
// Canonical corpus name: ByteSwap
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ByteSwap_005622b0.c

void UnknownObject::ByteSwap()
{
    // Two-byte exchange helper: swaps the single byte pointed to by a1 with the byte pointed to by a2 and returns the byte that originally sat at a1. Prelabelled as a structural twin of FloatClamp (004646c0) by cluster copy.
    // ASSIGNMENT: read the byte at a1 into result (the field byte being exchanged) [field:this:0x00000000, source:raw]
    // ASSIGNMENT: write the byte from a2 into a1 [source:raw]
    // ASSIGNMENT: write the saved original a1 byte into a2 [source:raw]
    // RETURN: return the original byte value that was at a1 [source:raw]

    // Conservative worker pseudocode:
    //   tmp = *a1;
    //   *a1 = *a2;
    //   *a2 = tmp;
    //   return tmp;
    // UNRESOLVED: mapping of field:this:0x00000000 to a function parameter is unclear; the function operates on two caller-supplied pointers rather than a this-relative struct access
    // UNRESOLVED: why the operation is a single-byte exchange (the twin-relationship prelabel suggests the swapped value may be wider in its origin context)
}
