// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DB120
// Canonical corpus name: FloatConstantSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatConstantSetter_004db120.c

void UnknownObject::SetFloatToTen()
{
    // Trivial field initializer: writes the constant 1092616192 (IEEE-754 float 10.0) into the this+0x10 dword slot (this[4]). No branches, no callees, no return value.
    // ASSIGNMENT: Write 1092616192 (float 10.0) to this[4], i.e. the dword field at this+0x10. [source:raw, field:this:0x00000010, abi:lead, function:0x004DB120]

    // Conservative worker pseudocode:
    //   void SetFloatToTen(_DWORD *this) {
    //     this[4] = 1092616192;  // float 10.0 at offset 0x10
    //   }
    // UNRESOLVED: The enclosing object type and the purpose of the float-10.0 field are unknown; the owner was not recoverable from this single-write body.
}
