// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005514A0
// Canonical corpus name: FlagUpdateWithCascade
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagUpdateWithCascade_005514a0.c

void UnknownObject::FlagUpdateWithCascade()
{
    // Flag-word mutation with a timer restart. Replaces this[1] (this+0x4) with (this[1] & 0xFFFE0FFF) | 0x2000 (mask off a flag region, set one flag), then restarts a timer through TimerStartViaQueryPerformanceCounter using this[0]. Returns the timer-start result.
    // ASSIGNMENT: this[1] (this+0x4) = (this[1] & 0xFFFE0FFF) | 0x2000: AND-mask 0xFFFE0FFF clears a flag region, then OR 0x2000 sets a flag bit; other bits preserved. [field:this:0x00000004, source:raw, function:0x005514A0]
    // CALL: Return TimerStartViaQueryPerformanceCounter(*this): restart the timer associated with this[0] and return its result. [field:this:0x00000000, source:raw, function:0x005514A0]
    // RETURN: Return the value produced by the timer-start call. [source:raw, function:0x005514A0]

    // Conservative worker pseudocode:
    //   this[1] = (this[1] & 0xFFFE0FFF) | 0x2000;
    //   return TimerStartViaQueryPerformanceCounter(this[0]);
    // UNRESOLVED: TimerStartViaQueryPerformanceCounter is referenced only by name in the raw source; it is absent from the packet callees, so its identity/location is unverified here.
    // UNRESOLVED: Meaning of the bit 0x2000 flag (and the region cleared by mask 0xFFFE0FFF) in this flag word is unknown.
}
