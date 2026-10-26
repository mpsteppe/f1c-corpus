// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047A800
// Canonical corpus name: ConstructorWithRangeInit_a800
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorWithRangeInit_a800_0047a800.c

void UnknownObject::ConstructorWithRangeInitA()
{
    // Object initializer (thiscall, no arguments). Calls InitVTableSet (0x004668E0) passing the two integer literals 1028443341 and 1065353216, then overrides the vtable pointer at this+0x0 with off_5A6570 (0x005A6570). Returns this. The existing analysis prose interprets the two literals as the float values 0.05 and 1.0, but that bit-pattern reading is not asserted here.
    // CALL: Invoke InitVTableSet (0x004668E0) with this and the integer literals 1028443341, 1065353216 to establish the vtable reference and write the two initializer fields [callee:0x004668E0, source:raw]
    // ASSIGNMENT: Write off_5A6570 (0x005A6570) into the vtable pointer at this+0x0, overriding whatever InitVTableSet installed [field:this:0x00000000, global:0x005A6570, source:raw]
    // RETURN: Return this from the initializer [function:0x0047A800, source:raw]

    // Conservative worker pseudocode:
    //   InitVTableSet(this, 1028443341, 1065353216);
    //   *this = &off_5A6570;
    //   return this;
    // UNRESOLVED: The semantic meaning of the two integer literals (1028443341, 1065353216) is only described in the analysis prose as float 0.05 / 1.0; the raw source carries no type annotation
    // UNRESOLVED: The object type owning this initializer is not identified beyond UnknownObject
}
