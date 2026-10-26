// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00519EB7
// Canonical corpus name: RenderStateCopyWithValidation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderStateCopyWithValidation_00519eb7.c

void UnknownObject::RenderStateCopyWithValidation()
{
    // Copies validated render-state data from a source buffer into a destination buffer, processing one entry per sprite object descriptor. Enables the copy only when the render-state flag at this+0xC8 is set and the source buffer at this+0x8C is non-null. Lazy-allocates the destination buffer (24 bytes per object) through the sub-allocator vtable when the slot at *(this+0x184)+0x70 is null. Skips descriptors whose sprite-object words are null or whose source state dword is negative, then copies 5 dwords and sets a validation flag when any copied value is non-zero. Returns the validation flag when any entry was processed, otherwise 0.
    // CALL: Allocates the destination render-state buffer through the sub-allocator vtable entry 0 (this+0x4) when the slot at *(this+0x184)+0x70 is null; allocation size is 24 bytes times the object count at this+0x20, and the result is stored back into *(this+0x184)+0x70 [field:this:0x00000004, field:*(this+0x4):0x00000000, field:this:0x00000184, field:*(this+0x184):0x00000070, field:this:0x00000020, source:raw]
    // GUARD: Proceeds with the render-state copy only when the enable flag at this+0xC8 is set and the source buffer at this+0x8C is non-null [field:this:0x000000C8, field:this:0x0000008C, source:raw]
    // GUARD: Returns early with the validation flag when the object count at this+0x20 is zero or negative [guard:0, field:this:0x00000020, source:raw]
    // LOOP: Iterates over sprite object descriptors: the descriptor array is read through this+0xC4 plus the +0x4C word-array offset, and each entry advances by 21 words [field:this:0x000000C4, field:*(this+0xC4):0x0000004C, source:raw]
    // GUARD: Skips the entry when the sprite object's first word (+0x00) is null [field:*(*(this+0xC4)+0x4C):0x00000000, source:raw]
    // GUARD: Skips the entry when the sprite object's word at +0x02 is null [field:*(*(this+0xC4)+0x4C):0x00000002, source:raw]
    // GUARD: Skips the entry when the sprite object's word at +0x04 is null [field:*(*(this+0xC4)+0x4C):0x00000004, source:raw]
    // GUARD: Skips the entry when the sprite object's word at +0x10 is null [field:*(*(this+0xC4)+0x4C):0x00000010, source:raw]
    // GUARD: Skips the entry when the sprite object's word at +0x12 is null [field:*(*(this+0xC4)+0x4C):0x00000012, source:raw]
    // GUARD: Skips the entry when the sprite object's word at +0x20 is null [field:*(*(this+0xC4)+0x4C):0x00000020, source:raw]
    // GUARD: Skips the entry when the source render-state dword (entry index advanced by this+0x8C) is negative [field:this:0x0000008C, source:raw]
    // ASSIGNMENT: Copies 5 dwords of render-state data from the source buffer (this+0x8C) into the destination buffer slot at *(this+0x184)+0x70, setting the validation flag when any copied dword is non-zero [field:*(this+0x184):0x00000070, field:this:0x0000008C, source:raw]
    // CALCULATION: Advances the destination pointer by 24 bytes and the source index by 256 bytes per processed object [field:*(this+0x184):0x00000070, field:this:0x0000008C, source:raw]
    // RETURN: Returns the validation flag (1 when any copied dword was non-zero) after the last processed entry, otherwise 0 [function:0x00519EB7, source:raw]
    // STATE_TRANSITION: Invoked by ProtocolStateHandler as part of the protocol-driven render-state update path [caller:0x0051A4B7, source:raw]

    // Conservative worker pseudocode:
    //   frame = *(this + 0x184);
    //   dirty = 0;
    //   if (*(byte*)(this + 0xC8) && *(this + 0x8C)) {
    //       if (*(frame + 0x70) == 0)
    //           *(frame + 0x70) = (vtable0(this + 0x4))(this, 1, 24 * *(this + 0x20));
    //       dest = *(frame + 0x70);
    //       if (*(this + 0x20) > 0) {
    //           entry = *(this + 0xC4) + 0x4C;
    //           srcIndex = 0;
    //           for (i = 0; i < *(this + 0x20); i++) {
    //               obj = *entry;
    //               if (!obj || !*obj || !obj[1] || !obj[8] || !obj[16] || !obj[9] || !obj[2]) break;
    //               src = srcIndex + *(this + 0x8C);
    //               if (*(src) < 0) break;
    //               for (j = 0; j < 5; j++) { dest[j + 1] = src[j + 1]; if (src[j + 1]) dirty = 1; }
    //               dest += 24;
    //               srcIndex += 256;
    //               entry += 21;
    //           }
    //       }
    //       return dirty;
    //   }
    //   return 0;
    // UNRESOLVED: The owning class of this container is not identified; this+0x4 is a sub-allocator vtable and this+0xC4 holds the sprite object descriptor array
    // UNRESOLVED: The sprite-object word offsets checked at +0x02, +0x04, +0x10, +0x12, +0x20 are validated as non-null pointers but their individual meanings are not recoverable from this packet
    // UNRESOLVED: The 5-dword copy and the 24-byte per-object destination stride imply a fixed render-state record layout that is not defined by this packet
}
