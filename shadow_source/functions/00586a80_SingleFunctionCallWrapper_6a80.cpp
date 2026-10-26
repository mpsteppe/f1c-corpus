// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586A80
// Canonical corpus name: SingleFunctionCallWrapper_6a80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionCallWrapper_6a80_00586a80.c

void UnknownObject::SingleFunctionCallWrapper_6a80()
{
    // Thin thiscall wrapper that invokes FieldAccessor with a pointer to the dword at index 2 of the this object and returns FieldAccessor's result unchanged. No other computation, guard or state change occurs.
    // CALL: Call FieldAccessor with the pointer to the dword at index 2 of the this object (this + 2). [function:0x00586A80, source:raw]
    // RETURN: Return the result of FieldAccessor directly. [source:raw]

    // Conservative worker pseudocode:
    //   int SingleFunctionCallWrapper_6a80(int* this) {
    //     return FieldAccessor(this + 2);
    //   }
    // UNRESOLVED: The identity and semantics of the called function FieldAccessor are not described in the packet and it is not listed in the callee evidence.
    // UNRESOLVED: The object type owning this wrapper is unknown; the dword at index 2 of the this object has no named meaning in the packet.
    // UNRESOLVED: The callers 0x00584230 and 0x00587730 are not analyzed in this packet, so the wrapper's role in their call paths is unresolved.
}
