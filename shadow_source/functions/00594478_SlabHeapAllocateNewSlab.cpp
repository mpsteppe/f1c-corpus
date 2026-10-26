// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00594478
// Canonical corpus name: sub_594478
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_594478_00594478.c

void UnknownObject::SlabHeapAllocateNewSlab()
{
    // Allocates and initializes a new slab for a custom heap allocator. If the slab descriptor array is full (dword_8D48F8 == dword_8D48E8) it grows the array via HeapReAlloc (capacity +16). It then allocates a descriptor slot, a 0x41C4-byte bitmap/free-list metadata block via HeapAlloc, and reserves a 1MB slab via VirtualAlloc, initializing descriptor fields (slot[0..2], bitmap head) and incrementing the active-slab counter dword_8D48F8. Returns the descriptor pointer, or 0 when any allocation fails (freeing earlier allocations on failure). Called by sub_59416F (0059416f) on the frame path.
    // GUARD: If dword_8D48F8 == dword_8D48E8 (descriptor array full), grow it by calling HeapReAlloc(hHeap, 0, lpMem, 4 * (5 * dword_8D48E8 + 80)) [global:0x008D48E8, global:0x008D48F8, source:raw]
    // CALL: HeapReAlloc(hHeap, 0, lpMem, 4 * (5 * dword_8D48E8 + 80)) grows the slab descriptor array; on a NULL return the function returns 0 [global:0x0059E1B4, global:0x008D48E8, global:0x008D48FC, global:0x008D4904, source:raw]
    // ASSIGNMENT: After a successful grow: dword_8D48E8 += 16 (raised capacity), lpMem = v1 (new array base), v0 = dword_8D48F8 (re-read active count) [global:0x008D48E8, global:0x008D48F8, global:0x008D48FC, source:raw]
    // CALCULATION: Compute descriptor slot pointer v2 = (char *)lpMem + 20 * v0 (20-byte stride per descriptor) [global:0x008D48FC, source:raw]
    // CALL: HeapAlloc(hHeap, 8u, 0x41C4u) allocates the bitmap/free-list metadata block stored at v2[4]; on NULL return the function returns 0 [global:0x0059E1C0, global:0x008D4904, source:raw]
    // CALL: VirtualAlloc(0, 0x100000u, 0x2000u, 4u) reserves the 1MB slab address space stored at v2[3]; on NULL return it frees the bitmap block (HeapFree(hHeap, 0, v2[4])) and returns 0 [global:0x0059E0A0, global:0x0059E1BC, source:raw]
    // ASSIGNMENT: Initialize the descriptor: v2[2] = -1 (free-block sentinel), v2[0] = 0, v2[1] = 0, increment dword_8D48F8 (active slab count), and set the bitmap head *v2[4] = -1 [global:0x008D48F8, source:raw]
    // RETURN: Return v2 (the new slab descriptor pointer) on success, or 0 on any of the three allocation failures [function:0x00594478, source:raw]
    // CALL: Invoked by sub_59416F (0059416f) on the frame path to obtain a fresh slab when the heap needs capacity [caller:0x0059416F]

    // Conservative worker pseudocode:
    //   v0 = dword_8D48F8;
    //   if (dword_8D48F8 == dword_8D48E8) {
    //     v1 = HeapReAlloc(hHeap, 0, lpMem, 4 * (5 * dword_8D48E8 + 80));
    //     if (!v1) return 0;
    //     dword_8D48E8 += 16;
    //     lpMem = v1;
    //     v0 = dword_8D48F8;
    //   }
    //   v2 = (char *)lpMem + 20 * v0;
    //   v3 = HeapAlloc(hHeap, 8u, 0x41C4u);
    //   v2[4] = v3;
    //   if (!v3) return 0;
    //   v4 = VirtualAlloc(0, 0x100000u, 0x2000u, 4u);
    //   v2[3] = v4;
    //   if (!v4) { HeapFree(hHeap, 0, v2[4]); return 0; }
    //   v2[2] = -1; v2[0] = 0; v2[1] = 0;
    //   ++dword_8D48F8;
    //   **v2[4] = -1;
    //   return v2;
    // UNRESOLVED: The 20-byte descriptor layout and the semantics of the 0x41C4-byte bitmap are inferred from surrounding allocations, not documented here
    // UNRESOLVED: Import stubs (VirtualAlloc, HeapReAlloc, HeapFree, HeapAlloc) are treated as read-only globals by packet facts; their IAT role is not stated in the packet
}
