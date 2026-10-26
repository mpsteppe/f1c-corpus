// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00558B30
// Canonical corpus name: sub_558B30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_558B30_00558b30.c

void UnknownObject::TextureSlotDeallocate()
{
    // Removes the slot addressed by index a2 from a texture/render allocation pool. Validates the active count at this+0x30 and the capacity at this+0x2C, computes the 128-byte slot from the base at this+0x34, and requires the slot's in-use bit (0x40). Two removal paths are selected by the sign of the flags byte at this+0x20: a doubly-linked-list unlink path (prev/next links at slot+120 and slot+124, free-list head at this+0x38) and an array path that swaps the last slot's data into the freed position via a 16-dword copy over the buffer at *(*(this+0x50)+0x20) and fixes the index array at this+0x3C. Both paths clear the in-use bit and decrement the count.
    // GUARD: If the active count *(this+0x30) is <= 0, return it (empty pool) [field:this:0x00000030, source:raw]
    // GUARD: If the requested index a2 >= capacity *(this+0x2C), return the count (out of range) [field:this:0x0000002C, source:raw]
    // CALCULATION: v4 = *(this+0x34) + (a2 << 7) computes the slot pointer from the base at this+0x34 with a 128-byte stride [field:this:0x00000034, source:raw]
    // GUARD: If the slot's in-use bit (0x40) is clear, return the count (slot already free) [source:raw]
    // GUARD: Branch on the signed flags byte at this+0x20: a value >= 0 selects the doubly-linked-list unlink path, otherwise the array/copy path [field:this:0x00000020, guard:0, source:raw]
    // ASSIGNMENT: List path: unlink the slot from the doubly-linked list using the prev link at slot+120 (0x78) and the next link at slot+124; when the slot was the head (no prev), the free-list head at this+0x38 advances to the slot's next link; both links are then zeroed [field:*(this+0x30):0x00000078, field:this:0x00000038, source:raw]
    // GUARD: Array path: if the last slot's pointer in the index array *(*(this+0x3C) + 4*count - 4) is already v4, fall through to the common cleanup (no data move needed) [field:this:0x0000003C, source:raw]
    // CALL: Array path: TextureAllocationWithFormatSizeFlags(0) is invoked before the data-copy step [callee:0x00558D10, source:raw]
    // ASSIGNMENT: Array path: copy the last slot's data into the freed slot's position: the sub-context pointer at this+0x50 is dereferenced and +0x20 (0x20) yields the copy buffer v5, dest/source pointers are derived from the slots' ids with a stride of v6 = *(this+0x24), and a loop copies 16 dwords (indexes 0, 1, 2, 6) per iteration while advancing by 16 dwords [field:*(this+0x50):0x00000020, field:this:0x00000050, field:this:0x00000024, source:raw]
    // ASSIGNMENT: Array path: fix the index array at this+0x3C so the freed slot's id maps to the last slot's slot pointer and vice versa [field:this:0x0000003C, source:raw]
    // STATE_TRANSITION: Common cleanup: clear the in-use bit on the slot (*(DWORD*)v4 &= ~0x40) and decrement the active count at this+0x30 [field:this:0x00000030, source:raw]
    // RETURN: Return the old count on the early-return guard paths, or the decremented count on a successful removal [source:raw]
    // CALL: Invoked from sub_4CB5E0 as a slot-deallocation helper [caller:0x004CB5E0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_558B30(this, a2) {
    //     result = *(this + 0x30);
    //     if (result <= 0) return result;
    //     if (a2 >= *(this + 0x2C)) return result;
    //     v4 = *(this + 0x34) + (a2 << 7);
    //     if ((*(_BYTE*)v4 & 0x40) == 0) return result;
    //     if (*(char*)(this + 0x20) >= 0) {
    //       prev = *(v4 + 120);
    //       if (prev) *(prev + 124) = *(v4 + 124);
    //       next = *(v4 + 124);
    //       if (next) *(next + 120) = *(v4 + 120);
    //       if (!*(v4 + 120)) *(this + 0x38) = *(v4 + 124);
    //       *(v4 + 120) = 0;
    //       *(v4 + 124) = 0;
    //       goto cleanup;
    //     }
    //     if (*(*(this + 0x3C) + 4 * result - 4) == v4) goto cleanup;
    //     TextureAllocationWithFormatSizeFlags(0);
    //     v5 = *(*(this + 0x50) + 0x20);
    //     if (v5) {
    //       v6 = *(this + 0x24);
    //       v7 = v5 + ((v6 * *(v4 + 4)) << 6);
    //       v8 = v5 + ((v6 * *(*(*(this + 0x3C) + 4 * result - 4) + 4)) << 6);
    //       v10 = 0;
    //       do { *v7 = *v8; v7[1] = v8[1]; v7[2] = v8[2]; v7[6] = v8[6]; v7 += 16; v8 += 16; ++v10; }
    //       while (v10 < v6);
    //     }
    //     *(*(*(this + 0x3C) + 4 * result - 4) + 4) = *(v4 + 4);
    //     *(*(this + 0x3C) + 4 * *(v4 + 4)) = *(*(this + 0x3C) + 4 * result - 4);
    //   cleanup:
    //     *(DWORD*)v4 &= ~0x40;
    //     result = *(this + 0x30) - 1;
    //     *(this + 0x30) = result;
    //     return result;
    //   }
    // UNRESOLVED: Whether this+0x20's flags byte selects two genuinely different slot representations (doubly-linked list vs compact array) or two container modes of one pool is DERIVED from structure, not confirmed.
    // UNRESOLVED: The purpose of the TextureAllocationWithFormatSizeFlags(0) call on the array path (allocation with a zero format argument before copying) is unresolved; it may guarantee a backing buffer for the copy.
    // UNRESOLVED: The exact meaning of the slot dword at +4 is only partially resolved: it serves as the copy-stride index and as the value stored into the index array.
    // UNRESOLVED: The packet's field base notation *(this+0x30) for the slot link at 0x78 does not literally match the raw source's slot pointer derived from this+0x34; the ref is used verbatim as canonicalized evidence.
}
