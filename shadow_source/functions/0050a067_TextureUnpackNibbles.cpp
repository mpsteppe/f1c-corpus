// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050A067
// Canonical corpus name: TextureUnpackNibbles
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureUnpackNibbles_0050a067.c

void UnknownObject::TextureUnpackNibbles()
{
    // Decodes a packed 4-bit (nibble) byte stream into float RGBA quads. Computes a source byte pointer from the object's data base (this+0x18), a stride for parameter a2 (this+0x1050) and a stride for parameter a3 (this+0x1054), iterates this+0x1058 source bytes, and for each byte writes the low nibble to the RGB channels (a4[0..2]) and the high nibble to the alpha channel, each scaled by 0.06666667. When the flag at this+0x10 is non-zero it calls ContactManifoldCleanup (0x00507845) on the decoded output buffer.
    // CALCULATION: Compute the source byte base pointer as this[6] (this+0x18) plus a3 * this[1045] (this+0x1054) plus a2 * this[1044] (this+0x1050), using the thiscall parameters a2/a3. [abi:lead, field:this:0x00000018, field:this:0x00001050, field:this:0x00001054, source:raw]
    // LOOP: Iterate exactly this[1046] (this+0x1058) source bytes; the loop end pointer i is the source base plus this+0x1058 and the running pointer consumes one byte per pass. [field:this:0x00001058, source:raw]
    // CALCULATION: Decode the low nibble of the current byte (*v5 & 0xF), scale it by 0.06666667 and write it to the RGB channels of the output quad (a4[0], a4[1], a4[2]); the 0.06666667 scale corresponds to the global float read flt_5AC108 (0x005AC108). [global:0x005AC108, source:raw]
    // CALCULATION: Capture the high nibble of the current byte (v8 = *v5 >> 4) and advance the source pointer; the high nibble is deferred to the alpha channel write of the loop increment. [source:raw]
    // ASSIGNMENT: Loop increment writes the alpha channel of the current quad as the scaled high nibble (*(a4 - 1) = v8 * 0.06666667) and the output pointer advances by four floats. [global:0x005AC108, source:raw]
    // GUARD: Guard on this[4] (this+0x10): when non-zero the decoded output is post-processed, otherwise the post-processing call is skipped. [field:this:0x00000010, source:raw]
    // CALL: Call ContactManifoldCleanup (0x00507845) with this cast to int and a pointer to the first decoded output quad (a4 - 4 * this[1046]) when the post-process flag at this+0x10 is set. [callee:0x00507845, field:this:0x00001058, source:raw]
    // RETURN: Function 0x0050A067 returns void after the optional ContactManifoldCleanup pass. [function:0x0050A067, source:raw]

    // Conservative worker pseudocode:
    //   void sub_50A067(_DWORD* this, int a2, int a3, float* a4) {
    //     char* v5 = (char*)(this[6] + a3 * this[1045] + a2 * this[1044]);
    //     for (char* i = &v5[this[1046]]; v5 < i; *(a4 - 1) = (double)v8 * 0.06666667) {
    //       double v7 = (double)(*v5 & 0xF) * 0.06666667;
    //       a4[2] = a4[1] = a4[0] = (double)v7;
    //       v8 = *v5++ >> 4;
    //       a4 += 4;
    //     }
    //     if (this[4])
    //       ContactManifoldCleanup((int)this, (unsigned int)&a4[-4 * this[1046]]);
    //   }
    // UNRESOLVED: Whether global flt_5AC108 (0x005AC108) is the exact 0.06666667 scale is DERIVED context; the rendered source spells the literal directly.
    // UNRESOLVED: The decode object class is not evidenced in this packet; owner kept as UnknownObject/UNKNOWN.
    // UNRESOLVED: The two strides at this+0x1050 and this+0x1054 are labeled by their arithmetic role (multipliers of a2 and a3); their row/column orientation is not deterministically evidenced.
    // UNRESOLVED: ContactManifoldCleanup's post-process semantics (0x00507845) are outside this packet.
    // UNRESOLVED: Whether the output is texture color data or another per-element RGBA stream is not deterministically evidenced here.
}
