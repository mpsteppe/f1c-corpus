// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587410
// Canonical corpus name: sub_587410
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_587410_00587410.c

void UnknownObject::decrementRefCountWithCleanup()
{
    // Wrapper that calls RefCountDecrementWithCleanup() and returns its result. The read of global 0x008D3E35 is not visible in the decompiled body.
    // CALL: Invoke RefCountDecrementWithCleanup() and use its return value as this function's result. [function:0x00587410, source:raw]
    // RETURN: Return the value produced by RefCountDecrementWithCleanup(). [function:0x00587410, source:raw]

    // Conservative worker pseudocode:
    //   return RefCountDecrementWithCleanup();
    // UNRESOLVED: Global 0x008D3E35 is read per the packet but does not appear in the decompiled body; its role in the refcount-decrement/cleanup path is unresolved.
    // UNRESOLVED: RefCountDecrementWithCleanup is not present in packet callees, so its target address is unknown.
}
