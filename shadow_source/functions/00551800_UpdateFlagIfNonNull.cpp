// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551800
// Canonical corpus name: ConditionalEntityCallOnNonNull
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalEntityCallOnNonNull_00551800.c

void UnknownObject::UpdateFlagIfNonNull()
{
    // Conditional delegation on a pointer argument: when a1 is non-null, calls FlagUpdateWithCascade (0x005514A0) with a1 and returns its result; when a1 is null, returns the value of the uninitialized local result (eax), which is unspecified. Called from sub_448140 (0x00448140).
    // GUARD: Guard on a1 being non-null; when a1 is null the FlagUpdateWithCascade call is skipped entirely. [source:raw]
    // CALL: Call FlagUpdateWithCascade (0x005514A0) with a1 and return its result when a1 is non-null. [callee:0x005514A0, source:raw]
    // RETURN: When a1 is null, return the uninitialized local result (eax); the returned value is indeterminate. [source:raw]
    // CALL: Invoked by sub_448140 (0x00448140). [caller:0x00448140, source:raw]

    // Conservative worker pseudocode:
    //   int sub_551800(_DWORD *a1) {
    //     int result;  /* uninitialized * /
    //     if (a1)
    //       return FlagUpdateWithCascade(a1);
    //     return result;
    //   }
    // UNRESOLVED: result (eax) is read uninitialized when a1 is null; the intended return value is not evidenced.
    // UNRESOLVED: The entity type of a1 and the meaning of the flag-cascade update are not evidenced in this packet.
}
