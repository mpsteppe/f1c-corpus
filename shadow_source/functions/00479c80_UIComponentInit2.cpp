// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479C80
// Canonical corpus name: UIComponentInit2
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIComponentInit2_00479c80.c

void UnknownObject::UIComponentInit2()
{
    // Object constructor: calls InitVTableSet(this, 0, 1065353216), then sets the vtable pointer at offset 0x0 to off_5A5C18, and returns this. Unconditional straight-line init; skeleton prose interprets the integer literals as a [0.0, 1.0] float range.
    // CALL: Call InitVTableSet(this, 0, 1065353216) to initialize object fields. [callee:0x004668E0, source:raw]
    // ASSIGNMENT: Set vtable pointer at offset 0x0 to the address of off_5A5C18. [field:this:0x00000000, global:0x005A5C18]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* UIComponentInit2(_DWORD* this) {
    //     InitVTableSet(this, 0, 1065353216);
    //     *this = &off_5A5C18;
    //     return this;
    //   }
    // UNRESOLVED: Object type identity and owner are unknown; packet has no owner evidence.
    // UNRESOLVED: Semantics of the integer literals 0 and 1065353216 passed to InitVTableSet are not asserted here; skeleton prose reads them as a [0.0, 1.0] float range but the float bit-pattern interpretation is not deterministic packet evidence.
    // UNRESOLVED: InitVTableSet (0x004668E0) internals and which additional fields it writes are outside this packet.
}
