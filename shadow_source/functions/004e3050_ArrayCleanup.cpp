// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E3050
// Canonical corpus name: ArrayCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayCleanup_004e3050.c

void UnknownObject::ArrayCleanup()
{
    // Destructor/cleanup routine that walks four per-cluster array pointers at stride 296 bytes (74 dwords), starting at offset 0x1F4. For each slot it zeroes the count field preceding the pointer, frees the allocation via FreeWrapper_7bcf when the pointer is non-null, then zeroes the pointer itself. Invoked from VehicleResetClear during vehicle state reset.
    // ASSIGNMENT: Seed loop counter v2 = 4 (four array slots). [source:raw]
    // ASSIGNMENT: Point v1 at the first array pointer, this + 125 dwords = offset 0x1F4. [field:this:0x000001F4, source:raw]
    // LOOP: do-while loop running exactly 4 iterations, advancing v1 by 74 dwords (296 bytes) per iteration; cleanup of cluster storage arrays invoked from VehicleResetClear. [function:0x004E3050, caller:0x004E09E0, source:raw]
    // ASSIGNMENT: Read current array pointer *v1 into result. [field:this:0x000001F4, source:raw]
    // GUARD: Guard on the current array pointer at offset 0x1F4: when it equals 0, the FreeWrapper_7bcf call is skipped for this slot. [guard:0, field:this:0x000001F4, source:raw]
    // ASSIGNMENT: Zero the count field immediately preceding the pointer at *(v1 - 1). [source:raw]
    // CALL: Conditionally call FreeWrapper_7bcf(result) to free the heap-allocated array when the pointer was non-null. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the current array pointer *v1 = 0 after freeing. [field:this:0x000001F4, source:raw]
    // CALCULATION: Advance v1 by 74 dwords to the next slot and decrement the counter. [source:raw]
    // RETURN: Return the last free/discarded pointer value (legacy ABI name Array_Cleanup). [abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   void *ArrayCleanup(void **this) {
    //     void **slot = this + 125;
    //     int n = 4;
    //     do {
    //       void *p = *slot;
    //       *(slot - 1) = 0;
    //       if (p) FreeWrapper_7bcf(p);
    //       *slot = 0;
    //       slot += 74;
    //     } while (--n);
    //   }
    // UNRESOLVED: Owning class and layout of the four cluster storage arrays are unknown; the stride 296-byte entries are inferred from the source.
    // UNRESOLVED: The count field zeroed at *(v1 - 1) (the dword immediately before offset 0x1F4) is not independently evidenced by the packet.
}
