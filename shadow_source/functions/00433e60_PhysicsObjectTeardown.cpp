// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00433E60
// Canonical corpus name: PhysicsObjectDestructor_3e60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsObjectDestructor_3e60_00433e60.c

void UnknownObject::PhysicsObjectTeardown()
{
    // Session/object teardown helper (__thiscall). Default-initializes the object, then conditionally frees three owned sub-buffers stored at offsets 0, 8 and 20, and finally frees the object itself when the low bit of the flags argument a2 is set. Returns the object pointer. Structural twin of PhysicsObjectDestructor per the packet prelabel.
    // CALL: Default-initialize the object via SessionConfigDefaultInit before any teardown. [callee:0x00432CC0, source:raw]
    // GUARD: Guard: free the sub-buffer at this + 20 only when the pointer at this + 20 is non-zero. [field:this:0x00000014]
    // CALL: Free the sub-buffer held at this + 20 via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x00000014]
    // GUARD: Guard: free the sub-buffer at this + 8 only when the pointer at this + 8 is non-zero. [field:this:0x00000008]
    // CALL: Free the sub-buffer held at this + 8 via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x00000008]
    // GUARD: Guard: free the sub-buffer at offset 0 of this only when the pointer is non-zero. [field:this:0x00000000]
    // CALL: Free the sub-buffer held at offset 0 of this via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x00000000]
    // GUARD: Guard: when bit 0 of the flags argument a2 is set, free the object itself. [source:raw]
    // CALL: Free the object itself via FreeWrapper_7bcf when the flag bit is set. [callee:0x00587BCF, source:raw]
    // RETURN: Return the object pointer this. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_433E60(int this, char flags) {
    //     SessionConfigDefaultInit(this);
    //     if (*(int*)(this + 20)) FreeWrapper_7bcf(*(void**)(this + 20));
    //     if (*(int*)(this + 8))  FreeWrapper_7bcf(*(void**)(this + 8));
    //     if (*(int*)this)        FreeWrapper_7bcf(*(void**)this);
    //     if (flags & 1)          FreeWrapper_7bcf((void*)this);
    //     return this;
    //   }
    // UNRESOLVED: Leading SessionConfigDefaultInit on this is unusual for a teardown path; whether it is a placement reset or a mislabeled initializer is unresolved.
    // UNRESOLVED: Semantics of offsets 0, 8 and 20 (which sub-objects they own) are unknown without the owning class layout.
    // UNRESOLVED: Caller LinkedListRemovalByName (0x00433D60) uses this helper; the exact destruction context is not visible here.
}
