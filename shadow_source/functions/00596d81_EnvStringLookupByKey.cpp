// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596D81
// Canonical corpus name: sub_596D81
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_596D81_00596d81.c

void UnknownObject::EnvStringLookupByKey()
{
    // Looks up a key=value string in a global string table (dword_8D3E90). The lookup proceeds only once the parse flag dword_8D5A48 is set; if the table is not yet built, it is populated from the wide-string list dword_8D3E98 via WideCharMultiByteStringConversionWithAllocLoop. For a non-null key, iterates the table entries, and for each entry whose length exceeds the key length, whose character at the key-length offset is '=' (61), and that matches the key case-insensitively via MbsnbicollCRTStringCollation, returns a pointer to the value just after the '='. Returns NULL when no entry matches or a guard fails.
    // ASSIGNMENT: v1 = dword_8D3E90 loads the string-table pointer. [global:0x008D3E90, source:raw]
    // GUARD: Return NULL when the parse/init flag dword_8D5A48 is zero. [global:0x008D5A48, source:raw]
    // GUARD: If the table pointer dword_8D3E90 is NULL, require dword_8D3E98 (wide-string list) to be non-null and populate the table via WideCharMultiByteStringConversionWithAllocLoop(); then require the resulting dword_8D3E90 to be non-null. [global:0x008D3E90, global:0x008D3E98, callee:0x00597FAC, source:raw]
    // GUARD: Return NULL when the search key lpString2 is NULL. [source:raw]
    // CALCULATION: v2 = Strlen(lpString2) measures the key length; every subsequent comparison uses this length. [callee:0x0058E1B0, source:raw]
    // LOOP: Walk the string table while (*v1); each entry is a pointer to a null-terminated string. [global:0x008D3E90, source:raw]
    // GUARD: Skip the entry when Strlen(*v1) <= v2 (entry is not longer than the key). [callee:0x0058E1B0, source:raw]
    // GUARD: Skip the entry when the character at entry[v2] is not '=' (61), so it is not a key=value pair for this key length. [source:raw]
    // CALL: Match the key case-insensitively: MbsnbicollCRTStringCollation(*v1, lpString2, v2) returns 0 on match. [callee:0x00597F6D, source:raw]
    // RETURN: Return &entry[v2 + 1], the pointer to the value just after the '=' separator. [source:raw]
    // RETURN: Return NULL (0) when no entry matches or a guard fails. [source:raw]

    // Conservative worker pseudocode:
    //   char* EnvStringLookupByKey(char* key) {
    //     if (!dword_8D5A48) return NULL;
    //     char** table = dword_8D3E90;
    //     if (!table) {
    //       if (!dword_8D3E98) return NULL;
    //       if (WideCharMultiByteStringConversionWithAllocLoop()) return NULL;
    //       table = dword_8D3E90;
    //       if (!table) return NULL;
    //     }
    //     if (!key) return NULL;
    //     int klen = Strlen(key);
    //     while (*table) {
    //       char* entry = *table;
    //       if (Strlen(entry) > klen && entry[klen] == 61 &&
    //           !MbsnbicollCRTStringCollation(entry, key, klen))
    //         return &entry[klen + 1];
    //       ++table;
    //     }
    //     return NULL;
    //   }
    // UNRESOLVED: The exact role of the returned value substring and how the caller sub_5921F3 (0x005921F3) consumes it is out of scope.
    // UNRESOLVED: Ownership of the global string table (dword_8D3E90) and wide-string list (dword_8D3E98) is unknown; the lookup is treated as a free function over module globals.
}
