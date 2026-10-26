// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D0EC0
// Canonical corpus name: ArithmeticComparison_0ec0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_0ec0_004d0ec0.c

void UnknownObject::ValueSetterWithNotifyGate()
{
    // Setter with a conditional notify/dispatch gate. Stores argument a2 at this+0x0 unconditionally, then inspects two independent notification flags (this+0x4 and this+0x8). If the flag at this+0x4 was non-zero it calls sub_5506A0(a2, 0, 0) and keeps the result; if the flag at this+0x8 is non-zero it calls sub_5506A0(a2, 0, 0) again and returns that result directly. Called by PitTimer (004d2e50) and Steward_Restart (004d3cf0) as a value-update with optional downstream notification.
    // ASSIGNMENT: Stores the incoming value a2 at this+0x0; this store happens unconditionally, before either notification gate is tested [field:this:0x00000000, source:raw]
    // GUARD: First notify gate: the flag at this+0x4, read before the store, is tested; dispatch only happens when it is non-zero [field:this:0x00000004, source:raw]
    // CALL: When the this+0x4 gate was non-zero, calls sub_5506A0(a2, 0, 0) and keeps its result as the candidate return value [callee:0x005506A0, field:this:0x00000004, source:raw]
    // GUARD: Second notify gate: the flag at this+0x8 is tested independently and may trigger dispatch even when the this+0x4 gate was clear [field:this:0x00000008, source:raw]
    // CALL: When the this+0x8 gate is non-zero, calls sub_5506A0(a2, 0, 0) again and returns its result directly, overriding the earlier candidate [callee:0x005506A0, field:this:0x00000008, source:raw]
    // RETURN: Returns the second call's result when this+0x8 is non-zero, otherwise the first call's result (or the uninitialized result variable when both gates were clear) [field:this:0x00000008, source:raw]
    // CALL: Invoked as a value update by PitTimer (004d2e50) and by Steward_Restart (004d3cf0) [caller:0x004D2E50, caller:0x004D3CF0, source:raw]

    // Conservative worker pseudocode:
    //   notify1 = this[0x4/4];
    //   this[0x0/4] = a2;
    //   result = notify1 ? sub_5506A0(a2, 0, 0) : <undefined>;
    //   if (this[0x8/4]) return sub_5506A0(a2, 0, 0);
    //   return result;
    // UNRESOLVED: Purpose of sub_5506A0 (notify / validate / dispatch) is not resolvable from this packet; its parameter convention is unknown
    // UNRESOLVED: Both gates dispatch the same call with the same arguments (a2, 0, 0); the reason for two separate gates is not visible here
    // UNRESOLVED: When neither gate is set, the decompiled result variable is returned without initialization; whether that path is reachable cannot be resolved from this packet
}
