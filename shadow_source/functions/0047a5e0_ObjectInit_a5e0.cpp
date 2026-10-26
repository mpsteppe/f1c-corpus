// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047A5E0
// Canonical corpus name: sub_47A5E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47A5E0_0047a5e0.c

void UnknownObject::ObjectInit_a5e0()
{
    // Object constructor: calls InitVTableSet(this, 1036831949, 1065353216), then sets the vtable pointer at offset 0x0 to off_5A6400, and returns this. Unconditional straight-line init; skeleton prose interprets the integer literals as float values ~0.05 and 1.0.
    // CALL: Call InitVTableSet(this, 1036831949, 1065353216) to initialize object fields. [callee:0x004668E0, source:raw]
    // ASSIGNMENT: Set vtable pointer at offset 0x0 to the address of off_5A6400. [field:this:0x00000000, global:0x005A6400]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* ObjectInit_a5e0(_DWORD* this) {
    //     InitVTableSet(this, 1036831949, 1065353216);
    //     *this = &off_5A6400;
    //     return this;
    //   }
    // UNRESOLVED: Object type identity and owner are unknown; packet has no owner evidence.
    // UNRESOLVED: Semantics of the integer literals 1036831949 and 1065353216 passed to InitVTableSet are not asserted here; skeleton prose reads them as floats ~0.05 and 1.0 but the float bit-pattern interpretation is not deterministic packet evidence.
    // UNRESOLVED: InitVTableSet (0x004668E0) internals and which additional fields it writes are outside this packet.
}
