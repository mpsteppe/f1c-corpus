// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499140
// Canonical corpus name: ConstructorWithVTableAndSubInit_9140
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorWithVTableAndSubInit_9140_00499140.c

void UnknownObject::ConstructorWithVTableAndSubInit()
{
    // Object constructor. First runs base/parent initialization via InitWithVTableParam(this, a2), then overwrites the vtable pointer at this+0x0 with the derived-class vtable off_5ACA30. Returns this. Part of an object construction chain; invoked by sub_492460.
    // CALL: Run base/parent initialization, forwarding parameter a2 to InitWithVTableParam [callee:0x00498D20, source:raw]
    // ASSIGNMENT: Overwrite the vtable pointer at this+0x0 with the derived-class vtable off_5ACA30 [field:this:0x00000000, global:0x005ACA30, source:raw]
    // RETURN: Return the constructed this pointer [function:0x00499140, source:raw]
    // CALL: Invoked by sub_492460 as part of the object construction chain [caller:0x00492460, source:raw]

    // Conservative worker pseudocode:
    //   DWORD* ctor(DWORD* this, int a2) {
    //     InitWithVTableParam(this, a2);
    //     this[0] = &off_5ACA30;
    //     return this;
    //   }
    // UNRESOLVED: The identity of the object type (and thus the class whose vtable off_5ACA30 belongs to) is not confirmed; off_5ACA30 is only DERIVED as a vtable.
    // UNRESOLVED: The behavior of the base initializer InitWithVTableParam is outside this packet.
    // UNRESOLVED: Owner object identity is unknown.
}
