// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058ACE6
// Canonical corpus name: FileSizeQueryWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileSizeQueryWrapper_0058ace6.c

void UnknownObject::FileSizeQueryWrapper()
{
    // Thread-safe wrapper around the low-level stream size query sub_58AD08. Takes the stream critical section via StreamBufferLockViaCriticalSection(a1), queries the size via sub_58AD08(a1), releases the critical section via AddressRangeCriticalSectionLeave(a1), and returns the reported size. Called from resource, mesh/index-buffer and file loader paths, making it the common locked size-query entry point for the file/stream layer.
    // CALL: StreamBufferLockViaCriticalSection(a1) enters the critical section protecting the stream addressed by a1 [callee:0x0058C1B1]
    // CALL: sub_58AD08(a1) performs the actual size query while the lock is held; its return value is saved [callee:0x0058AD08]
    // CALL: AddressRangeCriticalSectionLeave(a1) releases the critical section after the query completes [callee:0x0058C203]
    // RETURN: Returns the size produced by the inner query helper [source:raw]

    // Conservative worker pseudocode:
    //   StreamBufferLockViaCriticalSection(a1);
    //   result = sub_58AD08(a1);
    //   AddressRangeCriticalSectionLeave(a1);
    //   return result;
    // UNRESOLVED: The inner query sub_58AD08 (0x0058AD08) is not reconstructed here, so whether the returned value is a byte size or a different stream quantity is not established by this packet
}
