// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A03F0
// Canonical corpus name: SystemOSAPICall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SystemOSAPICall_004a03f0.c

void UnknownObject::SystemOSAPICall()
{
    // Shows the OS cursor (busy-waiting until ShowCursor(1) reports a positive display count), resets global state to 0 via GlobalStateSetter, runs a short computation on this via ShortComputation_0ad0, then initializes the audio mixer device from the byte_8AC494 global. Returns 0. Invoked by MainMenuTransition and sub_485B90 during menu and session transitions.
    // LOOP: Busy-wait calling ShowCursor(1) until the returned display count is greater than 0. [global:0x0059E2C4]
    // CALL: Reset global state to 0 through GlobalStateSetter. [callee:0x004A0D30]
    // CALL: Run the short computation ShortComputation_0ad0 on the this context. [callee:0x004A0AD0]
    // CALL: Initialize the audio mixer device from the byte_8AC494 global. [callee:0x004C85D0, global:0x008AC494]
    // RETURN: Return 0; invoked by MainMenuTransition and sub_485B90. [source:raw, caller:0x00404F30, caller:0x00485B90, function:0x004A03F0]

    // Conservative worker pseudocode:
    //   int SystemOSAPICall(void *this) {
    //     while (ShowCursor(1) <= 0);
    //     GlobalStateSetter(0);
    //     ShortComputation_0ad0(this);
    //     AudioMixerDeviceInit(&byte_8AC494);
    //     return 0;
    //   }
    // UNRESOLVED: unk_7CE24D is listed as a referenced global but does not appear in the raw decompiled body; its fill role (SessionTransitionFlag) is DERIVED, not observed here.
}
