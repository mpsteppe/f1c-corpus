// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C800
// Canonical corpus name: StringRegistry
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringRegistry_0053c800.c

void UnknownObject::StringRegistryRegister()
{
    // Registers the input string in a fixed-capacity (32 entries x 132 bytes) most-recent-first string registry. Copies the input into a 256-byte stack buffer, preprocesses it via sub_589901, then scans the existing entries of byte_8B5A3C with strcmp. If a duplicate is found it returns without inserting. Otherwise, when entries exist, every entry is shifted up one 132-byte slot (copied with ArithmeticComparison_c6b0, indexed through dword_8B5A38), the new string is written into slot 0 of byte_8B5A3C and the global count dword_8B8E30 is incremented.
    // GUARD: Registration proceeds only when the input's first byte is non-null (non-empty string) and the registry count dword_8B8E30 is below 32 [field:this:0x00000000, global:0x008B8E30, source:raw]
    // LOOP: Copy the input string (read through this+0) into the 256-byte stack buffer SrcStr, byte by byte, until the NUL terminator [field:this:0x00000000, source:raw]
    // CALL: sub_589901(SrcStr) preprocesses the stack copy before it is stored in the registry [callee:0x00589901, source:raw]
    // LOOP: Dedupe scan: strcmp SrcStr against each 132-byte-strided entry of byte_8B5A3C; a match breaks out and skips insertion [global:0x008B5A3C, global:0x008B8E30, source:raw]
    // LOOP: When no duplicate is found and count > 0, shift every existing entry up one 132-byte slot by copying with ArithmeticComparison_c6b0, indexing the entries through dword_8B5A38 (dword stride 33) so slot 0 becomes free [global:0x008B5A38, global:0x008B5A3C, global:0x008B8E30, callee:0x0053C6B0, source:raw]
    // ASSIGNMENT: Copy SrcStr into byte_8B5A3C starting at slot 0, byte by byte until the NUL terminator [global:0x008B5A3C, source:raw]
    // ASSIGNMENT: Registry count dword_8B8E30 is set to count + 1 [global:0x008B8E30, source:raw]
    // RETURN: Returns 0 when the string was already present, or the copy's terminating index + 1 after a successful insert [source:raw]
    // CALL: Used by pit-crew/animation setup, SpecialFX_Init, VidMan_Init and StringCompareCopy paths as a shared string registry [caller:0x0049CD80, caller:0x004A3220, caller:0x004A3910, caller:0x004A4900, caller:0x004CF070, caller:0x004DC450, caller:0x004F8D70, caller:0x004FA320, source:raw]

    // Conservative worker pseudocode:
    //   int sub_53C800(a1) {
    //     char SrcStr[256];
    //     if (*a1 && dword_8B8E30 < 32) {
    //       copy a1 into SrcStr until NUL;
    //       sub_589901(SrcStr);
    //       if (dword_8B8E30 > 0) {
    //         for (i = 0; i < dword_8B8E30; ++i)
    //           if (strcmp(SrcStr, byte_8B5A3C + 132 * i) == 0) return 0;
    //         for (i = dword_8B8E30; i > 0; --i)
    //           ArithmeticComparison_c6b0(&dword_8B5A38[33 * i], &dword_8B5A38[33 * (i - 1)]);
    //       }
    //       copy SrcStr into byte_8B5A3C until NUL;
    //       dword_8B8E30 += 1;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: What sub_589901 does to SrcStr (normalization, lowercasing, trimming) is unknown.
    // UNRESOLVED: The differing return values (0 on duplicate vs terminating index + 1 on insert) have unclear consumer semantics.
    // UNRESOLVED: Why the registry keeps the newest entry at slot 0 (MRU-front ordering) and who reads the entries is unknown.
    // UNRESOLVED: The structural relation between dword_8B5A38 (indexed in 33-dword steps) and byte_8B5A3C (132-byte slots) is consistent only arithmetically (132 = 33 * 4); the real layout is unverified.
    // UNRESOLVED: The field this+0 is read only as the input string's first byte; no further object state is used.
}
