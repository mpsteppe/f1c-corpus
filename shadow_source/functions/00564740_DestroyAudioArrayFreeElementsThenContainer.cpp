// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564740
// Canonical corpus name: DestroyAudioArrayFreeElementsThenContainer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestroyAudioArrayFreeElementsThenContainer_00564740.c

void UnknownObject::DestroyAudioArrayFreeElementsThenContainer()
{
    // Destroys a pointer-array container: iterates the element buffer (this+0x0) for lpMem[1] (this+0x4) entries calling BatchLoopWithMemoryCleanup on each element, then frees the buffer and the container struct via sub_58AA6F.
    // LOOP: Iterates i from 0 while i < (int)lpMem[1] (element count at this+0x4), calling BatchLoopWithMemoryCleanup on each element pointer (*lpMem)[i] from the buffer at this+0x0. [field:this:0x00000004, field:this:0x00000000, callee:0x00564860, source:raw]
    // CALL: sub_58AA6F(*lpMem) frees the element buffer pointed to by this+0x0. [field:this:0x00000000, callee:0x0058AA6F, source:raw]
    // RETURN: Returns sub_58AA6F(lpMem), freeing the container struct itself. [callee:0x0058AA6F, function:0x00564740, source:raw]

    // Conservative worker pseudocode:
    //   for (i = 0; i < (int)lpMem[1]; ++i)
    //       BatchLoopWithMemoryCleanup(((LPVOID*)*lpMem)[i]);
    //   sub_58AA6F(*lpMem);
    //   return sub_58AA6F(lpMem);
    // UNRESOLVED: sub_58AA6F (0x0058AA6F) is an unnamed memory deallocation helper; exact free semantics are not proven.
    // UNRESOLVED: BatchLoopWithMemoryCleanup (0x00564860) cleanup semantics are not independently verified in this packet.
    // UNRESOLVED: Container layout beyond this+0x0 and this+0x4 is unknown.
    // UNRESOLVED: Three callers (NetworkCleanup 0x00562C50, DirectDrawDisplayModeInit 0x00563E00, sub_5640F0 0x005640F0) are not analyzed.
}
