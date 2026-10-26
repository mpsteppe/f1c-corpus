// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C331
// Canonical corpus name: sub_58C331
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58C331_0058c331.c

void UnknownObject::_close()
{
    // CRT-style file-handle close. Validates that handle a1 is below uNumber (0x008D4A20) and that the open bit (bit 0) at the per-handle slot in dword_8D4920 (0x008D4920) is set; if valid, enters the per-handle critical section, closes via HandleCloseWithErrorReporting and returns its result. Otherwise writes 9 to the TLS errno slot and 0 to the TLS doserrno slot and returns -1.
    // GUARD: Proceed to close only if a1 < uNumber and the byte at dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4 has bit 0 set (handle is open). [global:0x008D4A20, global:0x008D4920, source:raw]
    // CALL: Enter the per-handle critical section via CriticalSectionEnterWithLazyInit(a1). [callee:0x00595A61, source:raw]
    // CALL: Close the OS handle via HandleCloseWithErrorReporting(a1); capture its return value in v1. [callee:0x0058C38E, source:raw]
    // CALL: Leave the per-handle critical section via FileCriticalSectionLeave(a1). [callee:0x00595AC0, source:raw]
    // RETURN: Return v1 (the close result) on the valid-handle path. [source:raw]
    // ASSIGNMENT: On the invalid-handle path, write 9 to the TLS errno slot obtained from TLSOffsetGetter(). [callee:0x0058AFCF, source:raw]
    // ASSIGNMENT: On the invalid-handle path, write 0 to the TLS doserrno slot obtained from TLSOffsetGetter_afd8(). [callee:0x0058AFD8, source:raw]
    // RETURN: Return -1 on the invalid-handle path. [source:raw]

    // Conservative worker pseudocode:
    //   if (a1 < uNumber && (dword_8D4920[a1 >> 5][36 * (a1 & 0x1F) + 4] & 1)) {
    //       CriticalSectionEnterWithLazyInit(a1);
    //       v1 = HandleCloseWithErrorReporting(a1);
    //       FileCriticalSectionLeave(a1);
    //       return v1;
    //   }
    //   *TLSOffsetGetter() = 9;
    //   *TLSOffsetGetter_afd8() = 0;
    //   return -1;
    // UNRESOLVED: The 9 written to the TLS errno slot is conventionally EBADF, but the errno enum is not evidenced in this packet.
    // UNRESOLVED: The 36-byte stride of the per-handle slot in dword_8D4920 is a derived constant from the array index expression; its structure is not further evidenced.
}
