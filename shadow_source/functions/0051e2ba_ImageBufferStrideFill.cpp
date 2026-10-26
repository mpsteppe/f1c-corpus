// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051E2BA
// Canonical corpus name: ImageBufferStrideFill
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ImageBufferStrideFill_0051e2ba.c

void UnknownObject::ImageBufferStrideFill()
{
    // Fills an image buffer with stride-based per-channel gradient byte values. Reads a context pointer at this+0x1A4, asks CombinatorialPermutationGenerator for a permutation count over context+0x20, then branches on the channel-mode field this+0x64: in 3-channel mode (== 3) it stores the count plus three per-channel strides and status 93 at obj+0x18/0x1C/0x20/0x24/0x14; otherwise it stores status 94 at obj+0x14 and the count at obj+0x18. It then issues two indirect calls (an object vtable call through obj+0x4, and an allocator call through this+0x4 slot +8 that returns the output buffer), iterates over the mode's channels, and for each channel whose stride is positive writes a division-interpolated gradient byte across the buffer, finally persisting the count at this+0x1B8 and the output buffer pointer at this+0x1B4 and returning the buffer pointer.
    // ASSIGNMENT: Read the context pointer: v10 = this[105] at this+0x1A4. [field:this:0x000001A4, source:raw]
    // CALL: Call CombinatorialPermutationGenerator(this, context + 0x20) and store the returned permutation count as v1. [callee:0x0051E1EF, field:this:0x000001A4]
    // ASSIGNMENT: Dereference this+0x0 to obtain the object base pointer obj (vtable anchor) used for the subsequent object writes. [field:this:0x00000000, source:raw]
    // GUARD: Branch on the channel-mode field: if this+0x64 == 3 take the three-channel layout path. [guard:0, field:this:0x00000064]
    // ASSIGNMENT: Three-channel mode: set obj+0x18 = count, obj+0x1C = stride[0] (context+0x20 / this+0x1C4), obj+0x20 = stride[1] (context+0x24 / this+0x1C8), obj+0x24 = stride[2] (context+0x28 / this+0x1CC), and set status obj+0x14 = 93. [field:obj:0x00000018, field:obj:0x0000001C, field:obj:0x00000020, field:obj:0x00000024, field:obj:0x00000014, field:this:0x000001C4, field:this:0x000001C8, field:this:0x000001CC]
    // ASSIGNMENT: Otherwise: set status obj+0x14 = 94 and obj+0x18 = count. [field:obj:0x00000014, field:obj:0x00000018]
    // CALL: Indirect __cdecl call through the vtable slot at obj+0x4 with arguments (this, 1); return value unused. [field:obj:0x00000004]
    // CALL: Indirect allocator call through this+0x4 slot +8 with arguments (this, 1, count v1, mode this+0x64); the returned pointer is the output buffer (result). [field:this:0x00000004, field:this:0x00000064, function:0x0051E2BA]
    // LOOP: Per-channel do-while loop over the mode this+0x64 channels; iteration advances the stride pointer (context+0x20 base, this+0x1C4) and the output-buffer pointer together. [guard:1, field:this:0x00000064]
    // CALCULATION: Per channel compute v17 = remaining / stride, with the current stride read from the stride array at this+0x1C4. [guard:2, field:this:0x000001C4]
    // GUARD: Skip the fill for a channel when its stride is not > 0 (this+0x1C4 > 0). [guard:2, field:this:0x000001C4]
    // LOOP: Nested fill loops: for each of v17 columns and each i stepping by the current remainder, write a gradient byte at output_buffer[j + i] = (v6 + (stride - 1) / 2) / (stride - 1), with v6 increasing by 255 per column. [field:this:0x000001C4, source:raw]
    // ASSIGNMENT: Persist the results into the context: this+0x1B4 (context+0x10) = output buffer pointer, this+0x1B8 (context+0x14) = permutation count v1. [field:this:0x000001B4, field:this:0x000001B8]
    // RETURN: Return the output buffer pointer (result). [function:0x0051E2BA, source:raw]

    // Conservative worker pseudocode:
    //   int sub_51E2BA(int this) {
    //     int ctx = *(int*)(this + 0x1A4);
    //     int count = CombinatorialPermutationGenerator(this, ctx + 0x20);
    //     int* obj = *(int**)this;
    //     if (*(int*)(this + 0x64) == 3) {
    //       obj[6] = count;
    //       obj[7] = *(int*)(ctx + 0x20);
    //       obj[8] = *(int*)(ctx + 0x24);
    //       obj[9] = *(int*)(ctx + 0x28);
    //       *(int*)(obj + 5) = 93;
    //     } else {
    //       *(int*)(obj + 5) = 94;
    //       obj[6] = count;
    //     }
    //     (*(void(__cdecl**)(int,int))(obj + 1))(this, 1);
    //     int buf = (*(int(__cdecl**)(int,int,int,int))(*(int**)(this + 4) + 2))(this, 1, count, *(int*)(this + 0x64));
    //     int remaining = count;
    //     int* stride = (int*)(ctx + 0x20);
    //     for (int c = 0; c < *(int*)(this + 0x64); ++c) {
    //       int s = *stride;
    //       int cols = remaining / s;
    //       if (s > 0) {
    //         int value = 0;
    //         for (int n = s; n > 0; --n) {
    //           for (int i = 0; i < count; i += remaining) {
    //             for (int j = 0; j < cols; ++j) {
    //               *(unsigned char*)(j + buf + i) = (unsigned char)((value + (s - 1) / 2) / (s - 1));
    //             }
    //           }
    //           value += 255;
    //         }
    //       }
    //       ++stride;
    //       buf += cols;
    //       remaining = cols;
    //     }
    //     *(int*)(ctx + 0x10) = buf;
    //     *(int*)(ctx + 0x14) = count;
    //     return buf;
    //   }
    // UNRESOLVED: Semantic role of the indirect vtable call at obj+0x4 (argument 1) is not identified; no callee evidence exists for it.
    // UNRESOLVED: Semantics of the per-channel gradient formula are inferred from the arithmetic; the exact pixel layout and the meaning of the (stride - 1) denominator are not proven.
    // UNRESOLVED: The buffer pointer returned from the allocator call is used both as fill destination and later written to context+0x10; the allocation size policy is not visible here.
    // UNRESOLVED: Field read this+0xC is declared by the facts but does not appear in the decompiled body.
    // UNRESOLVED: Called from ObjectSetupWithBoundsCheck; the caller-supplied context layout at this+0x1A4 is not established here.
    // UNRESOLVED: The ABI lead names this resource-decompression output filler; that label is LEGACY and unverified.
}
