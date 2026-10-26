// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9B20
// Canonical corpus name: sub_4F9B20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4F9B20_004f9b20.c

void UnknownObject::IsStateFlagClear()
{
    // Pure predicate: reads the global dword_8AFE7C (0x008AFE7C) and returns true when it equals zero. No side effects. Called by CircularBufferRingAdvance (0x004917C0), RenderSurfaceFillCopy (0x004918D0), and StateFlagComputation (0x004F9B30); the state-flag interpretation of the global is inferred from that caller's name, not proven.
    // CALCULATION: Read global dword_8AFE7C (0x008AFE7C) and test whether it equals zero [global:0x008AFE7C, function:0x004F9B20, source:raw]
    // RETURN: Return true when dword_8AFE7C equals zero, otherwise false [global:0x008AFE7C, source:raw]

    // Conservative worker pseudocode:
    //   bool IsStateFlagClear() {
    //     return dword_8AFE7C == 0;
    //   }
    // UNRESOLVED: The meaning of dword_8AFE7C and the object that owns it are not established.
    // UNRESOLVED: The state-flag reading is inferred from the caller name StateFlagComputation (0x004F9B30) and is DERIVED, not proven.
}
