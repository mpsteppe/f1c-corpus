// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048C070
// Canonical corpus name: sub_48C070
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_48C070_0048c070.c

void UnknownObject::HUDTimerConstructor()
{
    // Constructor for a HUD timer widget object. Delegates to the base initializer ConstructorWithStringCopy, then installs the HUD timer vtable pointer (off_5ABF88), stores the parameter a2 at this+0x308, enables two byte flags at this+0x304 and this+0x305, and initializes counters/fields at this+0x30C..this+0x318. Returns the constructed object pointer.
    // CALL: Call base initializer ConstructorWithStringCopy (0x0048B420) on this with six zero arguments. [callee:0x0048B420, source:raw]
    // ASSIGNMENT: Store parameter a2 at this[194] (this+0x308). [field:this:0x00000308, source:raw]
    // ASSIGNMENT: Set byte flag at this+0x304 (byte offset 772) to 1. [field:this:0x00000304, source:raw]
    // ASSIGNMENT: Set byte flag at this+0x305 (byte offset 773) to 1. [field:this:0x00000305, source:raw]
    // ASSIGNMENT: Set this[197] (this+0x314) to 1. [field:this:0x00000314, source:raw]
    // ASSIGNMENT: Install the vtable pointer: *this = &off_5ABF88 (HUD timer vtable). [field:this:0x00000000, global:0x005ABF88, source:raw]
    // ASSIGNMENT: Zero this[198] (this+0x318). [field:this:0x00000318, source:raw]
    // ASSIGNMENT: Zero this[195] (this+0x30C). [field:this:0x0000030C, source:raw]
    // ASSIGNMENT: Zero this[196] (this+0x310). [field:this:0x00000310, source:raw]
    // RETURN: Return the constructed object pointer (this). [function:0x0048C070, source:raw]

    // Conservative worker pseudocode:
    //   DWORD *sub_48C070(DWORD *this, int a2) {
    //     ConstructorWithStringCopy(this, 0, 0, 0, 0, 0, 0);
    //     this[194] = a2;
    //     *((BYTE *)this + 772) = 1;
    //     *((BYTE *)this + 773) = 1;
    //     this[197] = 1;
    //     *this = &off_5ABF88;
    //     this[198] = 0;
    //     this[195] = 0;
    //     this[196] = 0;
    //     return this;
    //   }
    // UNRESOLVED: The semantics of parameter a2 (timer ID, interval, or callback handle) are unknown.
    // UNRESOLVED: The roles of this+0x304/0x305 byte flags and this+0x314/0x318 fields are not independently confirmed beyond the literal init values.
    // UNRESOLVED: The vtable at off_5ABF88 is not inspected; the HUD timer behavior is inferred only from the constructor shape and caller context.
}
