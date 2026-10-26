// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479A10
// Canonical corpus name: ShortComputation_9a10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_9a10_00479a10.c

void UnknownObject::initRangeHalfToOne()
{
    // Constructor for an object of unknown type. Calls VtableSetWithInitCall(this, 1056964608, 1065353216), then installs vtable off_5A5880 into *this and returns the object pointer. Existing analysis interprets the two literal arguments as float range endpoints 0.5f and 1.0f, which is not deterministically verified.
    // CALL: Calls VtableSetWithInitCall(this, 1056964608, 1065353216) to initialize range/parameter fields of this before the vtable is installed. [callee:0x00466980, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Installs the vtable pointer: writes the address of off_5A5880 into *this (field this+0x0). [global:0x005A5880, field:this:0x00000000, source:raw]
    // RETURN: Returns this, the constructed object pointer. [function:0x00479A10, source:raw]

    // Conservative worker pseudocode:
    //   VtableSetWithInitCall(this, 1056964608, 1065353216);
    //   this->vtable = &off_5A5880;
    //   return this;
    // UNRESOLVED: Semantics of the two literal arguments (1056964608, 1065353216) passed to VtableSetWithInitCall are unproven; existing analysis reads them as float endpoints 0.5f and 1.0f.
    // UNRESOLVED: Object type behind vtable off_5A5880 is unknown.
    // UNRESOLVED: Legacy ABI lead name Short_Computation_479a10 is unverified.
}
