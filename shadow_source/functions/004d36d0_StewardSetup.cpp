// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D36D0
// Canonical corpus name: Steward_Setup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Steward_Setup_004d36d0.c

void UnknownObject::StewardSetup()
{
    // Steward subsystem setup: when StringSplitLoop(2, aDDevF119992002_3, 2330) returns non-zero, writes the 'Entered Steward' debug message via DebugLogWrite into the dword_8AD25C buffer; then registers the Vehicle, Timing and Pitstop subsystems through sub_5599D0/sub_559A00 with TimerFrameRateThrottle and TrackTemperatureDisplay as handler callbacks. Returns the result of the last sub_559A00 registration call. Called by Game_Setup (0042D5D0).
    // CALL: Call StringSplitLoop(2, aDDevF119992002_3, 2330) as a debug-message gate. [callee:0x004D7A50, global:0x005D3B6C, source:raw]
    // GUARD: When StringSplitLoop returns non-zero, emit the 'Entered Steward' debug message. [callee:0x004D7A50, source:raw]
    // CALL: Call DebugLogWrite(&dword_8AD25C, aEnteredSteward) to log the debug entry message into the message buffer. [callee:0x004D7AA0, global:0x008AD25C, global:0x005D41EC, source:raw]
    // CALL: Register the Vehicle subsystem: sub_5599D0(aVehicle, 0, 0). [callee:0x005599D0, global:0x005D41E4, source:raw]
    // CALL: Register the Timing subsystem: sub_559A00(aTiming, TimerFrameRateThrottle, 0) with TimerFrameRateThrottle as the handler callback. [callee:0x00559A00, global:0x005D41DC, global:0x004D3740, source:raw]
    // CALL: Register the Pitstop subsystem: sub_559A00(aPitstop, TrackTemperatureDisplay, 0) with TrackTemperatureDisplay as the handler callback. [callee:0x00559A00, global:0x005D41D4, global:0x004D37B0, source:raw]
    // RETURN: Return the result of the last sub_559A00 call (the Pitstop registration). Game_Setup (0042D5D0) is the caller. [function:0x004D36D0, caller:0x0042D5D0, source:raw]

    // Conservative worker pseudocode:
    //   int StewardSetup() {
    //     if (StringSplitLoop(2, aDDevF119992002_3, 2330)) DebugLogWrite(&dword_8AD25C, aEnteredSteward);
    //     sub_5599D0(aVehicle, 0, 0);
    //     sub_559A00(aTiming, TimerFrameRateThrottle, 0);
    //     return sub_559A00(aPitstop, TrackTemperatureDisplay, 0);
    //   }
    // UNRESOLVED: Exact semantics of sub_5599D0 / sub_559A00 (registration vs other setup) and of their handler-callback arguments are inferred, not confirmed.
    // UNRESOLVED: Meaning of the StringSplitLoop arguments (2, scene path, 2330) as a debug-gate condition is not established.
    // UNRESOLVED: dword_8AFE64 appears in the packet globals as read but is not directly referenced in the raw source text; likely accessed transitively by a callee.
    // UNRESOLVED: Subsystem name strings (aVehicle, aTiming, aPitstop) and handler globals (TimerFrameRateThrottle, TrackTemperatureDisplay) carry DERIVED names only.
}
