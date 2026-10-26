// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C9B4
// Canonical corpus name: sub_58C9B4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58C9B4_0058c9b4.c

void UnknownObject::FileReadUnderCriticalSection()
{
    // Critical-section-guarded file read wrapper. Validates the slot index a1 against the global open-file count uNumber and checks the per-slot active flag bit (bit 0 of the byte at slot-table pointer + 36*(a1&0x1F) + 4, where the slot table dword_8D4920 is indexed in 32-slot groups by a1>>5). On success enters the per-slot critical section, performs the read through sub_58CA19, leaves the critical section and returns the bytes read. On invalid/closed slot writes TLS error code 9 through TLSOffsetGetter, clears the TLS value written by TLSOffsetGetter_afd8, and returns -1. Structural twin of sub_58C331 (cluster_copy prelabel, DERIVED).
    // GUARD: Slot validity guard: a1 must be less than uNumber (global open-file count at 0x008D4A20) [global:0x008D4A20, source:raw]
    // GUARD: Slot-active guard: bit 0 of the byte at dword_8D4920[a1>>5] + 36*(a1&0x1F) + 4 must be non-zero; dword_8D4920 is a table of per-32-slot groups and the expression locates the flag byte for slot a1 [global:0x008D4920, source:raw]
    // CALL: CriticalSectionEnterWithLazyInit(a1) enters the per-slot critical section on the valid-slot path [callee:0x00595A61, source:raw]
    // CALL: v3 = sub_58CA19(a1, lpBuffer, nNumberOfBytesToRead) performs the actual read, forwarding the slot, buffer and byte count unchanged [callee:0x0058CA19, source:raw]
    // CALL: FileCriticalSectionLeave(a1) releases the per-slot critical section [callee:0x00595AC0, source:raw]
    // RETURN: Return v3 (bytes read) on the valid-slot path [source:raw]
    // ASSIGNMENT: Error path: write TLS error code 9 through the pointer returned by TLSOffsetGetter() [callee:0x0058AFCF, source:raw]
    // ASSIGNMENT: Error path: clear the TLS value written through the pointer returned by TLSOffsetGetter_afd8() to 0 [callee:0x0058AFD8, source:raw]
    // RETURN: Return -1 on the invalid/closed-slot error path [source:raw]
    // CALL: Called from sub_58806E, sub_58C255 and sub_59C30E as a shared guarded file-read helper [caller:0x0058806E, caller:0x0058C255, caller:0x0059C30E]

    // Conservative worker pseudocode:
    //   int FileReadUnderCriticalSection(int a1, LPVOID lpBuffer, DWORD nNumberOfBytesToRead) {
    //     if (a1 < uNumber && (*(_BYTE*)(dword_8D4920[a1>>5] + 36*(a1&0x1F) + 4) & 1) != 0) {
    //       CriticalSectionEnterWithLazyInit(a1);
    //       int v3 = sub_58CA19(a1, lpBuffer, nNumberOfBytesToRead);
    //       FileCriticalSectionLeave(a1);
    //       return v3;
    //     }
    //     *(_DWORD*)TLSOffsetGetter() = 9;
    //     *(_DWORD*)TLSOffsetGetter_afd8() = 0;
    //     return -1;
    //   }
    // UNRESOLVED: Meaning of the per-slot active-flag byte layout (36-byte stride, flag at +4) and the exact object held by dword_8D4920 are inferred from the source text only
    // UNRESOLVED: Significance of TLS error code 9 and the second TLS write through TLSOffsetGetter_afd8 is not documented
    // UNRESOLVED: The cluster_copy relationship to sub_58C331 (0058c331) is DERIVED and not independently verified here
    // UNRESOLVED: Owner class identity is not established by the packet
}
