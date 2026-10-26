// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497F90
// Canonical corpus name: StringArrayMatchSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringArrayMatchSearch_00497f90.c

void UnknownObject::StringArrayMatchSearch()
{
    // Searches a per-instance array of entries (base this + 69, stride 20 elements) for a match against input a2. Rejects null and empty inputs with 0. Copies a2 into a local 80-byte buffer, then sub_587C20(v7, &dword_5CC79C) locates the separator character stored in dword_5CC79C and truncates the copy at it by writing a null terminator. When the stored entry count this[1349] (this+0x1514) is positive, iterates the array with sub_588410 (which returns 0 on match), returning 1 on the first match and 0 when the examined count reaches the stored count. Called by UICustomRenderDispatch (00489fd0) and DriverNameStringHandler (00497ec0).
    // GUARD: Null input a2 returns 0 immediately (blocked input). [source:raw]
    // GUARD: Empty input (strlen(a2) == 0) returns 0 immediately. [source:raw]
    // ASSIGNMENT: The input string is copied into the local 80-byte buffer v7 with strcpy. [source:raw]
    // CALL: sub_587C20(v7, &dword_5CC79C) locates the separator character stored in dword_5CC79C within the copy; if found, the location is nulled to truncate the string at the separator. [callee:0x00587C20, global:0x005CC79C]
    // GUARD: When the stored entry count this[1349] (this+0x1514) is not positive, the search is skipped and 0 returned. [guard:0, field:this:0x00001514, source:raw]
    // LOOP: Iterates the array entries starting at this + 69, calling sub_588410(entry, v7) as the loop condition; a match (sub_588410 == 0) exits the loop and returns 1. [callee:0x00588410, source:raw]
    // GUARD: Each examined entry increments v5; when v5 reaches the stored count this[1349] (this+0x1514), the function returns 0 (no match within the array). [field:this:0x00001514, source:raw]
    // RETURN: Returns 1 when a matching entry is found, otherwise 0 (null/empty input, non-positive count, or no match found). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_497F90(_DWORD *this, const char *a2) {
    //     if (!a2) return 0;
    //     if (!strlen(a2)) return 0;
    //     strcpy(v7, a2);
    //     v4 = (_BYTE *)sub_587C20(v7, &dword_5CC79C);
    //     if (v4) *v4 = 0;
    //     if (this[1349] > 0) {
    //       for (i = this + 69; sub_588410(i, v7); i += 20) {
    //         if (++v5 >= this[1349]) return 0;
    //       }
    //       return 1;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The array entries are 20-element structures and sub_588410 is treated as a strcmp-like comparator returning 0 on match, but the layout of each entry and the comparator's exact contract are not evidenced in this packet.
    // UNRESOLVED: dword_5CC79C is read as the separator character; which character it holds and whether the match is exact or prefix-based is not evidenced.
    // UNRESOLVED: The legacy ABI lead (abi:lead) names this function String_Array_Match_Search; that naming is only a lead and is not independently corroborated.
}
