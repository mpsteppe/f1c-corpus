// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00455D50
// Canonical corpus name: HWInput_Init
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HWInput_Init_00455d50.c

void UnknownObject::HWInput_Init()
{
    // Initializes HWInput state. Logs an entry message unless the session type is 5 (server) or the debug-log enable condition fails, then calls an audio scene update, initializes global state with enum defaults, and returns the result of a camera viewport configuration batch.
    // GUARD: Check dword_7C569C (session type) != 5; gates the debug-log write. [global:0x007C569C]
    // CALL: Call StringSplitLoop(2, aDDevF119992002_13, 5258) to evaluate the debug-log enable condition. [callee:0x004D7A50, global:0x005C56A4, source:raw]
    // CALL: If guard passes and StringSplitLoop returns nonzero, call DebugLogWrite(&dword_8AD25C, aEnteredHwinput_1) to log the init entry. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C56E8]
    // CALL: Call AudioSceneUpdateLoop(this) to update audio scene state. [callee:0x004532D0, abi:lead]
    // CALL: Call GlobalStateInitializerWithEnumValues((int *)this) to initialize global state with enum defaults. [callee:0x004533A0, abi:lead]
    // CALL: Call CameraViewportConfigBatch(this); its result becomes the return value. [source:raw, abi:lead]
    // RETURN: Return the result of CameraViewportConfigBatch(this). [source:raw]

    // Conservative worker pseudocode:
    //   if (dword_7C569C != 5 && StringSplitLoop(2, aDDevF119992002_13, 5258))
    //       DebugLogWrite(&dword_8AD25C, aEnteredHwinput_1);
    //   AudioSceneUpdateLoop(this);
    //   GlobalStateInitializerWithEnumValues((int *)this);
    //   return CameraViewportConfigBatch(this);
    // UNRESOLVED: The call target named CameraViewportConfigBatch in the decompiled source has no callee evidence entry in the packet; it is referenced only via source:raw.
    // UNRESOLVED: Meaning of StringSplitLoop's arguments (2, format string, 5258) is unclear; treated only as a debug-log enable predicate.
}
