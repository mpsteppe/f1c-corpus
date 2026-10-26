// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00558E10
// Canonical corpus name: PixelWriteToTextureBuffer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PixelWriteToTextureBuffer_00558e10.c

void UnknownObject::PixelWriteToTextureBuffer()
{
    // Writes four pixel/vertex data words (a4/a5/a6/a7) into a texture buffer at a computed slot. Gated on the format identifier at this+0x4C being 1 and the signed flag byte at this+0x20 being negative (bit 7 set). When that flag demands it, allocates/resizes the texture with TextureAllocationWithFormatSizeFlags(this, 0). Reads the row-data pointer through the descriptor at this+0x50 (v9 = descriptor[8]), and if non-null computes the pixel slot as (a2<<7) indexing a 128-byte-stride table reached via this+0x34, scaled by this+0x24, plus a3, shifted <<6 for 64-byte entries; writes components at slot+0, +4, +8 and +0x18. Returns (char)v8, a register-reuse artifact.
    // GUARD: Format gate: the whole body executes only when the format identifier at this+0x4C equals 1 [guard:0, field:this:0x0000004C, source:raw]
    // GUARD: Allocation/overflow flag: when the signed byte at this+0x20 is negative (bit 7 set) the texture is (re)allocated and the write proceeds [field:this:0x00000020, source:raw]
    // CALL: TextureAllocationWithFormatSizeFlags(this, 0) allocates or resizes the texture buffer when the flag demands it [callee:0x00558D10, source:raw]
    // ASSIGNMENT: Read the texture descriptor pointer at this+0x50, then the row-data pointer v9 = descriptor[8] (descriptor+0x20) [field:this:0x00000050, field:*(this+0x50):0x00000020, source:raw]
    // GUARD: Row-data guard: the write target is computed and written only while v9 is non-null [source:raw]
    // CALCULATION: Compute the pixel slot: (a2<<7) indexes a 128-byte-stride table reached through the field at this+0x34, scaled by this+0x24, offset by a3, then shifted <<6 for 64-byte pixel entries [field:this:0x00000024, field:this:0x00000034, source:raw]
    // ASSIGNMENT: Write a4 into the pixel entry component at slot+0 [field:*(this+0x50):0x00000000, source:raw]
    // ASSIGNMENT: Write a5 into the pixel entry component at slot+4 [field:*(this+0x50):0x00000004, source:raw]
    // ASSIGNMENT: Write a6 into the pixel entry component at slot+8 [field:*(this+0x50):0x00000008, source:raw]
    // ASSIGNMENT: Write a7 into the pixel entry component at slot+0x18 [field:*(this+0x50):0x00000018, source:raw]
    // RETURN: Returns (char)v8, a decompiler artifact of v8's low byte used as a scratch register; not a meaningful boolean [source:raw]
    // CALL: Invoked on the frame path by particle/render helpers ParticleEffectBillboardQuadSetup, F_3DBoundingBoxRender and WheelContactParticle [caller:0x004CC500, caller:0x004CC700, caller:0x004CD6C0, function:0x00558E10, source:raw]

    // Conservative worker pseudocode:
    //   if (*(DWORD*)(this+0x4C) == 1) {
    //     if (*(signed char*)(this+0x20) < 0) {
    //       TextureAllocationWithFormatSizeFlags(this, 0);
    //       v9 = *(DWORD*)(*(DWORD*)(this+0x50) + 0x20);
    //       if (v9) {
    //         dst = v9 + ((a3 + *(DWORD*)(this+0x24) * *(DWORD*)((a2<<7) + *(DWORD*)(this+0x34) + 4)) << 6);
    //         dst[0] = a4; dst[1] = a5; dst[2] = a6; dst[6] = a7;
    //       }
    //     }
    //   }
    //   return v8;   /* scratch-register artifact * /
    // UNRESOLVED: The packet labels the four written components on base *(this+0x50) at offsets 0x0/0x4/0x8/0x18, while the raw source writes through the indirection v9 = descriptor[8] plus a computed offset; whether the pixel components live in the descriptor itself or in the row-data buffer is not resolvable from this packet alone
    // UNRESOLVED: Semantics of a2 (128-byte-stride index) and a3 (row/offset) are DERIVED from the arithmetic, not documented
    // UNRESOLVED: The meaning of bit 7 of the byte at this+0x20 (needs-allocation vs overflow-ready) is inferred
    // UNRESOLVED: The return value is a register-reuse artifact and carries no meaningful boolean
}
