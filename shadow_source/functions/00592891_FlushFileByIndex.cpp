// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00592891
// Canonical corpus name: sub_592891
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_592891_00592891.c

void UnknownObject::FlushFileByIndex()
{
    // Flushes file buffers for an open file identified by index a1. Validates a1 against the open file count uNumber (008D4A20) and against the slot's active flag bit 0 in the per-slot descriptor array, enters the per-file critical section, resolves the OS handle via sub_595A1F, calls FlushFileBuffers, and reports failures through the TLS slot getters (error code 9 for the generic path, GetLastError for the extended path). Returns 0 on success and -1 on any guarded failure. Called by MemoryBlockValidationCheck (0058A02C).
    // GUARD: Guard a1 < uNumber (008D4A20); an out-of-range index falls through to the error path. [global:0x008D4A20, source:raw]
    // GUARD: Guard the active-flag bit 0 at descriptor-block offset 4 (descriptor base selected by a1 >> 5, slot offset 36 * (a1 & 0x1F)); the slot must be open/active. [source:raw]
    // CALL: CriticalSectionEnterWithLazyInit(a1) enters the per-file critical section with lazy initialization. [callee:0x00595A61, source:raw]
    // GUARD: Re-check the active-flag bit 0 inside the critical section; if it is no longer set, fall through to the TLS error-9 path. [source:raw]
    // CALL: sub_595A1F(a1) translates the file index into an OS file handle. [callee:0x00595A1F, source:raw]
    // CALL: FlushFileBuffers(handle) flushes the file buffers to disk. [global:0x0059E120, source:raw]
    // GUARD: If FlushFileBuffers succeeds LastError stays 0; otherwise GetLastError captures the failure code. [global:0x0059E188, source:raw]
    // ASSIGNMENT: On a failed flush, write the captured GetLastError value into the TLS slot returned by TLSOffsetGetter_afd8 (extended error info). [callee:0x0058AFD8, source:raw]
    // ASSIGNMENT: On the generic failure path, write error code 9 into the TLS slot returned by TLSOffsetGetter and set the result to -1. [callee:0x0058AFCF, source:raw]
    // CALL: FileCriticalSectionLeave(a1) releases the per-file critical section on the success and failure paths. [callee:0x00595AC0, source:raw]
    // RETURN: Return LastError (0 on success, -1 on the guarded failure paths) to the caller MemoryBlockValidationCheck (0058A02C). [caller:0x0058A02C, function:0x00592891, source:raw]

    // Conservative worker pseudocode:
    //   int sub_592891(int idx) {
    //     if (idx < uNumber) {
    //       int slot = 36 * (idx & 0x1F);
    //       if ((*(dword_8D4920[idx >> 5] + slot + 4) & 1) != 0) {
    //         CriticalSectionEnterWithLazyInit(idx);
    //         if ((*(dword_8D4920[idx >> 5] + slot + 4) & 1) != 0) {
    //           HANDLE h = sub_595A1F(idx);
    //           DWORD err = FlushFileBuffers(h) ? 0 : GetLastError();
    //           if (err == 0) goto leave;
    //           *(DWORD *)TLSOffsetGetter_afd8() = err;
    //         }
    //         *(DWORD *)TLSOffsetGetter() = 9;
    //         err = -1;
    //       leave:
    //         FileCriticalSectionLeave(idx);
    //         return err;
    //       }
    //     }
    //     *(DWORD *)TLSOffsetGetter() = 9;
    //     return -1;
    //   }
    // UNRESOLVED: The descriptor array base is named dword_8D4920 in the raw source but no corresponding global entry exists in the packet's allowed evidence, so the array base address is not asserted here.
    // UNRESOLVED: The exact layout of the per-slot descriptor block (36-byte stride, active bit at offset 4) is read from raw offsets and has no named-struct evidence.
    // UNRESOLVED: The purpose of the TLS error codes (9 generic, GetLastError extended) beyond being set on failure is caller-consumed and not visible in this packet.
}
