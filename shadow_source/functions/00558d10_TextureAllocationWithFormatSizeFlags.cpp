// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00558D10
// Canonical corpus name: TextureAllocationWithFormatSizeFlags
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureAllocationWithFormatSizeFlags_00558d10.c

void UnknownObject::TextureAllocationWithFormatSizeFlags()
{
    // Allocates a texture buffer through BufferLockAllocate (00540F00), guarded by an already-allocated flag. Reads flags at this[8], sets bit 0x100 to mark allocation done, indexes a format-descriptor array through this[20] using the a2 slot shifted left 6, selects a 96-byte or 32-byte entry size from flag bit 0x80, and stores the returned handle back into the descriptor at offset +32. Uses global dword_8B78A0 (0x008B78A0) as the buffer-lock manager pointer. Called by sub_558A30, sub_558B30, PixelAttributeWriteToTexture, PixelWriteToTextureBuffer, and sub_558E70.
    // GUARD: Read this[8]; if bit 0x100 is already set the allocation is skipped and the existing result is returned [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Set the allocation-done bit: v4 = result | 0x100 and write it back to this[8] [field:this:0x00000020, source:raw]
    // CALCULATION: Compute the slot offset v5 = a2 << 6 into the descriptor table this[20] [field:this:0x00000050, source:raw]
    // CALL: 96-byte path (bit 0x80 clear): BufferLockAllocate(dword_8B78A0, *(this[20]+v5+28), 96, *(this[20]+v5+44), this[11] * *(this[20]+v5+8)) [callee:0x00540F00, global:0x008B78A0, field:this:0x0000002C, field:this:0x00000050, source:raw]
    // CALL: 32-byte path (bit 0x80 set): BufferLockAllocate(dword_8B78A0, *(this[20]+v5+28), 32, *(this[20]+v5+44), *(this[20]+v5+8)) [callee:0x00540F00, global:0x008B78A0, field:this:0x00000050, source:raw]
    // ASSIGNMENT: Store the returned allocation handle into the descriptor: *(this[20] + v5 + 32) = result [field:this:0x00000050, source:raw]
    // RETURN: Return the allocation result handle (or the previously stored flags value on the guarded path) [function:0x00558D10, source:raw]
    // CALL: Invoked by sub_558A30, sub_558B30, PixelAttributeWriteToTexture, PixelWriteToTextureBuffer, and sub_558E70 to lazily allocate a texture buffer on first use [caller:0x00558A30, caller:0x00558B30, caller:0x00558DC0, caller:0x00558E10, caller:0x00558E70, source:raw]

    // Conservative worker pseudocode:
    //   result = this[8];
    //   if ((result & 0x100) != 0) return result;
    //   this[8] = result | 0x100;
    //   v5 = a2 << 6;
    //   if ((this[8] & 0x80) == 0) {
    //     handle = BufferLockAllocate(dword_8B78A0, *(this[20]+v5+28), 96, *(this[20]+v5+44), this[11] * *(this[20]+v5+8));
    //   } else {
    //     handle = BufferLockAllocate(dword_8B78A0, *(this[20]+v5+28), 32, *(this[20]+v5+44), *(this[20]+v5+8));
    //   }
    //   *(this[20] + v5 + 32) = handle;
    //   return handle;
    // UNRESOLVED: The concrete class owning this method is unknown; fields are only evidenced as this[8]/this[11]/this[20] word offsets
    // UNRESOLVED: Semantics of descriptor entries at +28 (pointer), +44 (format), +8 (size) and the +32 handle slot are inferred from the BufferLockAllocate call shape only
    // UNRESOLVED: Global dword_8B78A0 is treated here as a buffer-lock manager pointer; the prior analysis names it SoundManager with no packet evidence
    // UNRESOLVED: The 0x80 format flag meaning (pixel depth/format selector) is not evidenced beyond selecting the 96 vs 32 byte entry size
}
