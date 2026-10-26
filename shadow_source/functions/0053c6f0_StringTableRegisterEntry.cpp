// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C6F0
// Canonical corpus name: sub_53C6F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53C6F0_0053c6f0.c

void UnknownObject::StringTableRegisterEntry()
{
    // Registers a null-terminated string into a global string table that holds up to 32 entries of 132 bytes. Copies the input into a local buffer, transforms it via sub_589901, then either stores it as the first entry when the table is empty or scans existing entries with strcmp (132-byte stride) for duplicates. If no duplicate is found, shifts the existing entries one slot right with ArithmeticComparison_c6b0 and inserts the new string at the front. The flag word dword_8B5A38 bit 0x4000 is set on every insertion and the count dword_8B8E30 is incremented. Called from SceneFileTopLevelParser during scene file parsing.
    // GUARD: Return early when the input string is empty: test the first byte at this+0x0 and skip registration when it is zero. [field:this:0x00000000, source:raw]
    // GUARD: Return early when the string table is full: only proceed while the registered entry count dword_8B8E30 is below 32. [global:0x008B8E30, source:raw]
    // LOOP: Copy the input string byte-by-byte into the local SrcStr buffer until the terminating NUL is stored. [source:raw]
    // CALL: Transform the copied string via sub_589901 before it is registered into the table. [callee:0x00589901, source:raw]
    // GUARD: Branch on the current entry count dword_8B8E30: the direct insert-at-front path is taken when the table is empty (count <= 0). [global:0x008B8E30, source:raw]
    // ASSIGNMENT: Copy the transformed string from SrcStr into the first table slot at byte_8B5A3C, writing through the terminating NUL. [global:0x008B5A3C, source:raw]
    // ASSIGNMENT: Set the table flag word: dword_8B5A38[0] |= 0x4000 marks the table as holding registered entries. [global:0x008B5A38, source:raw]
    // ASSIGNMENT: Increment the registered entry count dword_8B8E30 to the previously read value plus one. [global:0x008B8E30, source:raw]
    // LOOP: When the table already holds entries, scan the existing slots of byte_8B5A3C with strcmp, stepping the pointer by the 132-byte entry stride. [global:0x008B5A3C, source:raw]
    // GUARD: Duplicate detection: when strcmp matches an existing entry, stop the scan and leave the table unchanged. [global:0x008B5A3C, source:raw]
    // LOOP: When no duplicate is found and the table is non-empty, shift the existing entries one slot to the right, copying each from the last entry backward via ArithmeticComparison_c6b0. [callee:0x0053C6B0, global:0x008B5A38, source:raw]
    // ASSIGNMENT: Insert the new string at the front slot of byte_8B5A3C, set the 0x4000 flag on dword_8B5A38, and increment the entry count dword_8B8E30. [global:0x008B5A3C, global:0x008B5A38, global:0x008B8E30, source:raw]
    // CALL: Invoked from SceneFileTopLevelParser (0x0055B200) during scene file parsing. [caller:0x0055B200]
    // RETURN: Return the accumulated result value; the duplicate-skip and insert paths both terminate with a zero result. [function:0x0053C6F0, source:raw]

    // Conservative worker pseudocode:
    //   int StringTableRegisterEntry(char* a1) {
    //     if (!*a1 || count >= 32) return (int)a1;
    //     char SrcStr[256];
    //     copyString(a1, SrcStr);
    //     sub_589901(SrcStr);
    //     if (count <= 0) {
    //       copyString(SrcStr, byte_8B5A3C);
    //       dword_8B5A38[0] |= 0x4000;
    //       count = count + 1;
    //     } else {
    //       for (i = 0; i < count; i++)
    //         if (strcmp(SrcStr, byte_8B5A3C + i * 132) == 0) return 0;
    //       for (i = count; i > 0; i--)
    //         ArithmeticComparison_c6b0(&dword_8B5A38[33 * i], &dword_8B5A38[33 * (i - 1)]);
    //       copyString(SrcStr, byte_8B5A3C);
    //       dword_8B5A38[0] |= 0x4000;
    //       count = count + 1;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The entry layout is inferred from the 132-byte strcmp stride and the 33-DWORD shift step in ArithmeticComparison_c6b0; whether dword_8B5A38 and byte_8B5A3C alias the same allocation is not independently confirmed.
    // UNRESOLVED: The return-value contract differs by path (the guard-failure path returns the input pointer a1, while the insert/duplicate paths return 0); the caller's expectations are not evidenced.
    // UNRESOLVED: The exact meaning of the 0x4000 flag bit on dword_8B5A38 is not evidenced beyond being set on every successful insertion.
}
