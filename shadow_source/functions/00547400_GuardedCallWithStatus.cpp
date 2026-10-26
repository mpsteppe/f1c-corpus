// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00547400
// Canonical corpus name: GuardedCallWithStatus
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedCallWithStatus_00547400.c

void UnknownObject::GuardedCallWithStatus()
{
    // __stdcall status wrapper: if argument a1 is non-null it calls sub_548620(a1) and returns -1 when that call reports failure, otherwise it returns 0. When a1 is null it short-circuits and returns 0 without calling the callee. Used by ObjectAllocationWithInit as a guarded post-init status check.
    // GUARD: Short-circuit guard on a1: the callee is invoked only when a1 is non-null. [source:raw]
    // CALL: When a1 is non-null, call sub_548620(a1); a non-zero result makes the wrapper return -1. [callee:0x00548620]
    // RETURN: Return -1 on callee-reported failure, otherwise return 0 (including the a1 == null short-circuit path). [source:raw]

    // Conservative worker pseudocode:
    //   int __stdcall sub_547400(int a1) {
    //     if (a1 && sub_548620(a1)) return -1;
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of sub_548620 and the object that a1 points to.
    // UNRESOLVED: Whether the non-zero callee result is a genuine error code or a boolean failure flag.
}
