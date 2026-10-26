// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00462380
// Canonical corpus name: sub_462380
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_462380_00462380.c

void UnknownObject::FlaggedDriverCount()
{
    // Counts how many driver entries in the object's driver table have flag bit 2 set in their entry structure, calling FlagBitTest for each entry. Returns 0 immediately when the driver count at obj+0x3E14 is not greater than 0.
    // GUARD: Guard on driver count at obj+0x3E14: when it is not greater than 0, skip the loop body entirely and return 0. [guard:0, field:obj:0x00003E14]
    // ASSIGNMENT: Initialize the counter v1 to 0 before entering the count loop. [source:raw]
    // ASSIGNMENT: Dereference the this pointer (field at this+0x0) to obtain the object base, then compute the first driver entry address as base + 916. [field:this:0x00000000, source:raw]
    // LOOP: Iterate over driver entries advancing the entry pointer by a 140-byte stride. The Hex-Rays do/while rendering (v3 != 1) is a decompiler artifact; the loop is bounded by the driver count field at obj+0x3E14. [source:raw, field:obj:0x00003E14]
    // CALL: Call FlagBitTest on the current driver entry to test flag bit 2; when the bit is set, increment the counter v1. [callee:0x00461530, source:raw]
    // RETURN: Return v1, the total number of driver entries with flag bit 2 set. [source:raw, function:0x00462380]

    // Conservative worker pseudocode:
    //   int count = 0;
    //   if (driverCount(obj + 0x3E14) > 0) {
    //     char* entry = base + 916;
    //     for (i = 0; i < driverCount; i++) {
    //       if (FlagBitTest(entry, 2)) count++;
    //       entry += 140;
    //     }
    //   }
    //   return count;
    // UNRESOLVED: The entry stride of 140 bytes and the starting entry offset of 916 appear only in the raw source text and are not present in the deterministic fields list; their relationship to the count field at obj+0x3E14 is DERIVED.
    // UNRESOLVED: The decompiled loop condition (v3 != 1) involves registers shown as uninitialized in Hex-Rays; the true loop bound is inferred as the driver count at obj+0x3E14.
    // UNRESOLVED: Which concrete object type owns this driver table (UnknownObject) and the meaning of flag bit 2 in the entry structure are not established.
    // UNRESOLVED: Legacy ABI label 'Driver_Count_with_Condition' (abi:lead) is present but carries no structural evidence.
}
