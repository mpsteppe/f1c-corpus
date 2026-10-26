// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005033A5
// Canonical corpus name: DXTCompressedTextureBlockCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DXTCompressedTextureBlockCopy_005033a5.c

void UnknownObject::DXTCompressedTextureBlockCopy()
{
    // DXT-compressed texture block blit. Validates 4-byte alignment of the source and destination surface pitch/dimensions, dispatches on the destination pixel-format tag at dest+4 (DXT1-style formats use 8-byte blocks, DXT3/4/5-style use 16-byte blocks, anything else fails), computes block-aligned source and destination base addresses, then copies block rows with qmemcpy in a nested loop. Returns 0 on success and -2147467259 on any validation failure. Called from SurfacePixelCopy (0x00504508).
    // GUARD: Guard: source surface alignment check. Reads low bytes of src pitch/height fields (+0x1030, +0x1034, +0x1038, +0x103C); if (lowByte(srcHeight) | lowByte(srcWidth) | lowByte(srcRowPitch) | lowByte(srcSlicePitch)) & 3 != 0, return -2147467259. [field:obj:0x00001030, field:obj:0x00001034, field:obj:0x00001038, field:obj:0x0000103C, field:this:0x00000000, source:raw]
    // GUARD: Guard: destination surface alignment check on the dest surface object at this+4, same low-byte alignment test over dest pitch/dimension fields (+0x1034, +0x1038, +0x103C); on failure return -2147467259. [field:this:0x00000004, field:this:0x00001034, field:this:0x00001038, field:this:0x0000103C, source:raw]
    // GUARD: Guard/dispatch on destination pixel-format tag at dest+4: if 827611204 use 8 bytes per block; else if the tag is one of 844388420, 861165636, 877942852, 894720068 use 16 bytes per block; otherwise return -2147467259. [field:this:0x00000004, source:raw]
    // CALCULATION: Compute v15 = blockBytes * (destBlockWidth(+0x1058) >> 2): bytes per block row. [field:this:0x00001058, source:raw]
    // CALCULATION: Compute destination block base v20 = dest+0x18 + blockBytes * (destWidth(+0x1030) >> 2) + destRowOffset(+0x1040) * destVerticalStride(+0x1054) + destRowStride * (destHeight(+0x1034) >> 2). [field:this:0x00001034, field:this:0x00001040, field:this:0x00001054, source:raw]
    // CALCULATION: Compute source block base v8 = src+0x18 + blockBytes * (srcWidth(+0x1030) >> 2) + srcRowOffset(+0x1040) * srcVerticalStride(+0x1054) + srcRowStride(+0x1050) * (srcHeight(+0x1034) >> 2). [field:obj:0x00000018, field:obj:0x00001030, field:obj:0x00001034, field:obj:0x00001040, field:obj:0x00001050, field:obj:0x00001054, source:raw]
    // LOOP: Nested block copy: inner loop copies v15 bytes per block row via qmemcpy from the source cursor to the destination cursor, advancing both cursors by their per-row strides and reloading the per-row block count from dest(+0x105C); outer do-while advances the destination base by the dest vertical stride (+0x1054) and the source base by the src vertical stride, repeating while the block-row count from dest(+0x1060) is not exhausted. [field:this:0x0000105C, field:this:0x00001060, source:raw]
    // RETURN: Return 0 on success. [function:0x005033A5, source:raw]

    // Conservative worker pseudocode:
    //   int DXTCompressedTextureBlockCopy(void* this) {
    //       src = *(void**)this; dst = *((void**)this + 1);
    //       if (!aligned4(src->width, src->height, src->rowPitch, src->slicePitch)) return -2147467259;
    //       if (!aligned4(dst->width, dst->height, dst->rowPitch, dst->slicePitch)) return -2147467259;
    //       switch (dst->formatTag) {
    //           case 827611204:  blockBytes = 8;  break;
    //           case 844388420: case 861165636:
    //           case 877942852: case 894720068: blockBytes = 16; break;
    //           default: return -2147467259;
    //       }
    //       rowBytes = blockBytes * (dst->blockWidth >> 2);
    //       dstBase = dst->base + blockBytes * (dst->width >> 2)
    //               + dst->rowOffset * dst->vertStride + dst->rowStride * (dst->height >> 2);
    //       srcBase = src->base + blockBytes * (src->width >> 2)
    //               + src->rowOffset * src->vertStride + src->rowStride * (src->height >> 2);
    //       if (dst->blockRows) {
    //           do {
    //               for (blocks = dst->blocksPerRow; blocks > 0; ) {
    //                   qmemcpy(dstBase, srcBase, rowBytes);
    //                   srcBase += src->rowStride; dstBase += dst->rowStride;
    //                   blocks = dst->blocksPerRow;
    //               }
    //               dstBase += dst->vertStride;
    //               srcBase += src->vertStride;
    //           } while (--remaining < dst->blockRows);
    //       }
    //       return 0;
    //   }
    // UNRESOLVED: The pixel-format tag values are treated as opaque DXT-family format identifiers; the DXT1/3/4/5 correspondence is inferred from the 8/16-byte block split, not stated in the packet.
    // UNRESOLVED: The destination per-row stride and the source vertical stride offsets are expressed in the raw source as dword-indexed offsets (+0x1050 for dst row stride, +0x1054 for src vertical stride) that do not have matching allowed field:this/field:obj evidence references for the dst row-stride read; the copy still uses the raw arithmetic.
    // UNRESOLVED: Fields this+0x08, this+0x1C, this+0x1044, this+0x1064 are read by the packet's field extraction but are not visible as distinct reads in the raw decompilation.
    // UNRESOLVED: Surface object layouts (offsets of width/height/pitch fields) are known only via DERIVED fill labels; the owning class is not established.
}
