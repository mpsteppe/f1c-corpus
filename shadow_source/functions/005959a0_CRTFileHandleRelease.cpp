// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005959A0
// Canonical corpus name: sub_5959A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5959A0_005959a0.c

void UnknownObject::CRTFileHandleRelease()
{
    // CRT file-descriptor handle release, structural twin of sub_595924. If descriptor index a1 is in range, the slot's flag byte at offset 4 has bit 0 set (slot in use), and the slot dword is not -1, optionally clears the console standard handle matching a1 when dword_5E65B4 == 1, resets the slot dword to -1 and returns 0; otherwise stores error 9 in the TLS error slot, clears the extended error slot and returns -1.
    // GUARD: Fail when a1 >= uNumber, or the flag byte at slot offset 4 (dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4) has bit 0 clear, or the slot dword is -1. [global:0x008D4A20, source:raw]
    // GUARD: When dword_5E65B4 == 1, clear the console standard handle matching a1 with a null handle: a1 0 -> SetStdHandle(0xFFFFFFF6, 0), a1 1 -> SetStdHandle(0xFFFFFFF5, 0), a1 2 -> SetStdHandle(0xFFFFFFF4, 0). [global:0x005E65B4, global:0x0059E098, source:raw]
    // ASSIGNMENT: Reset the descriptor slot dword at dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) to -1. [source:raw]
    // RETURN: Return 0 on successful release. [source:raw]
    // CALL: Error path: write 9 through TLSOffsetGetter, write 0 through TLSOffsetGetter_afd8, and return -1. [callee:0x0058AFCF, callee:0x0058AFD8, source:raw]

    // Conservative worker pseudocode:
    //   int CRTFileHandleRelease(int fd) {
    //       slot = dword_8D4920[fd >> 5] + 36 * (fd & 0x1F);
    //       if (fd >= uNumber || (flag_byte(slot) & 1) == 0 || *(DWORD *)slot == -1) {
    //           *TLSOffsetGetter() = 9;
    //           *TLSOffsetGetter_afd8() = 0;
    //           return -1;
    //       }
    //       if (dword_5E65B4 == 1) SetStdHandle(std_handle_for(fd), 0);
    //       *(DWORD *)slot = -1;
    //       return 0;
    //   }
    // UNRESOLVED: The descriptor table base dword_8D4920 (36-byte stride, indexed by fd >> 5 with element fd & 0x1F) is used by the raw source but is not present in the packet globals list; the 36-byte entry layout is inferred from the raw source.
    // UNRESOLVED: The flag byte at slot offset 4 bit 0 is interpreted as an in-use marker only by symmetry with the assign twin; its independent meaning is unconfirmed.
    // UNRESOLVED: The 0xFFFFFFF6/0xFFFFFFF5/0xFFFFFFF4 constants are the raw two's-complement renderings of the standard-handle ids; their meaning as STD_INPUT/OUTPUT/ERROR is derived from the SetStdHandle call pattern.
    // UNRESOLVED: The caller HandleCloseWithErrorReporting (0x0058C38E) indicates this closes a handle on behalf of a close path, but the error-reporting linkage is not visible in this function body.
}
