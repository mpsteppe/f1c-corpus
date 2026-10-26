// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00583D90
// Canonical corpus name: StartAddress
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StartAddress_00583d90.c

void UnknownObject::FloatAnimationThreadProc()
{
    // Thread start routine (__stdcall, takes lpThreadParameter) that runs a float-accumulation loop guarded by a mutex-protected shutdown read. Initializes two timer objects with TimerInitWithSEH, then loops while MutexProtectedDataReadWithTimedWait(threadParam, 0) returns 0. Each iteration accumulates a frame value via FloatAdditionReturnsFUN00568d90Param1; when it is below 0.0078125 the timer is reset, a one-shot companion is stopped, the value is clamped to the 0.0..10.0 range, the mutex is released and sub_584110 dispatches the clamped value. It then polls the object's vtable dispatch at +84 and +80 (each up to three times), accumulates the clamped value into v19, and when the accumulated value reaches 0.333 invokes EmptyStub_0170, sub_583F50 and the vtable dispatch at +12 with the accumulated float, then resets v19. Sleeps 5 ms alertably via SleepEx each iteration. On exit tears down the two timer objects via SingleFunctionCallWrapper_3650 and returns 0.
    // CALL: Initializes two timer objects (v21 then v20) with TimerInitWithSEH and sets the thread state marker to 1 [callee:0x005835F0, source:raw]
    // GUARD: Loop condition: continues while MutexProtectedDataReadWithTimedWait(threadParam, 0) returns 0 (the mutex-protected shutdown/flag read) [callee:0x00583D40, source:raw]
    // CALL: Reads the accumulated frame value v1 from timer v20 via FloatAdditionReturnsFUN00568d90Param1 [callee:0x00583680, source:raw]
    // GUARD: When the accumulated value v1 is below 0.0078125, resets timer v20 with FloatSetWithTimingCall(v20, 0), stops the one-shot companion with SingleFunctionCallWrapper_3690, clamps v1 into the 0.0..10.0 range as v18, releases the mutex with MutexWaitWith1msTimeoutRelease and dispatches v18 via sub_584110 [callee:0x00583660, callee:0x00583690, callee:0x005840D0, callee:0x00584110, source:raw]
    // LOOP: Polls the object's vtable dispatch at +84 (field obj+0x54) up to three times until it returns false [field:obj:0x00000054, field:this:0x00000000, source:raw]
    // LOOP: Polls the object's vtable dispatch at +80 (field obj+0x50) up to three times until it returns false [field:obj:0x00000050, field:this:0x00000000, source:raw]
    // CALCULATION: Accumulates the clamped value into the running total: v19 = v18 + v19 [source:raw]
    // GUARD: When the accumulated total reaches 0.333, calls EmptyStub_0170, sub_583F50 with the total, dispatches the vtable entry at +12 (field obj+0xC) with the accumulated float, and resets v19 to 0.0 [callee:0x004B0170, callee:0x00583F50, field:obj:0x0000000C, field:this:0x00000000, source:raw]
    // CALL: Suspends the thread 5 ms alertably via SleepEx(5, 1) at the end of every loop iteration [global:0x0059E208, source:raw]
    // CALL: On loop exit, clears the state marker and tears down both timer objects with SingleFunctionCallWrapper_3650, then returns 0 [callee:0x00583650, source:raw]

    // Conservative worker pseudocode:
    //   TimerInitWithSEH(v21); state = 0;
    //   TimerInitWithSEH(v20); state = 1;
    //   total = 0.0;
    //   while (MutexProtectedDataReadWithTimedWait(threadParam, 0) == 0) {
    //     v1 = FloatAdditionReturnsFUN00568d90Param1(v20);
    //     if (v1 < 0.0078125) {
    //       FloatSetWithTimingCall(v20, 0);
    //       SingleFunctionCallWrapper_3690(v21);
    //       v18 = clamp(v1, 0.0, 10.0);
    //       MutexWaitWith1msTimeoutRelease(threadParam);
    //       sub_584110(v18);
    //       for (i = 0; i < 3 && dispatch(threadParam, +84); ++i) { }
    //       for (i = 0; i < 3 && dispatch(threadParam, +80); ++i) { }
    //       total += v18;
    //       if (total >= 0.333) {
    //         EmptyStub_0170();
    //         sub_583F50(total);
    //         dispatch(threadParam, +12, total);
    //         total = 0.0;
    //       }
    //     }
    //     SleepEx(5, 1);
    //   }
    //   state = 0;
    //   SingleFunctionCallWrapper_3650();
    //   state = -1;
    //   SingleFunctionCallWrapper_3650();
    //   return 0;
    // UNRESOLVED: The four read-only globals (flt_59E440, flt_59E5FC, dbl_59ED98, flt_5B8B58) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton fill labels them ZeroThreshold, FrameRateCorrectionFactor, Dbl_Physics_TimingThreshold and AudioBufferThreshold, all unverifiable from this packet
    // UNRESOLVED: Global SEH_583D90 (0x0059D063) is flagged by packet facts but appears nowhere in the raw decompiled source; it is presumably this thread function's SEH unwind table
    // UNRESOLVED: The decompiled comparisons encode FP status-register bits (v5/v6/v13 & 0x4100); these map to ordinary float comparisons (0.0078125, 10.0, 0.333) but the exact compiler-synthesized branch set is not directly visible
    // UNRESOLVED: The vtable dispatches at +80/+84 are polled up to three times with no visible meaning for the returned status bytes
    // UNRESOLVED: Constant 0.0078125 equals 1/128 and 0.333 approximates 1/3, but the intended physical frame/sleep relationship is not provable from this packet alone
}
