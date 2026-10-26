// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00518AAA
// Canonical corpus name: sub_518AAA
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_518AAA_00518aaa.c

void UnknownObject::PNGPLTEChunkParser()
{
    // PNG PLTE (palette) chunk parser: validates chunk ordering against the flags word (requires IHDR seen first, forbids IDAT before PLTE and duplicate PLTE), rejects palette lengths that are not a multiple of 3, allocates and fills the RGB palette via sub_513C80 and sub_517F58, records the palette pointer and entry count, and clamps the tRNS entry count for palette-indexed (color type 3) images. Part of the PNG decoder.
    // GUARD: Read the flags word at this+0x58; if the IHDR-seen bit is clear, dispatch the Missing-IHDR-before-PLTE error through GuardedCallWithLongjmp. [field:this:0x00000058, callee:0x00511869, global:0x005AFCE4, source:raw]
    // GUARD: If the IDAT-seen bit is set in this+0x58, dispatch the Invalid-PLTE-after-IDAT error through CallbackDispatch and continue with the chunk-skip path. [field:this:0x00000058, callee:0x00511887, global:0x005AFCCC, callee:0x00518828, source:raw]
    // GUARD: If the PLTE-seen bit is already set in this+0x58, dispatch the Duplicate-PLTE-chunk error through GuardedCallWithLongjmp. [field:this:0x00000058, callee:0x00511869, global:0x005AFCB4, source:raw]
    // ASSIGNMENT: Set the PLTE-seen bit in the flags word at this+0x58. [field:this:0x00000058, source:raw]
    // CALCULATION: Compute the chunk length modulo 3; when nonzero and the color type at this+0x116 differs from 3 dispatch the invalid-palette-chunk error through CallbackDispatch and skip the chunk, and when the color type equals 3 dispatch it through GuardedCallWithLongjmp. [field:this:0x00000116, guard:0, guard:1, callee:0x00511887, callee:0x00511869, callee:0x00518828, global:0x005AFC9C, source:raw]
    // CALL: Allocate palette storage for the entry count (chunk length divided by 3, three bytes per RGB triplet) via sub_513C80, store the returned pointer into this+0x104, and set the palette-active bit (0x10) in the flags byte at this+0x5D. [callee:0x00513C80, field:this:0x00000104, field:this:0x0000005D, source:raw]
    // LOOP: Fill each RGB palette entry by reading three bytes per triplet through sub_517F58 into the allocated buffer. [callee:0x00517F58, source:raw]
    // CALL: After the palette fill, run the chunk-end handler sub_518828. [callee:0x00518828, source:raw]
    // ASSIGNMENT: Record the palette pointer in this+0x104 and the palette entry count in this+0x108, then call FlagSetterWithGuard with the image-info argument, the pointer, and the count. [field:this:0x00000104, field:this:0x00000108, callee:0x00513B12, source:raw]
    // GUARD: For color type 3 with a tRNS argument present and its transparent-flag bit set: if the tRNS entry count in this+0x10A exceeds the palette entry count in this+0x108, dispatch the truncating-incorrect-tRNS-length error through CallbackDispatch and clamp this+0x10A down to this+0x108. [field:this:0x00000116, field:this:0x0000010A, field:this:0x00000108, callee:0x00511887, global:0x005AFC74, source:raw]

    // Conservative worker pseudocode:
    //   // Parse a PNG PLTE (palette) chunk. this = PNG decode context;
    //   // a2 = image-info (tRNS) object; a3 = chunk length.
    //   int PNGPLTEChunkParser(ctx, info, length) {
    //     flags = ctx->flags;                            // this+0x58
    //     if (!(flags & 1))                              // IHDR not seen
    //       return GuardedCallWithLongjmp(ctx, "Missing IHDR before PLTE");
    //     if (flags & 4) {                               // IDAT already seen
    //       CallbackDispatch(ctx, "Invalid PLTE after IDAT");
    //       return sub_518828(ctx, length);
    //     }
    //     if (flags & 2)                                 // duplicate PLTE
    //       return GuardedCallWithLongjmp(ctx, "Duplicate PLTE chunk");
    //     ctx->flags |= 2;                               // mark PLTE seen
    //     if (length % 3) {
    //       if (ctx->colorType != 3) {                   // this+0x116
    //         CallbackDispatch(ctx, "Invalid palette chunk");
    //         return sub_518828(ctx, length);
    //       }
    //       return GuardedCallWithLongjmp(ctx, "Invalid palette chunk");
    //     }
    //     count = length / 3;
    //     pal = sub_513C80(ctx, count, 3);
    //     ctx->paletteActive |= 16;                      // this+0x5D bit 4
    //     for (i = 0; i < count; i++)                    // 3 bytes per RGB entry
    //       read triplet via sub_517F58 into pal;
    //     sub_518828(ctx, 0);
    //     ctx->palette = pal;                            // this+0x104
    //     ctx->palCount = count;                         // this+0x108
    //     FlagSetterWithGuard(ctx, info, pal, count);
    //     if (ctx->colorType == 3 && info && (info->tflags & 16)
    //         && ctx->trnsCount > ctx->palCount) {       // this+0x10A vs this+0x108
    //       CallbackDispatch(ctx, "Truncating incorrect tRNS chunk length");
    //       ctx->trnsCount = ctx->palCount;
    //     }
    //   }
    // UNRESOLVED: The exact layout and semantics of sub_513C80 (allocation) and FlagSetterWithGuard (callback registration) are not available in this packet.
    // UNRESOLVED: The image-info argument a2 is caller-supplied; its layout (transparent-flag at offset 8) is inferred from the decompilation only.
    // UNRESOLVED: The precise relationship between the this+0x5D flags byte and the this+0x58 flags word is not fully established.
}
