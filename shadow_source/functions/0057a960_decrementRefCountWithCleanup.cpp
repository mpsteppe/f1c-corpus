// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A960
// Canonical corpus name: sub_57A960
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57A960_0057a960.c

void UnknownObject::decrementRefCountWithCleanup()
{
    // Thin wrapper with no local state or branching: tail-calls the helper the decompiler names RefCountDecrementWithCleanup() and forwards its result as the return value. The packet-listed read of global 0x008D3BF5 is not visible in the wrapper body and is presumably consumed inside the helper. A neighboring wrapper passes this function's address as a cleanup routine, suggesting a cleanup/callback registration role, which is unconfirmed here.
    // CALL: Tail-call the helper the decompiler names RefCountDecrementWithCleanup(); the helper has no packet address so no call target is named. [function:0x0057A960, source:raw]
    // RETURN: Forward the helper's result as this function's return value. [function:0x0057A960, source:raw]

    // Conservative worker pseudocode:
    //   return RefCountDecrementWithCleanup();
    // UNRESOLVED: RefCountDecrementWithCleanup has no address or call target in the packet (callees empty); only the decompiler name is known.
    // UNRESOLVED: Packet lists a read of global 0x008D3BF5 but the wrapper body shows no direct access; the read is assumed to occur inside the helper. Relationship unproven.
    // UNRESOLVED: A neighboring wrapper passes this function's address as a cleanup routine, implying a cleanup/callback role, but that cross-packet relationship is not part of this function's evidence.
}
