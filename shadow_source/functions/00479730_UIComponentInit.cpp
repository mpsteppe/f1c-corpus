// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479730
// Canonical corpus name: UIComponentInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIComponentInit_00479730.c

void UnknownObject::UIComponentInit()
{
    // UI component constructor: calls VtableSetWithInitCall with integer 0 and float 1045220557 (0.2f), then overwrites the vtable pointer of this with off_5A4DB8 and returns this.
    // CALL: VtableSetWithInitCall(this, 0, 1045220557) performs base UI component initialization with an integer parameter 0 and default float 1045220557. [callee:0x00466980, source:raw]
    // ASSIGNMENT: Set vtable pointer at this+0x0 to off_5A4DB8, overriding the value written by the init call. [field:this:0x00000000, global:0x005A4DB8, source:raw]
    // RETURN: Return the constructed this pointer. [function:0x00479730, source:raw]

    // Conservative worker pseudocode:
    //   VtableSetWithInitCall(this, 0, 1045220557);
    //   *this = &off_5A4DB8;
    //   return this;
    // UNRESOLVED: The vtable off_5A4DB8 cannot be tied to a named object class from this packet alone; the object type it dispatches to is unknown.
}
