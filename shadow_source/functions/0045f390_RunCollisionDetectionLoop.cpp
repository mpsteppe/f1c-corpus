// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045F390
// Canonical corpus name: RunCollisionDetectionLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RunCollisionDetectionLoop_0045f390.c

void UnknownObject::RunCollisionDetectionLoop()
{
    // Runs a timed collision-detection loop guarded on session phase this+0x3FC4 == 3. Initializes a QPC timer, then loops while AnimationValueFetchWithTiming keeps yielding values: refreshes animation timing every step (re-seeding a 4.0 budget) and accumulates the high-resolution timer delta until 60.0 seconds elapse (timeout returns 0). On animation completion, processes the fetched value, converts the timer with a sine transform, places the multiplayer vehicle, resets the collision array, and returns 1.
    // GUARD: If this[4081] (session phase/state at this+0x3FC4) is not 3, return 0 immediately. [guard:0, field:this:0x00003FC4, source:raw]
    // CALL: Initialize the timer structure: StructZeroInit_8ba0(v10), QPCTimerInitialization(1), and TimerResetUsingQueryPerformanceCounter(v10). [callee:0x00568BA0, callee:0x00568BE0, callee:0x00568C60]
    // ASSIGNMENT: Seed loop state: v2 = 0.0 (remaining step budget), v5 = 0.0 (step budget), v6 = 0.0 (accumulated elapsed time). [source:raw]
    // LOOP: Infinite loop that runs until AnimationValueFetchWithTiming returns nonzero or the 60.0-second timeout fires. [callee:0x0057A610]
    // CALL: When the remaining budget v2 is zero or below, refresh animation timing: AnimationTimingUpdateWithParamSet(this[4078]) with the parameter set at this+0x3FB8, and re-seed v5 = 4.0. [callee:0x0057A5A0, field:this:0x00003FB8]
    // GUARD: If AnimationValueFetchWithTiming(&v7, &v8, v9) returns nonzero, break out of the loop with fetched values. [callee:0x0057A610]
    // CALCULATION: Advance the timing budget: v3 = HighResolutionTimerDelta(v10); v6 += v3; v2 = v5 - v3; v5 = v2. [callee:0x00568CF0]
    // GUARD: Timeout guard: if accumulated elapsed v6 reaches 60.0, call EmptyStub_0170(v10) and return 0. [callee:0x004B0170]
    // CALL: Process the fetched animation/collision value v7 via sub_4F9FC0. [callee:0x004F9FC0]
    // CALL: Convert the fetched timer value with a sine transform: TimerConversionWithSin(v7). [callee:0x0042BDA0]
    // CALL: MultiplayerVehiclePlacement(&dword_7C569C, *v8): place/update the multiplayer vehicle from the dereferenced fetched value. [callee:0x0042CF10, global:0x007C569C]
    // CALL: ArrayInitializationLoop(this + 26864, 0): reset the collision array at dword-index 26864. [callee:0x0045C8B0]
    // RETURN: Call EmptyStub_0170(v10) as cleanup and return 1 on successful animation completion. [callee:0x004B0170]

    // Conservative worker pseudocode:
    //   char sub_45F390(void *this) {
    //     if (this[4081] != 3) return 0;
    //     byte timer[76]; StructZeroInit_8ba0(timer);
    //     QPCTimerInitialization(1);
    //     TimerResetUsingQueryPerformanceCounter(timer);
    //     double budget = 0.0; float v5 = 0.0; double elapsed = 0.0;
    //     for (;;) {
    //       if (budget <= 0.0) {
    //         AnimationTimingUpdateWithParamSet(this[4078]);
    //         v5 = 4.0;
    //       }
    //       float value; char *out; byte extra[4];
    //       if (AnimationValueFetchWithTiming(&value, &out, extra)) break;
    //       double delta = HighResolutionTimerDelta(timer);
    //       elapsed += delta;
    //       budget = v5 - delta;
    //       v5 = budget;
    //       if (elapsed >= 60.0) { EmptyStub_0170(timer); return 0; }
    //     }
    //     sub_4F9FC0(value);
    //     TimerConversionWithSin(value);
    //     MultiplayerVehiclePlacement(&dword_7C569C, *out);
    //     ArrayInitializationLoop(this + 26864, 0);
    //     EmptyStub_0170(timer);
    //     return 1;
    //   }
    // UNRESOLVED: Semantics of the value fetched by AnimationValueFetchWithTiming (v7, v8, v9 triple) and its 4.0 budget / 60.0 timeout units are taken from call order only.
    // UNRESOLVED: Why this+0x3FC4 must equal 3 to proceed and what phase that represents is unresolved.
    // UNRESOLVED: The collision array reset target this+26864 has no named counterpart in the packet.
}
