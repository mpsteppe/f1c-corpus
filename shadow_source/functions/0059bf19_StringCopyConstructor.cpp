// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059BF19
// Canonical corpus name: StringCopyConstructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCopyConstructor_0059bf19.c

void UnknownObject::StringCopyConstructor()
{
    // thiscall string copy constructor for the exception object. Sets the vtable (this+0x0) to the exception vftable (??_7exception@@6B@), measures the source string (*a2) with Strlen, allocates length+1 bytes via OperatorNewNhMallocWrapper, stores the buffer pointer at this+0x4, calls sub_58FCA0 to initialize/copy the string data when the allocation succeeded, sets the ownership/refcount flag this+0x8 to 1, and returns this.
    // ASSIGNMENT: Install the exception vftable (??_7exception@@6B@) as the object vtable at this+0x0. [field:this:0x00000000, global:0x005B9DC0]
    // CALL: Strlen(*a2) computes the length of the source string. [callee:0x0058E1B0]
    // CALL: OperatorNewNhMallocWrapper(length + 1) allocates a heap buffer large enough for the string copy including its terminator. [callee:0x00587C03]
    // ASSIGNMENT: Store the allocated buffer pointer at this+0x4. [field:this:0x00000004]
    // GUARD: sub_58FCA0() runs only when the allocation returned a nonzero buffer pointer; on null allocation this+0x4 stays null. [callee:0x0058FCA0]
    // CALL: sub_58FCA0() initializes/copies the string data into the newly allocated buffer. [callee:0x0058FCA0]
    // ASSIGNMENT: Set the ownership/refcount flag at this+0x8 to 1. [field:this:0x00000008]
    // RETURN: Return the constructed object pointer this. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* StringCopyConstructor(_DWORD* this, _DWORD** a2) {
    //     this[0] = &exception::vftable;
    //     int len = Strlen(*a2);
    //     int buf = OperatorNewNhMallocWrapper(len + 1);
    //     this[1] = buf;
    //     if (buf) sub_58FCA0();
    //     this[2] = 1;
    //     return this;
    //   }
    // UNRESOLVED: sub_58FCA0 is a jump thunk (its own IR records an unconditional control transfer with no local return); the actual copy routine is reached through that transfer, outside this packet.
    // UNRESOLVED: The specific exception type owning the vtable ??_7exception@@6B@ is not established by this packet alone.
}
