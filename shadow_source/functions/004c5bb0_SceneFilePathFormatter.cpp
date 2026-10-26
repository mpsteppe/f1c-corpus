// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C5BB0
// Canonical corpus name: SceneFilePathFormatter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneFilePathFormatter_004c5bb0.c

void UnknownObject::SceneFilePathFormatter()
{
    // Builds a formatted scene file path: seeds a stack buffer from the default directory byte_5EA438, copies and normalizes the input path a1 into it via sub_587DD0, truncates the string at the last dot, appends a 5-byte suffix composed of dword_5C5D24 followed by byte_5C5D28, then calls UtilityFunction_8a60(a3, &v7) and returns v7 when it reports success (returns 1), otherwise returns -1.
    // ASSIGNMENT: Initialize the path buffer: v8[0] = byte_5EA438[0], zero the remaining 0x1FC bytes via memset, and zero the trailing v9/v10 bytes. [global:0x005EA438, source:raw]
    // CALL: Call sub_587DD0(v8, a1, 511) to copy and normalize the input path string a1 into the buffer v8 with a size limit of 511. [callee:0x00587DD0, source:raw]
    // GUARD: Scan backward from the string end (v3 = &v8[strlen(v8)]) while the buffer is non-empty: locate the last dot (byte 46); if found at or after the buffer start, truncate the string there by writing *v3 = 0. [source:raw]
    // CALCULATION: Compute the append position v4 = &v8[strlen(v8) + 1], then prepend the 5-byte suffix: write dword_5C5D24 at v4-4 and byte_5C5D28 at v4 (the final byte at v4+4). [global:0x005C5D24, global:0x005C5D28, source:raw]
    // CALL: Call UtilityFunction_8a60(a3, &v7) to compute the result value into v7; success is signaled by a return value of 1. [callee:0x00568A60, function:0x004C5BB0, source:raw]
    // GUARD: If UtilityFunction_8a60 returns anything other than 1, return -1. [function:0x004C5BB0, source:raw]
    // RETURN: Return v7 (the computed result) when UtilityFunction_8a60 reports success. [function:0x004C5BB0, source:raw]

    // Conservative worker pseudocode:
    //   int SceneFilePathFormatter(char a1, int a2, int a3) {
    //       char buf[512];
    //       buf[0] = byte_5EA438[0];
    //       memset(&buf[1], 0, 0x1FC);
    //       sub_587DD0(buf, a1, 511);
    //       char *p = &buf[strlen(buf)];
    //       if (p > buf) {
    //           while (*p != 46) {
    //               if (--p <= buf) break;
    //           }
    //           *p = 0;
    //       }
    //       char *q = &buf[strlen(buf) + 1];
    //       *(int *)(--q) = dword_5C5D24;
    //       q[4] = byte_5C5D28;
    //       int result;
    //       if (UtilityFunction_8a60(a3, &result) == 1)
    //           return result;
    //       return -1;
    //   }
    // UNRESOLVED: The 5-byte suffix assembled from dword_5C5D24 + byte_5C5D28 is written but its semantic meaning (extension, version, separator) is not evidenced.
    // UNRESOLVED: What byte_5EA438 holds beyond a directory/path seed is not evidenced here.
    // UNRESOLVED: The exact computation inside UtilityFunction_8a60 is outside this function's evidence.
}
