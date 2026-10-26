// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D8720
// Canonical corpus name: UtilityFunction_8720
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_8720_004d8720.c

void UnknownObject::AudioReleaseAndCleanup()
{
    // Teardown helper on the race/session path: first calls sub_4D8FB0 (pre-reset), then releases audio resources for types 1 through 5 via AudioResourceReleaseByType, and finally returns the result of a thiscall dispatch/cleanup on `this` (target address absent from packet callee evidence). Invoked by OnScreen_Post (0049F0D0) and RaceInitWithConstants (004D8220).
    // CALL: Call sub_4D8FB0() before releasing audio resources. [callee:0x004D8FB0, source:raw]
    // CALL: Release audio resource type 1 via AudioResourceReleaseByType. [callee:0x004D9030, source:raw]
    // CALL: Release audio resource type 2 via AudioResourceReleaseByType. [callee:0x004D9030, source:raw]
    // CALL: Release audio resource type 3 via AudioResourceReleaseByType. [callee:0x004D9030, source:raw]
    // CALL: Release audio resource type 4 via AudioResourceReleaseByType. [callee:0x004D9030, source:raw]
    // CALL: Release audio resource type 5 via AudioResourceReleaseByType. [callee:0x004D9030, source:raw]
    // RETURN: Return the result of a thiscall dispatch/cleanup call on `this`; the callee address is not present in the packet evidence. [source:raw]
    // CALL: Called by OnScreen_Post (0049F0D0) and RaceInitWithConstants (004D8220) during race/session teardown. [caller:0x0049F0D0, caller:0x004D8220, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D8720(void *this) {
    //     sub_4D8FB0();
    //     AudioResourceReleaseByType(1);
    //     AudioResourceReleaseByType(2);
    //     AudioResourceReleaseByType(3);
    //     AudioResourceReleaseByType(4);
    //     AudioResourceReleaseByType(5);
    //     return DispatchAndCleanup(this);
    //   }
    // UNRESOLVED: Target address and semantics of the final thiscall dispatch/cleanup (raw source names it BatchVTableDispatchAndCleanup) are absent from the callee evidence.
    // UNRESOLVED: Purpose of sub_4D8FB0 and the exact audio resource type meaning (1..5) are not established.
}
