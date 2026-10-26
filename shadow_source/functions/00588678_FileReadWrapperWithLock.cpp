// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00588678
// Canonical corpus name: FileReadWrapperWithLock
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileReadWrapperWithLock_00588678.c

void UnknownObject::FileReadWrapperWithLock()
{
    // Thread-safe wrapper around the low-level stream read helper sub_5886A7. Takes the stream critical section via StreamBufferLockViaCriticalSection(a4), performs the read (arguments a1-a3 forwarded unchanged plus the same lock token a4), releases the critical section via AddressRangeCriticalSectionLeave(a4), and returns the number of bytes read. Called from file-enumeration, telemetry, resource, buffer and conditional-dispatch paths, so it is the common locked read entry point for the file/stream layer.
    // CALL: StreamBufferLockViaCriticalSection(a4) enters the critical section protecting the stream addressed by a4 [callee:0x0058C1B1]
    // CALL: sub_5886A7(a1, a2, a3, a4) performs the actual read while the lock is held; its return value is saved [callee:0x005886A7]
    // CALL: AddressRangeCriticalSectionLeave(a4) releases the critical section after the read completes [callee:0x0058C203]
    // RETURN: Returns the byte count produced by the inner read helper [source:raw]

    // Conservative worker pseudocode:
    //   StreamBufferLockViaCriticalSection(a4);
    //   result = sub_5886A7(a1, a2, a3, a4);
    //   AddressRangeCriticalSectionLeave(a4);
    //   return result;
    // UNRESOLVED: The inner reader sub_5886A7 (0x005886A7) is not reconstructed here, so the exact meaning of a1-a3 (buffer, size, offset) is not established by this packet
}
