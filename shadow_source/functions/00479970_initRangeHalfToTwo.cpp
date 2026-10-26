// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479970
// Canonical corpus name: FunctionCallWrapper_9970
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionCallWrapper_9970_00479970.c

void UnknownObject::initRangeHalfToTwo()
{
    // Constructor for an object of unknown type. Calls VtableSetWithInitCall(this, 1056964608, 0x40000000), then installs vtable off_5A5658 into *this and returns the object pointer. Existing analysis interprets the two literal arguments as float range endpoints 0.5f and 2.0f, which is not deterministically verified.
    // CALL: Calls VtableSetWithInitCall(this, 1056964608, 0x40000000) to initialize range/parameter fields of this before the vtable is installed. [callee:0x00466980, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Installs the vtable pointer: writes the address of off_5A5658 into *this (field this+0x0). [global:0x005A5658, field:this:0x00000000, source:raw]
    // RETURN: Returns this, the constructed object pointer. [function:0x00479970, source:raw]

    // Conservative worker pseudocode:
    //   VtableSetWithInitCall(this, 1056964608, 0x40000000);
    //   this->vtable = &off_5A5658;
    //   return this;
    // UNRESOLVED: Semantics of the two literal arguments (1056964608, 0x40000000) passed to VtableSetWithInitCall are unproven; existing analysis reads them as float endpoints 0.5f and 2.0f.
    // UNRESOLVED: Object type behind vtable off_5A5658 is unknown.
    // UNRESOLVED: Legacy ABI lead name Forwards_call_to_another_function_No_additional__479970 is unverified.
}
