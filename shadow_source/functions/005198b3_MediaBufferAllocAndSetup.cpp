// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005198B3
// Canonical corpus name: MediaBufferAlloc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MediaBufferAlloc_005198b3.c

void UnknownObject::MediaBufferAllocAndSetup()
{
    // Media playback buffer allocation and setup. Allocates an 80-byte buffer through the sub-allocator at this+0x4, stores the pointer at this+0x180 and sets its vtable to PlaybackStateController. When the a2 flag is set, patches the dispatcher state at obj+0x14 to 4 and dispatches via obj+0x0. When the readiness flag at *(this+0x19C)+0x8 is set and this+0x114 < 2, patches the state to 46 and dispatches; then runs VertexBufferOffsetSetup and derives a per-element factor of this+0x114 + 2 (else this+0x114). Finally, while a count at this+0x20 is non-zero, walks the sub-struct array at *(this+0xC4) (21 DWORDs each) and allocates a frame buffer slot per element through the sub-allocator vtable entry at *(this+0x4)+0x8, sizing each slot from the element's dimension fields and the derived factor; returns the last processed slot index.
    // CALL: Allocate the 80-byte media buffer through the sub-allocator vtable entry at *(this+0x4)+0 with arguments (this, 1, 80) [field:*(this+0x4):0x00000000, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Store the allocated buffer pointer at this+0x180 and write the PlaybackStateController vtable pointer into the buffer's first field [field:this:0x00000180, field:obj:0x00000000, global:0x0051984B, source:raw]
    // GUARD: When the a2 flag is set, set the dispatcher state at obj+0x14 to 4 and dispatch through the no-arg vtable entry obj+0x0 [field:obj:0x00000014, field:this:0x00000000, source:raw]
    // GUARD: Branch on the audio readiness flag byte at *(this+0x19C)+0x8 [field:*(this+0x19C):0x00000008, field:this:0x0000019C, source:raw]
    // GUARD: When the readiness flag is set and the value at this+0x114 is less than 2, set the dispatcher state at obj+0x14 to 46 and dispatch through the no-arg vtable entry obj+0x0 [field:this:0x00000114, field:obj:0x00000014, field:obj:0x00000000, field:this:0x00000000, guard:1, source:raw]
    // CALL: Run VertexBufferOffsetSetup(this) when the readiness flag is set [callee:0x00519375, source:raw]
    // CALCULATION: Derive the per-element frame size factor: this+0x114 + 2 on the readiness path, otherwise the value at this+0x114 unchanged [field:this:0x00000114, source:raw]
    // GUARD: Loop only runs while the element count at this+0x20 is greater than 0 [field:this:0x00000020, guard:0, source:raw]
    // LOOP: Walk the sub-struct array whose base is *(this+0xC4), advancing 21 DWORDs per element, for the count at this+0x20 [field:this:0x000000C4, field:this:0x00000020, source:raw]
    // CALL: Allocate a frame buffer slot per element through the sub-allocator vtable entry at *(this+0x4)+0x8 with (this, 1, width, height-like terms): width = the element field at *(this+0xC4)+0x24 times the element field eight bytes before it, height = factor times (that same width field times the element field twenty-four bytes before it, divided by this+0x114) [field:*(this+0x4):0x00000008, field:this:0x00000004, field:*(this+0xC4):0x00000024, field:this:0x00000114, source:raw]
    // ASSIGNMENT: Store each allocated slot pointer into the media buffer slot array that begins 8 bytes into the allocated object, one slot per element; the returned value is the final slot index [field:obj:0x00000000, source:raw]
    // RETURN: Return the last processed slot index (0 when the element count is not positive); invoked by sub_516C7B (00516c7b) [function:0x005198B3, caller:0x00516C7B, source:raw]

    // Conservative worker pseudocode:
    //   buf = allocator->alloc(this, 1, 80);
    //   *(this+0x180) = buf;
    //   *buf = PlaybackStateController;
    //   if (a2) { dispatcher->state = 4; dispatcher->dispatch0(this); }
    //   if (*(*(this+0x19C) + 8)) {
    //     if (*(this+0x114) < 2) { dispatcher->state = 46; dispatcher->dispatch0(this); }
    //     VertexBufferOffsetSetup(this);
    //     factor = *(this+0x114) + 2;
    //   } else {
    //     factor = *(this+0x114);
    //   }
    //   i = 0;
    //   if (*(this+0x20) > 0) {
    //     elem = *(this+0xC4) + 36;
    //     slot = buf + 2;
    //     do {
    //       ++i;
    //       width = *elem * *(elem - 2);
    //       height = factor * (*elem * *(elem - 6) / *(this+0x114));
    //       *slot = allocator2->alloc(this, 1, width, height);
    //       ++slot; elem += 21;
    //     } while (i < *(this+0x20));
    //   }
    //   return i;
    // UNRESOLVED: The sub-struct offsets used in the frame size calculation (the field eight bytes below the field at *(this+0xC4)+0x24, and the field twenty-four bytes below it) are derived from pointer arithmetic on *(this+0xC4)+36 and have no packet field references
    // UNRESOLVED: The state values 4 and 46 and the a2 flag semantics are not interpreted by this function
    // UNRESOLVED: field:this:0x000000C4 appears as a read of the sub-struct array pointer; its purpose beyond the loop base is not documented
}
