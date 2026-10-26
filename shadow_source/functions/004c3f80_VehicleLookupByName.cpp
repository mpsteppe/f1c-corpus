// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C3F80
// Canonical corpus name: VehicleLookupByName
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleLookupByName_004c3f80.c

void UnknownObject::VehicleLookupByName()
{
    // Searches the global vehicle array for an entry whose name matches a caller-provided string. Iterates entries at stride 1060 from the array base dword_8AC394, reads each entry's name pointer (falling back to the default string byte_5EA438 when null), and compares it against the search name via sub_588410, which returns 0 on a match. Stores the matching entry index into dword_8AC38C. Returns without writing when the search name is null, the entry count dword_8AC390 is not positive, or no match is found within the count.
    // GUARD: When the search name a1 is null, return without any lookup. [source:raw]
    // ASSIGNMENT: Initialize the candidate index v1 to 0. [source:raw]
    // GUARD: Only iterate when the entry count dword_8AC390 is greater than 0. [global:0x008AC390, source:raw]
    // LOOP: Iterate over vehicle entries, advancing by stride 1060 bytes from the array base dword_8AC394. [global:0x008AC394, source:raw]
    // ASSIGNMENT: Load the entry name pointer at (i + dword_8AC394); when null, substitute the default string byte_5EA438. [global:0x005EA438, source:raw]
    // CALL: Compare the entry name against the search name a1 via sub_588410, which returns 0 on a match. [callee:0x00588410, source:raw]
    // GUARD: Break out of the iteration on a match; if the incremented index v1 reaches dword_8AC390 first, return without storing. [global:0x008AC390, source:raw]
    // ASSIGNMENT: Store the matching entry index v1 into dword_8AC38C. [global:0x008AC38C, source:raw]
    // RETURN: Return void. [source:raw]

    // Conservative worker pseudocode:
    //   void VehicleLookupByName(char *name) {
    //     if (!name) return;
    //     int v1 = 0;
    //     if (dword_8AC390 > 0) {
    //       for (int i = 0; ; i += 1060) {
    //         char *v3 = *(char **)(i + dword_8AC394);
    //         if (!v3) v3 = byte_5EA438;
    //         if (!sub_588410(v3, name)) break;
    //         if (++v1 >= dword_8AC390) return;
    //       }
    //       dword_8AC38C = v1;
    //     }
    //   }
    // UNRESOLVED: Exact comparison semantics of sub_588410 (case sensitivity, partial vs full match) beyond returning 0 on match.
    // UNRESOLVED: The layout of each 1060-byte vehicle entry; only the leading name pointer is observed.
    // UNRESOLVED: Meaning of the default string byte_5EA438 used as a fallback for null entry names.
}
