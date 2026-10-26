// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479910
// Canonical corpus name: sub_479910
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_479910_00479910.c

void UnknownObject::initRangeZeroToHalf()
{
    // Constructor for an object of unknown type. Calls VtableSetWithInitCall(this, 0, 1056964608), then installs vtable off_5A54E8 into *this and returns the object pointer. Existing analysis interprets the two literal arguments as float range endpoints 0.0f and 0.5f, which is not deterministically verified.
    // CALL: Calls VtableSetWithInitCall(this, 0, 1056964608) to initialize range/parameter fields of this before the vtable is installed. [callee:0x00466980, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Installs the vtable pointer: writes the address of off_5A54E8 into *this (field this+0x0). [global:0x005A54E8, field:this:0x00000000, source:raw]
    // RETURN: Returns this, the constructed object pointer. [function:0x00479910, source:raw]

    // Conservative worker pseudocode:
    //   VtableSetWithInitCall(this, 0, 1056964608);
    //   this->vtable = &off_5A54E8;
    //   return this;
    // UNRESOLVED: Semantics of the two literal arguments (0, 1056964608) passed to VtableSetWithInitCall are unproven; existing analysis reads them as float endpoints 0.0f and 0.5f.
    // UNRESOLVED: Object type behind vtable off_5A54E8 is unknown.
    // UNRESOLVED: Legacy ABI lead name UI_Object_Init_479910 is unverified.
}
