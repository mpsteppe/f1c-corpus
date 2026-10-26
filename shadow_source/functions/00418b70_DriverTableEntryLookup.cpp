// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00418B70
// Canonical corpus name: ShortComputation_8b70
// Owner: DriverTableLookup [DERIVED]
// Raw source: functions/ShortComputation_8b70_00418b70.c

void DriverTableLookup::DriverTableEntryLookup()
{
    // Indexed lookup into a global driver data table. Given a driver index a1, returns dword_5BF9A0[5 * a1] when the index is not -1; otherwise returns -1 unchanged. Called only by InsertDriverTableEntry, consistent with a helper that retrieves one element of a per-driver table whose stride is five dwords.
    // ASSIGNMENT: Initialize result to a1 so the sentinel value survives the guard. [source:raw]
    // GUARD: Guard on a1 != -1; a -1 index bypasses the table read. [source:raw]
    // CALCULATION: Return the table element dword_5BF9A0[5 * a1], reading the global driver data table at a five-dword stride per index. [global:0x005BF9A0, source:raw]
    // RETURN: Return a1 unchanged when the guard fails, i.e. for the -1 sentinel index. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_418B70(int a1) {
    //     if (a1 == -1) return a1;
    //     return dword_5BF9A0[5 * a1];
    //   }
    // UNRESOLVED: Entry layout: the 5-dword stride implies a fixed per-driver record, but its fields are not evident here.
    // UNRESOLVED: Caller InsertDriverTableEntry 0x00418560 is the only use site; the semantic role of the returned dword (an id, flag, or pointer) is unproven.
}
