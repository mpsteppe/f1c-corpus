// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564620
// Canonical corpus name: IntegerDifferenceComparator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IntegerDifferenceComparator_00564620.c

void UnknownObject::IntegerDifferenceComparator()
{
    // Trivial comparator helper: reads the DWORD pointed to by a1 (the evidenced offset 0x0 of this), reads the DWORD pointed to by a2, and returns the signed difference *a1 - *a2. No side effects. The legacy ABI name Integer_Difference_Comparator matches the observed subtraction shape, suggesting a qsort-style ordering callback, but no callers are present in the packet to confirm that role.
    // CALCULATION: Dereference a1 and read the DWORD at offset 0x0 of this. [field:this:0x00000000, source:raw]
    // CALCULATION: Dereference a2 and read the DWORD it points to. [source:raw]
    // RETURN: Return the signed difference *a1 - *a2. [source:raw, function:0x00564620]

    // Conservative worker pseudocode:
    //   int sub_564620(_DWORD* a1, _DWORD* a2) {
    //     return *a1 - *a2;
    //   }
    // UNRESOLVED: The object identity of the second operand a2 is unknown; only the this field at offset 0x0 is evidenced.
    // UNRESOLVED: The comparator-shaped return suggests use in an ordering/sorting callback, but the packet lists no callers to confirm the calling convention role.
}
