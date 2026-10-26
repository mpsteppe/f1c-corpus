// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00462460
// Canonical corpus name: DriverDataCopyByID
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DriverDataCopyByID_00462460.c

void UnknownObject::DriverDataCopyByID()
{
    // Searches a driver table for an entry whose ID byte equals a2 and, on match, copies the 0x8C-byte entry block (entry base + 916) into the caller buffer a3 and writes the matching parallel dword (object + 15476 + 4 * entry index) into *a4. Entries are 140 bytes apart; the loop runs once per driver in the count at object + 0x3E14. Returns 1 when a match was copied, 0 otherwise, and returns 0 immediately when the driver count is 0 or negative.
    // GUARD: Driver count at the object pointed to by this (this+0x0) plus 0x3E14 must be greater than 0; returns 0 without searching when the count is 0 or negative [guard:0, field:obj:0x00003E14, field:this:0x00000000, source:raw]
    // LOOP: Iterates the driver entries with byte stride 140 (0x8C), once per driver in the count at object + 0x3E14, with the parallel dword cursor v8 starting at object + 15476 and stepping by 4 [field:obj:0x00003E14, field:this:0x00000000, source:raw]
    // GUARD: Per-entry ID byte at entry base + 1040 (offset 0x7C into the entry block) is compared for equality with a2 [source:raw]
    // CALL: qmemcpy copies 0x8C bytes from entry base + 916 into the caller buffer a3 when the ID matches [source:raw]
    // ASSIGNMENT: Write the parallel dword (object + 15476 + 4 * entry index) into *a4 and set the found flag v10 when a match occurred [field:this:0x00000000, source:raw]
    // RETURN: Returns the found flag (1 when a driver matched and was copied, 0 otherwise); used by NetCommSessionMessageDispatcher and DeferredTextureObjectLoader [function:0x00462460, caller:0x0045D890, caller:0x0046E1B0, source:raw]

    // Conservative worker pseudocode:
    //   v5 = *this;
    //   if (*(v5 + 15892) <= 0) return 0;
    //   found = 0;
    //   for (i = 0; i < *(v5 + 15892); ++i) {
    //     entry = v5 + 140 * i;
    //     if (*(entry + 1040) == a2) {
    //       qmemcpy(a3, entry + 916, 0x8C);
    //       *a4 = *(*(this) + 15476 + 4 * i);
    //       found = 1;
    //     }
    //   }
    //   return found;
    // UNRESOLVED: The purpose of the parallel dword table at object + 15476 is not stated; its pairing with the copied 0x8C entry block is inferred only from the shared loop index
}
