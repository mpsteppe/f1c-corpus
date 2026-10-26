// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00405030
// Canonical corpus name: SettingsSaveWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SettingsSaveWrapper_00405030.c

void UnknownObject::SettingsSaveWrapper()
{
    // __stdcall wrapper that runs a one-time initialization-style registration call with no arguments and then forwards a1 unchanged to a second function, returning that call's result.
    // CALL: Invoke OneTimeInitializationWithAtexitStyleRegistration (00404FE0) with no arguments; its side effects are not visible in this function. [callee:0x00404FE0]
    // CALL: Invoke ShortComputation_7dd0 (00407DD0) passing parameter a1 through unchanged. [callee:0x00407DD0]
    // RETURN: Return the value produced by ShortComputation_7dd0(a1). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_405030(int a1) {
    //     OneTimeInitializationWithAtexitStyleRegistration();
    //     return ShortComputation_7dd0(a1);
    //   }
    // UNRESOLVED: Whether the initialization-style registration actually runs once or on every call is not decidable from this function alone.
    // UNRESOLVED: Meaning of parameter a1 and of the returned value is defined by ShortComputation_7dd0, whose internals are outside this packet.
}
