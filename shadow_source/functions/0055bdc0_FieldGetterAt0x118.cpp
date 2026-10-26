// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055BDC0
// Canonical corpus name: FieldGetterAt0x118
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldGetterAt0x118_0055bdc0.c

void UnknownObject::FieldGetterAt0x118()
{
    // Trivial __thiscall getter that returns this[70], the 32-bit value at this+0x118, without any side effects. Owner and meaning of the field are unknown; the single known caller sub_53E070 consumes the value.
    // RETURN: Return this[70], the 32-bit field at this+0x118, read unchanged; no write or side effect in the body of sub_55BDC0 (ABI lead Field_Getter_at_0x118). Called from sub_53E070 (0x0053E070). [abi:lead, caller:0x0053E070, field:this:0x00000118, function:0x0055BDC0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_55BDC0(_DWORD *this) {
    //     return this[70];
    //   }
    // UNRESOLVED: Semantics and owner of the +0x118 field are unknown; only a read occurs here.
    // UNRESOLVED: Purpose of the value as consumed by caller sub_53E070 is not established.
}
