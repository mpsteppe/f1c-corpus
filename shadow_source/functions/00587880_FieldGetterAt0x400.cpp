// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587880
// Canonical corpus name: FieldGetterAt0x400
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldGetterAt0x400_00587880.c

void UnknownObject::FieldGetterAt0x400()
{
    // Trivial __thiscall getter: reads and returns the dword at this + 0x400 (this[256]). No side effects. The owner class and the meaning of field 0x400 are unknown.
    // CALL: Called by sub_587730 (0x00587730) and sub_5878A0 (0x005878A0) to read the getter's field. [caller:0x00587730, caller:0x005878A0, function:0x00587880]
    // CALCULATION: Field address is this + 256 * sizeof(_DWORD), i.e. this + 0x400. [field:this:0x00000400, source:raw]
    // RETURN: Return the dword read from field 0x400 of this; the call has no side effects. [field:this:0x00000400, source:raw]

    // Conservative worker pseudocode:
    //   int sub_587880(void *this) {
    //     return *(int *)((char *)this + 0x400);
    //   }
    // UNRESOLVED: Field 0x400 of the owning object is unnamed; its meaning depends on the caller's object layout.
    // UNRESOLVED: The owner class is unknown; only the field offset is evidenced.
}
