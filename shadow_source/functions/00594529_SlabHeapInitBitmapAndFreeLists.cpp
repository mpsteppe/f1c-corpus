// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00594529
// Canonical corpus name: sub_594529
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_594529_00594529.c

void UnknownObject::SlabHeapInitBitmapAndFreeLists()
{
    // Initializes a newly committed 32KB slab for first use. Derives the size-class index v3 from the free-block bitmask, initializes 64 free-list heads inside the slab descriptor, commits the slab memory via VirtualAlloc, writes block-header sentinels across the slab, links the slab blocks into the descriptor's free-list head/tail slots, writes bitmap tracking entries, bumps the slab reference-count byte, clears the size-class bit in the free-block bitmask, and returns the size-class index (or -1 when VirtualAlloc fails).
    // ASSIGNMENT: Load v1 = a1[4], the pointer to the slab descriptor array holding bitmap and free-list state. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Load v2 = a1[2], the free-block bitmask used to derive the size-class index. [field:this:0x00000008, source:raw]
    // LOOP: Compute size-class index v3 by repeatedly doubling v2 until it becomes negative (leading-bit count). [source:raw]
    // CALCULATION: Compute v5 = 516*v3 + v1 + 324, the address of this size class's free-list head array inside the descriptor. [source:raw]
    // LOOP: Initialize 64 free-list heads (8 bytes each) by linking each head slot to itself. [source:raw]
    // CALCULATION: Compute v6 = a1[3] + (v3 << 15), the 32KB slab base address for this size class. [field:this:0x0000000C, source:raw]
    // CALL: Call VirtualAlloc(v6, 0x8000, 0x1000, 4) to commit the 32KB slab as read-write memory. [global:0x0059E0A0, source:raw]
    // GUARD: If VirtualAlloc returns 0, return -1 to signal slab allocation failure. [global:0x0059E0A0, source:raw]
    // LOOP: Initialize block headers across the committed slab by writing -1/4080 sentinels and block links every 4096 bytes. [source:raw]
    // ASSIGNMENT: Link the first and last slab block (v6+3 and v6+7171) into the descriptor free-list head/tail slots at 516*v3+v1+832 and +836. [source:raw]
    // ASSIGNMENT: Write bitmap tracking entries: 0 at v1+4*v3+68 and 1 at v1+4*v3+196. [source:raw]
    // STATE_TRANSITION: Increment the reference-count byte at v1+67 (this+0x53); if it was previously zero, set bit 0 of this+0x4 (a1[1] |= 1). [field:this:0x00000053, field:this:0x00000004, source:raw]
    // CALCULATION: Clear the size-class bit in the free-block bitmask: a1[2] &= ~(0x80000000 >> v3). [field:this:0x00000008, source:raw]
    // RETURN: Return the computed size-class index v3. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_594529(_DWORD* a1) {
    //     int v1 = a1[4];             // slab descriptor array (bitmap + free lists)
    //     int v2 = a1[2];             // free-block bitmask
    //     int v3 = 0;
    //     while (v2 >= 0) { v2 *= 2; ++v3; }   // size-class index from bitmask
    //     // init 64 free-list heads at 516*v3 + v1 + 324
    //     v6 = a1[3] + (v3 << 15);    // 32KB slab base
    //     if (!VirtualAlloc(v6, 0x8000, 0x1000, 4)) return -1;
    //     // init block headers across the slab, link free lists
    //     // set bitmap entries, bump refcount byte v1+67, clear bit v3 of a1[2]
    //     return v3;
    //   }
    // UNRESOLVED: Semantics of the two bitmap entries at v1+4*v3+68 and v1+4*v3+196 (allocated/tracked counts) are inferred, not proven.
    // UNRESOLVED: The 516-byte descriptor row layout (head array at +324, free-list slots at +832/+836, bitmap slots at +68/+196) is only partially mapped.
    // UNRESOLVED: Slab address encoding (v3 << 15) and why block headers are 4096 bytes apart are unconfirmed.
}
