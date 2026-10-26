// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050AB51
// Canonical corpus name: sub_50AB51
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50AB51_0050ab51.c

void UnknownObject::YCbCrSurfaceCopyToFloatBuffer()
{
    // Copies a rectangular region from a packed 16-bit YCbCr source surface into a destination float buffer, expanding the dirty-rect bounds when the requested pixel lies outside them and, when the copy flag is set, converting each pair of YCbCr samples into two RGBA pixels (Y applied at 0.0045662099, chroma offsets at 128.0 and luma offset 16.0) with clamping to [0,1]. Returns an HRESULT-style error (-2147024882) when the surface is not initialized.
    // GUARD: Return error -2147024882 immediately when the surface state word (this+4240) is zero (surface not initialized). [field:this:0x00001090, source:raw]
    // GUARD: Dirty-rect containment check: the requested pixel (a2, a3) is considered inside when a2 is in [this+4212, this+4220) and a3 is in [this+4224, this+4228); only an out-of-rect request triggers the bounds update and (if a4 set) the copy. [field:this:0x00001074, field:this:0x0000107C, field:this:0x00001080, field:this:0x00001084, source:raw]
    // CALL: VertexColorPackRGBto16(this): flushes or repacks the surface state for the expanded region; when it returns a negative result that error is propagated. [callee:0x0050A92D, source:raw]
    // ASSIGNMENT: Expand the dirty-rect bounds to include (a2, a3): this+4220 = a2 + 1, this+4212 = a2, this+4224 = a3, this+4228 = a3 + 1. [field:this:0x00001074, field:this:0x0000107C, field:this:0x00001080, field:this:0x00001084, source:raw]
    // GUARD: When the copy flag a4 is non-zero, run the pixel-conversion loop; otherwise the function only performs the dirty-rect bookkeeping. [source:raw]
    // CALCULATION: Address the source and destination: source pixel pointer = this+24 + a3 * this+4180 + a2 * this+4176 + 2 * v6 (word offset into the packed surface), destination = this+4204 + i * 8 floats, with the starting offset v6 read from this+4208. [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, field:this:0x0000106C, field:this:0x00001070, source:raw]
    // LOOP: Iterate i from v6 (this+4208) while i < this+4216 (maximum element count), advancing i by 2 and the source/destination pointers by 2 words / 8 floats per iteration (two pixels per step). [field:this:0x00001070, field:this:0x00001078, source:raw]
    // CALCULATION: Extract YCbCr samples from the two 16-bit words v9 and v12 using byte shifts this+4244 (luma shift) and this+4248 (chroma shift), then subtract the black level 16.0 from luma and 128.0 from the chroma channels. [field:this:0x00001094, field:this:0x00001098, source:raw]
    // CALCULATION: Color-space conversion for the first pixel (coefficient globals): R = Y * 0.0045662099 + Cr * 0.0062589301, G = Y * 0.0045662099 - Cb * 0.00153632 - Cr * 0.00318811, B = Cb * 0.0079107098 + Y * 0.0045662099, alpha 1.0, each channel clamped to [0,1]. [global:0x0059E43C, global:0x0059E440, global:0x0059E6FC, global:0x0059EED0, global:0x005ADC38, source:raw]
    // ASSIGNMENT: Write the first pixel into the destination float buffer: v7[0..2] = clamped R/G/B, v7[3] = 1.0. [field:*(this+0x106C):0x00000000, field:*(this+0x106C):0x00000004, field:*(this+0x106C):0x00000008, field:*(this+0x106C):0x0000000C, source:raw]
    // CALCULATION: Color-space conversion for the second pixel using the same coefficient set and clamp: R = Y1 * 0.0045662099 + Cr * 0.0062589301, G = Y1 * 0.0045662099 - Cb * 0.00153632 - Cr * 0.00318811, B = Y1 * 0.0045662099 + Cb * 0.0079107098, alpha 1.0. [global:0x005ADC3C, global:0x005ADC40, global:0x005ADC44, global:0x005ADC48, source:raw]
    // ASSIGNMENT: Write the second pixel into the destination float buffer: v7[4..6] = clamped R/G/B, v7[7] = 1.0, then advance the source pointer by 2 words and the destination pointer by 8 floats. [field:*(this+0x106C):0x00000010, field:*(this+0x106C):0x00000014, field:*(this+0x106C):0x00000018, field:*(this+0x106C):0x0000001C, source:raw]
    // RETURN: Return 0 on success. [source:raw]

    // Conservative worker pseudocode:
    //   if (!*(this + 4240)) return -2147024882;
    //   if (a2 < *(this+4212) || a2 >= *(this+4220) || a3 < *(this+4224) || a3 >= *(this+4228)) {
    //       result = VertexColorPackRGBto16(this);
    //       if (result < 0) return result;
    //       *(this+4220) = a2 + 1; *(this+4212) = a2;
    //       *(this+4224) = a3; *(this+4228) = a3 + 1;
    //       if (a4) {
    //           i = *(this+4208);
    //           dst = *(this+4204);
    //           src = *(this+24) + a3 * *(this+4180) + a2 * *(this+4176) + 2 * i;
    //           for (; i < *(this+4216); i += 2, src += 2, dst += 8) {
    //               y0 = (src[0] >> *(this+4244)) - 16.0;
    //               cb = (src[0] >> *(this+4248)) - 128.0;
    //               y1 = (src[1] >> *(this+4244)) - 16.0;
    //               cr = (src[1] >> *(this+4248)) - 128.0;
    //               dst[0] = clamp(y0 * 0.0045662099 + cr * 0.0062589301);
    //               dst[1] = clamp(y0 * 0.0045662099 - cb * 0.00153632 - cr * 0.00318811);
    //               dst[2] = clamp(cb * 0.0079107098 + y0 * 0.0045662099);
    //               dst[3] = 1.0;
    //               dst[4] = clamp(y1 * 0.0045662099 + cr * 0.0062589301);
    //               dst[5] = clamp(y1 * 0.0045662099 - cb * 0.00153632 - cr * 0.00318811);
    //               dst[6] = clamp(y1 * 0.0045662099 + cb * 0.0079107098);
    //               dst[7] = 1.0;
    //           }
    //       }
    //   }
    //   return 0;
    // UNRESOLVED: The exact mapping of the nine float globals (0x0059E43C, 0x0059E440, 0x0059E6FC, 0x0059EED0, 0x005ADC38, 0x005ADC3C, 0x005ADC40, 0x005ADC44, 0x005ADC48) to the coefficient literals in the raw source is not established by the packet; the conversion-matrix reading follows the fill.
    // UNRESOLVED: The 16-bit packed sample interpretation (two YCbCr 4:2:2 pixels per 4 bytes, luma/chroma split via the shift fields this+4244 and this+4248) is DERIVED from the fill and the raw arithmetic, not independently evidenced.
    // UNRESOLVED: The purpose of the copy flag a4 (assumed to gate the pixel loop) and the meaning of the -2147024882 error constant (an HRESULT-style code) are interpretations, not packet-confirmed.
    // UNRESOLVED: The callers CopyTextureSurface (0x0050AEAE) and InputDeviceDataRead (0x0050AF57) provide the only static call context; the enclosing object type is UnknownObject.
}
