// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005997B7
// Canonical corpus name: PhysicsStateCleanupWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsStateCleanupWrapper_005997b7.c

void UnknownObject::PhysicsStateCleanupWrapper()
{
    // Thin single-expression wrapper around RefCountDecrementWithCleanup: calls it with no visible arguments and returns its result. Deterministic facts also record a read of the module global unk_8D4439 by this function, though the decompiled body shows no direct reference to it.
    // CALL: Call RefCountDecrementWithCleanup and use its return value as the function result; the decompiled body is a single-expression wrapper. [source:raw]
    // UNKNOWN: Deterministic facts record a read of the module global unk_8D4439 by this function, but the decompiled body contains no direct reference to it. [global:0x008D4439]

    // Conservative worker pseudocode:
    //   int sub_5997B7() {
    //     return RefCountDecrementWithCleanup();
    //   }
    // UNRESOLVED: How unk_8D4439 is read (argument setup, inlined prologue, or thunk linkage) is not visible in this packet's source text.
    // UNRESOLVED: The identity of the object whose reference count is decremented is unknown; RefCountDecrementWithCleanup has no call-target evidence reference in this packet.
    // UNRESOLVED: Whether the cleanup has side effects beyond the ref-count decrement depends on the callee, which is outside this packet.
}
