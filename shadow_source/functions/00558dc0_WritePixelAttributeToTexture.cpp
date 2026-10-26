// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00558DC0
// Canonical corpus name: PixelAttributeWriteToTexture
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PixelAttributeWriteToTexture_00558dc0.c

void UnknownObject::WritePixelAttributeToTexture()
{
    // Guarded pixel-attribute write into a texture buffer. Only when the mode field (this+0x4C) equals 1 and the flags byte (this+0x20) is negative (bit 31 set) does it ensure the texture allocation exists via TextureAllocationWithFormatSizeFlags, then write a4 into the texture buffer at a pixel position computed from the slot index (a2), the dimension field (this+0x24), and the slot-array width. Invoked from sub_4CD8D0 and TelemetryBarIndicatorRenderer.
    // GUARD: Both guards gate the write: mode (this+0x4C) must equal 1 AND the flags byte (this+0x20) must be signed-negative (bit 31 set). [guard:0, guard:1, field:this:0x0000004C, field:this:0x00000020]
    // CALL: Call TextureAllocationWithFormatSizeFlags(this, 0) to ensure the texture allocation exists before writing. [callee:0x00558D10, source:raw]
    // ASSIGNMENT: Read the texture buffer base pointer v5 from the texture sub-context: v5 = *(*(this+0x50)+0x20). [field:this:0x00000050, field:*(this+0x50):0x00000020, source:raw]
    // GUARD: Guard the write on v5 being non-zero before computing the destination. [field:*(this+0x50):0x00000020, source:raw]
    // CALCULATION: Compute the destination dword: ((a3 + (this+0x24) * slot_width) << 6) + v5 + 24, where slot_width = *(this+0x34 + (a2 << 7) + 4) (slot array stride 128, width field +4). [field:this:0x00000024, field:this:0x00000034, source:raw]
    // ASSIGNMENT: Write a4 into the computed texture-buffer destination dword. [field:*(this+0x50):0x00000020, source:raw]

    // Conservative worker pseudocode:
    //   if (this->mode == 1 && this->flags_byte < 0) {
    //     TextureAllocationWithFormatSizeFlags(this, 0);
    //     char* buf = *(char**)(*(this + 0x50) + 0x20);
    //     if (buf) {
    //       int slot_width = *(int*)(this->slot_array + (a2 << 7) + 4);
    //       buf[((a3 + this->dimension * slot_width) << 6) + 24] = a4;
    //     }
    //   }
    // UNRESOLVED: Pixel layout mapping (slot stride << 7, dimension multiply, << 6 row shift, +24 offset) is DERIVED from the decompiled expression; exact pixel format/row-pitch not grounded.
    // UNRESOLVED: Role of the +24 dword offset inside the texture buffer (header?) not explained.
    // UNRESOLVED: Mode enum and flags-byte bit 31 meaning not independently confirmed.
}
