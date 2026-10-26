// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051DFCB
// Canonical corpus name: sub_51DFCB
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_51DFCB_0051dfcb.c

void UnknownObject::TextureCodecModeDispatch()
{
    // Selects and installs a texture codec dispatch pair on a context object. With flag a2 set it installs TrackSurfaceHeightmapIncrement + VehicleUpdateFrameSetup and marks the context dirty. With a2 clear it installs a no-op second slot and selects BlockTextureDecompression when the mode at this+0x4C equals 2, otherwise PackedPixelCopyWithPaletteLookup, applying row-count underflow/overflow resets through the object vtable. In mode 2 it allocates and zeroes a dither buffer and initializes a symmetric array. A dirty flag on the context triggers zeroing of 32 rows of 0x1000 bytes.
    // GUARD: Test whether the codec mode at this+0x4C equals 0. [guard:0, field:this:0x0000004C]
    // ASSIGNMENT: Load the context pointer v4 from this+0x1A4. [field:this:0x000001A4]
    // ASSIGNMENT: Save result = *(v4+24) as the row-table base v9 used by the dirty-row clear. [source:raw]
    // STATE_TRANSITION: When the mode at this+0x4C was nonzero, promote it to 2. [field:this:0x0000004C]
    // ASSIGNMENT: Flag-set branch: install TrackSurfaceHeightmapIncrement at context+4 (this+0x1A8), VehicleUpdateFrameSetup at context+8 (this+0x1AC), and set the dirty flag context+0x1C (this+0x1C0) to 1. [global:0x0051D1DB, global:0x0051DFA8, field:this:0x000001A8, field:this:0x000001AC, field:this:0x000001C0]
    // GUARD: Flag-clear branch: when mode this+0x4C equals 2 select BlockTextureDecompression, otherwise PackedPixelCopyWithPaletteLookup, as the first dispatch slot; install nullsub_4 at context+8. [guard:1, field:this:0x0000004C, global:0x0051DCAA, global:0x0051DC01, global:0x0051DFCA, field:this:0x000001A8, field:this:0x000001AC]
    // GUARD: Row count this+0x70 below 1 triggers the underflow reset: write a small bound to obj+0x14 and 1 to obj+0x18, then invoke the object vtable. [field:this:0x00000070, field:obj:0x00000014, field:obj:0x00000018, field:obj:0x00000000]
    // CALL: Indirect call through the obj+0x0 vtable to run the underflow reset. [field:obj:0x00000000, field:this:0x00000000]
    // GUARD: Row count this+0x70 above 256 triggers the overflow clamp: write 56 to obj+0x14 and 256 to obj+0x18, then invoke the vtable and use its result. [field:this:0x00000070, field:obj:0x00000014, field:obj:0x00000018]
    // CALL: Indirect call through the this+0x0 vtable returning the clamped reset result. [field:this:0x00000000]
    // ASSIGNMENT: Default result of 256 when the row count falls inside the valid range. [source:raw]
    // CALCULATION: Compute the mode-2 allocation size v7 = 6 * (this+0x5C + 2). [field:this:0x0000005C]
    // CALL: Allocate the context+0x20 buffer (this+0x1C4) through the allocator at this+0x4+4 when it is unset. [field:this:0x000001C4, field:this:0x00000004]
    // CALL: MemoryZeroFill the allocated context+0x20 buffer for v7 bytes. [callee:0x005159A8, field:this:0x000001C4]
    // CALL: Call SymmetricArrayInit(a1) when the context+0x28 slot (this+0x1CC) is unset. [callee:0x0051DF18, field:this:0x000001CC]
    // ASSIGNMENT: Clear the context+0x24 toggle field (this+0x1C8) to 0. [field:this:0x000001C8]
    // LOOP: When the dirty flag context+0x1C (this+0x1C0) is set, zero 32 rows of 0x1000 bytes each from the row-table base v9, then clear the flag to 0. [field:this:0x000001C0]
    // CALL: MemoryZeroFill each of the 32 row pointers at v9 + 4*i. [callee:0x005159A8]
    // RETURN: Return result, which is the last operation result or the default 256. [source:raw, function:0x0051DFCB]
    // UNKNOWN: ABI: __cdecl(_DWORD* a1, char a2) returning int; a1 is the object, a2 is the dispatch flag. [abi:lead]

    // Conservative worker pseudocode:
    //   int sub_51DFCB(_DWORD* obj, char set) {
    //     bool wasZero = (obj[19] == 0);
    //     int ctx = obj[105]; int result = *(int*)(ctx + 24); int rows = result;
    //     if (!wasZero) obj[19] = 2;
    //     if (set) {
    //       *(void**)(ctx + 4) = TrackSurfaceHeightmapIncrement;
    //       *(void**)(ctx + 8) = VehicleUpdateFrameSetup;
    //       *(byte*)(ctx + 28) = 1;
    //     } else {
    //       *(void**)(ctx + 4) = (obj[19] == 2) ? BlockTextureDecompression : PackedPixelCopyWithPaletteLookup;
    //       *(void**)(ctx + 8) = nullsub_4;
    //       int n = obj[28];
    //       if (n < 1)  { *(int*)(*obj + 20) = 55; *(int*)(*obj + 24) = 1;  (fn)*obj(obj); }
    //       result = 256;
    //       if (n > 256) { *(int*)(*obj + 20) = 56; *(int*)(*obj + 24) = 256; result = (fn)*obj(obj); }
    //       if (obj[19] == 2) {
    //         unsigned int sz = 6 * (obj[23] + 2);
    //         if (!*(int*)(ctx + 32)) *(int*)(ctx + 32) = (allocator at obj[1]+4)(obj, 1, sz);
    //         result = MemoryZeroFill(*(void**)(ctx + 32), sz);
    //         if (!*(int*)(ctx + 40)) result = SymmetricArrayInit((int)obj);
    //         *(byte*)(ctx + 36) = 0;
    //       }
    //     }
    //     if (*(byte*)(ctx + 28)) {
    //       for (int i = 0; i < 32; i++) result = MemoryZeroFill(*(void**)(rows + 4*i), 0x1000);
    //       *(byte*)(ctx + 28) = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Owner object and context types are unidentified; owner remains UnknownObject.
    // UNRESOLVED: Packet-internal literal discrepancy: the obj+0x14 field record lists init_literal 56 while the raw source writes 55 at the underflow path; both spellings are preserved from the packet and not resolved here.
    // UNRESOLVED: Fields this+0x8 and this+0x1BC are listed as read evidence but have no visible access in the raw source; their purpose is unknown.
    // UNRESOLVED: The codec dispatch slots (context+4, context+8) target functions whose rendering semantics are outside this function.
}
