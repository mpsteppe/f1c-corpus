// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053B330
// Canonical corpus name: sub_53B330
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53B330_0053b330.c

void UnknownObject::SetFlagAndParams()
{
    // Parameter/configuration initializer: sets bit 1 (value 0x2) in the flags word at offset 0, stores the three input parameters a2, a3, a4 into the fields at offsets 0x1C, 0x20 and 0x24 respectively, and returns a4. No guard conditions; the function always executes fully.
    // ASSIGNMENT: Set bit 1 in the flags field at offset 0: *this |= 2u, marking the object enabled/active. [source:raw, field:this:0x00000000]
    // ASSIGNMENT: Store parameter a2 into the field at offset 0x1C. [source:raw, field:this:0x0000001C]
    // ASSIGNMENT: Store parameter a3 into the field at offset 0x20. [source:raw, field:this:0x00000020]
    // ASSIGNMENT: Store parameter a4 into the field at offset 0x24. [source:raw, field:this:0x00000024]
    // RETURN: Return a4 as the result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_53B330(_DWORD *this, int a2, int a3, int a4) {
    //     *this |= 2u;
    //     this[7] = a2;
    //     this[8] = a3;
    //     this[9] = a4;
    //     return a4;
    //   }
    // UNRESOLVED: Receiver object identity is unknown; the meaning of the flags bit and the three stored parameters depends on the caller's context.
    // UNRESOLVED: Callers ArrayElementFlagSetWithBoundsCheck (0x00558CB0) and sub_558E70 (0x00558E70) select the receiver; no owner is provable here.
}
