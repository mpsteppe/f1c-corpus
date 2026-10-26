// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040AA20
// Canonical corpus name: F_3DTransformObjectAllocator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DTransformObjectAllocator_0040aa20.c

void UnknownObject::TransformSoundObjectAllocator()
{
    // Lazily allocates and initializes up to five 3D sound/transform sub-objects on this. Four fixed 200-byte blocks are constructed via OperatorNewNhMallocWrapper plus F_3DSoundEmitter into slots this+0x10..0x1C and given a 1135869952 dword triple at sub-object+136. A fifth 204-byte block into this+0x20 carries a refcount dword, a default parameter block, a virtual call through vtable slot +28, and the same 1135869952 triple. Called by sub_40C140.
    // CALL: Invoked by sub_40C140 as part of object setup [caller:0x0040C140, source:raw]
    // GUARD: Lazy-init guard: each of the five slots this+0x10, this+0x14, this+0x18, this+0x1C and this+0x20 is allocated only while its stored pointer is null [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // CALL: For the first four slots: OperatorNewNhMallocWrapper(200) followed by the F_3DSoundEmitter constructor on the new block; a failed allocation yields a null slot [callee:0x00587C03, callee:0x00456170, source:raw]
    // ASSIGNMENT: Stores the four constructed pointers back into this+0x10, this+0x14, this+0x18 and this+0x1C [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Writes the dword 1135869952 (packet init_float 360.0) as a triple at each 200-byte sub-object +136 (+0x88), normalized by the packet fact model to fields this+0xA8, this+0xAC and this+0xB0 [field:this:0x000000A8, field:this:0x000000AC, field:this:0x000000B0, source:raw]
    // CALL: Fifth slot: OperatorNewNhMallocWrapper(204); on success the first dword is set to 1 (refcount), the payload starts one dword in, and F_3DSoundEmitter runs on the payload [callee:0x00587C03, callee:0x00456170, field:this:0x00000020, source:raw]
    // CALL: StringCopyWithBufferRealloc is invoked on the byte_5EA438 buffer and its return value is discarded [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Initializes the fifth sub-object's parameter block: zero dwords at +12..+44 and +92..+120, a zero byte at +96, and float literals 1114636288, 1110704128, 1056964608, 1140457472 and 1065353216 placed across +48..+88; the zeroed dword at +28 is the packet field *(this+0x20)+0x1C [field:*(this+0x20):0x0000001C, source:raw]
    // CALL: Dispatches a virtual method through the fifth sub-object's vtable at slot +28, with the this+0x20 payload as the receiver; no static callee address is available [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Writes the 1135869952 dword triple at the fifth sub-object +136 (this[8] + 136) [field:this:0x00000020, source:raw]
    // RETURN: Returns the dword 1135869952 carried in the result register [source:raw]

    // Conservative worker pseudocode:
    //   for (slot in { this+0x10, this+0x14, this+0x18, this+0x1C }) {
    //     if (!*(slot)) {
    //       block = OperatorNewNhMallocWrapper(200);
    //       *(slot) = block ? F_3DSoundEmitter(block) : 0;
    //       if (*(slot)) {
    //         w = *(slot) + 136;
    //         *w = 1135869952; *(w + 4) = 1135869952; *(w + 8) = 1135869952;
    //       }
    //     }
    //   }
    //   if (!*(this + 0x20)) {
    //     block = OperatorNewNhMallocWrapper(204);
    //     if (block) { *block = 1; obj = block + 4; F_3DSoundEmitter(obj); }
    //     else obj = 0;
    //     *(this + 0x20) = obj;
    //     StringCopyWithBufferRealloc(&byte_5EA438);
    //     *(obj + 12) = 0; *(obj + 16) = 0; *(obj + 20) = 0; *(obj + 24) = 0;
    //     *(obj + 28) = 0; *(obj + 32) = 0; *(obj + 36) = 0; *(obj + 40) = 0; *(obj + 44) = 0;
    //     *(obj + 48) = 1114636288; *(obj + 52) = 1110704128;
    //     *(obj + 56) = 1114636288; *(obj + 60) = 1110704128;
    //     *(obj + 64) = 1056964608; *(obj + 68) = 1140457472;
    //     *(obj + 72) = 1065353216; *(obj + 76) = 1065353216; *(obj + 80) = 1065353216;
    //     *(obj + 84) = 1056964608; *(obj + 88) = 1056964608;
    //     *(obj + 92) = 0; *(obj + 96) = 0; *(obj + 100) = 0; *(obj + 104) = 0;
    //     *(obj + 108) = 0; *(obj + 112) = 0; *(obj + 116) = 0; *(obj + 120) = 0;
    //     virtual_call(*(*(this + 0x20)) + 28, this + 0x20);
    //     w = this[8] + 136;
    //     *w = 1135869952; *(w + 4) = 1135869952; *(w + 8) = 1135869952;
    //   }
    //   return 1135869952;
    // UNRESOLVED: The indirect virtual call through the fifth sub-object's vtable at slot +28 has no static callee address in the packet
    // UNRESOLVED: The float literal block written into the fifth sub-object (1114636288, 1110704128, 1056964608, 1140457472, 1065353216) has no semantic interpretation available from this packet
    // UNRESOLVED: The StringCopyWithBufferRealloc return is discarded; whether it mutates byte_5EA438 or the sub-object is unresolved
    // UNRESOLVED: Packet fields this+0xA8/0xAC/0xB0 represent the 360.0f writes that the raw source performs at sub-object+136; the base chosen by the fact extractor differs from the raw source base
}
