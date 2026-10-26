// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048E600
// Canonical corpus name: UIStructInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIStructInit_0048e600.c

void UnknownObject::initUiBaseStruct()
{
    // Initializes the base UI object: runs the shared base initializer ShortComputation_5e30 on this, sets the vtable pointer at offset 0 to off_5AC540, stores a no-selection sentinel (-1) at offset 0xE4, zeroes the dwords at 0xE0, 0xE8 and 0xEC, and copies the default directory string byte_5EA438 through StringCopyWithBufferRealloc. Returns this.
    // CALL: Run the shared base-object initializer ShortComputation_5e30(this) before touching fields. [callee:0x00485E30, source:raw]
    // ASSIGNMENT: Zero the dword at this + 0xE0 (this[56]). [field:this:0x000000E0, source:raw]
    // ASSIGNMENT: Set the dword at this + 0xE4 (this[57]) to -1, a no-selection / invalid-handle sentinel. [field:this:0x000000E4, source:raw]
    // ASSIGNMENT: Set the vtable pointer *this to off_5AC540. [field:this:0x00000000, global:0x005AC540, source:raw]
    // CALL: Copy the default directory string byte_5EA438 into the object's string buffer via StringCopyWithBufferRealloc. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Zero the dword at this + 0xE8 (this[58]). [field:this:0x000000E8, source:raw]
    // ASSIGNMENT: Zero the dword at this + 0xEC (this[59]). [field:this:0x000000EC, source:raw]
    // RETURN: Return the constructed this pointer. [source:raw]
    // CALL: Called from sub_466090 and sub_493FC0 during UI object construction. [caller:0x00466090, caller:0x00493FC0]

    // Conservative worker pseudocode:
    //   void initUiBaseStruct(void* this) {
    //     ShortComputation_5e30(this);
    //     this[56] = 0;
    //     this[57] = -1;
    //     *(void**)this = &off_5AC540;
    //     StringCopyWithBufferRealloc(byte_5EA438);
    //     this[58] = 0;
    //     this[59] = 0;
    //     return this;
    //   }
    // UNRESOLVED: The purpose of the zeroed dwords at this + 0xE0, 0xE8 and 0xEC is not established by the packet; the sentinel -1 at 0xE4 suggests an invalid-handle marker but its consumer is unknown.
    // UNRESOLVED: The exact role of byte_5EA438 (named default application directory by existing analysis) and what StringCopyWithBufferRealloc stores is not documented in the packet.
}
