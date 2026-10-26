// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553A20
// Canonical corpus name: FloatToIntConversionChain
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToIntConversionChain_00553a20.c

void UnknownObject::FloatToIntConversionChain()
{
    // Two-path float-array processing gated by flag bit 0x40000 in this+0x18. When set: calls sub_55C860(this, a2, a2 + 3, a3) and clears bit 0x400. When clear: converts a2[4], a2[3], a2[1], a2[0] to ints via CRTFtol, dispatches to sub_553AA0(v5, v6, a3, this), and clears bit 0x400 in this+0x18 via mask 0xFFFFFBFF. Returns the updated flags (or the sub_55C860 result) in both paths.
    // GUARD: Test bit 0x40000 in the flags dword this+0x18; set selects the sub_55C860 alternate path, clear selects the CRTFtol conversion path. [field:this:0x00000018, source:raw]
    // CALL: Alternate path: call sub_55C860(this, a2, a2 + 3, a3) and clear bit 0x400 in this+0x18. [callee:0x0055C860, field:this:0x00000018, source:raw]
    // CALL: Main path: convert a2[4], a2[3], a2[1], a2[0] to ints via CRTFtol. [callee:0x00587BDC, source:raw]
    // CALL: Main path: dispatch the converted ints v5 (a2[3]) and v6 (a2[4]) with a3 and this to sub_553AA0. [callee:0x00553AA0, source:raw]
    // ASSIGNMENT: Main path: clear bit 0x400 by storing flags & 0xFFFFFBFF back into this+0x18; this masked value is also the return value. [field:this:0x00000018, source:raw]
    // RETURN: Invoked from FloatVectorWithConditionalTransform, F_2DTextRenderingWithScissorRectangle and sub_49F1C0; returns the updated flags dword from this+0x18 in both paths. [caller:0x00494C20, caller:0x0049B370, caller:0x0049F1C0, function:0x00553A20, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int FloatToIntConversionChain(int this, float* a2, int a3) {
    //     if (this[6] & 0x40000) {
    //       unsigned int result = sub_55C860(this, a2, a2 + 3, a3);
    //       this[6] &= ~0x400u;
    //       return result;
    //     }
    //     int v6 = CRTFtol(a2[4]);
    //     int v5 = CRTFtol(a2[3]);
    //     CRTFtol(a2[1]);
    //     CRTFtol(a2[0]);
    //     sub_553AA0(v5, v6, a3, this);
    //     unsigned int result = this[6] & 0xFFFFFBFF;
    //     this[6] = result;
    //     return result;
    //   }
    // UNRESOLVED: The float array a2 element semantics (what a2[0..4] represent) are not recoverable here; only this+0x18 has a field evidence reference in the packet.
    // UNRESOLVED: Global dword_8B78A0 (0x008B78A0) is listed in the packet globals but not referenced by the raw source of this function; its role is unclear.
    // UNRESOLVED: The CRTFtol results of a2[1] and a2[0] are discarded in the raw source; whether they have a side effect in the CRT shim is unconfirmed.
}
