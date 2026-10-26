// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050A3CE
// Canonical corpus name: VertexTextureDecoder1010102
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VertexTextureDecoder1010102_0050a3ce.c

void UnknownObject::VertexTextureDecoder1010102()
{
    // RGB10A2-style signed packed-texture vertex decoder. Computes a source texel pointer from this+0x18 plus this+0x1050 (row) and this+0x1054 (slice) pitch products with the two index arguments, then loops over this+0x1058 texels. Each packed 32-bit texel is sign-extended into three 10-bit channels (alpha bits [30:21], first channel bits [9:0], second channel bits [19:10]) via arithmetic-shift tricks, scaled by constants 0.001953125 (2^-9) and 0.0009765625 (2^-10), and written as four floats (three channels plus a constant 1.0). When the this+0x10 flag is non-zero, ContactManifoldCleanup is called on the decoded float output.
    // CALCULATION: Compute source texel pointer v4 = this+0x18 + a3 * this+0x1054 + a2 * this+0x1050 (slice and row pitch products with the index arguments). [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: For-loop iterating over this+0x1058 packed 32-bit texels from v4 up to v4 + this+0x1058; each iteration consumes one dword and emits one 4-float RGBA texel. [field:this:0x00001058, source:raw]
    // CALCULATION: Sign-extend alpha channel: v7 = (__int16)(32 * (*v4 >> 21)) >> 5, recovering a signed 10-bit value from bits [30:21]. [source:raw]
    // CALCULATION: Sign-extend first color channel: v8 = (double)((__int16)(*(_WORD *)v4 << 6) >> 6), recovering a signed 10-bit value from bits [9:0]. [source:raw]
    // CALCULATION: Sign-extend second color channel: v9 = (__int16)(32 * (*v4 >> 10)) >> 5, recovering a signed 10-bit value from bits [19:10]. [source:raw]
    // ASSIGNMENT: Write four output floats per texel: a4[0] = v8 * 0.001953125, a4[1] = v9 * 0.0009765625, a4[2] = v7 * 0.0009765625, a4[3] = 1.0 (alpha set via the loop increment). The scale factors correspond to the two read-only globals flt_59E4D8 and flt_5ACF38. [global:0x0059E4D8, global:0x005ACF38, source:raw]
    // GUARD: Guard: if this+0x10 is non-zero, post-process the decoded float output. [field:this:0x00000010]
    // CALL: Call ContactManifoldCleanup((int)this, &a4[-4 * this+0x1058]) on the decoded float RGBA output buffer start. [callee:0x00507845, field:this:0x00001058, source:raw]

    // Conservative worker pseudocode:
    //   void VertexTextureDecoder1010102(_DWORD *this, int a2, int a3, float *a4) {
    //     v4 = (_DWORD*)(this[0x18/4] + a3 * this[0x1054/4] + a2 * this[0x1050/4]);
    //     for (i = &v4[this[0x1058/4]]; v4 < i; *(a4 - 1) = 1.0f) {
    //       alpha  = (__int16)(32 * (*v4 >> 21)) >> 5;
    //       ch0    = (__int16)(*(_WORD*)v4 << 6) >> 6;
    //       ch1    = (__int16)(32 * (*v4++ >> 10)) >> 5;
    //       a4[0]  = (float)(ch0 * 0.001953125);
    //       a4 += 4;
    //       a4[-3] = (float)(ch1 * 0.0009765625);
    //       a4[-2] = (float)(alpha * 0.0009765625);
    //     }
    //     if (this[0x10/4])
    //       ContactManifoldCleanup((int)this, &a4[-4 * this[0x1058/4]]);
    //   }
    // UNRESOLVED: The role of ContactManifoldCleanup (0x00507845) on a decoded texture/vertex float buffer is unclear; the name originates from a different subsystem and the semantic purpose (edge fix / blend / state reset) is not provable from this packet.
    // UNRESOLVED: Which of flt_59E4D8 and flt_5ACF38 backs which of the two scale literals (0.001953125 vs 0.0009765625) is not provable from the packet; the raw source shows the constants as float literals.
    // UNRESOLVED: The exact physical meaning of the three 10-bit channels (color order vs position) depends on the shader/vertex format contract, which is not in this packet.
}
