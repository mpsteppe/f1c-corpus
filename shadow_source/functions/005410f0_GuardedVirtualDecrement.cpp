// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005410F0
// Canonical corpus name: GuardedVirtualDecrement
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedVirtualDecrement_005410f0.c

void UnknownObject::GuardedVirtualDecrement()
{
    // If a2 and the object pointer it holds at +24 are non-null, calls a virtual __stdcall method at vtable offset +48 on that object, stores the returned value into *this, and if the returned value is zero decrements the counter at a2+12.
    // GUARD: Check that a2 is non-null before dereferencing it. [source:raw]
    // GUARD: Check that the object pointer read from a2+24 is non-null before invoking its vtable. [source:raw]
    // CALL: Invoke the virtual __stdcall method at vtable offset +48 on the object pointer read from a2+24. [source:raw]
    // ASSIGNMENT: Store the virtual call return value into the dword pointed to by this (this+0). [field:this:0x00000000, source:raw]
    // CALCULATION: If the stored return value is zero, decrement the counter dword at a2+12. [source:raw]

    // Conservative worker pseudocode:
    //   void release_check(int *this, int a2) {
    //       if (a2) {
    //           int *obj = *(int **)(a2 + 24);
    //           if (obj) {
    //               int v = (*(int (__stdcall **)(void *))(*(_DWORD *)obj + 48))(obj);
    //               *this = v;
    //               if (!v)
    //                   --*(_DWORD *)(a2 + 12);
    //           }
    //       }
    //   }
    // UNRESOLVED: Identity and behavior of the virtual method at vtable offset +48 on the a2+24 object is unknown.
    // UNRESOLVED: Semantics of the counter at a2+12 and of the return value stored into *this (reference/lock count) are unproven.
}
