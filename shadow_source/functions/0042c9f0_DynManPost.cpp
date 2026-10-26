// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042C9F0
// Canonical corpus name: DynMan_Post
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DynMan_Post_0042c9f0.c

void UnknownObject::DynManPost()
{
    // Dynamic-management post-processing handler (DynMan_Post). Optionally logs a debug entry message when StringSplitLoop(2, build-path token, 933) returns non-zero, then iterates the vehicle-pointer array at 0x7C54F0 for VehicleCount (0x5C329C) vehicles calling per-vehicle reset sub_4C6E80 on each, initializes wheel dynamics from the race-elapsed-time value at 0x7C7428, resets season scoring, and finally destroys graphics resources through the global instance at 0x5EA560, returning the destructor's result.
    // GUARD: Conditional debug-entry gate: when StringSplitLoop(2, build-path token at 0x5C3334, 933) returns non-zero, log entry into DynMan post-processing. [callee:0x004D7A50, global:0x005C3334, source:raw]
    // CALL: Write the 'entered DynMan post' message string (0x5C3498) into the debug message buffer at 0x8AD25C. [callee:0x004D7AA0, global:0x005C3498, global:0x008AD25C]
    // LOOP: Iterate index i from 0 while i < the vehicle count stored at 0x5C329C. [global:0x005C329C]
    // CALL: Per-vehicle reset: call sub_4C6E80 on each vehicle pointer read from the vehicle-pointer array at 0x7C54F0. [callee:0x004C6E80, global:0x007C54F0, global:0x005C329C]
    // CALL: Initialize wheel dynamics using the race-elapsed-time value at 0x7C7428. [callee:0x0043E230, global:0x007C7428]
    // CALL: Reset season scoring state. [callee:0x0042BD60]
    // RETURN: Destroy graphics resources via the global instance at 0x5EA560 (destructor named in source; its call target is absent from the packet callee list) and return the destructor's result. [global:0x005EA560, function:0x0042C9F0, source:raw]

    // Conservative worker pseudocode:
    //   int DynManPost() {
    //     if (StringSplitLoop(2, buildPathToken, 933))
    //       DebugLogWrite(&debugMessageBuffer, enteredDynManPostMsg);
    //     for (i = 0; i < vehicleCount; ++i)
    //       sub_4C6E80(vehiclePtrArray[i]);
    //     WheelDynamicsInit(&raceTimeElapsed);
    //     SeasonScoringReset();
    //     return GraphicsResourceDestructor(globalInstance_5EA560);
    //   }
    // UNRESOLVED: The final graphics-resource destructor (GraphicsResourceDestructor in source) has no address in the packet's callee list; its call target is unresolved.
    // UNRESOLVED: The role of StringSplitLoop at this call site (build-path parsing gate for logging) is inferred from existing analysis.
    // UNRESOLVED: Called from Game_Post (0x42DA30); the exact post-race trigger context is not established here.
}
