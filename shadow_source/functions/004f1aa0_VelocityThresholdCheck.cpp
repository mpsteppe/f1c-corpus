// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F1AA0
// Canonical corpus name: VelocityThresholdCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VelocityThresholdCheck_004f1aa0.c

void UnknownObject::VelocityThresholdCheck()
{
    // Gate used by the contact/collision system. If the enable flag at this+0x32BC is zero, returns the default value byte_7C9080 immediately. Otherwise reads the velocity value at this+0x3444 and returns true only when it lies in [2, 4] and either the FPU condition flags (C0/C2) are clear or DistanceComparison((float*)this) is false.
    // GUARD: If the enable flag at this+0x32BC is zero, skip the check and return the default value byte_7C9080 [field:this:0x000032BC, global:0x007C9080, source:raw]
    // ASSIGNMENT: Read the velocity value at this+0x3444 into v2 [field:this:0x00003444, source:raw]
    // GUARD: Require v2 to be >= 2 and <= 4 for the check to pass [field:this:0x00003444, source:raw]
    // GUARD: When either FPU condition flag (C0/C2) is set, additionally require DistanceComparison((float*)this) to return false [callee:0x004EFFD0, source:raw]
    // CALL: DistanceComparison compares a distance metric using this as a float pointer when the flag test fails [callee:0x004EFFD0, source:raw]
    // RETURN: Return the conjunction of the range check and the flag/distance guard; called from sub_49B7A0 and sub_4F0430 [function:0x004F1AA0, caller:0x0049B7A0, caller:0x004F0430, source:raw]

    // Conservative worker pseudocode:
    //   if (!this->enable_flag_0x32BC) return byte_7C9080;
    //   v2 = this->velocity_0x3444;
    //   in_range = (v2 >= 2 && v2 <= 4);
    //   flags_ok = !(C0 | C2);
    //   return in_range && (flags_ok || !DistanceComparison((float*)this));
    // UNRESOLVED: The source of the C0/C2 FPU condition flags is an earlier floating-point compare that is not present in this packet; the thresholds it compared are unknown
    // UNRESOLVED: The float constant flt_59E43C is listed as a global of this function but does not appear in the raw pseudocode; its role (likely a threshold feeding the prior FPU compare) cannot be confirmed from this packet alone
    // UNRESOLVED: byte_7C9080 is a shared default-return value whose wider meaning is external to this packet
}
