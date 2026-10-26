// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049F150
// Canonical corpus name: FunctionCallWrapper_f150
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionCallWrapper_f150_0049f150.c

void UnknownObject::FunctionCallWrapper_f150()
{
    // SessionInitFlagSetter: stores the integer argument a2 into this+0x0 and writes the global byte_8AD384 flag to 1 exactly when a2 equals 1, returning the boolean result of that equality test. Existing analysis (skeletons_filled/FunctionCallWrapper_f150_0049f150.md) reads this+0x0 as a mode/state value taken from the caller's dispatch result and byte_8AD384 as a session-init-complete flag.
    // ASSIGNMENT: Store the argument a2 into the mode/state word at this+0x0 [field:this:0x00000000, source:raw]
    // CALCULATION: Test whether a2 equals 1 to produce the boolean result returned to the caller [source:raw]
    // ASSIGNMENT: Write the global byte_8AD384 flag as 1 when a2 equals 1 (session init complete), 0 otherwise [global:0x008AD384, source:raw]
    // RETURN: Return the boolean (a2 == 1); callers are OnScreen_Restart (0049F000) and ModeBasedDispatch (0049F790) [caller:0x0049F000, caller:0x0049F790, source:raw]

    // Conservative worker pseudocode:
    //   this[0] = a2;
    //   bool result = (a2 == 1);
    //   byte_8AD384 = result;
    //   return result;
    // UNRESOLVED: The semantics of a2 and of this+0x0 (mode vs state) are only DERIVED from the existing skeleton analysis, not confirmed by this packet
    // UNRESOLVED: The meaning of byte_8AD384 as a session-init-complete flag comes from the existing analysis and is not independently established here
}
