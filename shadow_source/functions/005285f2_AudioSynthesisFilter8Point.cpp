// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005285F2
// Canonical corpus name: AudioMixing
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioMixing_005285f2.c

void UnknownObject::AudioSynthesisFilter8Point()
{
    // 8-point inverse synthesis filter bank (MDCT-style) for audio decoding. Loop 1 iterates 8 times reading input samples a3[0..56] at stride 8, applies window/rotation math and writes 8 floats into a stack buffer; if all 8 inputs are zero it short-circuits and copies the DC product a3[0]*v6[0] to all 8 outputs. Loop 2 iterates 8 times, combines the 8 transformed samples, and writes 8 interleaved bytes into the output buffer a5 using a byte lookup indexed from a4 and base a1+0x11C+128, converting float to int via CRTFtol. Returns the last byte written. The ABI lead names it Audio_Mixing_8_point_Inverse_MDCT.
    // CALCULATION: v36 = *(DWORD*)(a1 + 0x11C) + 128: compute the base index used for the final output byte lookup. [field:this:0x0000011C, source:raw]
    // LOOP: First loop, 8 iterations (counter v34 = 8): step v6 over the window-coefficient buffer (a2+0x50), step a3 over the 8 input samples, and write 8 float results into the v7 stack buffer. [source:raw]
    // GUARD: Zero-sample short circuit: if the OR of all 8 input samples a3[0..56] is zero, skip the transform and copy the DC product a3[0]*v6[0] to all 8 output slots. [source:raw]
    // CALCULATION: Full synthesis path: combine the 8 windowed samples using the inline rotation constants 1.4142135, 1.847759, 2.613126 and 1.0823922 into the 8 output slots; the packet's fact table flags four read-only float globals (flt_5ACEA4, flt_5B0818, flt_5B081C, flt_5B0820) as read by this function. [global:0x005ACEA4, global:0x005B0818, global:0x005B081C, global:0x005B0820, source:raw]
    // LOOP: Second loop, 8 iterations: combine the 8 transformed samples (v25 buffer) and for each output byte index write the looked-up byte value into a5 at a5 + *(DWORD*)(a4 + 4*index). [source:raw]
    // CALL: CRTFtol converts the float rotation constant 1.4142135 to int; the (value + 4) >> 3 & 0x3FF expression forms a constant byte-lookup offset added to v36 for each output byte. [callee:0x00587BDC, source:raw]
    // RETURN: Return the last byte written into the output buffer. [function:0x005285F2, source:raw]

    // Conservative worker pseudocode:
    //   v36 = *(DWORD*)(a1 + 0x11C) + 128;
    //   v6 = *(float**)(a2 + 80);
    //   for (i = 0; i < 8; i++) {
    //     if (a3[0]|a3[8]|a3[16]|a3[24]|a3[32]|a3[40]|a3[48]|a3[56]) {
    //       // full 8-point synthesis: window multiply + rotation constants; write out[0..7]
    //     } else {
    //       out[0..7] = a3[0]*v6[0]; // DC short-circuit
    //     }
    //     v6++; a3++; }
    //   for (i = 0; i < 8; i++) {
    //     // combine 8 floats; for 8 sub-slots write lookup byte at a5 + a4[i]
    //   }
    // UNRESOLVED: The four read-only float globals (flt_5ACEA4, flt_5B0818, flt_5B081C, flt_5B0820) are flagged by the packet but do not appear by name in the raw decompiled source (constants render inline); the exact mapping of each global to each rotation constant is not established.
    // UNRESOLVED: The window-coefficient buffer at a2+0x50 and the object identity of a2 are unconfirmed.
    // UNRESOLVED: The byte-lookup at v36 + ((ftol(1.4142135)+4)>>3 & 0x3FF) is a constant-index table read; the meaning of the table and the 0x11C offset are unconfirmed.
    // UNRESOLVED: Owner object is not established; the ABI lead Audio_Mixing_8_point_Inverse_MDCT is a LEGACY label.
}
