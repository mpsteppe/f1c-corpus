// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053B1D0
// Canonical corpus name: TripleFieldGetter_b1d0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TripleFieldGetter_b1d0_0053b1d0.c

void UnknownObject::ReadThreeDwordsToOutputs()
{
    // Reads three consecutive DWORD fields of the this object (offsets +0x1C, +0x20, +0x24, i.e. this[7], this[8], this[9]) and writes each to a caller-provided output pointer. Every write is conditional on its output pointer being non-null, so the three checks are independent. Returns the third output pointer a4. Invoked by sub_558E70 (0x00558E70).
    // GUARD: If output pointer a2 is null the write of this+0x1C is skipped [source:raw]
    // ASSIGNMENT: *a2 = this[7] (byte offset +0x1C) [field:this:0x0000001C, source:raw]
    // GUARD: If output pointer a3 is null the write of this+0x20 is skipped [source:raw]
    // ASSIGNMENT: *a3 = this[8] (byte offset +0x20) [field:this:0x00000020, source:raw]
    // GUARD: If output pointer a4 is null the write of this+0x24 is skipped [source:raw]
    // ASSIGNMENT: *a4 = this[9] (byte offset +0x24) [field:this:0x00000024, source:raw]
    // RETURN: Returns a4 (the third output pointer); the function is invoked by sub_558E70 (0x00558E70) [function:0x0053B1D0, caller:0x00558E70, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   if (a2) *a2 = this+0x1C;
    //   if (a3) *a3 = this+0x20;
    //   if (a4) *a4 = this+0x24;
    //   return a4;
    // UNRESOLVED: The semantic purpose of the three fields (+0x1C/+0x20/+0x24) is not determinable from this packet; the skeleton fill labels them consecutive data fields without a named role
}
