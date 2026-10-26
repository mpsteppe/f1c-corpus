// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487F10
// Canonical corpus name: Destructor_7f10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Destructor_7f10_00487f10.c

void UnknownObject::DestructorWithVTableCleanup()
{
    // Scalar-deleting destructor pattern (__thiscall, char flag a2): first performs base vtable cleanup via VTableSetCleanup(this), then conditionally releases the object memory via FreeWrapper_7bcf(this) when the low bit of a2 is set, and returns the this pointer.
    // CALL: Perform base-class vtable cleanup with VTableSetCleanup(this); the effect of this sub-call on object state is owned by callee 00487F30 and not evidenced here. [callee:0x00487F30, function:0x00487F10, source:raw]
    // GUARD: If the low bit of flag a2 is set (a2 & 1 non-zero), the object memory is released; otherwise it is retained (e.g. embedded or member object). [function:0x00487F10, source:raw]
    // CALL: Release the object memory with FreeWrapper_7bcf(this) under the a2 low-bit condition. [callee:0x00587BCF, function:0x00487F10, source:raw]
    // RETURN: Return the this pointer. [function:0x00487F10, source:raw]

    // Conservative worker pseudocode:
    //   void* DestructorWithVTableCleanup(UnknownObject* this, char a2) {
    //     VTableSetCleanup(this);
    //     if (a2 & 1)
    //       FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: The object class owning this destructor pattern is unknown; owner evidence is empty in the packet.
    // UNRESOLVED: The a2 low-bit convention (0 = retain, 1 = release) matches the common scalar-deleting-destructor ABI flag but is not independently confirmed here.
    // UNRESOLVED: The exact vtable cleanup performed by VTableSetCleanup is owned by callee 00487F30 and is not evidenced in this packet.
}
