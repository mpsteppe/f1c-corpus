// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004798B0
// Canonical corpus name: ConstructorWithRangeInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorWithRangeInit_004798b0.c

void UnknownObject::ConstructorWithRangeInit()
{
    // Object constructor: calls VtableSetWithInitCall(this, -1082130432, 1065353216), the float range [-1.0f, 1.0f] encoded as int32, then installs off_5A5378 as the object's vtable pointer (this+0x0). Straight-line initialization with no guards.
    // CALL: VtableSetWithInitCall(this, -1082130432, 1065353216): initializes the object's range-related vtable fields with the two literal parameters, which decode to the float range [-1.0f, 1.0f] [callee:0x00466980, source:raw]
    // ASSIGNMENT: Install vtable: *this = &off_5A5378, writing the vtable pointer to the object's first dword field (this+0x0) [field:this:0x00000000, global:0x005A5378, source:raw]
    // RETURN: Return the constructed object pointer (this) [function:0x004798B0, source:raw]

    // Conservative worker pseudocode:
    //   VtableSetWithInitCall(this, -1082130432, 1065353216);
    //   this->vtable = off_5A5378;
    //   return this;
    // UNRESOLVED: The concrete object class owning this constructor is not identified; off_5A5378's virtual method table contents are unknown
    // UNRESOLVED: The float range [-1.0f, 1.0f] is a DERIVED interpretation of the raw int32 literals, not confirmed by any other packet evidence
    // UNRESOLVED: Relationship to the nearby constructors 00479820 and 00479850 (same VtableSetWithInitCall pattern, distinct vtables) is not established
}
