// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059B650
// Canonical corpus name: sub_59B650
// Owner: FileHandleManager [DERIVED]
// Raw source: functions/sub_59B650_0059b650.c

void FileHandleManager::FileHandleDupTransfer()
{
    // Duplicates the open file handle of slot a1 into a newly allocated slot via DuplicateHandle under per-file critical sections, clears the source status flag's bit 4 on success, and returns the new slot index or -1 with a TLS error code.
    // GUARD: Entry guard: a1 < uNumber and the status byte at dword_8D4920[a1>>5] + 36*(a1&0x1F) + 4 has bit 0 set (slot open); otherwise take the guard-failure path. [global:0x008D4A20, global:0x008D4920, function:0x0059B650]
    // CALL: CriticalSectionEnterWithLazyInit(a1) enters the per-file critical section for the source slot. [callee:0x00595A61]
    // ASSIGNMENT: Save the current source slot status byte into v2 for the later flag update. [global:0x008D4920]
    // CALL: sub_595801() allocates a new free file slot index; -1 signals allocation failure. [callee:0x00595801]
    // RETURN: On allocation failure set TLS error 24 via TLSOffsetGetter, TLS errno 0 via TLSOffsetGetter_afd8, leave the source slot critical section, and return -1. [callee:0x0058AFCF, callee:0x0058AFD8, callee:0x00595AC0]
    // CALL: GetCurrentProcess and sub_595A1F(a1) retrieve the source handle for slot a1. [global:0x0059E18C, callee:0x00595A1F]
    // CALL: DuplicateHandle duplicates the source handle into TargetHandle (inheritable, DUPLICATE_SAME_ACCESS); on success sub_595924(v3, TargetHandle) stores it into the new slot and LastError is 0, otherwise LastError = GetLastError(). [global:0x0059E100, callee:0x00595924]
    // ASSIGNMENT: On DuplicateHandle failure capture GetLastError() as LastError. [global:0x0059E188]
    // CALL: FileCriticalSectionLeave(v3) then FileCriticalSectionLeave(a1) release both slot critical sections. [callee:0x00595AC0]
    // RETURN: If no error, clear bit 4 of the new slot status byte (v2 & 0xEF) at dword_8D4920[v3>>5] + 36*(v3&0x1F) + 4 and return the new slot index v3. [global:0x008D4920, function:0x0059B650]
    // CALL: On error ErrorIDLookupTable(LastError) raises the mapped error before the function returns -1. [callee:0x0058AF5C]
    // ASSIGNMENT: Guard-failure path: set TLS error 9 via TLSOffsetGetter and TLS errno 0 via TLSOffsetGetter_afd8. [callee:0x0058AFCF, callee:0x0058AFD8]
    // RETURN: All failure paths return -1. [function:0x0059B650]

    // Conservative worker pseudocode:
    //   if (a1 < uNumber && (slot_status(a1) & 1)) {
    //       enter_critical_section(a1);
    //       byte v2 = slot_status(a1);
    //       int v3 = allocate_file_slot();
    //       if (v3 == -1) { set_tls_error(24); leave_critical_section(a1); return -1; }
    //       HANDLE source = get_slot_handle(a1);
    //       if (DuplicateHandle(GetCurrentProcess(), source, GetCurrentProcess(), &target, 0, TRUE, 2)) {
    //           store_slot_handle(v3, target);
    //           error = 0;
    //       } else {
    //           error = GetLastError();
    //       }
    //       leave_critical_section(v3);
    //       leave_critical_section(a1);
    //       if (!error) { slot_status(v3) = v2 & 0xEF; return v3; }
    //       raise_error(error);
    //   } else {
    //       set_tls_error(9);
    //   }
    //   return -1;
    // UNRESOLVED: Purpose of status byte bit 4 (cleared via v2 & 0xEF on successful duplicate) is not labelled in packet evidence.
}
