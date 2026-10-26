// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499EE0
// Canonical corpus name: TwinFieldGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwinFieldGetter_00499ee0.c

void UnknownObject::TwinFieldGetter()
{
    // Straight-line __thiscall accessor that copies the two consecutive DWORD fields at this+0x60 and this+0x64 into the output pointers a2 and a3, and returns the value of the second field (this+0x64). No guard, no side effect beyond the two pointer writes.
    // ASSIGNMENT: Copy this[24] (field this+0x60) into *a2. [field:this:0x00000060, source:raw]
    // ASSIGNMENT: Copy this[25] (field this+0x64) into *a3. [field:this:0x00000064, source:raw]
    // RETURN: Return the value read from this+0x64, the same value written to *a3. [field:this:0x00000064, source:raw]
    // CALL: Called by ConditionalMultiParamDispatch (0x004861A0), which uses this accessor to expose the two fields through its multi-parameter dispatch. [caller:0x004861A0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_499EE0(void *this, _DWORD *a2, _DWORD *a3) {
    //     *a2 = this[24];
    //     int result = this[25];
    //     *a3 = result;
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the two fields at this+0x60 / this+0x64 and the purpose of returning the second one are unknown.
}
