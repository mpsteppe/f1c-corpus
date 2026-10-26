// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494FB0
// Canonical corpus name: ShortComputation_4fb0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_4fb0_00494fb0.c

void UnknownObject::MemoryAllocationForward()
{
    // Thin __stdcall forwarding wrapper. Passes its three arguments to MemoryAllocation_cb20 as (a1, a2, 0, a3) and returns the callee result unchanged. The constant 0 occupies the third parameter slot. Called by HashTableIDResolution (0x00495890) and ResourceFileLoader (0x004F9D60), consistent with a small allocation helper used during resource loading. The packet flags a read of global dword_8AFE64 that does not appear in the decompiled body. The legacy ABI label Short_Computation_Surface_Font_Push_Wrapper conflicts with the observed allocator-callee behavior and is treated as stale.
    // CALL: Calls MemoryAllocation_cb20 with (a1, a2, 0, a3), passing a constant zero in the callee's third parameter [callee:0x0053CB20, source:raw]
    // RETURN: Returns the MemoryAllocation_cb20 result unchanged as the wrapper's own result [callee:0x0053CB20, source:raw]
    // CALL: Invoked by HashTableIDResolution (0x00495890) and ResourceFileLoader (0x004F9D60) during resource/hash-table loading paths [caller:0x00495890, caller:0x004F9D60, source:raw]

    // Conservative worker pseudocode:
    //   return MemoryAllocation_cb20(a1, a2, 0, a3);
    // UNRESOLVED: dword_8AFE64 is flagged by packet facts as read but never appears in the decompiled body; the read may be folded into the wrapper's actual machine code, and its semantics are unverified
    // UNRESOLVED: The legacy ABI label Short_Computation_Surface_Font_Push_Wrapper contradicts the allocator-callee behavior and is presumed stale
    // UNRESOLVED: The meaning of the constant zero third argument passed to MemoryAllocation_cb20 is unknown
}
