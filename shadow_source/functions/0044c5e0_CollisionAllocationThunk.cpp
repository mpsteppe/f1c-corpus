// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C5E0
// Canonical corpus name: CollisionThunk
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionThunk_0044c5e0.c

void UnknownObject::CollisionAllocationThunk()
{
    // Thin thunk that calls MemoryAllocation_31a0 passing the address of global ppvOut (0x007CA590) and returns its result directly.
    // CALL: Call MemoryAllocation_31a0 with the address of global ppvOut (0x007CA590); pass the global by address and propagate its result as the return value. [source:raw, global:0x007CA590, function:0x0044C5E0]

    // Conservative worker pseudocode:
    //   int CollisionAllocationThunk(void) {
    //       return MemoryAllocation_31a0(&ppvOut);
    //   }
    // UNRESOLVED: MemoryAllocation_31a0 is invoked but absent from packet callees; its address and semantics are unknown here.
    // UNRESOLVED: The target object owning ppvOut (0x007CA590) is unknown; owner stays UnknownObject.
}
