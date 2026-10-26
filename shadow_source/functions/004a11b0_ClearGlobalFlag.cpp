// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A11B0
// Canonical corpus name: GlobalFlagClear
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalFlagClear_004a11b0.c

void UnknownObject::ClearGlobalFlag()
{
    // Trivial global flag clear: writes the dword dword_7CE250 to 0 and returns void. No guards, callees, or fields. Called from Game_Post (0x0042DA30), consistent with an end-of-frame state reset. Consistent with the LEGACY Global_Flag_Clear ABI label.
    // ASSIGNMENT: dword_7CE250 = 0; clear the global dword to 0 (write); invoked from Game_Post (0x0042DA30), suggesting a per-frame/state reset [global:0x007CE250, caller:0x0042DA30, source:raw, function:0x004A11B0]
    // RETURN: void return; nothing is yielded to the caller [source:raw]

    // Conservative worker pseudocode:
    //   dword_7CE250 = 0;
    // UNRESOLVED: Purpose of the global dword_7CE250 is not established by the packet.
    // UNRESOLVED: Exact point within Game_Post (0x0042DA30) at which this clear runs is not established by the packet.
    // UNRESOLVED: Owner object identity is not established by the packet.
    // UNRESOLVED: The LEGACY Global_Flag_Clear ABI label is a deterministic tag, not runtime confirmation.
}
