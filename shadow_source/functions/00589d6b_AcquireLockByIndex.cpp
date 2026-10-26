// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589D6B
// Canonical corpus name: sub_589D6B
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_589D6B_00589d6b.c

void UnknownObject::AcquireLockByIndex()
{
    // Trivial forwarder that acquires a synchronization lock by calling CriticalSectionLazyInitEnter with lock slot index 13 and returns its result. The ABI lead labels this function Lock_Acquire_by_Index.
    // CALL: Call CriticalSectionLazyInitEnter(0x58DFEA) with constant lock index 13; its return value is the function result. [callee:0x0058DFEA, abi:lead, source:raw]
    // RETURN: Return the value produced by CriticalSectionLazyInitEnter unchanged. [function:0x00589D6B, source:raw]

    // Conservative worker pseudocode:
    //   int AcquireLockByIndex(void) {
    //       return CriticalSectionLazyInitEnter(13);
    //   }
    // UNRESOLVED: The subsystem owning critical-section slot 13 is unknown; the constant has no packet evidence linking it to a named resource.
    // UNRESOLVED: Why callers sub_587AC0 and sub_589CC6 route lock acquisition through this indirection instead of calling CriticalSectionLazyInitEnter directly is unresolved.
}
