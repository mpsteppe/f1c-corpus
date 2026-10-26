// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045D500
// Canonical corpus name: GuardedInitCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedInitCall_0045d500.c

void UnknownObject::GuardedInitCall()
{
    // Conditional initialization wrapper: reads the global byte flag byte_7CE260; when the flag is zero it calls BooleanFlagResetWithSideEffects(this) to reset state and returns that call's result, otherwise it returns the non-zero flag value unchanged. Legacy ABI lead names it Call_init_function_if_global_flag_is_zero. Its only known caller is SessionStateByte7CE25FSetter (0x00464600).
    // ASSIGNMENT: Load the global flag into the result slot: result = byte_7CE260. [global:0x007CE260]
    // GUARD: Branch on the global flag: when byte_7CE260 is zero, take the reinitialization path. [global:0x007CE260]
    // CALL: Call BooleanFlagResetWithSideEffects(this) while the flag is zero and return its value as the function result. [source:raw]
    // RETURN: When the flag is non-zero, return the flag value that was read from byte_7CE260. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_45D500(char* this) {
    //     char flag = byte_7CE260;
    //     if (!byte_7CE260)
    //       return BooleanFlagResetWithSideEffects(this);
    //     return flag;
    //   }
    // UNRESOLVED: Identity and semantics of BooleanFlagResetWithSideEffects are unknown; it is absent from the packet callee list.
    // UNRESOLVED: Meaning of the byte_7CE260 flag and the object type behind this are not established; the legacy ABI label (Call_init_function_if_global_flag_is_zero) is the only naming lead.
    // UNRESOLVED: The single known caller SessionStateByte7CE25FSetter (0x00464600) suggests a session-state relationship, but how it drives the flag is not shown here.
}
