// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9FC0
// Canonical corpus name: sub_4F9FC0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4F9FC0_004f9fc0.c

void UnknownObject::SessionTimeAndTimerReset()
{
    // Sets the session-time global dbl_8AFEA0 from the float argument, resets the high-precision performance-counter timer on `this`, performs two index/bounds checks against the data table at 008b8e48, and stores the result of sub_556760(0) into dbl_8AFEA8. Invoked from RunCollisionDetectionLoop, SessionSynchronizer and VidMan_Restart.
    // ASSIGNMENT: Store the float argument a2 into the session-time global dbl_8AFEA0 [global:0x008AFEA0, source:raw]
    // CALL: Reset the high-precision performance-counter timer on `this` via TimerResetUsingQueryPerformanceCounter [callee:0x00568C60, source:raw]
    // CALL: Bounds/index check 0 against the data table at 008b8e48 via BoundsCheckAgainstDAT008b8e48 [callee:0x00556700, source:raw]
    // CALL: Bounds/index check 1 against the data table at 008b8e48 via BoundsCheckAgainstDAT008b8e48 [callee:0x00556700, source:raw]
    // ASSIGNMENT: Store the result of sub_556760(0) into the input-axis dead-zone global dbl_8AFEA8 [callee:0x00556760, global:0x008AFEA8, source:raw]
    // CALL: Invoked by RunCollisionDetectionLoop (0045F390) as part of session time/timer initialization [caller:0x0045F390, source:raw]
    // CALL: Invoked by SessionSynchronizer (0045F950) to re-initialize session time and the timer together [caller:0x0045F950, source:raw]
    // CALL: Invoked by VidMan_Restart (004FA640) to re-initialize the timing state after a video-manager restart [caller:0x004FA640, source:raw]

    // Conservative worker pseudocode:
    //   dbl_8AFEA0 = a2;
    //   TimerResetUsingQueryPerformanceCounter(this);
    //   BoundsCheckAgainstDAT008b8e48(0);
    //   BoundsCheckAgainstDAT008b8e48(1);
    //   dbl_8AFEA8 = sub_556760(0);
    // UNRESOLVED: Packet facts flag a read of dword_8AFE64 (RaceTimeDelta) but the raw decompiled source never references it; role is not verifiable here
    // UNRESOLVED: Purpose of the two BoundsCheckAgainstDAT008b8e48 calls (0 and 1) is not documented; they appear to be index validation against the table at 008b8e48
}
