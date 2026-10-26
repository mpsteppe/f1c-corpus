// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005976E8
// Canonical corpus name: sub_5976E8
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5976E8_005976e8.c

void UnknownObject::FloatToStringFormatBCD()
{
    // Formats a double (passed as a1:hi/lo) into a fixed-width decimal string buffer using 96-bit packed BCD arithmetic. Sets the sign byte (buffer+2) to 32 or 45 from the exponent sign bit a2&0x8000. Handles special values: zero exponent and mantissa produces "0" output; exponent 0x7FFF routes to NaN/Inf/Ind/SNaN handling via sub_58FCA0 with buffer+3 set to 5 or 6. Normal path decodes the mantissa/exponent through BitPackedDataDecodeViaLookupTable into a 96-bit BCD working value, conditionally normalises via sub_597AA0 when the exponent reaches 0x3FFF, shifts left/right for scale, generates up to 21 ASCII digits by repeated 96-bit shifts and CRTAdd12, and applies rounding/trimming on the last digit. Returns 1 on success.
    // ASSIGNMENT: Seed the working BCD buffer v23 (10 bytes of 204 then -5, 63) and set v25=1; extract sign bit v6 = a2 & 0x8000 and exponent field v7 = a2 & 0x7FFF. [source:raw]
    // GUARD: Branch on sign bit: write 32 (space) to buffer+2 when clear, 45 (minus) when set. [source:raw]
    // GUARD: When exponent v7 is zero and mantissa a1 is zero, jump to the zero-output path (buffer+2=32, buffer+3=1, buffer+4='0', buffer+5=0, return 1). [source:raw]
    // GUARD: When exponent v7 == 0x7FFF, handle special values: write 1 to buffer+0 and classify via the high dword (sign/mantissa bits); negative NaN, Ind and SNaN cases route to sub_58FCA0 with buffer+3 set to 5, otherwise sub_58FCA0 with buffer+3 set to 6; return 0. [callee:0x0058FCA0, source:raw]
    // ASSIGNMENT: Pack the 96-bit decode input: v24 word0 = 0, word at +10 = exponent v7, qword at +2 = mantissa a1; compute initial scale v9 from exponent/mantissa bytes. [source:raw]
    // CALL: Decode the bit-packed double into the 96-bit BCD working value via BitPackedDataDecodeViaLookupTable with exponent adjustment -v9. [callee:0x00597CC0, source:raw]
    // GUARD: When the decoded exponent at v24+10 reaches 0x3FFF, bump the scale and normalise the working value via sub_597AA0. [callee:0x00597AA0, source:raw]
    // CALCULATION: Write the scale to buffer+0 as a word; when flag a4&1 is clear use a3 directly as the digit count, otherwise use a3 + scale (clamped to at most 21). [source:raw]
    // CALCULATION: Compute a shift count from the decoded exponent at v24+10 minus 16382, zero the exponent word, left-shift the 96-bit value 8 times, then right-shift by the (possibly negative) adjustment via F_96BitLeftShiftBy1 and F_96BitRightShift. [callee:0x005975C6, callee:0x005975F4, source:raw]
    // LOOP: Digit generation loop over v11+1 iterations: double the 96-bit value twice, accumulate via CRTAdd12, then store the leading byte plus 48 ('0') into the buffer. [callee:0x005975C6, callee:0x00597568, source:raw]
    // STATE_TRANSITION: Rounding/trimming: when the last generated digit is below 53, trim trailing '0's (or fall to the zero path); otherwise propagate a carry, incrementing the scale at buffer+0 and setting buffer+3 from the final pointer offset, then NUL-terminate the string at buffer+4. [source:raw]
    // RETURN: Return v25 (1) on the successful format path, 0 on the special-value path. [source:raw]

    // Conservative worker pseudocode:
    //   int FloatToStringFormatBCD(__int64 a1, int a2, int a3, char a4, int a5) {
    //     _BYTE v23[12], v24[12]; int v25 = 1;
    //     __int16 v6 = a2 & 0x8000; unsigned __int16 v7 = a2 & 0x7FFF;
    //     memset(v23, 204, 10); v23[10] = -5; v23[11] = 63;
    //     *(_BYTE*)(a5 + 2) = (a2 & 0x8000) ? 45 : 32;
    //     if (!v7 && !a1) {
    //       *(_WORD*)a5 = 0; *(_BYTE*)(a5 + 2) = 32; *(_BYTE*)(a5 + 3) = 1;
    //       *(_BYTE*)(a5 + 4) = 48; *(_BYTE*)(a5 + 5) = 0; return 1;
    //     }
    //     if (v7 == 0x7FFF) {
    //       *(_WORD*)a5 = 1;
    //       int special = 6;
    //       if ((HIDWORD(a1) == 0x80000000 && !(_DWORD)a1) || (HIDWORD(a1) & 0x40000000)) special = 5;
    //       sub_58FCA0(); *(_BYTE*)(a5 + 3) = special; return 0;
    //     }
    //     *(_WORD*)v24 = 0; *(_WORD*)&v24[10] = v7; *(_QWORD*)&v24[2] = a1;
    //     int v9 = (77 * (HIBYTE(v7) + 2 * HIBYTE(HIDWORD(a1))) + 19728 * v7 - 323162868) >> 16;
    //     BitPackedDataDecodeViaLookupTable(v24, -(__int16)v9, 1);
    //     if (*(_WORD*)&v24[10] >= 0x3FFF) { LOWORD(v9) = v9 + 1; sub_597AA0(v24, v23); }
    //     *(_WORD*)a5 = v9;
    //     int v11 = (a4 & 1) ? (__int16)v9 + a3 : a3;
    //     if (v11 > 0) {
    //       if (v11 > 21) v11 = 21;
    //       int v12 = *(unsigned __int16*)&v24[10] - 16382; *(_WORD*)&v24[10] = 0;
    //       for (int n = 8; n; --n) F_96BitLeftShiftBy1(v24);
    //       for (int i = (unsigned char)-(char)v12; v12 < 0 && i; --i) F_96BitRightShift((int*)v24);
    //       _BYTE* p = (_BYTE*)(a5 + 4);
    //       for (int c = v11 + 1; c; --c) {
    //         __int64 w = *(_QWORD*)v24; int w2 = *(_DWORD*)&v24[8];
    //         F_96BitLeftShiftBy1(v24); F_96BitLeftShiftBy1(v24);
    //         CRTAdd12((unsigned int*)v24, (unsigned int*)&w);
    //         F_96BitLeftShiftBy1(v24);
    //         _BYTE d = v24[11]; v24[11] = 0; *p++ = d + 48;
    //       }
    //       if (*(_BYTE*)(p - 1) < 53) {
    //         _BYTE* q = p - 2;
    //         while (q >= (_BYTE*)(a5 + 4)) { if (*q != 48) break; --q; }
    //         *(_WORD*)a5 = 0; *(_BYTE*)(a5 + 2) = 32; *(_BYTE*)(a5 + 3) = 1;
    //         *(_BYTE*)(a5 + 4) = 48; *(_BYTE*)(a5 + 5) = 0; return 1;
    //       }
    //       _BYTE* q = p - 2;
    //       while (q >= (_BYTE*)(a5 + 4)) { if (*q != 57) break; *q-- = 48; }
    //       ++q; ++*(_WORD*)a5; ++*q;
    //       _BYTE v21 = (_BYTE)q - a5 - 3;
    //       *(_BYTE*)(a5 + 3) = v21; *(_BYTE*)(v21 + a5 + 4) = 0;
    //     } else {
    //       *(_WORD*)a5 = 0; *(_BYTE*)(a5 + 2) = 32; *(_BYTE*)(a5 + 3) = 1;
    //       *(_BYTE*)(a5 + 4) = 48; *(_BYTE*)(a5 + 5) = 0;
    //     }
    //     return v25;
    //   }
    // UNRESOLVED: Special-string outputs for NaN/Inf/Ind/SNaN come from globals a1Qnan, a1Inf, a1Ind, a1Snan but their selection is implemented inside sub_58FCA0, which is not evidenced here.
    // UNRESOLVED: The exact CRT/LocaleAwareStringFormat contract for the buffer at a5 (length/format expectations) is not evidenced in this function.
    // UNRESOLVED: The BCD normalisation performed by sub_597AA0 and the decode performed by BitPackedDataDecodeViaLookupTable have no evidenced internal details here.
    // UNRESOLVED: The caller LocaleAwareStringFormat (0x00595621) passes a3/a4/a5 whose concrete meanings (precision, flags, output buffer) are only inferred.
}
