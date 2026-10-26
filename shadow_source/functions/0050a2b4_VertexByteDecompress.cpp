// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050A2B4
// Canonical corpus name: VertexByteDecompress
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VertexByteDecompress_0050a2b4.c

void UnknownObject::VertexByteDecompress()
{
    // Decompresses packed byte-per-channel vertex data into float RGBA output. Computes a source pointer from the object's data base (this+0x18), a stride for parameter a2 (this+0x1050) and a stride for parameter a3 (this+0x1054), then iterates this+0x1058 elements consuming 4 source bytes per element, scaling each byte by 0.0078125 into the four output components a4[0..3]. When the flag at this+0x10 is set, it calls ContactManifoldCleanup (0x00507845) on the decoded output buffer.
    // CALCULATION: Compute the source byte base pointer as this[6] (this+0x18) plus a3 * this[1045] (this+0x1054) plus a2 * this[1044] (this+0x1050), using the thiscall parameters a2/a3. [abi:lead, field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: Iterate exactly this[1046] (this+0x1058) elements consuming four source bytes each; the loop end pointer i is the source base plus 4 * this+0x1058. [field:this:0x00001058, source:raw]
    // CALCULATION: Decode the first source byte into output component a4[0]: *a4 = byte * 0.0078125; the 0.0078125 scale corresponds to the global float read flt_59E774 (0x0059E774). [global:0x0059E774, source:raw]
    // CALCULATION: Decode the second source byte into output component a4[1]: *(a4 - 3) = second byte * 0.0078125, using the same scale. [global:0x0059E774, source:raw]
    // CALCULATION: Decode the third source byte into output component a4[2]: *(a4 - 2) = third byte * 0.0078125, using the same scale. [global:0x0059E774, source:raw]
    // ASSIGNMENT: Loop increment writes the fourth output component a4[3]: *(a4 - 1) = fourth byte * 0.0078125, using the same scale. [global:0x0059E774, source:raw]
    // GUARD: Guard on this[4] (this+0x10): when non-zero the decoded output is post-processed, otherwise the post-processing call is skipped. [field:this:0x00000010, source:raw]
    // CALL: Call ContactManifoldCleanup (0x00507845) with this cast to int and a pointer to the first decoded output quad (a4 - 4 * this[1046]) when the post-process flag at this+0x10 is set. [callee:0x00507845, field:this:0x00001058, source:raw]
    // RETURN: Function 0x0050A2B4 returns void after the optional ContactManifoldCleanup pass. [function:0x0050A2B4, source:raw]

    // Conservative worker pseudocode:
    //   void sub_50A2B4(_DWORD* this, int a2, int a3, float* a4) {
    //     char* v4 = (char*)(this[6] + a3 * this[1045] + a2 * this[1044]);
    //     for (char* i = &v4[4 * this[1046]]; v4 < i; *(a4 - 1) = (double)*(v4 - 1) * 0.0078125) {
    //       v7 = *v4;
    //       v4 += 4;
    //       *a4 = (double)v7 * 0.0078125;
    //       a4 += 4;
    //       *(a4 - 3) = (double)*(v4 - 3) * 0.0078125;
    //       *(a4 - 2) = (double)*(v4 - 2) * 0.0078125;
    //     }
    //     if (this[4])
    //       ContactManifoldCleanup((int)this, (unsigned int)&a4[-4 * this[1046]]);
    //   }
    // UNRESOLVED: Whether global flt_59E774 (0x0059E774) is the exact 0.0078125 scale is DERIVED context; the rendered source spells the literal directly.
    // UNRESOLVED: The decode object class is not evidenced in this packet; owner kept as UnknownObject/UNKNOWN.
    // UNRESOLVED: The two strides at this+0x1050 and this+0x1054 are labeled by their arithmetic role (multipliers of a2 and a3); their row/column orientation is not deterministically evidenced.
    // UNRESOLVED: Whether the four scaled components are RGBA color, a position+tangent stream, or another per-element vertex layout is not deterministically evidenced here; the canonical name and the structural twin F_8BitVertexPositionDecompression (0050a0f0) suggest a vertex decode.
    // UNRESOLVED: ContactManifoldCleanup's post-process semantics (0x00507845) are outside this packet.
}
