// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048E070
// Canonical corpus name: Constructor_e070
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Constructor_e070_0048e070.c

void UnknownObject::constructBinkVideoPlayer()
{
    // Constructor-style initializer: runs the shared base initializer ShortComputation_5e30 on this, sets the vtable pointer at offset 0 to off_5AC3E0, zeroes the dwords at 0xE0, 0xE4 and 0xE8, sets a -1 sentinel at 0xEC, and calls StringCopyWithBufferRealloc with a null argument (string reset). Returns this.
    // CALL: Run the shared base-object initializer ShortComputation_5e30(this) before touching fields. [callee:0x00485E30, source:raw]
    // ASSIGNMENT: Zero the dword at this + 0xE8 (this[58]). [field:this:0x000000E8, source:raw]
    // ASSIGNMENT: Set the dword at this + 0xEC (this[59]) to -1, a no-selection / invalid-handle sentinel. [field:this:0x000000EC, source:raw]
    // ASSIGNMENT: Set the vtable pointer *this to off_5AC3E0. [field:this:0x00000000, global:0x005AC3E0, source:raw]
    // ASSIGNMENT: Zero the dword at this + 0xE0 (this[56]). [field:this:0x000000E0, source:raw]
    // ASSIGNMENT: Zero the dword at this + 0xE4 (this[57]). [field:this:0x000000E4, source:raw]
    // CALL: Call StringCopyWithBufferRealloc with a null argument, resetting the object's string buffer. [callee:0x00566650, source:raw]
    // RETURN: Return the constructed this pointer. [source:raw]
    // CALL: Called from FunctionCallWrapper_8bc0 and sub_493FC0 during object construction. [caller:0x00478BC0, caller:0x00493FC0]

    // Conservative worker pseudocode:
    //   void constructBinkVideoPlayer(void* this) {
    //     ShortComputation_5e30(this);
    //     this[58] = 0;
    //     this[59] = -1;
    //     *(void**)this = &off_5AC3E0;
    //     this[56] = 0;
    //     this[57] = 0;
    //     StringCopyWithBufferRealloc(0);
    //     return this;
    //   }
    // UNRESOLVED: The purpose of the zeroed dwords at this + 0xE0, 0xE4 and 0xE8 and the -1 sentinel at 0xEC is not established by the packet; the existing analysis proposal (Bink video player) is not corroborated by packet facts.
    // UNRESOLVED: The behavior of StringCopyWithBufferRealloc when passed a null argument (string reset) is not documented in the packet.
}
