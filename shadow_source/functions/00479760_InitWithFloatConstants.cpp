// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479760
// Canonical corpus name: InitWithFloatConstants
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitWithFloatConstants_00479760.c

void UnknownObject::InitWithFloatConstants()
{
    // Constructor with float range: calls VtableSetWithInitCall with floats 1056964608 (0.5f) and 1065353216 (1.0f), then overwrites the vtable pointer of this with off_5A4E70 and returns this.
    // CALL: VtableSetWithInitCall(this, 1056964608, 1065353216) performs base object initialization with float range parameters 0.5f and 1.0f. [callee:0x00466980, source:raw]
    // ASSIGNMENT: Set vtable pointer at this+0x0 to off_5A4E70, overriding the value written by the init call. [field:this:0x00000000, global:0x005A4E70, source:raw]
    // RETURN: Return the constructed this pointer. [function:0x00479760, source:raw]

    // Conservative worker pseudocode:
    //   VtableSetWithInitCall(this, 1056964608, 1065353216);
    //   *this = &off_5A4E70;
    //   return this;
    // UNRESOLVED: The vtable off_5A4E70 cannot be tied to a named object class from this packet alone; the object type it dispatches to is unknown.
}
