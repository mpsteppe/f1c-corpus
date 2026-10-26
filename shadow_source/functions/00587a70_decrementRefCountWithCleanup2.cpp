// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587A70
// Canonical corpus name: sub_587A70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_587A70_00587a70.c

void UnknownObject::decrementRefCountWithCleanup2()
{
    // Thin single-expression wrapper around RefCountDecrementWithCleanup: calls it with no visible arguments and returns its result unchanged. Deterministic facts also record a read of the module global unk_8D3E3D by this function, though the decompiled body shows no direct reference to it.
    // CALL: Call RefCountDecrementWithCleanup() and use its return value as this function's result; the decompiled body is a single-expression wrapper. [function:0x00587A70, source:raw]
    // UNKNOWN: Deterministic facts record a read of the module global unk_8D3E3D by this function, but the decompiled body contains no direct reference to it. [global:0x008D3E3D]

    // Conservative worker pseudocode:
    //   return RefCountDecrementWithCleanup();
    // UNRESOLVED: How unk_8D3E3D is read (argument setup, inlined prologue, or thunk linkage) is not visible in this packet's source text.
    // UNRESOLVED: The identity of the object whose reference count is decremented is unknown; RefCountDecrementWithCleanup has no call-target evidence reference in this packet.
    // UNRESOLVED: Whether the cleanup has side effects beyond the ref-count decrement depends on the callee, which is outside this packet.
}
