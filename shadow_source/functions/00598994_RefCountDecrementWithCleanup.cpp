// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598994
// Canonical corpus name: RefCountDecrementWithCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RefCountDecrementWithCleanup_00598994.c

void UnknownObject::RefCountDecrementWithCleanup()
{
    // Decrements a global reference counter (dword_5E9EF4) under a lock acquired by sub_59A54D and released by sub_59A5E9. If the post-decrement test shows the counter reached zero (old value was 1), runs cleanup by dispatching StatusCheckWithErrorDispatch on three globals (unk_8D42A0, dword_8D43C8, dword_8D4210) and returns the last dispatch result. Otherwise returns the lock-release result. Part of teardown for a CRT-like locale/exception management subsystem; has no static callers.
    // CALL: Call sub_59A54D(v3) to acquire the synchronization/lock primitive guarding the reference counter. [callee:0x0059A54D, source:raw]
    // ASSIGNMENT: Post-decrement the global reference counter dword_5E9EF4 and capture whether the old value was 1 (i.e. counter reached zero). [global:0x005E9EF4, source:raw]
    // CALL: Call sub_59A5E9(v3) to release the lock; its return value is kept as the default result. [callee:0x0059A5E9, source:raw]
    // GUARD: Guard: if the counter reached zero (old value was 1), run the cleanup dispatches below. [global:0x005E9EF4, source:raw]
    // CALL: Dispatch StatusCheckWithErrorDispatch on global unk_8D42A0 as part of zero-reached cleanup. [callee:0x00598AA0, global:0x008D42A0, source:raw]
    // CALL: Dispatch StatusCheckWithErrorDispatch on global dword_8D43C8 as part of zero-reached cleanup. [callee:0x00598AA0, global:0x008D43C8, source:raw]
    // CALL: Dispatch StatusCheckWithErrorDispatch on global dword_8D4210 and return its result as the function result. [callee:0x00598AA0, global:0x008D4210, source:raw]
    // RETURN: Return the lock-release result (from sub_59A5E9) when no zero-reached cleanup ran. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_598994() {
    //     int v3;
    //     sub_59A54D(&v3);
    //     bool reachedZero = (dword_5E9EF4-- == 1);
    //     int result = sub_59A5E9(&v3);
    //     if (reachedZero) {
    //       StatusCheckWithErrorDispatch(&unk_8D42A0);
    //       StatusCheckWithErrorDispatch(&dword_8D43C8);
    //       return StatusCheckWithErrorDispatch(dword_8D4210);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Identities and roles of globals unk_8D42A0, dword_8D43C8 and dword_8D4210 (locale/exception-management structures per existing DERIVED analysis, unverified).
    // UNRESOLVED: What StatusCheckWithErrorDispatch does with each global during zero-reached cleanup.
    // UNRESOLVED: Why the lock release result (not a dedicated success value) is returned on the non-cleanup path.
    // UNRESOLVED: No static callers; actual invocation path is unknown.
}
