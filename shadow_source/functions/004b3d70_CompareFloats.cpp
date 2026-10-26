// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B3D70
// Canonical corpus name: FloatComparator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatComparator_004b3d70.c

void UnknownObject::CompareFloats()
{
    // Three-way float comparator. Compares *a1 against *a2 promoted to double: returns 1 when *a1 is strictly greater, 0 when *a1 >= *a2 (covers equality and the not-greater case), and -1 otherwise. The first operand read (*a1) is anchored to field this+0x0 per the packet. Signature fits a callback comparator (e.g. qsort-style ordering), but the packet records no callers. The DERIVED template prelabel mislabels this as a getter returning field 0x0; the raw body shows comparator semantics, and the raw source outranks the prelabel.
    // GUARD: If *a1 > (double)*a2, branch to return 1; *a1 is the first operand, mapped to field this+0x0. [field:this:0x00000000, function:0x004B3D70, source:raw]
    // RETURN: return 1 (first operand strictly greater than second). [function:0x004B3D70, source:raw]
    // GUARD: If *a1 >= (double)*a2, branch to return 0; covers the equality case. [field:this:0x00000000, function:0x004B3D70, source:raw]
    // RETURN: return 0 (operands equal, or first not greater). [function:0x004B3D70, source:raw]
    // RETURN: return -1 (first operand less than second). [function:0x004B3D70, source:raw]

    // Conservative worker pseudocode:
    //   if (*a1 > (double)*a2) return 1;
    //   if (*a1 >= (double)*a2) return 0;
    //   return -1;
    // UNRESOLVED: Only field this+0x0 is evidenced, but the function also dereferences *a2 (the second operand); the packet exposes no field entry for it, so a2's offset is unanchored.
    // UNRESOLVED: No callers are recorded in the packet; the comparator's use site (sort/insertion-order callback) is unknown.
    // UNRESOLVED: The DERIVED prelabel classifies this as a getter returning field 0x0, which conflicts with the comparator reading of the raw body; the raw source wins.
}
