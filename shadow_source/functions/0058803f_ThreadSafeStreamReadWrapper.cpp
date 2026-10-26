// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058803F
// Canonical corpus name: ThreadSafeReadWrapper_803f
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreadSafeReadWrapper_803f_0058803f.c

void UnknownObject::ThreadSafeStreamReadWrapper()
{
    // Synchronous thread-safe read wrapper: acquires the stream lock via StreamBufferLockViaCriticalSection(a4), performs the actual read by forwarding (a1, a2, a3, a4) to sub_58806E, releases via AddressRangeCriticalSectionLeave(a4), and returns the inner read result unchanged. Used as a shared read primitive across deserialization, file enumeration, scene parsing, mesh loading and file-write paths.
    // CALL: Acquire the stream lock with StreamBufferLockViaCriticalSection(a4) using argument 4 as the stream handle. [callee:0x0058C1B1, source:raw]
    // CALL: Perform the actual read: v4 = sub_58806E(a1, a2, a3, a4), forwarding all four arguments unchanged. [callee:0x0058806E, source:raw]
    // CALL: Release the lock with AddressRangeCriticalSectionLeave(a4) before returning. [callee:0x0058C203, source:raw]
    // RETURN: Return the inner read result v4 from sub_58806E unchanged. [callee:0x0058806E, source:raw]
    // CALL: Used as a shared synchronous read primitive by deserialization, file enumeration, scene parsing, mesh loading and file-write paths, e.g. BinaryDataDeserialization (0x004054E0), MemoryAllocationWithBufferRead (0x004080F0), FileEnumerationByExtension (0x00421B10), BufferedFileReader (0x00534F90), MeshVertexIndexBufferLoader (0x00550AD0), SceneFileTopLevelParser (0x0055B200) and FileWriteWithBackendDispatch (0x00566C00). [caller:0x004054E0, caller:0x004080F0, caller:0x00421B10, caller:0x00534F90, caller:0x00550AD0, caller:0x0055B200, caller:0x00566C00]

    // Conservative worker pseudocode:
    //   int ThreadSafeStreamReadWrapper(int a1, int a2, int a3, int a4) {
    //     StreamBufferLockViaCriticalSection(a4);
    //     int v4 = sub_58806E(a1, a2, a3, a4);
    //     AddressRangeCriticalSectionLeave(a4);
    //     return v4;
    //   }
    // UNRESOLVED: The lock/unlock pair is separated by the inner call rather than a symmetric enter/leave helper, and the two lock primitives live at different addresses (0x0058C1B1 vs 0x0058C203); whether they guard the same underlying critical section is inferred from naming, not proven here.
    // UNRESOLVED: sub_58806E is the actual read implementation but its body is not in this packet; the exact read semantics of a1/a2/a3 are not established.
}
