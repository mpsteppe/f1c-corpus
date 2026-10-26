// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00542490
// Canonical corpus name: F_3FieldGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3FieldGetter_00542490.c

void UnknownObject::GetThreeFields()
{
    // __thiscall three-field getter. Each output pointer is individually null-guarded: if a2 is non-null write *a2 = this[12] (this+0x30); if a3 is non-null write *a3 = this[13] (this+0x34); if a4 is non-null write *a4 = this[14] (this+0x38). Returns a4 (the last output pointer). No callees, no globals. Called by TwoCallDelegation_2420 (00542420) and sub_558E70 (00558e70). Prior analysis labels the three source fields as orientation angles / facing components (DERIVED, not proven by this packet).
    // GUARD: Guard: if a2 is non-null, copy the field at this+0x30 into *a2. [field:this:0x00000030, source:raw]
    // ASSIGNMENT: *a2 = this[12], i.e. dword at this+0x30. [field:this:0x00000030, source:raw]
    // GUARD: Guard: if a3 is non-null, copy the field at this+0x34 into *a3. [field:this:0x00000034, source:raw]
    // ASSIGNMENT: *a3 = this[13], i.e. dword at this+0x34. [field:this:0x00000034, source:raw]
    // ASSIGNMENT: result = a4 (return value is preloaded with a4 before the last guarded write). [source:raw]
    // GUARD: Guard: if a4 is non-null, copy the field at this+0x38 into *a4. [field:this:0x00000038, source:raw]
    // ASSIGNMENT: *a4 = this[14], i.e. dword at this+0x38. [field:this:0x00000038, source:raw]
    // RETURN: Return a4 (the last output pointer). [function:0x00542490, source:raw]
    // CALL: Invoked by TwoCallDelegation_2420 (00542420). [caller:0x00542420]
    // CALL: Invoked by sub_558E70 (00558e70). [caller:0x00558E70]

    // Conservative worker pseudocode:
    //   DWORD *GetThreeFields(DWORD *this, DWORD *a2, DWORD *a3, DWORD *a4) {
    //     if (a2) *a2 = this[12];
    //     if (a3) *a3 = this[13];
    //     if (a4) *a4 = this[14];
    //     return a4;
    //   }
    // UNRESOLVED: The semantic meaning of the three source dwords (this+0x30/0x34/0x38) is labeled as orientation/facing by prior analysis but is not proven by this packet.
    // UNRESOLVED: Why the return value is the last output pointer a4 rather than void or a status code is unexplained by the packet.
}
