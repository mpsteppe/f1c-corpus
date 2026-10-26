// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00503772
// Canonical corpus name: sub_503772
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_503772_00503772.c

void UnknownObject::MMXImageBlend()
{
    // MMX-vectorized variant of the 2x2 box-average image compositor. When the row width a3 is not divisible by 4 it dispatches to the scalar ImageBlendingCompositing (0x00503533); otherwise it processes one source row pair (rows separated by stride a5) in packed-word arithmetic, sums the four 16-bit channel words with rounding offset constant 0x2000200020002, shifts right by 2 (divide by 4), and stores unsigned-saturated bytes, advancing 8 source bytes per output element.
    // GUARD: Alignment guard: when (a3 & 3) != 0 the row byte width is not dword-aligned, so take the scalar fallback path. [source:raw]
    // CALL: On the misaligned path, call ImageBlendingCompositing (0x00503533) with the full argument set (a1, a2, a3, a4, a5, a6). [callee:0x00503533, source:raw]
    // RETURN: Return the result produced by the scalar fallback call. [source:raw]
    // STATE_TRANSITION: Emit EMMS via _m_empty() to clear the MMX state before the packed-word pass. [source:raw]
    // CALCULATION: Precompute the row-pair range end v20 = a2 + a5*a4 and the row byte width v21 = 4*a3. [source:raw]
    // LOOP: Outer loop over output rows while the source position a2 stays below v20; each pass processes one source row pair (cursor v7 at row r and v10 at row r + a5). [source:raw]
    // LOOP: Inner loop advancing 8 bytes (one __m64) per iteration on both the source and destination cursors while the source column stays below the row end v11. [source:raw]
    // CALCULATION: Load __m64 pixels from both rows of the pair and byte-unpack each row into words with _m_punpcklbw/_m_punpckhbw; accumulate the four words with the rounding offset constant 0x2000200020002 via _m_paddw, then _m_psrawi(..., 2) to divide each channel by 4. [source:raw]
    // CALCULATION: Re-pack the averaged word channels with _m_packuswb into unsigned-saturated bytes, clamping each output byte into the 0..255 range. [source:raw]
    // ASSIGNMENT: Store the packed __m64 result to the destination cursor v17. [source:raw]

    // Conservative worker pseudocode:
    //   int MMXImageBlend(unsigned int* dst, unsigned int src, int a3, int a4, int a5, int a6) {
    //     if ((a3 & 3) != 0) return ImageBlendingCompositing(dst, src, a3, a4, a5, a6);
    //     int end = src + a5 * a4;
    //     _m_empty();
    //     while ((int)src < end) {
    //       for (p = src, out = dst; p < src + 4 * a3; p += 8, out += 8) {
    //         /* 2x2 average over row pair, packed words, rounding 0x2000200020002, psraw 2, packuswb * /
    //         *(unsigned __int64*)out = _m_packuswb(_m_psrawi(sum4(p, p + a5), 2));
    //       }
    //       src += 2 * a5;
    //       dst = (unsigned int*)((char*)dst + a6);
    //     }
    //   }
    // UNRESOLVED: The raw source line is truncated, so the tail of the MMX pass is not visible; whether the aligned path returns a value or falls through at function end is not evidenced here.
    // UNRESOLVED: The exact tap ordering of the v9/v10 row-pair loads (which 8-byte window is current vs neighbour) is only partially visible in the truncated source; the 2x2 average semantics match the scalar ImageBlendingCompositing but the precise gather is DERIVED.
    // UNRESOLVED: As with the scalar variant, the identity of the source and destination image surfaces is not evidenced in this packet.
}
