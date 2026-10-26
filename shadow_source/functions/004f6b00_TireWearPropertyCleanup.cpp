// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F6B00
// Canonical corpus name: TireWearPropertyCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireWearPropertyCleanup_004f6b00.c

void UnknownObject::TireWearPropertyCleanup()
{
    // Teardown helper: walks a fixed table of 45 heap pointers anchored at byte_8AFC74 backwards at a 20-byte stride, freeing each non-null entry through FreeWrapper_7bcf, and returns the last processed pointer value (the last freed block, or null when no entry was non-null). Used in the pit/tire-wear property cleanup path.
    // ASSIGNMENT: Seed the walk cursor v0 with the address of byte_8AFC74, the end anchor of a 45-entry pointer table. [source:raw, global:0x008AFC74, function:0x004F6B00]
    // ASSIGNMENT: Seed the iteration counter v1 with 45, the table entry count. [source:raw]
    // LOOP: do-while loop that runs 45 times: v1 is decremented each iteration and the loop exits when v1 reaches zero. [source:raw]
    // CALCULATION: Read the candidate pointer as the dword 20 bytes below the current cursor, *((_DWORD *)v0 - 5). [source:raw]
    // CALCULATION: Step the cursor backward by the 20-byte table entry stride: v0 -= 20. [source:raw]
    // GUARD: Only free the candidate when the read pointer is non-null. [source:raw]
    // CALL: Free the non-null heap block via FreeWrapper_7bcf(candidate) and store its result. [callee:0x00587BCF, source:raw]
    // RETURN: Return the last candidate value (the last freed pointer, or null if every entry was null). [source:raw]

    // Conservative worker pseudocode:
    //   void *sub_4F6B00(void) {
    //     char *cursor = &byte_8AFC74;            // end anchor of the 45-entry table
    //     int count = 45;
    //     void *result = 0;
    //     do {
    //       result = *(unsigned int *)(cursor - 20);   // entry pointer 20 bytes below cursor
    //       cursor -= 20;
    //       if (result) result = FreeWrapper_7bcf(result);
    //       --count;
    //     } while (count);
    //     return result;
    //   }
    // UNRESOLVED: The layout and element type of the 45-entry, 20-byte-stride table anchored at byte_8AFC74 are unknown; only the end-anchor address is evidenced.
    // UNRESOLVED: The ABI label Tire_Wear_Property_Cleanup is legacy naming; the table's semantic role (tire-wear properties) is unproven by runtime evidence.
}
