// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479820
// Canonical corpus name: ConstructorVTableFUN00466980
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorVTableFUN00466980_00479820.c

void UnknownObject::ConstructorVTableFUN00466980()
{
    // Object constructor: calls VtableSetWithInitCall(this, -1073741824, 0x40000000) to initialize range-related vtable fields, then installs off_5A5150 as the object's vtable pointer (this+0x0). Straight-line initialization with no guards.
    // CALL: VtableSetWithInitCall(this, -1073741824, 0x40000000): initializes the object's range-related vtable fields with the two literal parameters [callee:0x00466980, source:raw]
    // ASSIGNMENT: Install vtable: *this = &off_5A5150, writing the vtable pointer to the object's first dword field (this+0x0) [field:this:0x00000000, global:0x005A5150, source:raw]
    // RETURN: Return the constructed object pointer (this) [function:0x00479820, source:raw]

    // Conservative worker pseudocode:
    //   VtableSetWithInitCall(this, -1073741824, 0x40000000);
    //   this->vtable = off_5A5150;
    //   return this;
    // UNRESOLVED: The concrete object class owning this constructor is not identified; off_5A5150's virtual method table contents are unknown
    // UNRESOLVED: Purpose of the two range literals (-1073741824, 0x40000000) written by VtableSetWithInitCall is not determined from this function alone
}
