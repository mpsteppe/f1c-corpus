// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479790
// Canonical corpus name: ConstructorWithRangeInitAndVTable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorWithRangeInitAndVTable_00479790.c

void UnknownObject::ConstructorWithRangeInitAndVTable()
{
    // Constructor with symmetric range: calls VtableSetWithInitCall with floats -1082130432 (-1.0f) and 1065353216 (1.0f), then overwrites the vtable pointer of this with off_5A4F28 and returns this.
    // CALL: VtableSetWithInitCall(this, -1082130432, 1065353216) performs base object initialization with symmetric float range parameters -1.0f and 1.0f. [callee:0x00466980, source:raw]
    // ASSIGNMENT: Set vtable pointer at this+0x0 to off_5A4F28, overriding the value written by the init call. [field:this:0x00000000, global:0x005A4F28, source:raw]
    // RETURN: Return the constructed this pointer. [function:0x00479790, source:raw]

    // Conservative worker pseudocode:
    //   VtableSetWithInitCall(this, -1082130432, 1065353216);
    //   *this = &off_5A4F28;
    //   return this;
    // UNRESOLVED: The vtable off_5A4F28 cannot be tied to a named object class from this packet alone; the object type it dispatches to is unknown.
}
