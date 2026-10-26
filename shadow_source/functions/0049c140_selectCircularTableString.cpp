// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049C140
// Canonical corpus name: sub_49C140
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49C140_0049c140.c

void UnknownObject::selectCircularTableString()
{
    // Selects a string from one of three string tables using a circular index read from a global input object, then copies the resolved string into the output buffer with a bound. The index is computed from a field at dword_7C54E0 + 0x4040: incremented and wrapped so the dispatch value cycles 0,1,2. Index 0 and the default branch use off_5CCBF0, index 1 uses off_5CCBE8, index 2 uses off_5CCBEC. For each branch the selected table is binary-searched against byte_5EC4C0 with byte_5EC4CC as the result buffer; a successful non-null match is strcpy'd into byte_5EC4CC, otherwise byte_5EC4CC is null-terminated empty. Finally sub_587DD0 copies at most a2-1 bytes from byte_5EC4CC into the output buffer a1, a NUL terminator is written at a1[a2-1], and 0 is returned.
    // CALCULATION: Reads the selection field at dword_7C54E0 + 0x4040, adds 1, and wraps a stored value of 2 back to 0, producing the circular dispatch index v2 in {0,1,2}. [global:0x007C54E0, source:raw]
    // GUARD: Dispatch on the circular index: v2==0 uses the off_5CCBF0 table, v2==1 uses off_5CCBE8, v2==2 uses off_5CCBEC, and any other value falls back to off_5CCBF0. [global:0x005CCBF0, global:0x005CCBE8, global:0x005CCBEC, source:raw]
    // CALL: Index-0/default branch: BinarySearchInStringTable(byte_5EC4C0, off_5CCBF0[0], byte_5EC4CC) searches the selected table and reports whether the entry exists. [callee:0x00423A00, global:0x005EC4C0, global:0x005CCBF0, global:0x005EC4CC]
    // CALL: Index-1 branch: BinarySearchInStringTable(byte_5EC4C0, off_5CCBE8[0], byte_5EC4CC) searches the off_5CCBE8 table. [callee:0x00423A00, global:0x005EC4C0, global:0x005CCBE8, global:0x005EC4CC]
    // CALL: Index-2 branch: BinarySearchInStringTable(byte_5EC4C0, off_5CCBEC[0], byte_5EC4CC) searches the off_5CCBEC table. [callee:0x00423A00, global:0x005EC4C0, global:0x005CCBEC, global:0x005EC4CC]
    // ASSIGNMENT: When the binary search succeeds and the selected table entry is non-null, the entry is strcpy'd into the shared result buffer byte_5EC4CC. [global:0x005EC4CC, global:0x005CCBF0, global:0x005CCBE8, global:0x005CCBEC, source:raw]
    // ASSIGNMENT: When the selected table entry is null or the lookup fails, byte_5EC4CC is cleared by writing zero to its first byte. [global:0x005EC4CC, source:raw]
    // CALL: sub_587DD0(a1, byte_5EC4CC, a2 - 1) copies at most a2-1 bytes from the resolved string in byte_5EC4CC into the output buffer a1. [callee:0x00587DD0, global:0x005EC4CC, source:raw]
    // ASSIGNMENT: Writes a NUL terminator at output position a1[a2-1], bounding the copied string. [source:raw]
    // RETURN: Returns 0 on every completion path. [function:0x0049C140, source:raw]

    // Conservative worker pseudocode:
    //   int selectCircularTableString(char* out, unsigned outSize) {
    //     int sel = *(int*)(dword_7C54E0 + 0x4040) + 1;
    //     if (*(int*)(dword_7C54E0 + 0x4040) == 2) sel = 0;
    //     const char** table = (sel == 1) ? off_5CCBE8 : (sel == 2) ? off_5CCBEC : off_5CCBF0;
    //     if (BinarySearchInStringTable(byte_5EC4C0, table[0], byte_5EC4CC)) {
    //       if (table[0]) strcpy(byte_5EC4CC, table[0]);
    //       else byte_5EC4CC[0] = 0;
    //     } else {
    //       byte_5EC4CC[0] = 0;
    //     }
    //     sub_587DD0(out, byte_5EC4CC, outSize - 1);
    //     out[outSize - 1] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The global dword_7C54E0 object and the meaning of its +0x4040 selection field are not established by this packet; the dispatch semantics are inferred from the raw control flow.
    // UNRESOLVED: The identities of the three string tables (off_5CCBF0, off_5CCBE8, off_5CCBEC) and what the selection rotation selects between are not confirmed.
    // UNRESOLVED: byte_5EC4CC is treated as a shared result buffer, but its allocation and lifetime are outside this function.
    // UNRESOLVED: The caller relationship to UtilityFunction_d8b0 (0049d8b0) is not analyzed; the reason the output buffer receives a string here is unknown.
}
