// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C8DC0
// Canonical corpus name: GuardedVirtualCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedVirtualCall_004c8dc0.c

void UnknownObject::GuardedVirtualCall()
{
    // Guarded dispatch through a virtual method table. If the global object pointer dword_8AC4C4 is non-null, loads the object's vtable, selects the method slot at vtable byte offset +80 (index 20), and invokes it thiscall-style as (this=dword_8AC4C4, arg=a1), returning its int result. On the null path the function falls through and returns whatever stale value was left in EAX, since the local result is never assigned in that branch. Called by LoadingPhase2, sub_4B8C40, and ConditionalMultiPathDispatcher.
    // GUARD: Guard on global dword_8AC4C4 being non-null; when it is null the virtual call is skipped and the function falls through. [global:0x008AC4C4, source:raw]
    // CALCULATION: Load the vtable pointer from the object dword_8AC4C4 and select the method slot at byte offset +80. [source:raw]
    // CALL: Invoke the selected __thiscall method as (this=dword_8AC4C4, arg=a1); the call target is data-dependent and resolved through the vtable. [source:raw, function:0x004C8DC0]
    // RETURN: Return the virtual call's int result; on the null-guard path, return an uninitialized EAX value. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C8DC0(int a1) {
    //     if (dword_8AC4C4) {
    //       void* obj = (void*)dword_8AC4C4;
    //       return (*(int (__thiscall **)(void*, int))(*((_DWORD*)obj) + 80))(obj, a1);
    //     }
    //     return /* fall-through, result left uninitialized in EAX * / 0;
    //   }
    // UNRESOLVED: Identity and purpose of the object behind dword_8AC4C4 are unknown; the vtable slot at byte offset +80 is resolved at runtime.
    // UNRESOLVED: On the null-guard path the function returns an uninitialized EAX value; callers appear to tolerate the undefined result.
    // UNRESOLVED: The meaning of argument a1 is caller-defined and not recoverable from this function alone.
}
