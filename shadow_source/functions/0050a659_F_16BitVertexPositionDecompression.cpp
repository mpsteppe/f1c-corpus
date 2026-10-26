// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050A659
// Canonical corpus name: F_16BitVertexPositionDecompression
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_16BitVertexPositionDecompression_0050a659.c

void UnknownObject::F_16BitVertexPositionDecompression()
{
    // 16-bit packed vertex-position decompressor. Computes a source uint16 pointer from this+0x18 plus this+0x1050 (row) and this+0x1054 (slice) pitch products with the two index arguments, and a loop end at v4 + this+0x1064 bytes (this+0x1058/0x1064 count fields bound the pass). Each iteration reads three consecutive uint16 words, scales each by 0.000015259022 (~2^-16), and writes four output floats: channel0 = word2 * scale, channel1 = word1 * scale, channel2 = word0 * scale, alpha = 1.0. When the this+0x10 flag is non-zero, ContactManifoldCleanup is called on the decoded float output.
    // CALCULATION: Compute source pointer v4 = (uint16*)(this+0x18 + a3 * this+0x1054 + a2 * this+0x1050) (slice and row pitch products with the index arguments). [field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // CALCULATION: Compute loop end bound i = v4 + this+0x1064 bytes; the total source byte count at this+0x1064 bounds the decode pass. [field:this:0x00001064, source:raw]
    // LOOP: For-loop iterating while v4 < i; each iteration consumes three uint16 words and emits one 4-float RGBA vertex. [field:this:0x00001064, source:raw]
    // CALCULATION: Scale the three source words to float with 0.000015259022; channel0 uses word2, channel1 uses word1, channel2 uses word0. The scale factor corresponds to the read-only global flt_5AD290. [global:0x005AD290, source:raw]
    // ASSIGNMENT: Write four output floats per vertex: a4[0] = word2 * scale, a4[1] = word1 * scale, a4[2] = word0 * scale, a4[3] = 1.0 (alpha set via the loop increment). [source:raw]
    // GUARD: Guard: if this+0x10 is non-zero, post-process the decoded float output. [field:this:0x00000010]
    // CALL: Call ContactManifoldCleanup((int)this, &a4[-4 * this+0x1058]) on the decoded float RGBA output buffer start. [callee:0x00507845, field:this:0x00001058, source:raw]

    // Conservative worker pseudocode:
    //   void F_16BitVertexPositionDecompression(_DWORD *this, int a2, int a3, float *a4) {
    //     v4 = (unsigned __int16*)(this[0x18/4] + a3 * this[0x1054/4] + a2 * this[0x1050/4]);
    //     i = (unsigned __int16*)((char*)v4 + this[0x1064/4]);
    //     for (; v4 < i; *(a4 - 1) = 1.0f) {
    //       a4[0] = (float)((double)v4[2] * 0.000015259022);
    //       a4 += 4;
    //       a4[-3] = (float)((double)v4[1] * 0.000015259022);
    //       v7 = *v4;
    //       v4 += 3;
    //       a4[-2] = (float)((double)v7 * 0.000015259022);
    //     }
    //     if (this[0x10/4])
    //       ContactManifoldCleanup((int)this, &a4[-4 * this[0x1058/4]]);
    //   }
    // UNRESOLVED: The role of ContactManifoldCleanup (0x00507845) on a decoded vertex float buffer is unclear; the name originates from a different subsystem and the semantic purpose is not provable from this packet.
    // UNRESOLVED: The exact channel order (word2/word1/word0 mapping to X/Y/Z vs any other axis order) depends on the vertex format contract, which is not in this packet.
    // UNRESOLVED: flt_5AD290's name in the existing analysis is 'LuminanceDecodeScale', but it is shared as a scale constant here too; the shared-constant identity across decoders is not provable from this packet.
    // UNRESOLVED: The relationship between the loop bound at this+0x1064 and the count at this+0x1058 (used only in the post-process call) is not fully determined here.
}
