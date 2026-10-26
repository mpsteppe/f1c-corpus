// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00599AD9
// Canonical corpus name: RefCountDecrementWithCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RefCountDecrementWithCheck_00599ad9.c

void UnknownObject::RefCountDecrementWithCheck()
{
    // Decrements a global reference counter at 0x005EA04C; when the counter drops to zero, dispatches StatusCheckWithErrorDispatch on three objects (byte_8D4568, dword_8D4400, dword_8D4440) as cleanup. Wrapped by a frame pair (sub_59A54D enter, sub_59A5E9 leave) and returns either the frame-leave pointer or the last dispatch result.
    // CALL: Enter the SEH/critical-section frame on the local buffer v3 via sub_59A54D. [callee:0x0059A54D]
    // CALCULATION: v0 = (dword_5EA04C-- == 1): post-decrement the reference counter at 0x005EA04C, recording whether it was 1 before the decrement (now zero). [global:0x005EA04C]
    // CALL: Leave the frame via sub_59A5E9(v3); retain its pointer result. [callee:0x0059A5E9]
    // GUARD: If the counter reached zero (v1 true), take the cleanup path. [global:0x005EA04C, source:raw]
    // CALL: Cleanup: dispatch StatusCheckWithErrorDispatch on byte_8D4568. [callee:0x00598AA0, global:0x008D4568]
    // CALL: Cleanup: dispatch StatusCheckWithErrorDispatch on dword_8D4400. [callee:0x00598AA0, global:0x008D4400]
    // CALL: Cleanup: dispatch StatusCheckWithErrorDispatch on dword_8D4440 and return its result. [callee:0x00598AA0, global:0x008D4440]
    // RETURN: On the zero path return the last dispatch result; otherwise return the frame-leave pointer from sub_59A5E9. [source:raw]

    // Conservative worker pseudocode:
    //   char *RefCountDecrementWithCheck() {
    //     _BYTE frame[4];
    //     sub_59A54D(frame);
    //     bool zeroed = (dword_5EA04C-- == 1);
    //     char *r = sub_59A5E9(frame);
    //     if (zeroed) {
    //       StatusCheckWithErrorDispatch(byte_8D4568);
    //       StatusCheckWithErrorDispatch(dword_8D4400);
    //       return StatusCheckWithErrorDispatch(dword_8D4440);
    //     }
    //     return r;
    //   }
    // UNRESOLVED: Whether sub_59A54D/sub_59A5E9 are an SEH frame pair or a critical-section enter/leave is unproven.
    // UNRESOLVED: The semantic roles of byte_8D4568, dword_8D4400 and dword_8D4440 (which objects are finalized when the reference count reaches zero) are not established by the packet.
    // UNRESOLVED: No static caller is known, so the object graph guarded by the counter is unidentified.
}
