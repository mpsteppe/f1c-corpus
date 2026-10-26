// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404D20
// Canonical corpus name: sub_404D20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_404D20_00404d20.c

void UnknownObject::ReadFloatFieldAtOffset0x18()
{
    // Trivial thiscall getter: reads the pointer stored at this+0x0 and returns the float value at offset 0x18 of the pointed-to object, promoted to double per the signature. Unconditional read and return with no guards or callees. Called by sub_422BE0 (00422BE0).
    // ASSIGNMENT: Read the target object pointer stored at this+0x0 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Read the float field at offset 0x18 of the pointed-to object [field:obj:0x00000018, source:raw]
    // RETURN: Return the float field promoted to double (the C signature returns double) [function:0x00404D20, source:raw]
    // CALL: Invoked by sub_422BE0 (00422BE0), the only known caller, to fetch this float field for its own logic [caller:0x00422BE0]

    // Conservative worker pseudocode:
    //   return (double)*(float*)(*(DWORD*)this + 0x18);
    // UNRESOLVED: The type and semantic role of the object behind the this-pointer indirection are unknown; only the double indirection (this -> object -> float at 0x18) is evidenced
    // UNRESOLVED: Whether the float-to-double promotion is semantically meaningful or a compiler artifact of the returning convention is not resolvable from this packet
}
