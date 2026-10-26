// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051E0DC
// Canonical corpus name: sub_51E0DC
// Owner: TextureProcessingContext [DERIVED]
// Raw source: functions/sub_51E0DC_0051e0dc.c

void TextureProcessingContext::textureContextInit()
{
    // Initializes a texture processing context. Allocates a 44-byte context object via the allocator vtable (slot 0), stores its pointer at this+0x1A4, fills its dispatch slots with sub_51DFCB and SetVehicleFlag, validates a mode field at this+0x64 (must be 3, otherwise reports error 46 through the owner vtable), allocates a 128-slot buffer array holding 32 per-row 4096-byte allocations, initializes the palette path when the byte at this+0x5A is set (palette buffer + pixel count, with <8 and >256 clamps reported as errors 55 and 56), then conditionally allocates a dither buffer sized 6*(this+0x5C+2) and returns SymmetricArrayInit(this) when this+0x4C becomes 2. Called by sub_516C7B.
    // ASSIGNMENT: Allocate 44-byte context object via allocator vtable slot 0 and store the pointer at this+0x1A4 [abi:lead, field:this:0x00000004, field:*(this+0x4):0x00000000, field:this:0x000001A4]
    // ASSIGNMENT: Set context vtable (obj+0x0) to sub_51DFCB and obj+0xC to SetVehicleFlag [field:obj:0x00000000, global:0x0051DFCB, global:0x0051E0CD, source:raw]
    // ASSIGNMENT: Zero obj+0x20 and obj+0x28 (uninterpreted context slots) [source:raw]
    // GUARD: If this+0x64 != 3 (channel-mode validation), write 46 to owner vtable+20 and invoke the owner vtable call (error path) [guard:1, field:this:0x00000064, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Allocate 128-slot buffer array via allocator vtable slot +4 and store the pointer at obj+0x18 [field:*(this+0x4):0x00000004, field:obj:0x00000018, abi:lead]
    // LOOP: Loop 32 times (index 0..124 step 4): allocate a 4096-byte buffer via allocator vtable slot +4 and store the result into the obj+0x18 array at the loop index [field:*(this+0x4):0x00000004, field:obj:0x00000018, source:raw]
    // ASSIGNMENT: Set obj+0x1C byte to 1 (initialized/ready flag) [source:raw]
    // GUARD: If byte at this+0x5A (palette flag) is nonzero, branch to the palette path; otherwise set obj+0x10 to 0 [field:this:0x0000005A, source:raw]
    // GUARD: If pixel count v4 = this+0x54 < 8, write 55 to owner vtable+20, 8 to owner vtable+24 and invoke the owner vtable call (clamp/error path) [field:this:0x00000054, field:this:0x00000000, source:raw]
    // GUARD: If pixel count v4 > 256, write 56 to owner vtable+20, 256 to owner vtable+24 and invoke the owner vtable call (clamp/error path) [field:this:0x00000054, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Allocate palette buffer via allocator vtable slot +8 with (this, 1, v4, 3), store it at obj+0x10, and store the pixel count v4 at obj+0x14 [field:*(this+0x4):0x00000008, field:this:0x00000054, field:obj:0x00000014, abi:lead, source:raw]
    // STATE_TRANSITION: If this+0x4C is nonzero, set this+0x4C to 2 (dither-mode activation) [field:this:0x0000004C]
    // GUARD: If this+0x4C == 2, allocate a 6*(this+0x5C+2)-byte buffer via allocator vtable slot +4, store it at obj+0x20, and return the result of SymmetricArrayInit(this) [guard:0, field:this:0x0000004C, field:this:0x0000005C, field:*(this+0x4):0x00000004, source:raw]
    // RETURN: Return the prior allocator result (last row-buffer or palette allocation), except on the this+0x4C==2 path which returns SymmetricArrayInit(this) [source:raw]

    // Conservative worker pseudocode:
    //   obj = this->allocator->alloc(this, 1, 44);
    //   this->context = obj;
    //   obj->vtable = sub_51DFCB;
    //   obj->slot0xC = SetVehicleFlag;
    //   obj->slot0x20 = 0;
    //   obj->slot0x28 = 0;
    //   if (this->channelMode != 3) {
    //     this->vtable->error(46);
    //   }
    //   obj->rowBuffers = this->allocator->alloc(this, 1, 128);
    //   for (i = 0; i < 128; i += 4) {
    //     obj->rowBuffers[i/4] = this->allocator->alloc(this, 1, 4096);
    //   }
    //   obj->ready = 1;
    //   if (this->paletteFlag) {
    //     v4 = this->pixelCount;
    //     if (v4 < 8)  this->vtable->error(55, 8);
    //     if (v4 > 256) this->vtable->error(56, 256);
    //     obj->palette = this->allocator->allocTyped(this, 1, v4, 3);
    //     obj->pixelCount = v4;
    //   } else {
    //     obj->palette = 0;
    //   }
    //   if (this->ditherFlag) this->ditherFlag = 2;
    //   if (this->ditherFlag == 2) {
    //     obj->dither = this->allocator->alloc(this, 1, 6 * (this->channelCount + 2));
    //     return SymmetricArrayInit(this);
    //   }
    //   return result;
    // UNRESOLVED: SymmetricArrayInit call target has no address or callee evidence in the packet; only the decompiled raw name is available
    // UNRESOLVED: obj+0xC, obj+0x10, obj+0x1C, obj+0x20 and obj+0x28 have no packet field entries; only raw-text evidence supports them
    // UNRESOLVED: Packet field obj+0x18 carries init_literal 256 while the raw code assigns obj+0x18 an allocator result; the field metadata for that offset appears mislabeled
    // UNRESOLVED: Semantic of the this+0x64 != 3 validation (existing analysis suggests channel count) is unconfirmed
    // UNRESOLVED: Role and call context of caller sub_516C7B are not characterized
}
