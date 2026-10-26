// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00432A10
// Canonical corpus name: DirectoryPathExtraction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DirectoryPathExtraction_00432a10.c

void UnknownObject::DirectoryPathExtraction()
{
    // Truncates the path string held at array offset 0x8 (reached through the object pointer at this[0]) to its directory part by writing a null terminator at the character just after the last backslash (literal 92). Reads the path pointer from the array, defaults to the global byte_5EA438 when null, computes its length, skips a trailing backslash, then scans backwards for the previous backslash. Always returns 0. Invoked by PollingLoopWithBranch (0046E7F0). Structural twin of PathAccessor (004328c0) per cluster_copy prelabel.
    // ASSIGNMENT: Read the path string pointer v1 from array offset 0x8, dereferencing the array pointer held at this+0. [field:obj:0x00000008, field:this:0x00000000, source:raw]
    // GUARD: Guard on v1: when the path pointer is null, substitute the default string global byte_5EA438. [global:0x005EA438, source:raw]
    // CALCULATION: Compute the path length v2 = strlen(v1). [source:raw]
    // GUARD: Guard on the length: proceed only when v2 > 0. [source:raw]
    // CALCULATION: Point the cursor v3 at the final character v1[v2 - 1]. [source:raw]
    // GUARD: When the last character is a backslash (literal 92), move the cursor one position earlier to v1[v2 - 2]. [source:raw]
    // LOOP: Scan v3 backwards while the character is not a backslash; if the cursor passes the start of the string, terminate it at that point and return 0. [source:raw]
    // ASSIGNMENT: After finding a backslash, advance past it (++v3) and write the null terminator *v3 = 0, truncating the path to its directory portion. [source:raw]
    // RETURN: Return the constant 0 on every path. [source:raw]
    // CALL: Called by PollingLoopWithBranch (0046E7F0) during path/directory handling. [caller:0x0046E7F0, source:raw]

    // Conservative worker pseudocode:
    //   char sub_432A10(void *this) {
    //     const char *v1 = *(const char **)(*(_DWORD *)this + 8);
    //     if (!v1) v1 = &byte_5EA438;
    //     int v2 = strlen(v1);
    //     if (v2 > 0) {
    //       const char *v3 = &v1[v2 - 1];
    //       if (*v3 == 92) v3 = &v1[v2 - 2];
    //       if (v3 > v1) {
    //         while (*v3 != 92) {
    //           if (--v3 <= v1) { *v3 = 0; return 0; }
    //         }
    //         ++v3;
    //       }
    //       *v3 = 0;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The function mutates the string buffer referenced by the array at offset 0x8; ownership and buffer size of that buffer are not established here.
    // UNRESOLVED: Content and purpose of the global byte_5EA438 default string are not established from this function alone.
    // UNRESOLVED: Return value is always 0, so the function appears to act for effect (path truncation) rather than returning a result.
    // UNRESOLVED: Owner kept as UnknownObject/UNKNOWN per packet; cluster_copy prelabel references PathAccessor (004328c0) at DERIVED trust only.
}
