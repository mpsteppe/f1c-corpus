// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BA950
// Canonical corpus name: ConditionalAllocation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalAllocation_004ba950.c

void UnknownObject::ConditionalAllocation()
{
    // Allocation helper (__thiscall). Allocates a heap block of 432 multiplied by 32 bytes when a2 is nonzero, or 432 multiplied by 8 bytes when a2 is zero, via OperatorNewNhMallocWrapper, stores the returned pointer into this[0], and returns this.
    // GUARD: Guard on a2 selecting 32 or 8 as the element count factor. [source:raw]
    // CALCULATION: Compute the allocation size: 432 * (a2 != 0 ? 32 : 8). [source:raw]
    // CALL: Call OperatorNewNhMallocWrapper with the computed byte count to allocate the block. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Store the allocation result into this[0] (field this+0x0). [field:this:0x00000000, source:raw]
    // RETURN: Return this, allowing the call to be chained. [source:raw]
    // CALL: Called by CollisionObjectInsertion (0x004B48E0), which uses this helper to allocate storage sized by the a2 flag. [caller:0x004B48E0, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_4BA950(_DWORD *this, char a2) {
    //     *this = OperatorNewNhMallocWrapper(432 * (a2 != 0 ? 32 : 8));
    //     return this;
    //   }
    // UNRESOLVED: Element size 432 and the meaning of the two counts (32 vs 8) selected by a2 are unknown.
    // UNRESOLVED: Packet prelabel flags this as a structural twin of SimpleSetterWithSubCall via cluster_copy, but the owning class and field-0 slot purpose are still unknown.
}
