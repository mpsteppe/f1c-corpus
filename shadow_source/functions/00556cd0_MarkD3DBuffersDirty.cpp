// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00556CD0
// Canonical corpus name: D3DMarkDirty
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/D3DMarkDirty_00556cd0.c

void UnknownObject::MarkD3DBuffersDirty()
{
    // Marks D3D resources as dirty for re-upload under the D3DMarkDirty ABI. Two flag guards drive unconditional or conditional self-recursive calls to D3DMarkDirty(a2, 1) (this[17] at 0x44, and this[19] at 0x4C combined with a3). Then walks a linked list headed at this[129] (0x204); for each node it ORs the dirty bit 0x400 into every element's flag at (element_ptr + 56), calls sub_55D720(a2, 1) per element, advances by a 64-byte stride, and finally clears bit 0x10000000 on the node's processed-flag field (mapped to this:0x368). Returns the last node's element count.
    // GUARD: If this[17] (flag at 0x44) is non-zero, call D3DMarkDirty(a2, 1) unconditionally to mark the resource dirty. [field:this:0x00000044, callee:0x00556CD0, abi:lead, source:raw]
    // GUARD: If this[19] (flag at 0x4C) is non-zero AND a3 is non-zero, call D3DMarkDirty(a2, 1) as well. [field:this:0x0000004C, callee:0x00556CD0, source:raw]
    // LOOP: Walk the resource node linked list starting at this[129] (head at 0x204); each node's next pointer lives at node + 0x10. [field:this:0x00000204, source:raw]
    // ASSIGNMENT: Read the node's element count (i[70]) and its resource element array pointer (i[71]) — mapped by the field evidence to the node count field this:0x224 and array-pointer field this:0x228. [field:this:0x00000224, field:this:0x00000228, source:raw]
    // LOOP: For each element j in 0..count-1: OR the dirty bit 0x400 into the element's flag at (element_ptr + 56), call sub_55D720(a2, 1) to mark/trigger re-upload, then advance element_ptr by the 64-byte element stride. [field:this:0x00000228, callee:0x0055D720, source:raw]
    // ASSIGNMENT: After processing each node, clear bit 0x10000000 in the node's processed-flag field (mapped to this:0x368). [field:this:0x00000368, source:raw]
    // RETURN: Return result — the element count of the last processed node (or the last inner-loop count). [source:raw]

    // Conservative worker pseudocode:
    //   int MarkD3DBuffersDirty(this, a2, a3) {
    //     int result;
    //     if (this->dirty_uncond) result = D3DMarkDirty(a2, 1);
    //     if (this->dirty_cond) {
    //       result = a3;
    //       if (a3) result = D3DMarkDirty(a2, 1);
    //     }
    //     for (node* i = this->head; i; i = i->next) {
    //       int count = i->count;
    //       int elems = i->elems;
    //       for (int j = 0; j < count; j++) {
    //         *(uint32*)(elems + 56) |= 0x400;
    //         sub_55D720(a2, 1);
    //         count = i->count;
    //         elems += 64;
    //       }
    //       i->processed_flag &= ~0x10000000;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The packet maps the node's element count and array pointer to this:0x224 and this:0x228 (node base at this:0x204 + 0x20 / + 0x24), while the raw source indexes them as i[70] and i[71] on the node pointer (node + 0x118 / + 0x11C). The exact struct layout mapping between the two readings is unresolved.
    // UNRESOLVED: Packet fields this:0x32C and this:0x330 (node + 0x128 / + 0x12C) are adjacent node properties that this function neither reads nor writes; their role is unknown.
    // UNRESOLVED: a2 and the meaning of argument 1 in the recursive D3DMarkDirty and sub_55D720 calls depend on the caller (0x005570C0) and the resource/device context.
}
