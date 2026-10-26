// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051C813
// Canonical corpus name: sub_51C813
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_51C813_0051c813.c

void UnknownObject::PackedPixelBlend()
{
    // MMX/SIMD loop that processes a1/4 groups of four packed 32-bit pixels read from three source buffers (a2, a3, a4). Each source pixel is byte-unpacked, bias-subtracted with qword_5D89E8, multiplied and accumulated against the QWORD coefficient globals qword_5D89F0, qword_5D89F8 and qword_5D8A00, arithmetic-shifted right by 8, packed to bytes (using qword_8B00C0 as a zero filler), masked with qword_5D8A08 and reassembled. Three DWORD composite results (12 bytes) are written to the destination a5 per group; all three source pointers advance one DWORD per group. Returns the advanced a2 pointer.
    // LOOP: Group loop: v8 = a1 >> 2 sets the number of 4-pixel groups; the do/while body runs once per group until v8 reaches zero. [source:raw]
    // CALCULATION: Load and unpack: byte-unpack each 32-bit source pixel from a2, a3 and a4 (punpcklbw against zero); the a3 and a4 channels are bias-subtracted with the packed bias constant qword_5D89E8 before the multiply-add stage. [global:0x005D89E8, source:raw]
    // CALCULATION: Weighted multiply-accumulate: interleaved low/high words of the unpacked a3/a4 channels are multiplied against the coefficient QWORDs qword_5D89F0, qword_5D89F8 and qword_5D8A00 (pmaddwd), combined with the shifted a2 channel and arithmetic-shifted right by 8 to yield scaled per-channel products. [global:0x005D89F0, global:0x005D89F8, global:0x005D8A00, source:raw]
    // CALCULATION: Pack and mask: the products are saturating-packed back to bytes (packssdw/packuswb), the zero constant qword_8B00C0 supplies the zero lanes, and the packed words are masked with qword_5D8A08 and shifted to assemble the final output bytes for each of the three DWORD results. [global:0x008B00C0, global:0x005D8A08, source:raw]
    // ASSIGNMENT: Output write: three DWORD results are stored to the destination a5 at a 12-byte stride per group (a5 += 12), and the source pointers a2, a3 and a4 each advance by one DWORD (++result, ++a4, ++a3). [source:raw]
    // RETURN: Returns the advanced a2 source pointer (result). [source:raw]

    // Conservative worker pseudocode:
    //   groups = a1 >> 2;
    //   do {
    //     src2 = unpack_bytes(*a2);
    //     src3 = unpack_bytes(*a3) - BIAS_QWORD_5D89E8;
    //     src4 = unpack_bytes(*a4) - BIAS_QWORD_5D89E8;
    //     prod = multiply_accumulate(src3, src4, src2, COEF_QWORDS_5D89F0_5D89F8_5D8A00);
    //     out = mask_pack_shift(prod, MASK_QWORD_5D8A08, ZERO_QWORD_8B00C0);
    //     *(dest + 0) = out.low_dword;
    //     *(dest + 4) = out.mid_dword;
    //     *(dest + 8) = out.high_dword;
    //     dest += 12; ++a2; ++a3; ++a4;
    //   } while (--groups);
    //   return a2;
    // UNRESOLVED: The exact per-channel transform (color-space conversion, alpha blend or generic 3x3 pixel matrix) is not determinable from the packet; the byte layout of the six QWORD constants is unknown.
    // UNRESOLVED: The single static caller is sub_51C94F; the role of this routine in the 2D pipeline is not evidenced beyond the caller edge.
}
