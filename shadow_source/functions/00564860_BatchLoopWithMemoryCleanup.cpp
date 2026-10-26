// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564860
// Canonical corpus name: BatchLoopWithMemoryCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BatchLoopWithMemoryCleanup_00564860.c

void UnknownObject::BatchLoopWithMemoryCleanup()
{
    // Batch teardown of a counted array. Iterates i over the count stored at this+0x0, calling IndirectCallViaFunctionPointer(lpMem, i) per element, then frees the sub-resource at this+0x14 via sub_58AA6F and finally frees the array itself, returning sub_58AA6F's result.
    // LOOP: Loop from i=0 while i < count (dword at this+0x0), stepping by 1 [field:this:0x00000000, source:raw]
    // CALL: Per-element callback: IndirectCallViaFunctionPointer(lpMem, i) invoked for each element [callee:0x00564890, field:this:0x00000000, source:raw]
    // CALL: Frees the sub-resource pointer at this+0x14 (lpMem[5]) via sub_58AA6F [callee:0x0058AA6F, field:this:0x00000014, source:raw]
    // RETURN: Frees the array container itself via sub_58AA6F(lpMem) and returns that routine's result [callee:0x0058AA6F, function:0x00564860, source:raw]
    // CALL: Invoked by NetworkCleanup (00562C50) [caller:0x00562C50, source:raw]
    // CALL: Invoked by DirectDrawDisplayModeInit (00563E00) [caller:0x00563E00, source:raw]
    // CALL: Invoked by DestroyAudioArrayFreeElementsThenContainer (00564740) [caller:0x00564740, source:raw]

    // Conservative worker pseudocode:
    //   for (i = 0; i < (int)lpMem[0]; ++i)
    //       IndirectCallViaFunctionPointer(lpMem, i);
    //   sub_58AA6F(lpMem[5]);
    //   return sub_58AA6F(lpMem);
    // UNRESOLVED: IndirectCallViaFunctionPointer's per-element action (element destructor vs release callback) is not established from this packet alone
    // UNRESOLVED: sub_58AA6F is treated as a memory deallocation routine from prior analysis (DERIVED); this packet only shows it is called on the sub-resource and the container
    // UNRESOLVED: The owning class of the counted array container is unknown; the +0x0 count / +0x14 sub-resource layout is read-only evidence
}
