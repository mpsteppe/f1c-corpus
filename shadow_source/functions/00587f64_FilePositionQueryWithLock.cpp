// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587F64
// Canonical corpus name: sub_587F64
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_587F64_00587f64.c

void UnknownObject::FilePositionQueryWithLock()
{
    // Locked file-position query wrapper. Acquires the stream critical section on the stream handle, queries the current file tell/seek position through FileTellSeekPositionQuery, releases the critical section, and returns the queried position. A thin lock/unlock guard around a single position query; on the frame path via binary/resource/audio readers.
    // CALL: Acquires the stream critical section via StreamBufferLockViaCriticalSection on the stream handle a1 before the position query [callee:0x0058C1B1, source:raw]
    // CALL: Queries the current file tell/seek position via FileTellSeekPositionQuery(a1, a2, a3) and stores the result in v3 [callee:0x00587F90, source:raw]
    // CALL: Releases the stream critical section via AddressRangeCriticalSectionLeave(a1) after the query completes [callee:0x0058C203, source:raw]
    // RETURN: Returns the queried file position value stored in v3 [function:0x00587F64, source:raw]
    // CALL: Serves as the locked position-query wrapper for binary/resource readers such as BinaryDataDeserialization and AudioStreamBufferRead [caller:0x004054E0, caller:0x00535390, source:raw]

    // Conservative worker pseudocode:
    //   StreamBufferLockViaCriticalSection(a1);
    //   v3 = FileTellSeekPositionQuery(a1, a2, a3);
    //   AddressRangeCriticalSectionLeave(a1);
    //   return v3;
    // UNRESOLVED: The exact meaning of a2/a3 depends on FileTellSeekPositionQuery's relative/absolute seek semantics, which are outside this packet
}
