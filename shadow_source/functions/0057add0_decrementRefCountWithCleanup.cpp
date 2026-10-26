// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057ADD0
// Canonical corpus name: sub_57ADD0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57ADD0_0057add0.c

void UnknownObject::decrementRefCountWithCleanup()
{
    // Thin wrapper with no local state or branching: tail-calls the helper the decompiler names RefCountDecrementWithCleanup() and forwards its result as the return value. The packet-listed read of global 0x008D3BF9 is not visible in the wrapper body and is presumably consumed inside the helper.
    // CALL: Tail-call the helper the decompiler names RefCountDecrementWithCleanup(); the helper has no packet address so no call target is named. [function:0x0057ADD0, source:raw]
    // RETURN: Forward the helper's result as this function's return value. [function:0x0057ADD0, source:raw]

    // Conservative worker pseudocode:
    //   return RefCountDecrementWithCleanup();
    // UNRESOLVED: RefCountDecrementWithCleanup has no address or call target in the packet (callees empty); only the decompiler name is known.
    // UNRESOLVED: Packet lists a read of global 0x008D3BF9 but the wrapper body shows no direct access; the read is assumed to occur inside the helper. Relationship unproven.
}
