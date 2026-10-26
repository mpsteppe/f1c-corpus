// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00503E36
// Canonical corpus name: PixelBlenderCompositor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PixelBlenderCompositor_00503e36.c

void UnknownObject::PixelBlenderCompositor()
{
    // 8-bit pixel blender compositor (canonical name PixelBlenderCompositor): averages each 2x2 source pixel block, taken as two bytes from each of two adjacent source rows, into one 8-bit destination byte per block. The four pixels are blended per channel group using masks 0xE3 and 0x1C with rounding constants 66 and 8. After each row pair the destination advances by its row stride (this+0x1054) while the source advances by two row strides, giving a 2:1 downscale. Always returns 0.
    // CALCULATION: Dereference this+0x0 to obtain the source surface object, then read its +0x18 field to get the source pixel-data base pointer. [field:this:0x00000000, field:obj:0x00000018]
    // CALCULATION: Read the source row stride at obj+0x1050 and the blocks-per-row count at obj+0x105C, then compute the outer loop end bound as source base plus stride multiplied by blocks-per-row. [field:obj:0x00001050, field:obj:0x0000105C]
    // CALCULATION: Read the destination surface object at this+0x4 and obtain its 8-bit pixel-data base pointer. [field:this:0x00000004, field:*(obj+0x18):0x00000000]
    // LOOP: Outer row-pair loop runs while the source pixel pointer is below the end bound; each pass processes one 2x2 block row pair, advances the destination pointer by the destination row stride at this+0x1054, and advances the source by two source row strides. [field:this:0x00001054, field:obj:0x00001050]
    // CALCULATION: Read the source block width at obj+0x1058 and form the inner loop row-end bound as the source pointer plus the width. [field:obj:0x00001058]
    // LOOP: Inner block loop reads the four 8-bit source pixels of a 2x2 block, at byte offsets +0x0 and +0x1 on each of the two rows, and writes one blended 8-bit pixel into the destination surface. [field:*(obj+0x18):0x00000000, field:*(obj+0x18):0x00000001]
    // CALCULATION: Blend the four pixels: sum and average each channel group separately, using mask 0xE3 with rounding constant 66 and mask 0x1C with rounding constant 8, shifting right by 2 and XOR-combining into the output pixel. [source:raw]
    // RETURN: Return 0 after the outer loop completes; no error path exists. [source:raw]
    // CALL: Dispatched as the format-27 handler by COMInterfaceVectorProcessingMethod (00504B37) during vector compositing. [caller:0x00504B37]

    // Conservative worker pseudocode:
    //   int PixelBlenderCompositor(int* this) {
    //     char* srcSurf = (char*)this[0];
    //     BYTE* src = *(BYTE**)(srcSurf + 0x18);
    //     int srcStride = *(int*)(srcSurf + 0x1050);
    //     int blocks = *(int*)(srcSurf + 0x105C);
    //     int width = *(int*)(srcSurf + 0x1058);
    //     char* dstSurf = (char*)this[1];
    //     BYTE* dst = *(BYTE**)(dstSurf + 0x18);
    //     int dstStride = *(int*)(dstSurf + 0x1054);
    //     BYTE* srcEnd = src + srcStride * blocks;
    //     for (; src < srcEnd; src += 2 * srcStride) {
    //       BYTE* rowB = src + srcStride;
    //       BYTE* out = dst;
    //       BYTE* rowEnd = src + width;
    //       for (BYTE* p = src; p + 1 < rowEnd; p += 2, out++) {
    //         BYTE a0 = p[0], a1 = p[1];
    //         BYTE b0 = rowB[(p - src)], b1 = rowB[(p - src) + 1];
    //         *out = (BYTE)(((((b0 & 0xE3) + (a0 & 0xE3) + (b1 & 0xE3) + (a1 & 0xE3) + 66) >> 2)
    //                    ^ ((((b0 & 0x1C) + (a0 & 0x1C) + (b1 & 0x1C) + (a1 & 0x1C) + 8) >> 2))) & 0x1C);
    //       }
    //       dst = (BYTE*)((char*)dst + dstStride);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: this+0x1C is recorded as a read field but has no visible use in the raw pseudocode; its purpose is unknown.
    // UNRESOLVED: The pixel format (RGB 332 implied by masks 0xE3 and 0x1C) follows the existing analysis skeletons_filled/PixelBlenderCompositor_00503e36.md and is DERIVED, not independently confirmed.
    // UNRESOLVED: The 2:1 horizontal and vertical downscale semantics implied by the block averaging are inferred from the loop structure (DERIVED); the object type behind this+0x0 and this+0x4 is UnknownObject.
}
