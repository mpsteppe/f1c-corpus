// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00591CA1
// Canonical corpus name: IDToValueTableLookupInConstantTable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IDToValueTableLookupInConstantTable_00591ca1.c

void UnknownObject::IDToValueTableLookupInConstantTable()
{
    // Linear search over a constant table at unk_5E7640 of 8-byte ID/value entries; returns a pointer to the value DWORD of the entry whose ID matches the argument, or NULL when the scan reaches the table end dbl_5E7718. Called from FloatParsingWithErrorHandling.
    // LOOP: Scan the constant table starting at unk_5E7640, stepping 8 bytes (two DWORDs) per entry until the entry ID (*v2) matches the requested ID. [global:0x005E7640, caller:0x00591BF1, source:raw]
    // RETURN: Return NULL when the scan pointer reaches the table end dbl_5E7718 without a match. [global:0x005E7718, source:raw]
    // RETURN: Return a pointer to the value DWORD of the matching entry (off_5E7644, the second DWORD of each entry). [global:0x005E7644, source:raw, abi:lead]

    // Conservative worker pseudocode:
    //   ptr = 0x005E7640;
    //   idx = 0;
    //   while (*(DWORD*)ptr != id) {
    //     ptr += 8; idx++;
    //     if (ptr >= 0x005E7718) return NULL;
    //   }
    //   return &((DWORD*)0x005E7640)[2 * idx + 1];
    // UNRESOLVED: Purpose and consumer of the returned value pointer, and the meaning of the ID/value pairs, are not established from packet evidence.
}
