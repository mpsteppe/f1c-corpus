// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058E0C7
// Canonical corpus name: TLSValueRetrievalWithInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TLSValueRetrievalWithInit_0058e0c7.c

void UnknownObject::GetPerThreadDataWithInit()
{
    // CRT-style per-thread data retrieval. Saves the current GetLastError value, reads the per-thread data block pointer via TlsGetValue(dwTlsIndex). On first access for a thread (null pointer), lazily allocates a 116-byte block with sub_58AB58(1, 116), registers it with TlsSetValue(dwTlsIndex, block), initializes it via TwoFieldInitializer_e0b4 and stamps it with the current thread id and a -1 sentinel; on allocation/registration failure it terminates with CRTAmsgExit(0x10). Finally restores the saved LastError value and returns the per-thread data pointer.
    // CALL: Capture GetLastError() into LastError so the TLS setup path can restore it afterward. [global:0x0059E188, source:raw]
    // CALL: Retrieve the per-thread data block via TlsGetValue(dwTlsIndex). [global:0x0059E14C, global:0x005E6D40, source:raw]
    // GUARD: Branch on the TlsGetValue result: a null value means the per-thread block has not been allocated yet on this thread. [source:raw]
    // CALL: Allocate a new per-thread data block with sub_58AB58(1, 116) (116-byte block). [callee:0x0058AB58, source:raw]
    // CALL: Register the newly allocated block with TlsSetValue(dwTlsIndex, block); if the allocation or registration fails, terminate with CRTAmsgExit(0x10). [callee:0x0058A2A6, global:0x0059E158, global:0x005E6D40, source:raw]
    // CALL: Initialize fields of the new block via TwoFieldInitializer_e0b4. [callee:0x0058E0B4, source:raw]
    // CALL: Capture GetCurrentThreadId() to stamp the block with the owning thread id. [global:0x0059E15C, source:raw]
    // ASSIGNMENT: Stamp the block: Value[1] = -1 and Value[0] = current thread id. [source:raw]
    // CALL: Restore the saved LastError value via SetLastError so the TLS machinery does not disturb the caller's error state. [global:0x0059E150, source:raw]
    // RETURN: Return the per-thread data pointer (newly created on first access, previously stored otherwise). [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* GetPerThreadDataWithInit() {
    //     DWORD lastError = GetLastError();
    //     _DWORD* block = TlsGetValue(dwTlsIndex);
    //     if (block == NULL) {
    //       block = sub_58AB58(1, 116);
    //       if (block && TlsSetValue(dwTlsIndex, block)) {
    //         TwoFieldInitializer_e0b4((int)block);
    //         DWORD tid = GetCurrentThreadId();
    //         block[1] = -1;
    //         block[0] = tid;
    //       } else {
    //         CRTAmsgExit(0x10);
    //       }
    //     }
    //     SetLastError(lastError);
    //     return block;
    //   }
    // UNRESOLVED: The per-thread block layout (beyond Value[0] thread id and Value[1] = -1 sentinel) is unknown; the fields initialized by TwoFieldInitializer_e0b4 are not enumerated here.
    // UNRESOLVED: The identity of the per-thread structure's owner is unknown; treated as an unverified CRT-owned block.
    // UNRESOLVED: The allocation size semantics of sub_58AB58(1, 116) (element count / element size vs byte count) are unverified.
}
