// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047A8F0
// Canonical corpus name: ShortComputation_a8f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_a8f0_0047a8f0.c

void UnknownObject::ObjectInit_a8f0()
{
    // Object constructor: calls InitVTableSet(this, 1028443341, 1065353216), then sets the vtable pointer at offset 0x0 to off_5A6628, and returns this. Unconditional straight-line init; skeleton prose interprets the integer literals as float values ~0.05 and 1.0, but the first literal differs from the sibling 0047A580/0047A5E0 and its float value is not asserted here.
    // CALL: Call InitVTableSet(this, 1028443341, 1065353216) to initialize object fields. [callee:0x004668E0, source:raw]
    // ASSIGNMENT: Set vtable pointer at offset 0x0 to the address of off_5A6628. [field:this:0x00000000, global:0x005A6628]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* ObjectInit_a8f0(_DWORD* this) {
    //     InitVTableSet(this, 1028443341, 1065353216);
    //     *this = &off_5A6628;
    //     return this;
    //   }
    // UNRESOLVED: Object type identity and owner are unknown; packet has no owner evidence.
    // UNRESOLVED: Semantics of the integer literals 1028443341 and 1065353216 passed to InitVTableSet are not asserted here; the skeleton prose reads them as floats ~0.05 and 1.0 but the float bit-pattern interpretation is not deterministic packet evidence, and 1028443341 is not the bit pattern of 0.05f.
    // UNRESOLVED: InitVTableSet (0x004668E0) internals and which additional fields it writes are outside this packet.
}
