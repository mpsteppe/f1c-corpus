// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8A70
// Canonical corpus name: RandomParameterDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RandomParameterDispatch_004f8a70.c

void UnknownObject::RandomParameterDispatch()
{
    // Draws a random value from the LCG generator on the receiver, maps it into one of three parameter buckets (20, 19 or 18) via the thresholds 10922 and 21844, and passes the selected bucket to HUDElementConfig together with a fixed mode 2 and float 1.0/1.0. Returns the HUDElementConfig result. With an LCG output range up to 32767 the two thresholds split the range into approximately equal thirds.
    // CALL: Call RandLCGRandomNumberGenerator(this) and store its output as v2. [callee:0x005884ED, source:raw]
    // GUARD: Branch on v2 >= 10922; the else path selects parameter 20 for low random values. [source:raw]
    // ASSIGNMENT: Assign v3 = 20 when v2 is below the 10922 threshold. [source:raw]
    // GUARD: Nested branch on v2 < 21844 to distinguish the middle third from the top third. [source:raw]
    // CALCULATION: Compute v3 = (v2 < 21844) + 18, yielding 19 for the middle third and 18 for the top third. [source:raw]
    // CALL: Call HUDElementConfig(this, v3, 2, 1.0, 1.0) with the selected parameter and return its result. [callee:0x004F87C0, source:raw]
    // CALL: Invoked by sub_4B3400 (0x004B3400) as part of its element update dispatch. [caller:0x004B3400, source:raw]

    // Conservative worker pseudocode:
    //   v2 = RandLCGRandomNumberGenerator(this);
    //   if (v2 >= 10922)
    //     v3 = (v2 < 21844) + 18;   // 19 or 18
    //   else
    //     v3 = 20;
    //   return HUDElementConfig(this, v3, 2, 1.0f, 1.0f);
    // UNRESOLVED: The LCG output range is not in the packet, so the split of the range among the 10922/21844 thresholds is inferred, not proven.
    // UNRESOLVED: Meaning of the selected parameter v3 and of the fixed HUDElementConfig arguments (2, 1.0, 1.0) is unknown here.
    // UNRESOLVED: The receiver object type and what the random parameter configures are unknown.
}
