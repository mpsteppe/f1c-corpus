// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004541D0
// Canonical corpus name: PAUSEStringCopier
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PAUSEStringCopier_004541d0.c

void UnknownObject::PAUSEStringCopier()
{
    // Thiscall copy of a PAUSE-menu key name string into output buffer a2, selected by an index byte at this+0xC8C. Requires a count at this+0xC88 > 0 to proceed; writes the index to *a3. Indexes below 0x5A select the primary table aPause_0 (16 bytes per entry); indexes above 128 select the secondary table aEmpty_0 via index-128. Returns 1 on copy, 0 when gated or out of range.
    // GUARD: Block when the key-count field at this+0xC88 is <= 0, returning 0. [guard:0, field:this:0x00000C88]
    // ASSIGNMENT: Read the key-index byte at this+0xC8C and store it to the output int pointed by a3. [field:this:0x00000C8C, source:raw]
    // GUARD: Branch when the index byte is <= 128 (unsigned). [source:raw]
    // GUARD: When the index is < 0x5A, take the primary-table copy path. [source:raw, global:0x005C4890]
    // CALL: Copy the string from &aPause_0[16 * index] into a2 via strcpy and return 1. [source:raw, global:0x005C4890]
    // RETURN: Return 0 when the index is between 0x5A and 128 inclusive (primary path blocked). [source:raw]
    // CALCULATION: Compute the secondary index v4 = index - 128. [source:raw]
    // GUARD: Block the secondary path when v4 >= 0x58, returning 0. [source:raw, global:0x005C4E30]
    // LOOP: Copy the NUL-terminated string from &aEmpty_0[16 * v4] into a2 byte by byte until a zero byte is copied. [source:raw, global:0x005C4E30]
    // RETURN: Return 1 after the secondary-table copy completes. [source:raw]

    // Conservative worker pseudocode:
    //   char PAUSEStringCopier(int this, char *a2, int *a3) {
    //     if (*(int *)(this + 3208) <= 0)
    //       return 0;
    //     unsigned int index = *(unsigned __int8 *)(this + 3212);
    //     *a3 = index;
    //     if (index <= 128) {
    //       if (index < 0x5A) {
    //         strcpy(a2, &aPause_0[16 * index]);
    //         return 1;
    //       }
    //       return 0;
    //     }
    //     unsigned int v4 = index - 128;
    //     if (v4 >= 0x58)
    //       return 0;
    //     char *v5 = &aEmpty_0[16 * v4];
    //     int v6 = a2 - v5;
    //     do {
    //       char v7 = *v5;
    //       v5[v6] = *v5;
    //       ++v5;
    //     } while (v7);
    //     return 1;
    //   }
    // UNRESOLVED: Declaring object owning the count at this+0xC88 and index byte at this+0xC8C is not identified.
    // UNRESOLVED: Exact contents of the aPause_0 and aEmpty_0 string tables are unknown.
}
