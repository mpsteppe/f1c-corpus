// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00541040
// Canonical corpus name: DrainingLoopFinalizer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DrainingLoopFinalizer_00541040.c

void UnknownObject::DrainingLoopFinalizer()
{
    // Resource teardown finalizer. Guarded on a2 non-null and its state handle a2+24 non-null: drains the counter at a2+12 to zero by repeatedly calling GuardedVirtualDecrement(a2), caches the state pointer a2+24, zeroes the counter, invokes a virtual __stdcall method through vtable slot 8 of the cached state and stores its result into *this (this+0x0), then clears a2+24 back to 0.
    // GUARD: Outer guard: the teardown runs only when a2 is non-null AND the state handle/pointer at a2+24 is non-null. [function:0x00541040, source:raw]
    // LOOP: Drain loop: while the counter at a2+12 is greater than 0, call GuardedVirtualDecrement(a2); the loop terminates once the counter reaches zero. [callee:0x005410F0, source:raw]
    // ASSIGNMENT: Cache v3 = *(a2+24), the state pointer that will receive the virtual call. [source:raw]
    // ASSIGNMENT: Zero the drained counter at a2+12 after the loop completes. [source:raw]
    // CALL: Indirect virtual call: read the vtable from *v3 and call the __stdcall method at vtable slot offset 8 with v3 as argument; store its result into *this (field this+0x0). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clear the state handle at a2+24 back to 0, marking the object released. Invoked from render-target, audio and resource teardown paths (RenderTargetCleanup, AudioResourceFree, ResourceTeardownWithStateArrayReset). [caller:0x0053F270, caller:0x00540CB0, caller:0x00558990, source:raw]

    // Conservative worker pseudocode:
    //   void DrainingLoopFinalizer(_DWORD *this, int a2) {
    //     if (a2 && *(int*)(a2 + 24)) {
    //       while (*(int*)(a2 + 12) > 0)
    //         GuardedVirtualDecrement(a2);
    //       int v3 = *(int*)(a2 + 24);
    //       *(int*)(a2 + 12) = 0;
    //       *this = (*(int(__stdcall **)(int))(*(int*)v3 + 8))(v3);
    //       *(int*)(a2 + 24) = 0;
    //     }
    //   }
    // UNRESOLVED: The struct layout of a2 is not described by packet fields: offsets +12 (drained counter) and +24 (state handle cleared at the end) appear only in the raw source.
    // UNRESOLVED: The virtual method resolved through vtable slot 8 of v3 is not named; its identity depends on the caller's object type.
    // UNRESOLVED: The prelabel names this a structural twin of SimpleSetterWithSubCall (0040d470); the drain loop and virtual store make the copy label DERIVED only, not a semantic match.
    // UNRESOLVED: The LEGACY ABI lead provides no owner identity or additional semantic signal.
}
