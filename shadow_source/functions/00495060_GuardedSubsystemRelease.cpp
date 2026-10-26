// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495060
// Canonical corpus name: GuardedSubsystemRelease
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedSubsystemRelease_00495060.c

void UnknownObject::GuardedSubsystemRelease()
{
    // Guarded release of a tracked subsystem/iterator. Reads the global handle dword_7CDE1C; when non-null, hands it to UICleanupIterator and returns the iterator result; when null, returns the handle unchanged (zero). Invoked from sub_4A00A0 and FileLoadWithRetryLoop.
    // ASSIGNMENT: result := dword_7CDE1C (read the global tracked-handle value) [global:0x007CDE1C]
    // GUARD: if dword_7CDE1C is non-null, run the cleanup path [global:0x007CDE1C]
    // CALL: UICleanupIterator(dword_7CDE1C) releases the tracked iterator; its return value becomes the function result [callee:0x00554D70, global:0x007CDE1C]
    // RETURN: return dword_7CDE1C unchanged when the handle was already null (zero) [global:0x007CDE1C, function:0x00495060]

    // Conservative worker pseudocode:
    //   int GuardedSubsystemRelease() {
    //       if (g_handle) return UICleanupIterator(g_handle);
    //       return g_handle;
    //   }
    // UNRESOLVED: Global dword_8B78A0 is listed in the packet evidence but is absent from the decompiled body; its role is unknown.
    // UNRESOLVED: The object type owned by dword_7CDE1C and the exact cleanup semantics of UICleanupIterator are unknown.
}
