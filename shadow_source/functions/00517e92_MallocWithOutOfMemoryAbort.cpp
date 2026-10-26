// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00517E92
// Canonical corpus name: sub_517E92
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_517E92_00517e92.c

void UnknownObject::MallocWithOutOfMemoryAbort()
{
    // Allocation helper: returns 0 immediately when either argument is null; otherwise allocates a2 bytes via MallocWrapperForNhMalloc (0x0058A935) and, if the allocation returns null, raises an out-of-memory condition through GuardedCallWithLongjmp (0x00511869) with the global "Out of Memory" string (0x005AFA90). Returns the allocated pointer.
    // GUARD: Guard on inputs: if either a1 or a2 is null, return 0 without allocating. [source:raw]
    // CALL: v2 = MallocWrapperForNhMalloc(a2) allocates a2 bytes through the NH malloc wrapper. [callee:0x0058A935, source:raw]
    // GUARD: Guard on allocation result: when v2 is null, enter the out-of-memory path. [callee:0x0058A935, source:raw]
    // CALL: GuardedCallWithLongjmp(a1, "Out of Memory") triggers the guarded failure path using the global message string aOutOfMemory (0x005AFA90) and the a1 context. [callee:0x00511869, global:0x005AFA90, source:raw]
    // RETURN: Return v2, the allocated pointer (null only when the early input guard fired). [callee:0x0058A935, source:raw]

    // Conservative worker pseudocode:
    //   int MallocWithOutOfMemoryAbort(int a1, int a2) {
    //     if (!a1 || !a2)
    //       return 0;
    //     int v2 = MallocWrapperForNhMalloc(a2);
    //     if (!v2)
    //       GuardedCallWithLongjmp(a1, "Out of Memory");
    //     return v2;
    //   }
    // UNRESOLVED: Exact role of a1 (forwarded to GuardedCallWithLongjmp): context/callback/handler identity not established from raw source.
    // UNRESOLVED: Callers cluster in audio paths (EngineSoundWaveTableGenerator 0x00513482, AudioBufferSizeCalc 0x0051868C), but a shared owning class is unknown.
}
