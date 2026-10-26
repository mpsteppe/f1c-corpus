// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051DCAA
// Canonical corpus name: BlockTextureDecompression
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BlockTextureDecompression_0051dcaa.c

void UnknownObject::BlockTextureDecompression()
{
    // Decompresses block-compressed texture rows with serpentine error diffusion. For each of a4 output rows, walks the row pixels, looks up palette entries through a grid (this+0x1BC) with channel offsets (this+0x1CC, this+0x11C), populates empty palette cells via BitstreamTextureBlockCopy, writes the chosen palette index to the destination pixel, and accumulates quantization error into a dither error buffer (this+0x1C4) that drives the neighbouring pixels, alternating scan direction per row via a toggle at this+0x1C8.
    // ASSIGNMENT: Load context: v4 = a1[105] (context pointer, this+0x1A4), v36 = *(v4+24) (palette grid pointer, this+0x1BC), v44 = *(v4+40) (channel offset table, this+0x1CC), v49 = a1[71] (palette base offset, this+0x11C). [field:this:0x000001A4, field:this:0x000001BC, field:this:0x000001CC, field:this:0x0000011C, source:raw]
    // ASSIGNMENT: Load palette channel tables: v6 = a1[29] (this+0x74) with v34 = v6[0], v7 = v6[1] (this+0x78) and v32 = v6[2] (this+0x7C); v5 = a1[23] (row pixel width, this+0x5C) drives the inner iteration. [field:this:0x00000074, field:this:0x00000078, field:this:0x0000007C, field:this:0x0000005C, source:raw]
    // LOOP: Outer loop over a4 rows: guard a4 > 0 via the initial result = a4; maintain the source row pointer v45 = a3 and reset the error accumulators at the start of each row. [source:raw]
    // STATE_TRANSITION: Scan-direction toggle at *(v4+36) (this+0x1C8): when set, switch to the reverse pass (v40 = -1, v52 = -3) and clear the toggle; otherwise use the forward pass (v40 = 1, v52 = 3) and set the toggle, so consecutive rows alternate direction. [field:this:0x000001C8, source:raw]
    // CALCULATION: Per pixel, derive three source component values (v15/v16/v54) via the channel offset table v44 (this+0x1CC) and palette base v49 (this+0x11C), index the palette grid v36 (this+0x1BC); when the grid cell is empty (0) call BitstreamTextureBlockCopy (0x0051DB31) to populate it. [field:this:0x000001BC, field:this:0x000001CC, field:this:0x0000011C, callee:0x0051DB31, source:raw]
    // CALCULATION: Write the chosen palette index into the destination pixel *v50 and compute the per-channel quantization error from the palette tables (v34/v7/v32 at this+0x74, this+0x78, this+0x7C), accumulating diffusion terms into the error buffer v12 (pointed to by this+0x1C4) channels 0/1/2. [field:this:0x00000074, field:this:0x00000078, field:this:0x0000007C, field:this:0x000001C4, field:*(this+0x1C4):0x00000000, field:*(this+0x1C4):0x00000002, field:*(this+0x1C4):0x00000004, source:raw]
    // LOOP: Inner loop over v38 pixels (this+0x5C), advancing the source/destination pointers v51/v50 and the error row v12 in the scan direction v52/v40 for each pixel. [field:this:0x0000005C, source:raw]
    // ASSIGNMENT: Flush the accumulated error into the row-tail error cells after each row: *v12 = v48 (channel 0), v12[1] = v47 (channel 1), v12[2] = v46 (channel 2). [field:*(this+0x1C4):0x00000000, field:*(this+0x1C4):0x00000002, field:*(this+0x1C4):0x00000004, source:raw]
    // RETURN: Return the last row's trailing error value v46 (16-bit) as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   ctx = a1[105];                      // context, this+0x1A4
    //   grid = *(ctx+24);                   // palette grid, this+0x1BC
    //   offtab = *(ctx+40);                 // channel offsets, this+0x1CC
    //   pbase = a1[71];                     // palette base, this+0x11C
    //   tbl = a1[29];                       // channel tables: tbl[0], tbl[1], tbl[2]
    //   width = a1[23];                     // row pixel width, this+0x5C
    //   result = a4;
    //   for (row = 0; row < a4; row++) {
    //     if (*(ctx+36)) { dir = -1; step = -3; *(ctx+36) = 0; }   // reverse pass
    //     else           { dir = 1;  step = 3;  *(ctx+36) = 1; }   // forward pass
    //     for (x = 0; x < width; x++) {
    //       c0 = src[row*width+x+0]; c1 = src[row*width+x+1]; c2 = src[row*width+x+2];
    //       cell = grid + ...;
    //       if (*cell == 0) BitstreamTextureBlockCopy(c1>>2, a1, c0>>3, c2>>3);
    //       idx = *cell - 1;
    //       dst_pixel = idx;
    //       err0 = c0 - tbl[0][idx]; err1 = c1 - tbl[1][idx]; err2 = c2 - tbl[2][idx];
    //       accumulate err0/err1/err2 into errbuf (this+0x1C4) channels 0/1/2 with diffusion terms;
    //     }
    //     flush errbuf[0] = e0; errbuf[1] = e1; errbuf[2] = e2;
    //   }
    //   return result;
    // UNRESOLVED: The context object behind a1[105] (this+0x1A4) is presented by the packet as this-relative fields (0x1BC, 0x1C4, 0x1C8, 0x1CC); whether those sub-offsets live in the same struct or a separate context object is unresolved.
    // UNRESOLVED: The exact palette-index-to-color transform and the error-diffusion weights are recovered only as arithmetic here; the intended visual algorithm (serpentine ordered dithering) is inferred.
    // UNRESOLVED: Which texture or plane this routine decompresses, and the meaning of the returned error value to the caller, are not proven.
}
