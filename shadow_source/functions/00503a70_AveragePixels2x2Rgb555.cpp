// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00503A70
// Canonical corpus name: sub_503A70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_503A70_00503a70.c

void UnknownObject::AveragePixels2x2Rgb555()
{
    // Structural twin of the cluster representative sub_503920: a downsampling helper that averages each 2x2 block of 16-bit RGB555 source pixels into one output pixel, iterating rows of the source surface (pixel base at +0x18, row stride at +0x1050, row count at +0x105C) and within each row processing pixels up to the per-row bound at +0x1058, summing the four pixels' green components with mask 0x3E0 and red/blue with mask 0x7C1F, applying rounding constants 64 (green) and 2050 (red/blue), then dividing by 4 (>>2) and writing the 16-bit result to the destination surface's pixel buffer; always returns 0.
    // ASSIGNMENT: Load the source surface object from a1[0] and the destination surface object from a1[1]. [function:0x00503A70, field:this:0x00000000, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Load the source pixel data base from the source object at +0x18 and the destination pixel base from the object at a1[1] + 24. [field:obj:0x00000018, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Load the source row stride (offset 4176) and the source row count (offset 4188) from the source object and compute the row-loop end pointer = pixelBase + stride * rowCount. [field:obj:0x00001050, field:obj:0x0000105C, source:raw]
    // LOOP: Outer loop over rows: advance the source pointer by the row stride until the row-count end pointer is reached. [field:obj:0x00001050, field:obj:0x0000105C, source:raw]
    // LOOP: Inner loop per row: process source pixels while the pointer stays below the per-row bound computed from offset 4184. [field:obj:0x00001058, source:raw]
    // CALCULATION: Average the four 16-bit RGB555 pixels of each 2x2 block: sum green components with mask 0x3E0 and red/blue components with mask 0x7C1F, add rounding constants 64 (green) and 2050 (red/blue), then divide each channel by 4 (>>2) and recombine into a single 16-bit value. [field:*(obj+0x18):0x00000000, field:*(obj+0x18):0x00000002, source:raw]
    // ASSIGNMENT: Write the averaged 16-bit result into the destination pixel buffer at the current destination pointer. [field:this:0x0000001C, source:raw]
    // CALCULATION: Advance the destination pointer each row by the destination surface's row stride (offset 4176 on the destination object). [field:this:0x00001054, source:raw]
    // RETURN: Return 0 when all rows have been processed. [source:raw]

    // Conservative worker pseudocode:
    //   src = *a1; dst = a1[1];
    //   src_px = *(src+0x18); dst_px = *(dst+24);
    //   stride = *(src+4176); rows = *(src+4188); bound = *(src+4184);
    //   for (p = src_px; p < src_px + stride*rows; p += stride) {
    //     for (q = p; q < p + bound; q += 2) {
    //       avg = (rgb555_avg(q, q+2, q+stride, q+2+stride));
    //       *dst_px++ = avg;
    //     }
    //     dst_px = (word*)((char*)dst_px + *(dst+4176));
    //   }
    //   return 0;
    // UNRESOLVED: Identified as a structural twin of sub_503920 by the packet prelabel (cluster_copy, DERIVED); the two differ in pixel format — the channel masks and rounding constants here (0x7C1F / 0x3E0, 2050 / 64) indicate an RGB555 variant, while the twin uses different channel masks and rounding.
    // UNRESOLVED: The destination pixel base is read in the raw source as *(a1[1]+24) and the destination stride as *(a1[1]+4176); the packet attributes these reads to field base "this" at offsets 0x1C and 0x1054, which differ by 4 from the source object's +0x18 / +0x1050. The base/offset attribution between the extractor and the raw text is unresolved.
    // UNRESOLVED: The RGB555 interpretation is inferred from the masks and rounding constants; it is not independently confirmed.
    // UNRESOLVED: The downsample scale factor and the exact output row layout are not fully established.
    // UNRESOLVED: Only one caller is known (COMInterfaceVectorProcessingMethod 0x00504B37); the owning class and invocation context are unknown.
    // UNRESOLVED: The packet lists no globals, guards or callees.
}
