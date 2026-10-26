// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00433290
// Canonical corpus name: PathDirectoryExtractionAndComparison
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PathDirectoryExtractionAndComparison_00433290.c

void UnknownObject::PathDirectoryExtractionAndComparison()
{
    // Directory-path extraction and extension comparison. Reads the output string pointer at this+0x0 (defaulting to byte_5EA438 when null), fetches the module directory path through PathAccessor_28e0 on the module callback table dword_7C73E0, and copies it into the output buffer with sub_588640 when the accessor returns non-null. Calls sub_568910 on the max-length argument, then scans a2 backward from its end for a '.' to strip the file extension; if the stripped string is empty, concatenates asc_5C4068 into a2 with sub_587DD0 and NUL-terminates at a3-1. Returns the concatenation result (0 when no concatenation ran). Called by PathStringModifier (00433370).
    // ASSIGNMENT: Reads the output string pointer *a1 from field this+0x0 into v3 and v4; when *a1 is null, v4 (and later v3) default to byte_5EA438 [field:this:0x00000000, global:0x005EA438, source:raw]
    // LOOP: Scans v4 backward from its end looking for backslash 92 (0x5C), breaking when found; the found position i is never used afterwards [source:raw]
    // CALL: Calls PathAccessor_28e0 with the module callback table dword_7C73E0 to obtain the module directory path (v6) [callee:0x004328E0, global:0x007C73E0, source:raw]
    // GUARD: Path copy into the output buffer runs only when the accessor result v6 is non-null [source:raw]
    // CALL: When v6 is non-null: computes v7 = strlen(v6) + 1, defaults v3 to byte_5EA438 if *a1 was null, then calls sub_588640(v6, v3, v7 - 1) to copy the module path string (strlen(v6) chars) into the output buffer [callee:0x00588640, field:this:0x00000000, global:0x005EA438, source:raw]
    // CALL: Calls sub_568910 with the max-length argument a3; purpose unknown [callee:0x00568910, source:raw]
    // CALCULATION: Scans a2 backward from its end (v9) for '.', 46 (0x2E); when found before the start, truncates the extension by writing a NUL at the dot position [source:raw]
    // GUARD: Extension concatenation runs only when a2 is empty ('\0') after the dot stripping [source:raw]
    // CALL: When a2 is empty: calls sub_587DD0(a2, asc_5C4068, a3 - 1) to concatenate the dot-extension string asc_5C4068 into a2, then writes NUL at a2[a3 - 1]; the result of sub_587DD0 is the return value [callee:0x00587DD0, global:0x005C4068, source:raw]
    // RETURN: Returns result (the sub_587DD0 concatenation result, or 0 when no concatenation ran) [source:raw]
    // STATE_TRANSITION: Invoked by PathStringModifier (00433370) [caller:0x00433370, source:raw]

    // Conservative worker pseudocode:
    //   // a1: char** output buffer pointer; a2: input path; a3: max length
    //   v3 = *a1;
    //   v4 = *a1 ? *a1 : &byte_5EA438;
    //   // backslash scan; found position is never used
    //   for (i = v4 + strlen(v4); i > v4; --i) if (*i == 92) break;
    //   v6 = PathAccessor_28e0((char***)dword_7C73E0);
    //   if (v6) {
    //     if (!v3) v3 = &byte_5EA438;
    //     sub_588640(v6, v3, strlen(v6));  // copy module path into output buffer
    //   }
    //   sub_568910(a3);
    //   v9 = a2 + strlen(a2);
    //   while (v9 > a2) { if (*v9 == 46) { *v9 = 0; break; } --v9; }
    //   if (*a2 == 0) {
    //     result = sub_587DD0(a2, asc_5C4068, a3 - 1);
    //     a2[a3 - 1] = 0;
    //   } else result = 0;
    //   return result;
    // UNRESOLVED: The backslash scan loop (first loop) finds the last backslash position in the default/output path but the resulting cursor i is never consumed; likely dead code or a decompiler artifact
    // UNRESOLVED: sub_568910 is called with the max-length argument a3 but its behavior is unknown
    // UNRESOLVED: sub_587DD0 is treated as a concatenation helper per the skeleton fill, but its exact append semantics (whether it respects a3-1 as a bound) are not provable from this packet
    // UNRESOLVED: The output buffer pointer at this+0x0 is read twice (into v3 and v4) with the byte_5EA438 fallback applied at different points; the intended class is unknown
}
