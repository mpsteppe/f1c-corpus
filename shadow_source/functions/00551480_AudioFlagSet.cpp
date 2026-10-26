// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551480
// Canonical corpus name: AudioFlagSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioFlagSet_00551480.c

void UnknownObject::AudioFlagSet()
{
    // Sets audio timer flag bit 0x1000 while clearing bits 0x7000 on the dword flags at this + 0x4, then returns the accumulated query-performance-counter timer value through TimerAccumulateViaQueryPerformanceCounter using the value at this + 0x0. Unconditional; no branches or guards. Called by TimerBasedStateUpdateWithCap (005514C0), LinkedListStringKeyRemoval (00551790) and SceneNode (0055A910).
    // ASSIGNMENT: this[1] = (this[1] & 0xFFFF8FFF) | 0x1000: sets flag bit 0x1000 and clears bits 0x7000 on the dword at this + 0x4 [field:this:0x00000004, source:raw]
    // CALL: Calls TimerAccumulateViaQueryPerformanceCounter with the value at this + 0x0 to accumulate a performance-counter timestamp [field:this:0x00000000, source:raw]
    // RETURN: Returns the accumulated timer value produced by TimerAccumulateViaQueryPerformanceCounter [function:0x00551480, source:raw]

    // Conservative worker pseudocode:
    //   this[1] = (this[1] & 0xFFFF8FFF) | 0x1000;
    //   return TimerAccumulateViaQueryPerformanceCounter(this[0]);
    // UNRESOLVED: TimerAccumulateViaQueryPerformanceCounter has no address in the packet callee facts; the call is visible only in the raw decompiled source, so its target is unverified
    // UNRESOLVED: The value at this + 0x0 is described by prior analysis as a QueryPerformanceCounter handle for timer accumulation, but its exact type is not independently evidenced
}
