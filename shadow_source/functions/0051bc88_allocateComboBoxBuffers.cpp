// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051BC88
// Canonical corpus name: UIListComboBoxBufferAllocator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIListComboBoxBufferAllocator_0051bc88.c

void UnknownObject::allocateComboBoxBuffers()
{
    // Allocates a per-object dispatch state and per-object 256-byte buffers. Allocates an 84-byte state block via the allocator vtable at this+0x4, stores it at this+0x198, and seeds its first entry with FAILOverviewSaysFIRCrossfeedButDispatchesToIMDCT. When the object count at this+0x20 is positive, loops that many times allocating a 256-byte buffer per object, zeroing it, storing it at object offset +80 of the array at *(this+0xC4), and marking the matching dispatch slot (state + 11, advanced per iteration) to -1. Returns the number of buffers allocated.
    // CALL: Invoke allocator entry 0 from the vtable at this+0x4 with (this, 1, 84) to allocate an 84-byte dispatch state block. [field:this:0x00000004, field:*(this+0x4):0x00000000, source:raw]
    // ASSIGNMENT: Store the allocated dispatch state pointer at this+0x198. [field:this:0x00000198, source:raw]
    // ASSIGNMENT: Write FAILOverviewSaysFIRCrossfeedButDispatchesToIMDCT (0x0051BAD1) as entry 0 of the new dispatch state block. [global:0x0051BAD1, source:raw]
    // GUARD: Guard on the object count at this+0x20: only a positive count enters the per-object buffer allocation loop. [guard:0, field:this:0x00000020, source:raw]
    // LOOP: Loop v6 from 0 while v6 is less than the object count at this+0x20; each iteration strides the descriptor array destination by 84 bytes. [field:this:0x00000020, source:raw]
    // CALL: Within the loop, invoke allocator entry 0 again with (this, 1, 256) to allocate a 256-byte buffer for the current object. [field:this:0x00000004, field:*(this+0x4):0x00000000, source:raw]
    // ASSIGNMENT: Store the allocated buffer at object offset +80 (base *(this+0xC4), advanced by 84 per iteration). [field:*(this+0xC4):0x00000050, field:this:0x000000C4, source:raw]
    // CALL: Zero the 256-byte buffer with memset(0, 256); memset is named in the raw source only and carries no callee address evidence. [source:raw]
    // ASSIGNMENT: Initialize the corresponding dispatch slot (state pointer + 11, advanced per iteration) to -1 and advance the loop counter. [source:raw]
    // RETURN: Return the loop counter, i.e. the number of buffers allocated. [source:raw]
    // CALL: Called by sub_516C7B during setup to allocate the combo-box per-object buffers. [caller:0x00516C7B]

    // Conservative worker pseudocode:
    //   result = (*(*(this + 0x4)))(this, 1, 84);
    //   *(this + 0x198) = result;
    //   *result = FAILOverviewSaysFIRCrossfeedButDispatchesToIMDCT;
    //   v6 = 0;
    //   if (*(this + 0x20) > 0) {
    //     v7 = *(this + 0xC4) + 80;
    //     v3 = result + 11;
    //     do {
    //       v4 = (*(*(this + 0x4)))(this, 1, 256);
    //       *(v7) = v4;
    //       memset(v4, 0, 256);
    //       *v3 = -1;
    //       v7 += 84;
    //       v3 += 1;
    //       v6 += 1;
    //     } while (v6 < *(this + 0x20));
    //   }
    //   return v6;
    // UNRESOLVED: The allocator object at this+0x4 and the dispatch state's class are not identified by packet evidence.
    // UNRESOLVED: The role of the -1 slot initialization and of FAILOverviewSaysFIRCrossfeedButDispatchesToIMDCT in the dispatch state is not established.
    // UNRESOLVED: The object descriptor type at *(this+0xC4) and what its +80 field holds after initialization are unknown.
}
