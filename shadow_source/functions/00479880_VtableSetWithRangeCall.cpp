// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479880
// Canonical corpus name: VtableSetWithRangeCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VtableSetWithRangeCall_00479880.c

void UnknownObject::VtableSetWithRangeCall()
{
    // Object constructor: calls VtableSetWithInitCall with constructor arguments -1082130432 and 1065353216, then overwrites the object's vtable pointer at offset 0x0 with the address of the global vtable off_5A52C0, returning this.
    // CALL: Call VtableSetWithInitCall(this, -1082130432, 1065353216) to perform base initialization. [callee:0x00466980, source:raw]
    // ASSIGNMENT: Write the vtable pointer: this->field_0 = &off_5A52C0. [field:this:0x00000000, global:0x005A52C0, source:raw]
    // RETURN: Return this as the constructed object pointer. [source:raw, function:0x00479880]

    // Conservative worker pseudocode:
    //   VtableSetWithInitCall(this, -1082130432, 1065353216);
    //   *this = &off_5A52C0;
    //   return this;
    // UNRESOLVED: Owner object type is UnknownObject; the class this constructor initializes is unidentified.
    // UNRESOLVED: Semantic meaning of constructor arguments -1082130432 and 1065353216 is not confirmed; they are kept as decimal literals.
    // UNRESOLVED: No static callers recorded; the construction site and runtime role of the object are unknown.
}
