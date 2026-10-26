// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047F300
// Canonical corpus name: SceneFilenameMatchAgainstBasePath
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneFilenameMatchAgainstBasePath_0047f300.c

void UnknownObject::SceneFilenameMatchAgainstBasePath()
{
    // Iterates a scene-file array (dword_8AC490, stride 396) for a count held in dword_8AC488. For each non-empty entry it reads the filename string at entry+4, compares it against the base path in dword_7CE5D0 (falling back to the static byte_5EA438 string when that pointer is null) via sub_596C80, and breaks with the comparison result when a match (zero return) is found. If no entry matches before the count is exhausted it falls back to AIW(0).
    // ASSIGNMENT: Load the scene entry count into v0 from dword_8AC488 and reset the iteration index v1 to 0. [global:0x008AC488, source:raw]
    // GUARD: If dword_8AC488 <= 0, return AIW(0) immediately: no scene files to inspect. [global:0x008AC488, callee:0x004C54F0, source:raw]
    // LOOP: Infinite for-loop stepping the array byte offset i by 396 per scene entry; the exit path is the explicit v1/v0 bound check. [global:0x008AC490, source:raw]
    // CALCULATION: Compute the filename string length: strlen of the string at scene entry + 4, plus 1 for the terminator. [source:raw]
    // GUARD: Only test entries whose computed length minus 1 is greater than 0, i.e. non-empty filename strings. [source:raw]
    // CALCULATION: Resolve the comparison base path: dword_7CE5D0, or the static byte_5EA438 string when that pointer is null. [global:0x007CE5D0, global:0x005EA438, source:raw]
    // CALL: Call sub_596C80 on the scene filename at entry+4 against the resolved base path with the computed length; a zero return (match) breaks the loop and is returned. [callee:0x00596C80, source:raw]
    // CALL: Fallback call AIW(0) when the index v1 reaches the count v0 with no match found. [callee:0x004C54F0, source:raw]
    // RETURN: Return the last comparison result (zero on match) or the AIW(0) fallback result when the loop is exhausted. [callee:0x004C54F0, callee:0x00596C80, source:raw]

    // Conservative worker pseudocode:
    //   int sub_47F300() {
    //     v0 = dword_8AC488;
    //     v1 = 0;
    //     if (dword_8AC488 <= 0)
    //       return AIW(0);
    //     for (i = 0; ; i += 396) {
    //       v3 = strlen(dword_8AC490 + i + 4) + 1;
    //       if ((int)(v3 - 1) > 0) {
    //         v4 = dword_7CE5D0 ? (char*)dword_7CE5D0 : byte_5EA438;
    //         result = sub_596C80(dword_8AC490 + i + 4, v4, v3 - 1);
    //         if (!result)
    //           break;
    //       }
    //       if (++v1 >= v0)
    //         return AIW(0);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The scene array entry structure at dword_8AC490 (stride 396, filename at +4) is inferred from indexing alone and not confirmed by field evidence.
    // UNRESOLVED: The exact comparison semantics and return convention of sub_596C80 are not documented in this packet; the interpretation as a base-path match is carried from the canonical name and skeleton prose.
    // UNRESOLVED: The precise meaning of the AIW(0) fallback call is unresolved.
}
