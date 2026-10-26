// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00411120
// Canonical corpus name: SessionStructureCleanup
// Owner: SessionLoadingContext [DERIVED]
// Raw source: functions/SessionStructureCleanup_00411120.c

void SessionLoadingContext::cleanupSessionStructures()
{
    // Iterates six batches of 36-byte objects stored on a session/loading context and conditionally dispatches each object to ModeDispatchedRenderPhysicsCall with the current session time (dbl_8AFEA0). Batches 1-3 (counts at this+0x24/0x30/0x3C, bases at this+0x28/0x34/0x40) dispatch every element when their count is positive. Batches 4-6 (counts at this+0x48/0x54/0x60, bases at this+0x4C/0x58/0x64) skip elements whose associated vehicle-state data is still live (slot sentinel, state pointer, or byte-flag guards against the vehicle array unk_5EC6D8 and state array dword_5ED434). Called from the loading phase to reinitialize or release physics/render state.
    // LOOP: Batch 1: while the count at this+0x24 is positive, dispatch each 36-byte object starting at this+0x28 to ModeDispatchedRenderPhysicsCall with session time dbl_8AFEA0. [guard:0, field:this:0x00000024, field:this:0x00000028, callee:0x0040F300, global:0x008AFEA0]
    // LOOP: Batch 2: while the count at this+0x30 is positive, dispatch each 36-byte object starting at this+0x34 to ModeDispatchedRenderPhysicsCall with session time dbl_8AFEA0. [guard:1, field:this:0x00000030, field:this:0x00000034, callee:0x0040F300, global:0x008AFEA0]
    // LOOP: Batch 3: while the count at this+0x3C is positive, dispatch each 36-byte object starting at this+0x40 to ModeDispatchedRenderPhysicsCall with session time dbl_8AFEA0. [guard:2, field:this:0x0000003C, field:this:0x00000040, callee:0x0040F300, global:0x008AFEA0]
    // LOOP: Batch 4: while the count at this+0x48 is positive, dispatch each 36-byte object starting at this+0x4C only when its associated vehicle is not live: the vehicle slot at unk_5EC6D8 + 18624*(index/4) has sentinel -1, or the 296-byte-subrecord state pointer is null, or its +64 byte flag is zero. Indices at or above 14976 are always dispatched. [guard:3, field:this:0x00000048, field:this:0x0000004C, callee:0x0040F300, global:0x008AFEA0, global:0x005EC6D8]
    // LOOP: Batch 5: while the count at this+0x54 is positive, dispatch each 36-byte object starting at this+0x58 when its associated vehicle (unk_5EC6D8 + 18624*(index/2)) lacks the live-state pointer (dword at +821 for even, +838 for odd) or the corresponding byte flag at +3348/+3416. Active vehicles are skipped; iteration stops at 7488 or the count. [guard:4, field:this:0x00000054, field:this:0x00000058, callee:0x0040F300, global:0x008AFEA0, global:0x005EC6D8]
    // LOOP: Batch 6: while the count at this+0x60 is positive, dispatch each 36-byte object starting at this+0x64 only when its associated vehicle-state entry (dword_5ED434 + 4656*(index/8) + 17*(index%8)) is null or its +64 byte flag is zero. Indices at or above 29952 are always dispatched. [field:this:0x00000060, field:this:0x00000064, callee:0x0040F300, global:0x008AFEA0, global:0x005ED434]
    // RETURN: Return the batch-6 count at this+0x60 as the result. [field:this:0x00000060, source:raw]

    // Conservative worker pseudocode:
    //   for each of 6 batches (count, base pairs this+0x24..0x64):
    //     iterate count 36-byte entries; call ModeDispatchedRenderPhysicsCall(entry, dbl_8AFEA0)
    //   batches 1-3: unconditional on count > 0
    //   batches 4-6: skip entries whose vehicle/state data is still active (sentinel != -1, non-null state ptr, byte flag set)
    //   return batch-6 count
    // UNRESOLVED: Why batches 1-3 dispatch unconditionally while batches 4-6 are vehicle-conditioned is not explained; likely distinct render vs physics object pools but unproven.
    // UNRESOLVED: The vehicle strides 18624 and the 296-byte subrecords / 17-element state groups are read-only observations from the guard arithmetic; no field offsets are claimed beyond the packet evidence.
}
