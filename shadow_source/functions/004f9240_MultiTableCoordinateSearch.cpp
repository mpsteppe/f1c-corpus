// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9240
// Canonical corpus name: MultiTableCoordinateSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiTableCoordinateSearch_004f9240.c

void UnknownObject::MultiTableCoordinateSearch()
{
    // Searches multiple coordinate tables (__stdcall, target 4-tuple a1/a2/a3/a4) for a matching entry. Reads the current table index from dword_8AFE6C; if ShortComputation_9150 reports zero tables, returns -1. Iterates table indices v4 from 0 upward, calling UtilityFunction_9160 (0 when the index wraps back to the starting table, otherwise v4) to make that table current. Within each table, iterates entry index i up to ConditionalDispatch_9190, reading four coordinate values per entry with GlobalGuardedFieldReader (which also rewrites a1) and comparing them to the target tuple. Returns the matching entry index i, or -1 when every table is exhausted without a match.
    // ASSIGNMENT: Snapshot the current table index from dword_8AFE6C into v8 and initialize the scan index v4 to 0. [global:0x008AFE6C, source:raw]
    // GUARD: If ShortComputation_9150() returns 0 or fewer tables, return -1 immediately. [callee:0x004F9150, source:raw]
    // LOOP: Outer loop over table indices v4 from 0 until ShortComputation_9150() is reached. [callee:0x004F9150, source:raw]
    // CALL: Select the table to search: UtilityFunction_9160(0) when v4 wraps back to the starting index v8, otherwise UtilityFunction_9160(v4). [callee:0x004F9160, global:0x008AFE6C, source:raw]
    // LOOP: Inner loop over entry index i in [0, ConditionalDispatch_9190()) within the currently selected table. [callee:0x004F9190, source:raw]
    // CALL: Call GlobalGuardedFieldReader(i, &a1, &v9, &v10, &v11) to read four coordinate values from table entry i (a1 is written back by the reader). [callee:0x004F91B0, source:raw]
    // GUARD: Break the inner loop when the read 4-tuple matches the target: a1 equals the original first coordinate v5, and v9/v10/v11 equal a2/a3/a4. [source:raw, function:0x004F9240]
    // RETURN: Return the matching entry index i, or -1 when the outer loop exhausts all tables (++v4 reaches ShortComputation_9150()) without a match. [source:raw, function:0x004F9240]
    // CALL: Called by sub_4F9420 (0x004F9420) as the coordinate-lookup entry point. [caller:0x004F9420, source:raw]

    // Conservative worker pseudocode:
    //   int MultiTableCoordinateSearch(int a1, int a2, int a3, int a4) {
    //     int start = dword_8AFE6C;
    //     if (ShortComputation_9150() <= 0) return -1;
    //     int target1 = a1;
    //     for (int v4 = 0; ; ++v4) {
    //       if (v4) UtilityFunction_9160(v4 == start ? 0 : v4);
    //       int i = 0;
    //       for (; i < ConditionalDispatch_9190(); ++i) {
    //         GlobalGuardedFieldReader(i, &a1, &v9, &v10, &v11);
    //         if (a1 == target1 && v9 == a2 && v10 == a3 && v11 == a4) break;
    //       }
    //       if (i < ConditionalDispatch_9190()) return i;
    //       if (v4 + 1 >= ShortComputation_9150()) return -1;
    //     }
    //   }
    // UNRESOLVED: The contract of UtilityFunction_9160 (what making a table 'current' does, and why index 0 is used on the wrap-around case) is not established from this packet alone.
    // UNRESOLVED: The semantics of GlobalGuardedFieldReader rewriting a1 are inferred from the comparison against the saved v5; the exact table/entry layout is unknown.
    // UNRESOLVED: The role of dword_8AFE6C as 'current table index' and its relationship to the wrap condition is DERIVED from usage, not confirmed.
}
