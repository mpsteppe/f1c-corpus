// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005427D0
// Canonical corpus name: sub_5427D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5427D0_005427d0.c

void UnknownObject::locateBitmapFile()
{
    // Searches for a bitmap file on behalf of texture creation. Copies and normalizes the input path (truncating over-long paths to 0x300 bytes), tests it directly via sub_543130, then searches each registered data-directory entry (byte_8B5A3C, stride 132, dword_8B8E30 entries) by formatting a "%s\\%s" path, and finally walks an object linked list headed by dword_8B8F14 via the next pointer at +304, testing each entry with sub_55FE70. If the directory loop breaks early the list step is skipped and the search count is -1. The result is accepted only when the found count equals dword_8B6AC0; otherwise the message "Could not locate bitmap file %s" is formatted and reported through sub_53C590, returning -1.
    // GUARD: If the input path a1 is NULL, return 0 immediately. [source:raw]
    // GUARD: If the input path length exceeds 0x300 bytes, force a null terminator at a1+767 (offset 0x2FF) as a truncation guard. [field:this:0x000002FF]
    // ASSIGNMENT: Copy the input path a1 into the local SrcStr buffer. [source:raw]
    // CALL: Normalize the SrcStr path in place via sub_589901. [callee:0x00589901]
    // GUARD: If sub_543130(SrcStr, a2, a3, a4) fails, return 0 (direct/current-directory lookup failed). [callee:0x00543130]
    // LOOP: For each registered data-directory entry (byte_8B5A3C base, 132-byte stride, dword_8B8E30 entries) build a "%s\\%s" path into v11 via StringFormatWithBufferOverflowCheck using the format string at 0x005C2D64 and test it with sub_543130; break on the first failure. [global:0x008B5A3C, global:0x008B8E30, global:0x005C2D64, callee:0x0058815F, callee:0x00543130]
    // LOOP: If every directory entry checked out, walk the object linked list headed by dword_8B8F14 following the next pointer at +304, testing each node with sub_55FE70 and counting successes. [global:0x008B8F14, callee:0x0055FE70]
    // GUARD: If the found count i (or -1 when the directory loop broke early) does not equal dword_8B6AC0, return 0. [global:0x008B6AC0]
    // CALL: Format the failure message "Could not locate bitmap file %s" (string at 0x005DBD94) into a local buffer via StringFormatWithBufferOverflowCheck and report it through sub_53C590 with -1. [global:0x005DBD94, callee:0x0058815F, callee:0x0053C590]
    // RETURN: Return -1 on the not-found path. [source:raw]

    // Conservative worker pseudocode:
    //   int locateBitmapFile(const char* path, int a2, int a3, int a4) {
    //     CHAR SrcStr[768]; char msg[256];
    //     if (!path) return 0;
    //     if (strlen(path) > 0x300) *(BYTE*)(path+767) = 0;
    //     strcpy(SrcStr, path); sub_589901(SrcStr);
    //     if (!sub_543130(SrcStr, a2, a3, a4)) return 0;
    //     int dirs = 0;
    //     if (dword_8B8E30 > 0) {
    //       const char* p = byte_8B5A3C;
    //       do {
    //         StringFormatWithBufferOverflowCheck(msg, "%s\\%s", p, SrcStr);
    //         if (!sub_543130(msg, a2, a3, a4)) break;
    //         ++dirs; p += 132;
    //       } while (dirs < dword_8B8E30);
    //     }
    //     int found;
    //     if (dirs == dword_8B8E30) {
    //       int* node = dword_8B8F14;
    //       for (found = 0; node; ++found) {
    //         if (!sub_55FE70(SrcStr, a2, a3, a4)) break;
    //         node = *(int**)(node + 304);
    //       }
    //     } else found = -1;
    //     if (found != dword_8B6AC0) return 0;
    //     StringFormatWithBufferOverflowCheck(msg, "Could not locate bitmap file %s", SrcStr);
    //     sub_53C590(-1, msg);
    //     return -1;
    //   }
    // UNRESOLVED: The exact roles of a2/a3/a4 (likely output parameters) and the meaning of the expected count dword_8B6AC0 are not established by this packet.
    // UNRESOLVED: The identity of the object linked list headed by dword_8B8F14 is unknown.
}
