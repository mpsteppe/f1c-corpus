// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00490250
// Canonical corpus name: ObjectInitWithFieldZeroing_0250
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitWithFieldZeroing_0250_00490250.c

void UnknownObject::initWidgetList()
{
    // Unconditional initializer: runs the shared base initializer ShortComputation_5e30 on this, zeroes five consecutive dwords from 0xE0 through 0xF0 (this[56]..this[60]), sets the vtable pointer at offset 0 to off_5AC760, and returns this.
    // CALL: Run the shared base-object initializer ShortComputation_5e30(this) before touching fields. [callee:0x00485E30, source:raw]
    // ASSIGNMENT: Zero the dword at this + 0xE0 (this[56]). [field:this:0x000000E0, source:raw]
    // ASSIGNMENT: Zero the dword at this + 0xE4 (this[57]). [field:this:0x000000E4, source:raw]
    // ASSIGNMENT: Zero the dword at this + 0xE8 (this[58]). [field:this:0x000000E8, source:raw]
    // ASSIGNMENT: Zero the dword at this + 0xEC (this[59]). [field:this:0x000000EC, source:raw]
    // ASSIGNMENT: Zero the dword at this + 0xF0 (this[60]). [field:this:0x000000F0, source:raw]
    // ASSIGNMENT: Set the vtable pointer *this to off_5AC760. [field:this:0x00000000, global:0x005AC760, source:raw]
    // RETURN: Return the initialized this pointer. [source:raw]
    // CALL: Called from sub_493FC0 during UI widget-list construction. [caller:0x00493FC0]

    // Conservative worker pseudocode:
    //   void initWidgetList(void* this) {
    //     ShortComputation_5e30(this);
    //     this[56] = 0;
    //     this[57] = 0;
    //     this[58] = 0;
    //     this[59] = 0;
    //     this[60] = 0;
    //     *(void**)this = &off_5AC760;
    //     return this;
    //   }
    // UNRESOLVED: The purpose of the five zeroed dwords at this + 0xE0 through 0xF0 is not established by the packet; existing analysis (widget list) is a proposal without packet corroboration.
}
