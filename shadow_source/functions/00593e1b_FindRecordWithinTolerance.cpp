// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00593E1B
// Canonical corpus name: sub_593E1B
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_593E1B_00593e1b.c

void UnknownObject::FindRecordWithinTolerance()
{
    // Linear search over a global array of 20-byte records. Starting at lpMem, it iterates dword_8D48F8 records, and for each record tests whether a1 lies within 0x100000 bytes of the DWORD stored at dword index 3 (byte offset 12) using an unsigned difference test. Returns the pointer to the first matching record, or 0 when no record matches.
    // LOOP: Iterate result from lpMem through lpMem + 20 * dword_8D48F8 over the 20-byte record array. [source:raw, global:0x008D48FC, global:0x008D48F8]
    // CALCULATION: Advance result by 20 bytes per record. [source:raw]
    // GUARD: Test whether the unsigned difference a1 - *(DWORD*)result[3] is below 0x100000, i.e. a1 falls within 0x100000 bytes of the record's key DWORD at dword index 3. [source:raw]
    // RETURN: Return the matching record pointer, or 0 when the scan completes without a match. [source:raw]

    // Conservative worker pseudocode:
    //   char *sub_593E1B(int a1) {
    //     for (char *result = (char *)lpMem;
    //          result < (char *)lpMem + 20 * dword_8D48F8; result += 20) {
    //       if ((unsigned int)(a1 - *((_DWORD *)result + 3)) < 0x100000)
    //         return result;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The record layout (20 bytes with a key DWORD at dword index 3) and the meaning of the key value are unproven.
    // UNRESOLVED: The 0x100000 tolerance suggests a proximity lookup (e.g. address or resource within 1 MB), but the object type and the purpose of the returned record are unknown.
    // UNRESOLVED: Ownership of the global record array (lpMem, dword_8D48F8) and its initialization are unknown; callers are sub_58AA6F, sub_58B5D4 and sub_58BB68.
    // UNRESOLVED: The unsigned-difference comparison semantics for negative differences are well defined but the intended use is not confirmed.
}
