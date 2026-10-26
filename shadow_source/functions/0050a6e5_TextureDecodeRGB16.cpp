// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050A6E5
// Canonical corpus name: TextureDecodeRGB16
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureDecodeRGB16_0050a6e5.c

void UnknownObject::TextureDecodeRGB16()
{
    // Decodes 64-bit packed RGBA texture data (four uint16 channels per pixel) into float RGBA. Computes a source pointer from offset 0x18 plus slice/row strides at 0x1050/0x1054, then loops two DWORDs per pixel (this[0x1058] pixels) extracting the four 16-bit channels, scaling each by 0.000015259022, with the first channel decoded via sub_58A870. Writes four floats per output element. When the flag at 0x10 is non-zero, runs ContactManifoldCleanup over the decoded buffer.
    // CALCULATION: Compute the source pixel pointer v5 = (DWORD*)(a1[0x18] + a4 * a1[0x1054] + a3 * a1[0x1050]), indexing a row (a3) and slice (a4) into the source data pointer at offset 0x18 using the slice stride 0x1054 and row stride 0x1050. [source:raw, field:this:0x00000018, field:this:0x00001050, field:this:0x00001054]
    // LOOP: Iterate v5 from start to v8 = &v5[2 * a1[0x1058]], stepping two DWORDs (four uint16 channels) per pixel for the count at offset 0x1058. [source:raw, field:this:0x00001058]
    // CALL: Call sub_58A870 with the low byte of its first argument set to 32, passing the v5[1] word, to produce the first float channel value (unsigned 16-bit result scaled by 0.000015259022). [callee:0x0058A870, source:raw]
    // CALCULATION: Extract the remaining three 16-bit channels (HIWORD of v5[1], HIWORD of *v5, LOWORD of *v5) and scale each by 0.000015259022. [source:raw]
    // ASSIGNMENT: Write float RGBA for the pixel (four scaled channels) into a5, advancing a5 by 4 floats per pixel. [source:raw]
    // GUARD: Guard on a1[4] (flag at offset 0x10) after the loop restores the original a1 pointer (v7): if non-zero, run the post-process step over the decoded output buffer. [source:raw, field:this:0x00000010]
    // CALL: Call ContactManifoldCleanup(a1, buffer-start) where buffer-start is a5 backed up by 4 * a1[0x1058] floats, as the conditional post-process over the decoded RGBA buffer. [callee:0x00507845, source:raw]

    // Conservative worker pseudocode:
    //   void DecodeRGB16(DWORD* a1, int a2, int a3, int a4, float* a5) {
    //     DWORD* v5 = (DWORD*)(a1[6] + a4 * a1[1045] + a3 * a1[1044]);
    //     DWORD* v7 = a1;
    //     DWORD* v8 = &v5[2 * a1[1046]];
    //     if (v5 < v8) {
    //       do {
    //         a1_scratch_lobyte = 32;
    //         a5[0] = (double)(WORD)sub_58A870(a1_scratch, v5[1]) * 0.000015259022;
    //         a5[1] = (double)(WORD)HIWORD(v5[1]) * 0.000015259022;
    //         a5[2] = (double)(WORD)v5[0] * 0.000015259022;
    //         a5[3] = (double)(WORD)(v5[1]) * 0.000015259022;
    //         v5 += 2; a5 += 4;
    //       } while (v5 < v8);
    //       a1 = v7;
    //     }
    //     if (a1[4]) ContactManifoldCleanup((int)a1, (unsigned int)(a5 - 4 * a1[1046]));
    //   }
    // UNRESOLVED: The packet's global list names two read floats (flt_5AD290, flt_5ADB14); whether they feed the inlined 0.000015259022 scale or the sub_58A870 decode is not verifiable from this function's raw source.
    // UNRESOLVED: sub_58A870's purpose (channel decode / gamma lookup) is a DERIVED usage inference; its contract is unknown here.
    // UNRESOLVED: The decompiler reuses parameter a1 as scratch inside the loop (low byte = 32 for sub_58A870, then HIWORD of v5[1]); the original pointer is restored via v7 before the post-process check.
    // UNRESOLVED: ContactManifoldCleanup post-process semantics (what the flag at 0x10 selects) are not established here.
    // UNRESOLVED: The uint16 channel ordering within the packed DWORD pair is inferred from the raw source, not from an external format contract.
}
