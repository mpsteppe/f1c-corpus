// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00465150
// Canonical corpus name: SingleCallWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleCallWrapper_00465150.c

void UnknownObject::SingleCallWrapper()
{
    // Thin tail-call wrapper: reads the pointer stored at field 0x0 of this (_DWORD *this), then forwards it together with a2 to the single delegated routine (sub_464D30 in the raw source), returning that routine's value directly. The delegate target is not enumerated in the packet callees, so its address is not recoverable from the packet evidence. The prelabel characterizes this as a getter of field 0x0, but the field is forwarded to a call rather than returned.
    // ASSIGNMENT: Read *this (field 0x0 of this): the pointer to the delegated object is loaded from byte offset 0x0. [field:this:0x00000000, source:raw]
    // CALL: Tail-delegate: sub_464D30(*this, a2) forwards the field-0x0 pointer and a2 to the single delegated routine (sub_464D30 in the raw source; not enumerated in the packet callees, so no callee evidence ref exists). [source:raw]
    // RETURN: return the delegated call's value directly. [source:raw]
    // CALL: Call-context: the packet records a single caller, SessionTypeSetter at 0x00463F70. [caller:0x00463F70, function:0x00465150]

    // Conservative worker pseudocode:
    //   int sub_465150(_DWORD **this, int a2) {
    //       return sub_464D30(*this, a2);  // tail call to single delegate
    //   }
    // UNRESOLVED: The raw source calls sub_464D30 but the packet enumerates no callees and supplies no callee address or evidence ref for it; the target exists only as source:raw text.
    // UNRESOLVED: The prelabel 'getter' characterization is incomplete: field 0x0 is read but immediately forwarded to sub_464D30 rather than returned.
    // UNRESOLVED: The semantic role of a2 is unknown.
    // UNRESOLVED: The type and meaning of the object pointed to by field 0x0 are unknown.
    // UNRESOLVED: Owner class is unknown; no ownership evidence is present in the packet.
}
