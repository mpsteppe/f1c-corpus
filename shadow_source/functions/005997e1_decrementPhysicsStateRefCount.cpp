// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005997E1
// Canonical corpus name: PhysicsStateAccessor
// Owner: UnknownObject [DERIVED]
// Raw source: functions/PhysicsStateAccessor_005997e1.c

void UnknownObject::decrementPhysicsStateRefCount()
{
    // Wrapper that returns the result of decrementing the reference count (with dead-object check) of the global physics-state object at 0x008D4438.
    // CALL: Call RefCountDecrementWithCheck with the address of global object unk_8D4438 as the single argument; the object is destroyed when its reference count reaches zero. [source:raw, global:0x008D4438]
    // RETURN: Return the integer result of RefCountDecrementWithCheck directly. [source:raw]

    // Conservative worker pseudocode:
    //   int decrementPhysicsStateRefCount(void) {
    //       return RefCountDecrementWithCheck(&unk_8D4438);
    //   }
    // UNRESOLVED: The absolute address of RefCountDecrementWithCheck is not present in the packet (no callee evidence).
    // UNRESOLVED: The class type and identity of the global object unk_8D4438 are unknown.
    // UNRESOLVED: Whether this wrapper is a static exit/teardown trampoline or a live-method call site is unresolved.
}
