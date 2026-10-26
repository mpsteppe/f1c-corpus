// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D2DD0
// Canonical corpus name: sub_4D2DD0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D2DD0_004d2dd0.c

void UnknownObject::GetOrCreateSubStructure()
{
    // Lazily allocates and zero-initializes an 8-byte sub-structure on first call: when field this+0xA4 is null, allocates 8 bytes via OperatorNewNhMallocWrapper (00587C03), zero-initializes the block via ZeroInitSubCall (004D0060), stores the pointer at this+0xA4, and passes it to a follow-up initialization sub-call; on allocation failure it stores 0 and passes null. Subsequent calls return the cached pointer unchanged. Invoked by Steward_Restart (004D3CF0).
    // GUARD: Lazy-init guard: result = this[41] (field this+0xA4); when non-zero the block already exists and is returned directly without re-allocation [field:this:0x000000A4, source:raw]
    // CALL: First allocation: OperatorNewNhMallocWrapper (00587C03) allocates 8 bytes of heap [callee:0x00587C03, source:raw]
    // CALL: Zero-initialize the fresh block via ZeroInitSubCall (004D0060) [callee:0x004D0060, source:raw]
    // ASSIGNMENT: Store the initialized block pointer into this[41] (field this+0xA4); on allocation failure store 0 instead [field:this:0x000000A4, source:raw]
    // CALL: Pass the stored block (or null on allocation failure) to a follow-up initialization sub-call before returning; that sub-call's address is not present in the packet's callee evidence and is therefore not recorded [field:this:0x000000A4, source:raw]
    // RETURN: Returns the cached pointer (this[41]) on subsequent calls, or the initialization sub-call's return value on the first call [function:0x004D2DD0, source:raw]
    // CALL: Invoked by Steward_Restart (004D3CF0) during a restart to guarantee the sub-structure exists before use [caller:0x004D3CF0]

    // Conservative worker pseudocode:
    //   if (this[41] != 0) return this[41];
    //   block = OperatorNewNhMallocWrapper(8);
    //   if (block != 0) {
    //     block = ZeroInitSubCall(block);
    //     this[41] = block;
    //     return init_sub_call(block);
    //   } else {
    //     this[41] = 0;
    //     return init_sub_call(0);
    //   }
    // UNRESOLVED: The first-call path ends by invoking a further initialization sub-call shown in the raw source but absent from the packet's callee list, so its address is not recorded here
    // UNRESOLVED: The 8-byte sub-structure's purpose and concrete type are DERIVED from existing_analysis (Steward_Restart context) and remain unknown
}
