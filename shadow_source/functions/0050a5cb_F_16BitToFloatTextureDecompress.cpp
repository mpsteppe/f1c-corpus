// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050A5CB
// Canonical corpus name: F_16BitToFloatTextureDecompress
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_16BitToFloatTextureDecompress_0050a5cb.c

void UnknownObject::F_16BitToFloatTextureDecompress()
{
    // 16-bit luminance-plus-alpha texture decompressor. Computes a source dword pointer from this+0x18 plus this+0x1050 (row) and this+0x1054 (slice) pitch products with the two index arguments, then loops over this+0x1058 texels. Each texel consumes two consecutive uint16 words: the current word drives RGB (all three output channels equal, scaled by 0.000015259022 ~ 2^-16) and the previously-consumed word drives the alpha channel with the same scale. Writes 4-float RGBA output. When the this+0x10 flag is non-zero, ContactManifoldCleanup is called on the decoded float output.
    // CALCULATION: Compute source dword pointer v4 = this+0x18 + a3 * this+0x1054 + a2 * this+0x1050 (slice and row pitch products with the index arguments). [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: For-loop iterating over this+0x1058 texels from v4 up to v4 + this+0x1058; each iteration consumes one dword (two uint16 words) and emits one 4-float RGBA texel. [field:this:0x00001058, source:raw]
    // CALCULATION: v7 = (double)(unsigned __int16)*v4 * 0.000015259022; the current uint16 word is the luminance sample scaled to float. [source:raw]
    // ASSIGNMENT: Write RGB channels from the luminance sample: a4[2] = a4[1] = *a4 = v7, then advance the output pointer by 4 floats. [source:raw]
    // ASSIGNMENT: Set the alpha channel of the just-written texel (via the loop increment) to the previously-consumed uint16 word scaled by 0.000015259022. The scale factor corresponds to the two read-only globals flt_5AD290 and flt_5ADB14. [global:0x005AD290, global:0x005ADB14, source:raw]
    // GUARD: Guard: if this+0x10 is non-zero, post-process the decoded float output. [field:this:0x00000010]
    // CALL: Call ContactManifoldCleanup((int)this, &a4[-4 * this+0x1058]) on the decoded float RGBA output buffer start. [callee:0x00507845, field:this:0x00001058, source:raw]

    // Conservative worker pseudocode:
    //   void F_16BitToFloatTextureDecompress(_DWORD *this, int a2, int a3, float *a4) {
    //     v4 = (_DWORD*)(this[0x18/4] + a3 * this[0x1054/4] + a2 * this[0x1050/4]);
    //     for (i = &v4[this[0x1058/4]]; v4 < i; *(a4 - 1) = (float)(*((unsigned __int16*)v4 - 1) * 0.000015259022)) {
    //       v7 = (double)(unsigned __int16)*v4++ * 0.000015259022;
    //       a4[2] = (float)v7;
    //       a4[1] = (float)v7;
    //       *a4 = (float)v7;
    //       a4 += 4;
    //     }
    //     if (this[0x10/4])
    //       ContactManifoldCleanup((int)this, &a4[-4 * this[0x1058/4]]);
    //   }
    // UNRESOLVED: The role of ContactManifoldCleanup (0x00507845) on a decoded texture float buffer is unclear; the name originates from a different subsystem and the semantic purpose is not provable from this packet.
    // UNRESOLVED: Which of flt_5AD290 and flt_5ADB14 backs the 0.000015259022 scale literal is not provable from the packet; the raw source shows the constant as a float literal.
    // UNRESOLVED: Whether the two globals encode the same scale value or two distinct constants (one per channel role) is not resolvable from this packet.
    // UNRESOLVED: The cluster_copy prelabel references 00509b8e as a structural twin, but that function's IR is not present for cross-checking here.
}
