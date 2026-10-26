// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598C70
// Canonical corpus name: NullCheckWithVirtualDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NullCheckWithVirtualDispatch_00598c70.c

void UnknownObject::NullCheckWithVirtualDispatch()
{
    // Conditional release path: if the object pointer at this+0 is non-null, calls RefcountDecrementWithLock (00598C88) to obtain a vtable-like pointer, and if that result is also non-null, invokes virtual method slot 0 on it with argument 1 (thiscall). Returns void. Packets label it a structural twin of ConditionalFreeWithBit0Flag (00404F70).
    // GUARD: Guard on the object pointer at this+0 being non-null; skip everything when it is null. [field:this:0x00000000, source:raw]
    // CALL: Call RefcountDecrementWithLock (00598C88) and store its result as the vtable-like pointer v1. [callee:0x00598C88, source:raw]
    // GUARD: Guard on v1 being non-null before dispatching. [source:raw]
    // CALL: Invoke virtual slot 0 through v1 as a thiscall with argument 1; the concrete method target is only known at runtime. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_598C70(void *this) {
    //     if (*(DWORD *)this) {
    //       void ***v1 = (void ***)RefcountDecrementWithLock();
    //       if (v1)
    //         (*(void (__thiscall **)(void *, int))(*v1))(v1, 1);
    //     }
    //   }
    //   
    //   // called from destructor-style paths: 00598E39, 005994BC, 00599E71, 0059A473, 0059A86C
    // UNRESOLVED: The concrete class behind this and the method invoked through virtual slot 0 are only determinable at runtime.
    // UNRESOLVED: Purpose of the argument 1 passed to the virtual call (refcount/flag semantics) is unknown here.
    // UNRESOLVED: Relationship to the cluster twin ConditionalFreeWithBit0Flag (00404F70) is structural only, not semantically proven.
}
