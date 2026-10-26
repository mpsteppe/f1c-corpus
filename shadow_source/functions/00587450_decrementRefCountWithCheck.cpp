// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587450
// Canonical corpus name: sub_587450
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_587450_00587450.c

void UnknownObject::decrementRefCountWithCheck()
{
    // Wrapper that calls RefCountDecrementWithCheck() and returns its pointer result. The read of global 0x008D3E34 is not visible in the decompiled body.
    // CALL: Invoke RefCountDecrementWithCheck() and use its return value as this function's result. [function:0x00587450, source:raw]
    // RETURN: Return the char* value produced by RefCountDecrementWithCheck(). [function:0x00587450, source:raw]

    // Conservative worker pseudocode:
    //   return RefCountDecrementWithCheck();
    // UNRESOLVED: Global 0x008D3E34 is read per the packet but does not appear in the decompiled body; its role in the refcount-decrement/check path is unresolved.
    // UNRESOLVED: RefCountDecrementWithCheck is not present in packet callees, so its target address is unknown.
}
