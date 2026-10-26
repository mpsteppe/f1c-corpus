// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E3CD
// Canonical corpus name: LockIndirectCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LockIndirectCall_0050e3cd.c

void UnknownObject::LockIndirectCall()
{
    // Trivial two-step wrapper: invokes sub_50FEA7 with the literal argument 1, then calls through the function-pointer global off_5D781C and returns that indirect call's result.
    // CALL: Call sub_50FEA7(1u), passing the constant 1 as the only argument. [callee:0x0050FEA7, source:raw]
    // CALL: Call through the function-pointer global off_5D781C and take its return value as the result. [global:0x005D781C, source:raw]
    // RETURN: Return the value produced by the indirect call through off_5D781C. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_50E3CD() {
    //     sub_50FEA7(1);
    //     return off_5D781C();
    //   }
    // UNRESOLVED: The meaning of the constant 1 passed to sub_50FEA7 is unknown.
    // UNRESOLVED: The target and purpose of the indirect call through off_5D781C are not resolved here.
}
