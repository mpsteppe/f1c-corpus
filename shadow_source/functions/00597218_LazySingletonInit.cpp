// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00597218
// Canonical corpus name: LazyInitSingletonWithFlagGuard_7218
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LazyInitSingletonWithFlagGuard_7218_00597218.c

void UnknownObject::LazySingletonInit()
{
    // One-time lazy initialization of a subsystem guarded by a static flag. When dword_8D5A4C is zero, calls sub_596E40(-3) to initialize the subsystem and sets dword_8D5A4C = 1; subsequent calls are no-ops. Returns the initialization result.
    // GUARD: One-time-init guard: when dword_8D5A4C is zero, run the subsystem initialization; the flag prevents re-entry afterwards. [global:0x008D5A4C, source:raw]
    // CALL: Call sub_596E40(-3) to initialize the subsystem with the literal parameter -3. [callee:0x00596E40, source:raw]
    // ASSIGNMENT: Set the initialization-complete flag dword_8D5A4C = 1. [global:0x008D5A4C, source:raw]
    // RETURN: Return the initialization result; called by sub_592A9C, sub_592AF4 and sub_592BAD. The legacy ABI label is One_time_initialization_of_a_subsystem_guarded_b. [abi:lead, caller:0x00592A9C, caller:0x00592AF4, caller:0x00592BAD, function:0x00597218, source:raw]

    // Conservative worker pseudocode:
    //   if (!dword_8D5A4C) {
    //     result = sub_596E40(-3);
    //     dword_8D5A4C = 1;
    //   }
    //   return result;
    // UNRESOLVED: When dword_8D5A4C is already set, the raw source leaves result undefined (compiler artifact); the function likely returns the first-call result only.
    // UNRESOLVED: The meaning of the literal -3 passed to sub_596E40 is unknown.
}
