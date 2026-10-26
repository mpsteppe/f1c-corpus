// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005870E0
// Canonical corpus name: FieldResetWithSubCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldResetWithSubCall_005870e0.c

void UnknownObject::FieldResetWithSubCall()
{
    // Multi-field reset/initializer on a TaskBase-like struct. Delegates initialization of the sub-field at offset 0x4 to SimpleSetter_7500, then unconditionally writes the fields at 0x10, 0x14, 0x18 and 0x19 to their reset values. Returns zero.
    // CALL: Call SimpleSetter_7500 on the sub-object at this + 0x4 to perform its initialization. [source:raw, callee:0x00587500]
    // ASSIGNMENT: Initialize result to zero. [source:raw]
    // ASSIGNMENT: Write the field at this + 0x14 (this + 20) to -1 (all bits set). [source:raw, field:this:0x00000014]
    // ASSIGNMENT: Write the field at this + 0x10 (this + 16) to 0. [source:raw, field:this:0x00000010]
    // ASSIGNMENT: Write the byte at this + 0x18 (this + 24) to 0. [source:raw, field:this:0x00000018]
    // ASSIGNMENT: Write the byte at this + 0x19 (this + 25) to 0. [source:raw, field:this:0x00000019]
    // RETURN: Return the zero result. No guard gates any of the writes. [source:raw, function:0x005870E0]

    // Conservative worker pseudocode:
    //   int sub_5870E0(int this) {
    //     SimpleSetter_7500(this + 4);
    //     *(int*)(this + 0x10) = 0;
    //     *(int*)(this + 0x14) = -1;
    //     *(BYTE*)(this + 0x18) = 0;
    //     *(BYTE*)(this + 0x19) = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Purpose of the sub-object at this + 0x4 and what SimpleSetter_7500 initializes is unknown here.
    // UNRESOLVED: Meaning of the reset values (-1 at 0x14, 0 at the others) and the role of this struct (TaskBase-like) is caller-context dependent.
    // UNRESOLVED: Caller sub_57BF00 (0x0057BF00) relationship to this reset remains unexamined.
}
