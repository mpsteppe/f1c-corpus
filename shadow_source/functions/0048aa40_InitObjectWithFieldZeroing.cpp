// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048AA40
// Canonical corpus name: ObjectInitWithFieldZeroing
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitWithFieldZeroing_0048aa40.c

void UnknownObject::InitObjectWithFieldZeroing()
{
    // Object constructor: calls ConstructorInitVTable on the object with parameters 1 and -1, zeroes the eight consecutive DWORD fields at offsets 0xEC through 0x108 and the two byte flags at offsets 0x10C and 0x10D, then installs the final vtable pointer off_5ABE28 at offset 0x0. Returns the constructed this pointer.
    // CALL: Delegate vtable/state setup to ConstructorInitVTable with the constant arguments 1 and -1 before the scalar field initialization. [callee:0x00488B00, source:raw]
    // ASSIGNMENT: Zero the eight consecutive DWORD fields at offsets 0xEC, 0xF0, 0xF4, 0xF8, 0xFC, 0x100, 0x104 and 0x108. [field:this:0x000000EC, field:this:0x000000F0, field:this:0x000000F4, field:this:0x000000F8, field:this:0x000000FC, field:this:0x00000100, field:this:0x00000104, field:this:0x00000108]
    // ASSIGNMENT: Zero the two byte flags at offsets 0x10C and 0x10D. [field:this:0x0000010C, field:this:0x0000010D]
    // ASSIGNMENT: Install the final vtable pointer off_5ABE28 at offset 0x0, completing construction. [global:0x005ABE28, field:this:0x00000000]
    // RETURN: Return the constructed this pointer; invoked by sub_493FC0. [function:0x0048AA40, caller:0x00493FC0, source:raw]

    // Conservative worker pseudocode:
    //   DWORD* sub_48AA40(DWORD* this) {
    //     ConstructorInitVTable((int)this, 1, -1);
    //     this[59] = 0; this[60] = 0; this[61] = 0; this[62] = 0;
    //     this[63] = 0; this[64] = 0; this[65] = 0; this[66] = 0;
    //     *(BYTE*)this + 0x10C = 0;
    //     *(BYTE*)this + 0x10D = 0;
    //     this[0] = (DWORD)&off_5ABE28;
    //     return this;
    //   }
    // UNRESOLVED: Meaning of the ConstructorInitVTable arguments 1 and -1 (likely a flag/count pair) is defined by the callee, not this function.
    // UNRESOLVED: Purpose of the zeroed tail region (0xEC-0x10D) is unknown; no accessor evidence ties it to a named subsystem.
}
