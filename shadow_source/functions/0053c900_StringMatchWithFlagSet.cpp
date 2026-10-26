// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C900
// Canonical corpus name: StringMatchWithFlagSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringMatchWithFlagSet_0053c900.c

void UnknownObject::StringMatchWithFlagSet()
{
    // Copies the input string a2 into the stack buffer SrcStr, normalizes it via sub_589901, then searches a global string table whose records are 132 bytes apart starting at byte_8B5A3C with dword_8B8E30 active entries, comparing each record with strcmp. On a match at index v4, sets the 0x400 flag on dword_8B5A38[33 * v4]. Every search outcome returns SearchPathPrune(this); the input pointer is returned unchanged only when the input string is empty.
    // GUARD: If *a2 == 0 (empty input), skip the lookup and return a2 unchanged. [source:raw]
    // LOOP: Copy a2 into the 256-byte stack buffer SrcStr, character by character, until the terminating NUL. [source:raw]
    // CALL: Normalize SrcStr with sub_589901 before comparison. [callee:0x00589901]
    // GUARD: Only search when the registered entry count dword_8B8E30 is greater than zero. [global:0x008B8E30]
    // LOOP: Walk table records from byte_8B5A3C with a 132-byte stride, comparing each against SrcStr with strcmp until a match is found. [global:0x008B5A3C, source:raw]
    // RETURN: If index v4 reaches dword_8B8E30 without a match, return SearchPathPrune(this) early. [callee:0x0053CA00, global:0x008B8E30]
    // ASSIGNMENT: On a match, set the 0x400 flag on dword_8B5A38[33 * v4]. [global:0x008B5A38]
    // CALL: Return SearchPathPrune(this) after the search completes. [callee:0x0053CA00]

    // Conservative worker pseudocode:
    //   if (*a2 == 0) return a2;
    //   copy a2 into SrcStr up to the terminating NUL;
    //   sub_589901(SrcStr);
    //   if (dword_8B8E30 > 0) {
    //     for (i = byte_8B5A3C; strcmp(SrcStr, i); i += 132) {
    //       if (++v4 >= dword_8B8E30) return SearchPathPrune(this);
    //     }
    //     dword_8B5A38[33 * v4] |= 0x400;
    //   }
    //   return SearchPathPrune(this);
    // UNRESOLVED: sub_589901 normalization and SearchPathPrune(this) are not evidenced beyond their call sites here.
    // UNRESOLVED: The meaning of the 0x400 flag on dword_8B5A38[33 * v4] is unknown; only the write is evidenced.
    // UNRESOLVED: The 132-byte record stride and the dword_8B8E30 count imply a record array at byte_8B5A3C, but the record layout itself is not evidenced.
}
