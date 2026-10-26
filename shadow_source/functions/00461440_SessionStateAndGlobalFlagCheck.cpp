// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00461440
// Canonical corpus name: ReferencesGlobalState
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ReferencesGlobalState_00461440.c

void UnknownObject::SessionStateAndGlobalFlagCheck()
{
    // Session-state predicate: reads the int at this+0x3FC4 and returns true only when it equals 1 or 2 AND the global flag byte at 0x007D1074 is non-zero. Used as a gate by InputCommandDispatchToEntities and TeamRadioNetworkMessageProcessing.
    // CALCULATION: Reads the int at this+0x3FC4 (dword index 4081) into v1 [field:this:0x00003FC4, source:raw]
    // GUARD: True only when v1 equals 1 or 2 (the accepted session state values) [source:raw]
    // GUARD: Ands the state check with the global flag byte_7D1074 being non-zero [global:0x007D1074, source:raw]
    // RETURN: Returns (v1 == 2 || v1 == 1) && byte_7D1074 [source:raw]
    // CALL: Consumed by InputCommandDispatchToEntities and TeamRadioNetworkMessageProcessing as a session-state gate [caller:0x0045F4A0, caller:0x0045F710, abi:lead]

    // Conservative worker pseudocode:
    //   v1 = this[4081];
    //   return (v1 == 2 || v1 == 1) && byte_7D1074;
    // UNRESOLVED: The concrete meaning of state values 1 and 2 for the session phase field is not established
    // UNRESOLVED: The meaning of the global byte_7D1074 flag, and the owner class of this, are unknown
}
