// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00509644
// Canonical corpus name: TextureByteToFloatConverter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureByteToFloatConverter_00509644.c

void UnknownObject::TextureByteToFloatConverter()
{
    // Converts packed 24-bit RGB byte texture data (3 bytes per pixel) to 32-bit float RGBA, writing alpha as the constant 1.0 and scaling each byte channel by 0.0039215689 (the packet-listed global flt_59E460 folded to a literal). The source run is selected from field +0x18 using the pitch in +0x1050 and slice stride in +0x1054; the loop iterates over the byte span given by field +0x1064. When field +0x10 is non-zero, the decoded output start (recovered via field +0x1058) is passed to ContactManifoldCleanup for post-processing.
    // CALCULATION: Compute the source base pointer v4 = this[6] (field +0x18) + a3 * this[1045] (field +0x1054) + a2 * this[1044] (field +0x1050), selecting the RGB run for tile (a2, a3). [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: for loop from v4 while v4 < v4 + this[1049] (field +0x1064), advancing 3 source bytes per sample. [field:this:0x00001064, source:raw]
    // CALCULATION: Convert the B, G and R byte channels to floats with the scale global flt_59E460 (folded literal 0.0039215689) and store them in the float output, advancing 4 floats per pixel. [global:0x0059E460, source:raw]
    // ASSIGNMENT: Write the constant alpha 1.0 to the fourth float of every output pixel via the loop increment expression. [source:raw]
    // GUARD: Guard on this[4] (field +0x10): when non-zero a post-processing pass runs on the decoded buffer. [field:this:0x00000010, source:raw]
    // CALL: Call ContactManifoldCleanup(this, &a4[-4 * this[1046]]); recovers the output buffer start using field +0x1058. [callee:0x00507845, field:this:0x00001058, source:raw]

    // Conservative worker pseudocode:
    //   void sub_509644(void *this, int a2, int a3, float *a4) {
    //     unsigned __int8 *v4 = (unsigned __int8*)(this[6] + a3 * this[1045] + a2 * this[1044]);
    //     for (unsigned __int8 *i = &v4[this[1049]]; v4 < i; *(a4 - 1) = 1.0f) {
    //       *a4     = v4[2] * 0.0039215689f;  // B
    //       *(a4+1) = v4[1] * 0.0039215689f;  // G
    //       *(a4+2) = v4[0] * 0.0039215689f;  // R
    //       v4 += 3; a4 += 4;
    //     }
    //     if (this[4]) ContactManifoldCleanup((int)this, (unsigned int)&a4[-4 * this[1046]]);
    //   }
    // UNRESOLVED: The callee ContactManifoldCleanup (0x00507845) name is domain-mismatched for a texture decoder; it likely post-processes the decoded float buffer.
    // UNRESOLVED: The global flt_59E460 is labeled AlphaScaleFactor in the analysis but here scales the RGB channels while alpha is the literal 1.0.
    // UNRESOLVED: Field +0x1058 is used only to recover the buffer start for post-processing; its pixel-count label is analysis-derived.
    // UNRESOLVED: Field +0x1064 (loop bound) semantics as byte count vs pixel count is not resolved.
}
