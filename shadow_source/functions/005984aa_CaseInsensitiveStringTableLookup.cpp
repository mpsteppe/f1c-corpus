// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005984AA
// Canonical corpus name: CaseInsensitiveStringTableLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CaseInsensitiveStringTableLookup_005984aa.c

void UnknownObject::CaseInsensitiveStringTableLookup()
{
    // Searches a null-terminated table of string pointers rooted at dword_8D3E90 for an entry whose first cchCount1 bytes match lpString1 under the case-insensitive collation MbsnbicollCRTStringCollation, requiring the string to terminate (next byte is '=' 61 or null) immediately after the matched prefix. Returns the entry index on match; returns a negated index when the table is exhausted or empty.
    // ASSIGNMENT: Point v2 at the table base dword_8D3E90 and pre-fetch the first entry string v3 = *(const CHAR**)dword_8D3E90. [source:raw, global:0x008D3E90]
    // GUARD: When the first table dword is null the table is empty; return the negated index of the terminator slot, which is 0. [source:raw, global:0x008D3E90]
    // LOOP: Walk the table one dword at a time until a match is found or a null terminator entry is reached. [source:raw, global:0x008D3E90]
    // CALL: Compare lpString1 against the current entry string v3 for the first cchCount1 characters with MbsnbicollCRTStringCollation; a zero return means a case-insensitive match. [source:raw, callee:0x00597F6D]
    // GUARD: On a collation match, read the byte at offset cchCount1 of the matched string; if it is '=' (61) or null the match is complete and the walk stops. [source:raw, global:0x008D3E90]
    // CALCULATION: Advance to the next entry: pre-fetch v3 = *((_DWORD*)v2 + 1) and step v2 += 4. [source:raw, global:0x008D3E90]
    // RETURN: Return the matching entry index (v2 - dword_8D3E90) >> 2 on success, or its negated value when a null terminator entry is reached. [source:raw, global:0x008D3E90]

    // Conservative worker pseudocode:
    //   int sub_5984AA(const char *key, int len) {
    //     const char **tab = (const char **)dword_8D3E90;
    //     int i = 0;
    //     if (!tab[0]) return 0;
    //     while (tab[i]) {
    //       if (MbsnbicollCRTStringCollation(key, tab[i], len) == 0) {
    //         char c = tab[i][len];
    //         if (c == 61 || c == 0) return i;
    //       }
    //       ++i;
    //     }
    //     return -i;
    //   }
    // UNRESOLVED: The exact layout of the table entry pointed at by dword_8D3E90 (entry plus following dword) is inferred from the indexing pattern and not independently confirmed.
    // UNRESOLVED: Whether the trailing '=' terminator implies a token=value table format is not provable from this function alone.
}
