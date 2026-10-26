// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00599232
// Canonical corpus name: ConditionalDelegateCallWithNullGuard
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalDelegateCallWithNullGuard_00599232.c

void UnknownObject::delegateCallWithNullGuard()
{
    // Reads a delegate pointer at this+0x50; returns 0 if it is NULL or the delegate call sub_59BB00(v4, a2, 0, a3) reports failure, otherwise returns this.
    // ASSIGNMENT: v4 loaded from this[20] (delegate pointer at offset this+0x50). [field:this:0x00000050, source:raw]
    // GUARD: If v4 is NULL, function returns 0 immediately without calling the delegate. [source:raw]
    // CALL: Delegate sub_59BB00 invoked with (v4, a2, 0, a3); a constant 0 is passed as third argument. [callee:0x0059BB00]
    // GUARD: If sub_59BB00 returns non-zero (failure), function returns 0. [source:raw]
    // RETURN: Returns this on success, 0 when the delegate is NULL or the delegate call fails. [source:raw, function:0x00599232]

    // Conservative worker pseudocode:
    //   v4 = this[20];
    //   if (v4 == 0) return 0;
    //   if (sub_59BB00(v4, a2, 0, a3) != 0) return 0;
    //   return this;
    // UNRESOLVED: Semantics of sub_59BB00's return value and the meaning of its constant 0 argument are unknown.
    // UNRESOLVED: The object type owning the delegate pointer at this+0x50 is unidentified.
}
