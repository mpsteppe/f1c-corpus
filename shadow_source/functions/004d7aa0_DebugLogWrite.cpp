// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7AA0
// Canonical corpus name: DebugLogWrite
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DebugLogWrite_004d7aa0.c

void UnknownObject::DebugLogWrite()
{
    // Writes a formatted debug log line through the file handle stored at this+0x4. Calls FileWriteWrapperWithLock (0x0058A163) with the handle, format string a2 and the va_list, then calls LockCallUnlockWrapper (0x00589FFD) on the same handle and returns its result. Called from roughly 130 call sites across game subsystems.
    // CALL: Read the file handle DWORD at this+0x4 and call FileWriteWrapperWithLock(handle, a2, va) to write the formatted message [field:this:0x00000004, callee:0x0058A163, source:raw]
    // CALL: Call LockCallUnlockWrapper(handle) with the same this+0x4 file handle to flush/synchronize the log file after the write [field:this:0x00000004, callee:0x00589FFD, source:raw]
    // RETURN: Return the result of LockCallUnlockWrapper [callee:0x00589FFD, source:raw]

    // Conservative worker pseudocode:
    //   int DebugLogWrite(int a1, char *fmt, ...) {
    //     va_list va; va_start(va, fmt);
    //     FileWriteWrapperWithLock(*(void **)(a1 + 4), fmt, va);
    //     return LockCallUnlockWrapper(*(void **)(a1 + 4));
    //   }
    // UNRESOLVED: Owner object type holding the file handle at +0x4 is unknown; the handle is consumed here but never created.
    // UNRESOLVED: Formatted output destination file is not evidenced by this packet.
}
