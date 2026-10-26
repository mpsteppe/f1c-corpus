// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051D166
// Canonical corpus name: StreamDecoderInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StreamDecoderInit_0051d166.c

void UnknownObject::StreamDecoderInit()
{
    // Initializes a stream decoder sub-struct. Allocates a 48-byte decoder object through vtable entry 0 of the allocator interface stored at this+0x4, records it at this+0x19C, seeds its first function pointer with PhysicsObjectStateSetter, clears the byte at +0x8 and computes a buffer size (this+0x5C times this+0x64) into +0x28. When the mode flag at this+0x110 equals 2 it installs the audio sample stream path (AudioSampleStream at +0x4, sub_51CF80 at +0xC) and allocates the streaming buffer through vtable entry 1 of this+0x4 into +0x20; otherwise it installs the texture/palette path (VirtualDispatchWrapper_cdf9 at +0x4, TexturePaletteColorLookup at +0xC) and leaves +0x20 null. Finishes by delegating to WheelGeometryDataInitialization.
    // ASSIGNMENT: Allocate the 48-byte decoder sub-struct by calling vtable entry 0 of the interface at this+0x4 with arguments (this, 1, 48) and store the result at this+0x19C [field:this:0x0000019C, field:*(this+0x4):0x00000000, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Seed the new sub-struct: its first function pointer v1+0x0 becomes PhysicsObjectStateSetter and the byte at v1+0x8 is cleared [global:0x0051CD3E, source:raw]
    // CALCULATION: Compute the streaming buffer size as this+0x5C times this+0x64 and write it into v1+0x28 [field:this:0x0000005C, field:this:0x00000064, source:raw]
    // GUARD: Branch on the mode flag at this+0x110: value 2 selects the audio stream path, every other value selects the texture/palette path [guard:0, field:this:0x00000110, source:raw]
    // ASSIGNMENT: Audio path: install AudioSampleStream at v1+0x4 and sub_51CF80 at v1+0xC [global:0x0051CD53, global:0x0051CF80, source:raw]
    // CALL: Audio path: allocate the streaming buffer of the computed size via vtable entry 1 of the interface at this+0x4 and store the result at v1+0x20 [field:*(this+0x4):0x00000004, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Texture/palette path: clear v1+0x20 and install VirtualDispatchWrapper_cdf9 at v1+0x4 and TexturePaletteColorLookup at v1+0xC [global:0x0051CDF9, global:0x0051CE2A, source:raw]
    // CALL: Delegate the remaining setup to WheelGeometryDataInitialization(a1); the function itself is reached from sub_516C7B (00516C7B) [function:0x0051D166, caller:0x00516C7B, source:raw]

    // Conservative worker pseudocode:
    //   v1 = (*(interface[0]))(a1, 1, 48);
    //   a1[0x19C/4] = v1;
    //   *(byte*)(v1 + 8) = 0;
    //   *(v1 + 0x0) = PhysicsObjectStateSetter;
    //   *(v1 + 0x28) = *(a1 + 0x5C) * *(a1 + 0x64);
    //   if (*(a1 + 0x110) == 2) {
    //     *(v1 + 0x4) = AudioSampleStream;
    //     *(v1 + 0xC) = sub_51CF80;
    //     *(v1 + 0x20) = (*(interface[1]))(a1, 1, *(v1 + 0x28));
    //   } else {
    //     *(v1 + 0x20) = 0;
    //     *(v1 + 0x4) = VirtualDispatchWrapper_cdf9;
    //     *(v1 + 0xC) = TexturePaletteColorLookup;
    //   }
    //   return WheelGeometryDataInitialization(a1);
    // UNRESOLVED: The decoder sub-struct offsets (v1) are not packet fields, so their layout is only partially visible; the allocator interface at this+0x4 has no resolved owner
    // UNRESOLVED: The exact distinction between the audio stream handlers (sub_51CF80) and the texture/palette handlers is inferred from the mode guard and not independently documented
}
