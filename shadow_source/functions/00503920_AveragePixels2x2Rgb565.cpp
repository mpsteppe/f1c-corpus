// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00503920
// Canonical corpus name: sub_503920
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_503920_00503920.c

void UnknownObject::AveragePixels2x2Rgb565()
{
    // Downsampling helper that averages each 2x2 block of 16-bit RGB565 source pixels into one output pixel: it iterates rows of the source surface (pixel base at +0x18, row stride at +0x1050, row count at +0x105C) and within each row processes pixels up to the per-row bound at +0x1058, summing the four pixels' red/blue components with mask 0xF81F and green with mask 0x7E0, applying rounding constants 4098 and 64, then dividing by 4 (>>2) and writing the 16-bit result to the destination surface's pixel buffer; always returns 0.
    // ASSIGNMENT: Load the source surface object from a1[0] and the destination surface object from a1[1]. [function:0x00503920, field:this:0x00000000, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Load the source pixel data base from the source object at +0x18 and the destination pixel base from the object at a1[1] + 24. [field:obj:0x00000018, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Load the source row stride (offset 4176) and the source row count (offset 4188) from the source object and compute the row-loop end pointer = pixelBase + stride * rowCount. [field:obj:0x00001050, field:obj:0x0000105C, source:raw]
    // LOOP: Outer loop over rows: advance the source pointer by the row stride until the row-count end pointer is reached. [field:obj:0x00001050, field:obj:0x0000105C, source:raw]
    // LOOP: Inner loop per row: process source pixels while the pointer stays below the per-row bound computed from offset 4184. [field:obj:0x00001058, source:raw]
    // CALCULATION: Average the four 16-bit RGB565 pixels of each 2x2 block: sum red/blue components with mask 0xF81F and green with mask 0x7E0, add rounding constants 4098 and 64, then divide each channel by 4 (>>2) and recombine into a single 16-bit value. [field:*(obj+0x18):0x00000000, field:*(obj+0x18):0x00000002, source:raw]
    // ASSIGNMENT: Write the averaged 16-bit result into the destination pixel buffer at the current destination pointer. [field:this:0x0000001C, source:raw]
    // CALCULATION: Advance the destination pointer each row by the destination surface's row stride (offset 4176 on the destination object). [field:this:0x00001054, source:raw]
    // RETURN: Return 0 when all rows have been processed. [source:raw]

    // Conservative worker pseudocode:
    //   src = *a1; dst = a1[1];
    //   src_px = *(src+0x18); dst_px = *(dst+24);
    //   stride = *(src+4176); rows = *(src+4188); bound = *(src+4184);
    //   for (p = src_px; p < src_px + stride*rows; p += stride) {
    //     for (q = p; q < p + bound; q += 2) {
    //       avg = (rgb565_avg(q, q+2, q+stride, q+2+stride));
    //       *dst_px++ = avg;
    //     }
    //     dst_px = (word*)((char*)dst_px + *(dst+4176));
    //   }
    //   return 0;
    // UNRESOLVED: The destination pixel base is read in the raw source as *(a1[1]+24) and the destination stride as *(a1[1]+4176); the packet attributes these reads to field base "this" at offsets 0x1C and 0x1054, which differ by 4 from the source object's +0x18 / +0x1050. The base/offset attribution between the extractor and the raw text is unresolved.
    // UNRESOLVED: The RGB565 interpretation is inferred from masks 0xF81F / 0x7E0 and rounding constants 4098 / 64; it is not independently confirmed.
    // UNRESOLVED: The downsample scale factor and the exact output row layout are not fully established.
    // UNRESOLVED: Only one caller is known (COMInterfaceVectorProcessingMethod 0x00504B37); the owning class and invocation context are unknown.
    // UNRESOLVED: The packet lists no globals, guards or callees.
}
