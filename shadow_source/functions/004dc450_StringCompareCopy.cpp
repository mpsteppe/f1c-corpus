// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DC450
// Canonical corpus name: StringCompareCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCompareCopy_004dc450.c

void UnknownObject::StringCompareCopy()
{
    // Compares a caller-supplied path a3 against a criteria parameter a2 and conditionally copies it into the global path buffer byte_5EA438. First the directory portion of a3 is copied into the buffer and truncated at the last backslash, then the filename portion is matched via sub_546AA0; when the match fails and flag a4 is set, the filename is copied into the buffer and stripped of its extension (ASCII 46) before further processing. Returns 1 when either input pointer is null or the match succeeds, 0 when the match fails.
    // ASSIGNMENT: Seed the local result v9 and the early-return value to 1 before the null check. [source:raw]
    // GUARD: Proceed only when both a1 and a3 are non-null; otherwise return the seeded value 1. [source:raw]
    // CALL: Copy source path a3 into the global path buffer byte_5EA438 via StringCopyWithBufferRealloc. [source:raw, callee:0x00566650, global:0x005EA438]
    // CALCULATION: Compute v5 = strlen(byte_5EA438) + 1 to locate the end of the copied path in the buffer. [source:raw, global:0x005EA438]
    // GUARD: The backward directory-scan loop only runs when the copied path is non-empty ((int)(v5 - 1) > 0). [source:raw]
    // LOOP: Scan byte_5EA438 backward from its last character looking for a backslash (ASCII 92), stopping at the buffer base. [source:raw, global:0x005EA438]
    // ASSIGNMENT: Null-terminate byte_5EA438 at the found backslash, truncating the copied path to its directory portion. [source:raw, global:0x005EA438]
    // CALL: Register the directory path byte_5EA438 via StringRegistry. [source:raw, callee:0x0053C800, global:0x005EA438]
    // CALCULATION: Set v7 to the end of the source path a3 (a3 + strlen(a3)). [source:raw]
    // LOOP: Scan backward from the end of a3 for a backslash (ASCII 92) so v7 ends up pointing just past the last separator, i.e. the filename portion. [source:raw]
    // CALL: Check the filename/extension match of the filename portion v7 against the criteria parameter a2 via sub_546AA0. [source:raw, callee:0x00546AA0]
    // GUARD: When sub_546AA0 returns 0 (no match), clear v9 and, if flag a4 is set, run the copy-and-strip path. [source:raw]
    // ASSIGNMENT: Clear v9 to 0 when the filename match failed. [source:raw]
    // CALL: Copy the filename portion v7 into byte_5EA438 via StringCopyWithBufferRealloc. [source:raw, callee:0x00566650, global:0x005EA438]
    // CALCULATION: Set v8 to the end of the currently copied filename in byte_5EA438. [source:raw, global:0x005EA438]
    // LOOP: Scan byte_5EA438 backward from its end for a dot (ASCII 46) to locate the extension separator. [source:raw, global:0x005EA438]
    // ASSIGNMENT: Null-terminate byte_5EA438 at the found dot, stripping the file extension. [source:raw, global:0x005EA438]
    // CALL: Process the stripped filename byte_5EA438 via sub_589901. [source:raw, callee:0x00589901, global:0x005EA438]
    // CALL: Copy the relative path byte_5EA438 via RelativeStringCopy. [source:raw, callee:0x005472B0, global:0x005EA438]
    // CALL: Match the final buffer byte_5EA438 against flag-based criteria via StringMatchWithFlagSet. [source:raw, callee:0x0053C900, global:0x005EA438]
    // RETURN: Return v9: 1 when inputs are null or the match succeeded, 0 when the match failed. [source:raw]
    // CALL: Invoked by TextureAdjuster (0x004DC770). [caller:0x004DC770]

    // Conservative worker pseudocode:
    //   int sub_4DC450(void *a1, char a2, const char *a3, char a4) {
    //     int v9 = 1;
    //     if (a1 && a3) {
    //       StringCopyWithBufferRealloc(a3);
    //       unsigned v5 = strlen(byte_5EA438) + 1;
    //       if ((int)(v5 - 1) > 0) {
    //         char *i = &byte_5EA438[v5 - 2];
    //         while (i > byte_5EA438 && *i != 92) --i;
    //         *i = 0;
    //       }
    //       StringRegistry(byte_5EA438);
    //       const char *v7 = &a3[strlen(a3)];
    //       if (v7 > a3) {
    //         while (*v7 != 92) { if (--v7 <= a3) break; }
    //         ++v7;
    //       }
    //       if (!sub_546AA0(a2, v7)) {
    //         v9 = 0;
    //         if (a4) {
    //           StringCopyWithBufferRealloc(v7);
    //           char *v8 = &byte_5EA438[strlen(byte_5EA438)];
    //           if (v8 > byte_5EA438) {
    //             while (*v8 != 46) { if (--v8 <= byte_5EA438) break; }
    //             *v8 = 0;
    //           }
    //           sub_589901(byte_5EA438);
    //           RelativeStringCopy(byte_5EA438);
    //         }
    //       }
    //       StringMatchWithFlagSet(byte_5EA438);
    //       return v9;
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: FreeWrapper_7bcf (0x00587BCF) is listed as a callee but does not appear in the raw source.
    // UNRESOLVED: dword_8AFE64 (0x008AFE64) is listed as a referenced global but does not appear in the raw source.
    // UNRESOLVED: Semantics of the match-criteria parameter a2 and the copy-and-strip enable flag a4 depend on the caller; a1 is used only as a null check.
    // UNRESOLVED: Internal behavior of StringRegistry, StringMatchWithFlagSet, sub_546AA0, sub_589901 and RelativeStringCopy is external and inferred from names.
}
