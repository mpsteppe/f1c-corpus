// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00503B94
// Canonical corpus name: F_16BitTextureBlending
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_16BitTextureBlending_00503b94.c

void UnknownObject::F_16BitTextureBlending()
{
    // 16-bit texture vector blend (canonical name F_16BitTextureBlending): averages each 2x2 source pixel block, taken as two pixels from each of two adjacent source rows, into one 16-bit destination pixel. The four pixels are combined per channel group using masks 0x83E0 and 0x7C1F with rounding constants 65600 and 2050. After each row pair the destination advances by its row stride (this+0x1054) while the source advances by two row strides, giving a 2:1 downscale. Always returns 0.
    // CALCULATION: Dereference this+0x0 to obtain the source surface object, then read its +0x18 field to get the source pixel-data base pointer. [field:this:0x00000000, field:obj:0x00000018]
    // CALCULATION: Read the source row stride at obj+0x1050 and the blocks-per-row count at obj+0x105C, then compute the outer loop end bound as source base plus stride multiplied by blocks-per-row. [field:obj:0x00001050, field:obj:0x0000105C]
    // CALCULATION: Read the destination surface object at this+0x4 and obtain its 16-bit pixel-data base pointer. [field:this:0x00000004, field:*(obj+0x18):0x00000000]
    // LOOP: Outer row-pair loop runs while the source pixel pointer is below the end bound; each pass processes one 2x2 block row pair, advances the destination pointer by the destination row stride at this+0x1054, and advances the source by two source row strides. [field:this:0x00001054, field:obj:0x00001050]
    // CALCULATION: Read the source block width at obj+0x1058 and form the inner loop row-end bound as the source pointer plus two times the width. [field:obj:0x00001058]
    // LOOP: Inner block loop reads the four 16-bit source pixels of a 2x2 block, at word offsets +0x0 and +0x2 on each of the two rows, and writes one blended 16-bit pixel into the destination surface. [field:*(obj+0x18):0x00000000, field:*(obj+0x18):0x00000002]
    // CALCULATION: Blend the four pixels: sum and average each channel group separately, using mask 0x83E0 with rounding constant 65600 and mask 0x7C1F with rounding constant 2050, shifting right by 2 and XOR-combining into the output pixel. [source:raw]
    // RETURN: Return 0 after the outer loop completes; no error path exists. [source:raw]
    // CALL: Dispatched as the format-25 handler by COMInterfaceVectorProcessingMethod (00504B37) during vector compositing. [caller:0x00504B37]

    // Conservative worker pseudocode:
    //   int F_16BitTextureBlending(int* this) {
    //     char* srcSurf = (char*)this[0];
    //     char* srcBase = *(char**)(srcSurf + 0x18);
    //     int srcStride = *(int*)(srcSurf + 0x1050);
    //     int blocks = *(int*)(srcSurf + 0x105C);
    //     int width = *(int*)(srcSurf + 0x1058);
    //     char* dstSurf = (char*)this[1];
    //     WORD* dst = *(WORD**)(dstSurf + 0x18);
    //     int dstStride = *(int*)(dstSurf + 0x1054);
    //     char* srcEnd = srcBase + srcStride * blocks;
    //     for (char* rowA = srcBase; rowA < srcEnd; rowA += 2 * srcStride) {
    //       char* rowB = rowA + srcStride;
    //       WORD* out = dst;
    //       for (char* p = rowA; p < rowA + 2 * width; p += 4, out++) {
    //         WORD a0 = *(WORD*)p, a1 = *(WORD*)(p + 2);
    //         WORD b0 = *(WORD*)(rowB + (p - rowA)), b1 = *(WORD*)(rowB + (p - rowA) + 2);
    //         *out = (WORD)(((((b0 & 0x83E0) + (a0 & 0x83E0) + (b1 & 0x83E0) + (a1 & 0x83E0) + 65600) >> 2)
    //                     ^ ((((a1 & 0x7C1F) + (b0 & 0x7C1F) + (a0 & 0x7C1F) + (b1 & 0x7C1F) + 2050) >> 2)
    //                       ^ (((b0 & 0x83E0) + (a0 & 0x83E0) + (b1 & 0x83E0) + (a1 & 0x83E0) + 65600) >> 2))) & 0x7C1F);
    //       }
    //       dst = (WORD*)((char*)dst + dstStride);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The canonical name F_16BitTextureBlending is inherited by cluster_copy from structural twin sub_503920 (00503920) at DERIVED trust; the twin relationship is not independently confirmed.
    // UNRESOLVED: this+0x1C is recorded as a read field but has no visible use in the raw pseudocode; its purpose is unknown.
    // UNRESOLVED: The 2:1 horizontal and vertical downscale semantics implied by the block averaging, and the exact 16-bit pixel channel layout behind masks 0x83E0 and 0x7C1F, are inferred from the arithmetic (DERIVED) and not independently grounded.
    // UNRESOLVED: The object type owning the source and destination surface pointers at this+0x0 and this+0x4 is UnknownObject.
}
