// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595F11
// Canonical corpus name: sub_595F11
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_595F11_00595f11.c

void UnknownObject::sub_595F11()
{
    // Checked file-handle seek wrapper. If a1 is a valid open file index (a1 below the uNumber count and the record's flag byte, at offset 4 of the per-file record, having bit 0 set), it enters the per-file critical section, performs a seek via FilePointerSeekWithErrorHandling, leaves the critical section and returns the seek result. Otherwise it writes error code 9 into the primary TLS slot, zeroes the secondary TLS slot and returns -1.
    // GUARD: Validity guard: a1 < uNumber (count of file records) AND the byte at dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4 has bit 0 set (record open). [global:0x008D4A20, global:0x008D4920, source:raw]
    // CALL: CriticalSectionEnterWithLazyInit(a1) enters the per-file critical section before seeking. [callee:0x00595A61, source:raw]
    // CALL: FilePointerSeekWithErrorHandling(a1, a2, a3, dwMoveMethod) performs the seek and returns the result stored in v4. [callee:0x00595F82, source:raw]
    // CALL: FileCriticalSectionLeave(a1) releases the per-file critical section. [callee:0x00595AC0, source:raw]
    // RETURN: Return the seek result v4 on the success path. [source:raw]
    // STATE_TRANSITION: On the invalid-handle path, store 9 into the dword at TLSOffsetGetter() (TLS error code). [callee:0x0058AFCF, source:raw]
    // ASSIGNMENT: Store 0 into the dword at TLSOffsetGetter_afd8() (secondary TLS slot). [callee:0x0058AFD8, source:raw]
    // RETURN: Return -1 on the invalid-handle path. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_595F11(int a1, int a2, int a3, DWORD dwMoveMethod) {
    //     if (a1 < uNumber && (*(_BYTE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4) & 1) != 0) {
    //       CriticalSectionEnterWithLazyInit(a1);
    //       int v4 = FilePointerSeekWithErrorHandling(a1, a2, a3, dwMoveMethod);
    //       FileCriticalSectionLeave(a1);
    //       return v4;
    //     } else {
    //       *(_DWORD *)TLSOffsetGetter() = 9;
    //       *(_DWORD *)TLSOffsetGetter_afd8() = 0;
    //       return -1;
    //     }
    //   }
    // UNRESOLVED: The 36-byte per-file record layout and the exact meaning of the bit-0 open flag at record offset 4 are inferred, not separately evidenced.
    // UNRESOLVED: Meaning of TLS error code 9 and the purpose of the secondary TLS slot are unknown.
    // UNRESOLVED: Relation to the structural twin sub_58C331 is proposed by clustering, not independently confirmed.
}
