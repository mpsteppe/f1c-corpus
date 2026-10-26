// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E0E70
// Canonical corpus name: SubslotCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SubslotCleanup_004e0e70.c

void UnknownObject::SubslotCleanup()
{
    // Per-index subslot teardown: computes the subslot pointer at this + 296*a2, conditionally releases a resource at slot+81 and a resource at slot+98 via ConditionalResourceRelease, and drives VibrationStateMachine(a2, 0.0) to clear vibration for the subslot. Returns the second release result, or the result of FlagFieldBitManipulation(0,0,0,0) when the second released pointer is non-null. On the frame path; called by SubsystemStateMachine and RepairServiceStateDispatcher.
    // CALCULATION: Compute v2 = &this[296 * a2], the per-index subslot base selected by a2. [source:raw]
    // CALL: Call ConditionalResourceRelease(v2 + 81) to conditionally release the first resource region of the subslot. [callee:0x004E0D70, source:raw]
    // CALL: Call VibrationStateMachine(a2, 0.0) to reset the vibration state for subslot a2. [callee:0x004E2230, source:raw]
    // CALCULATION: Advance the subslot pointer by 98 elements: v2 += 98. [source:raw]
    // CALL: Call ConditionalResourceRelease(v2) on the advanced pointer and keep its result as the return value. [callee:0x004E0D70, source:raw]
    // GUARD: Guard on *v2 (the second released resource pointer) being non-null after release; when non-null return the result of FlagFieldBitManipulation(0, 0, 0, 0). [callee:0x0054C030, source:raw]
    // RETURN: Return result (the second ConditionalResourceRelease result) when the guard does not trigger. [source:raw]
    // CALL: Called by SubsystemStateMachine (0x004E17C0) and RepairServiceStateDispatcher (0x004ED250) to tear down a subslot. [caller:0x004E17C0, caller:0x004ED250, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4E0E70(char *this, int idx) {
    //     int *p = (int *)&this[296 * idx];
    //     ConditionalResourceRelease(p + 81);
    //     VibrationStateMachine(idx, 0.0);
    //     p += 98;
    //     int result = ConditionalResourceRelease(p);
    //     if (*p) return FlagFieldBitManipulation(0, 0, 0, 0);
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the 296-byte per-subslot stride and the two released regions (slot+81, slot+98) is unknown; the packet declares no fields for this object.
    // UNRESOLVED: Return-value contract of FlagFieldBitManipulation(0,0,0,0) and why it is called only when *v2 is non-null are unknown.
}
