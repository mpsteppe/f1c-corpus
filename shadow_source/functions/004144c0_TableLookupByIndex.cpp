// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004144C0
// Canonical corpus name: TableLookupByIndex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TableLookupByIndex_004144c0.c

void UnknownObject::TableLookupByIndex()
{
    // Indexed table read on the global dword_5BF9B0 (0x005BF9B0): computes the element offset as 5 * a1 and returns the dword at that slot. Read-only; no guards, fields or callees. Called by ShortComputation_1a00 (0x00411A00) and RandomRangeTableInitializer (0x00411AB0).
    // CALCULATION: Compute the element index as 5 * a1 [function:0x004144C0, source:raw]
    // RETURN: Return the dword at dword_5BF9B0[5 * a1] [global:0x005BF9B0, function:0x004144C0, source:raw]
    // CALL: Invoked by ShortComputation_1a00 (0x00411A00) and RandomRangeTableInitializer (0x00411AB0) as a shared table lookup [caller:0x00411A00, caller:0x00411AB0, source:raw]

    // Conservative worker pseudocode:
    //   return dword_5BF9B0[5 * a1];
    // UNRESOLVED: Stride 5 implies dword_5BF9B0 holds records of 5 dwords; the record layout is not defined here
    // UNRESOLVED: The caller-visible meaning of a1 as a lookup key is not documented in this function
}
