// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464720
// Canonical corpus name: ByteClamp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ByteClamp_00464720.c

void UnknownObject::ByteClamp()
{
    // Clamps the byte at a1 into the inclusive range [a2, a3]: writes a2 when the value is below the lower bound, writes a3 when it is above the upper bound, and returns the original value.
    // ASSIGNMENT: result = *a1: read the current byte value [source:raw]
    // GUARD: if *a1 < a2 (below lower bound) or *a1 > a3 (above upper bound), the value is out of range [source:raw]
    // ASSIGNMENT: *a1 = a2: write the violated bound; in the decompiled expression a2 is reassigned to a3 by the comma operator when the upper bound is exceeded, so *a1 receives a2 below the low bound and a3 above the high bound [source:raw]
    // RETURN: return result: the pre-clamp value of *a1 [source:raw]

    // Conservative worker pseudocode:
    //   old = *a1;
    //   if (old < a2) *a1 = a2;
    //   else if (old > a3) *a1 = a3;
    //   return old;
    // UNRESOLVED: the decompiler comma-operator expression (a2 = a3, result > a3) is a codegen artifact for selecting the violated bound; the two-sided clamp interpretation is recovered from the guard and write
    // UNRESOLVED: no evidence identifies the object or setting the clamped byte belongs to
}
