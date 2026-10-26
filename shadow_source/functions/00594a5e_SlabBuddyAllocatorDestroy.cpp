// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00594A5E
// Canonical corpus name: sub_594A5E
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_594A5E_00594a5e.c

void UnknownObject::SlabBuddyAllocatorDestroy()
{
    // Destroys a slab/buddy allocator context. Releases the committed arena base (lpMem[4], byte offset 0x10) via VirtualFree with MEM_RELEASE, advances the global list head off_5E9988 when this context is the current head, then either resets the static-pool marker dword_5E7978 to -1 (when lpMem is the static sentinel &off_5E7968) or unlinks the doubly-linked list node and frees the context structure via HeapFree on hHeap.
    // CALL: Release the arena base stored at lpMem[4] (byte offset 0x10 of the context) via VirtualFree with size 0 and MEM_RELEASE (0x8000). [field:this:0x00000010, global:0x0059E0A4, source:raw]
    // ASSIGNMENT: If this context is the current list head off_5E9988, advance the head to the next pointer lpMem[1] (byte offset 4). [global:0x005E9988, field:this:0x00000004, source:raw]
    // GUARD: Static-pool branch: when lpMem equals the static sentinel &off_5E7968, set the heap marker dword_5E7978 to -1 and skip the HeapFree path. [global:0x005E7968, global:0x005E7978, source:raw]
    // CALL: Dynamic-pool branch: unlink the node by writing the previous pointer (byte offset 0) into the successor's predecessor slot and the next pointer (byte offset 4) into the predecessor's next slot (obj base, byte offset 4), then free the context with HeapFree(hHeap, 0, lpMem). [field:this:0x00000000, field:this:0x00000004, field:obj:0x00000004, global:0x0059E1BC, global:0x008D4904, source:raw]
    // RETURN: The dynamic-pool path returns the HeapFree result; the static-pool path returns the updated list head. [source:raw]

    // Conservative worker pseudocode:
    //   void *sub_594A5E(LPVOID *lpMem) {
    //     VirtualFree(lpMem[4], 0, MEM_RELEASE);
    //     if (off_5E9988 == lpMem) off_5E9988 = lpMem[1];
    //     if (lpMem == &off_5E7968) {
    //       dword_5E7978 = -1;
    //       return off_5E9988;
    //     }
    //     *(DWORD*)lpMem[1] = (DWORD)*lpMem;
    //     *((DWORD*)*lpMem + 1) = (DWORD)lpMem[1];
    //     return HeapFree(hHeap, 0, lpMem);
    //   }
    // UNRESOLVED: The allocator type is unknown; the double-list-base pattern (obj vs this) makes it unclear which structure owns the arena and which owns the neighbor nodes.
    // UNRESOLVED: The semantics of the static sentinel off_5E7968 and the marker dword_5E7978 are inferred only from the branch shape, not independently verified.
    // UNRESOLVED: The owner stays UNKNOWN; no callee or field-level type evidence identifies a concrete class.
}
