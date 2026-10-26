// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595924
// Canonical corpus name: sub_595924
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_595924_00595924.c

void UnknownObject::CRTFileHandleAssign()
{
    // CRT file-descriptor handle assignment. If the descriptor index a1 is in range and its slot (in the 36-byte-stride descriptor table) is empty (== -1), optionally binds the console standard handle matching a1 when dword_5E65B4 == 1, stores the supplied handle in the slot and returns 0; otherwise stores error 9 in the TLS error slot, clears the extended error slot and returns -1.
    // GUARD: Fail when a1 >= uNumber or the descriptor slot entry at dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) is not -1 (slot already occupied). [global:0x008D4A20, source:raw]
    // GUARD: When dword_5E65B4 == 1, map descriptor index a1 to a console standard handle and assign hHandle to it: a1 0 -> SetStdHandle(0xFFFFFFF6), a1 1 -> SetStdHandle(0xFFFFFFF5), a1 2 -> SetStdHandle(0xFFFFFFF4). [global:0x005E65B4, global:0x0059E098, source:raw]
    // ASSIGNMENT: Store hHandle into the descriptor slot entry at dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F). [source:raw]
    // RETURN: Return 0 on successful assignment. [source:raw]
    // CALL: Error path: write 9 through TLSOffsetGetter, write 0 through TLSOffsetGetter_afd8, and return -1. [callee:0x0058AFCF, callee:0x0058AFD8, source:raw]

    // Conservative worker pseudocode:
    //   int CRTFileHandleAssign(int fd, HANDLE h) {
    //       if (fd >= uNumber || slot(fd) != -1) {
    //           *TLSOffsetGetter() = 9;
    //           *TLSOffsetGetter_afd8() = 0;
    //           return -1;
    //       }
    //       if (dword_5E65B4 == 1) SetStdHandle(std_handle_for(fd), h);
    //       slot(fd) = h;
    //       return 0;
    //   }
    // UNRESOLVED: The descriptor table base dword_8D4920 (36-byte stride, indexed by a1 >> 5 with element a1 & 0x1F) is used by the raw source but is not present in the packet globals list; the 36-byte entry layout is inferred from the raw source.
    // UNRESOLVED: The exact role of dword_5E65B4 beyond gating the console standard-handle mapping (console-attached flag) is inferred from the prior analysis.
    // UNRESOLVED: The 0xFFFFFFF6/0xFFFFFFF5/0xFFFFFFF4 constants are the raw two's-complement renderings of the standard-handle ids; their meaning as STD_INPUT/OUTPUT/ERROR is derived from the SetStdHandle call pattern.
}
