// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047A580
// Canonical corpus name: FloatReturnStub
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatReturnStub_0047a580.c

void UnknownObject::FloatReturnStub()
{
    // Object constructor: calls InitVTableSet(this, 1036831949, 1065353216), then sets the vtable pointer at offset 0x0 to off_5A6290, and returns this. Unconditional straight-line init; skeleton prose interprets the integer literals as float values ~0.05 and 1.0.
    // CALL: Call InitVTableSet(this, 1036831949, 1065353216) to initialize object fields. [callee:0x004668E0, source:raw]
    // ASSIGNMENT: Set vtable pointer at offset 0x0 to the address of off_5A6290. [field:this:0x00000000, global:0x005A6290]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* FloatReturnStub(_DWORD* this) {
    //     InitVTableSet(this, 1036831949, 1065353216);
    //     *this = &off_5A6290;
    //     return this;
    //   }
    // UNRESOLVED: Object type identity and owner are unknown; packet has no owner evidence.
    // UNRESOLVED: Semantics of the integer literals 1036831949 and 1065353216 passed to InitVTableSet are not asserted here; skeleton prose reads them as floats ~0.05 and 1.0 but the float bit-pattern interpretation is not deterministic packet evidence.
    // UNRESOLVED: InitVTableSet (0x004668E0) internals and which additional fields it writes are outside this packet.
}
