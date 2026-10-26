// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00528CC0
// Canonical corpus name: sub_528CC0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_528CC0_00528cc0.c

void UnknownObject::ColorSpaceDecodeSSE2()
{
    // SSE2 packed decode of 4-lane color data into two output __m128 vectors a2 and a3. Masks the packed input at this+0x0 with 0x005D9280, applies an affine transform (multiply by 0x005D9260, add offset 0x005D9210), computes a residual v5 = transformed minus offset, subtracts the residual scaled by the four coefficients 0x005D9250/0x005D9240/0x005D9230/0x005D9220 to form v6, squares v6 into v7, evaluates two Horner-scheme polynomials of v7 (branch A: 0x005D9200/0x005D91B0/0x005D9190/0x005D9170; branch B: 0x005D91F0/0x005D91A0/0x005D9180/0x005D9160 plus final add 0x005D9150), extracts integer bit fields with masks 0x005D91E0/0x005D91D0/0x005D91C0 and a 0x1E-bit shift to build a selection mask, conditionally blends the two polynomial results, XORs in carry-derived bits and input bits masked by 0x005D9270, and stores the complementary pair into a2 and a3. Returns a2.
    // CALCULATION: Mask the packed input lanes loaded from this+0x0 (a1[0]) with the bit mask at 0x005D9280 to isolate the encoded channel fields. [field:this:0x00000000, global:0x005D9280, source:raw]
    // CALCULATION: Affine transform: multiply the masked input by 0x005D9260, add offset 0x005D9210 to form v4, then compute residual v5 = v4 minus offset 0x005D9210. [global:0x005D9260, global:0x005D9210, source:raw]
    // CALCULATION: Residual correction: subtract v5 scaled by coefficients 0x005D9250, 0x005D9240, 0x005D9230 and 0x005D9220 from the masked input to form v6, then square v6 into v7. [global:0x005D9250, global:0x005D9240, global:0x005D9230, global:0x005D9220, source:raw]
    // CALCULATION: Bit-field extraction: isolate v8 = v4 & 0x005D91E0, high bits v9 = v8 & 0x005D91D0, difference v10 = v8 - v9, combine with the carry mask 0x005D91C0, left-shift selected fields by 0x1E and build the non-zero comparison mask v12 used for branch selection. [global:0x005D91E0, global:0x005D91D0, global:0x005D91C0, source:raw]
    // CALCULATION: Evaluate polynomial branch A (v13) over v7 with coefficients 0x005D9200, 0x005D91B0, 0x005D9190 and 0x005D9170, scaled by v6. [global:0x005D9200, global:0x005D91B0, global:0x005D9190, global:0x005D9170, source:raw]
    // CALCULATION: Evaluate polynomial branch B (v14) over v7 with coefficients 0x005D91F0, 0x005D91A0, 0x005D9180 and 0x005D9160, plus final additive constant 0x005D9150. [global:0x005D91F0, global:0x005D91A0, global:0x005D9180, global:0x005D9160, global:0x005D9150, source:raw]
    // ASSIGNMENT: Select between the two branch results with the v12 mask (ANDNOT/AND blend), XOR the result with the carry-shifted field (mask 0x005D91C0) and with the input bits masked by 0x005D9270, and store into output vector a2. [global:0x005D9270, global:0x005D91C0, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the complement (mask inverted) of the two branch results, XORed with the carry-derived vector v11, into output vector a3. [global:0x005D91C0, field:this:0x00000000, source:raw]
    // RETURN: Return the output pointer a2 as the function result. [function:0x00528CC0, source:raw]

    // Conservative worker pseudocode:
    //   v3 = a1[0] & xmmword_5D9280;
    //   v4 = v3 * xmmword_5D9260 + xmmword_5D9210;
    //   v5 = v4 - xmmword_5D9210;
    //   v6 = v3 - (xmmword_5D9250 + xmmword_5D9240 + xmmword_5D9230 + xmmword_5D9220) * v5;
    //   v7 = v6 * v6;
    //   v8 = v4 & xmmword_5D91E0;  v9 = v8 & xmmword_5D91D0;  v10 = v8 - v9;
    //   v12 = (v9 << 0x1E) != 0;
    //   v13 = ((((xmmword_5D9200 * v7 + xmmword_5D91B0) * v7 + xmmword_5D9190) * v7 + xmmword_5D9170) * v6;
    //   v14 = ((((xmmword_5D91F0 * v7 + xmmword_5D91A0) * v7 + xmmword_5D9180) * v7 + xmmword_5D9160) * v7 + xmmword_5D9150;
    //   *a2 = ((v12 & v14) | (~v12 & v13)) ^ ((v10 & xmmword_5D91C0) << 0x1E) ^ (a1[0] & xmmword_5D9270);
    //   *a3 = ((v12 & v13) | (~v12 & v14)) ^ v11;
    //   return a2;
    // UNRESOLVED: The 20 xmmword coefficient globals 0x005D9150..0x005D9280 carry only prose names (color-space transform coefficients); their numeric contents and exact roles are DERIVED, not verified.
    // UNRESOLVED: This function is called from SSEQuaternionCompositionFromAxisAngleComponents (0x00520E0E); whether a1/a2/a3 hold color data or a different packed representation is not grounded here.
    // UNRESOLVED: The bit layout of the two output vectors (which lane maps to which channel) is not derivable from the raw source.
}
