// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E4570
// Canonical corpus name: ShortComputation_4570
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_4570_004e4570.c

void UnknownObject::PhysicsCleanupSequence()
{
    // Cleanup/destructor sequence: calls sub_4E4790(this), then DualArrayDestructorLoopFree on the dual-array storage at this+441 (dword index), then returns the result of a thunk call dispatched on (this+2).
    // CALL: Call sub_4E4790(this) - first cleanup/initialization step on the object. [callee:0x004E4790, source:raw]
    // CALL: Call DualArrayDestructorLoopFree(this + 441) - loop-free destructor of the dual array stored at dword index 441 of this. [callee:0x004DFCA0, source:raw]
    // RETURN: Return the result of a thunk dispatch to sub_4F83B0 with argument (this + 2). [function:0x004E4570, source:raw]

    // Conservative worker pseudocode:
    //   int PhysicsCleanupSequence(this) {
    //     sub_4E4790((int)this);
    //     DualArrayDestructorLoopFree(this + 441);
    //     return ThunkToFUN004f83b0((int)(this + 2));
    //   }
    // UNRESOLVED: The thunk call target sub_4F83B0 appears only in the raw source; no callee evidence reference exists for it in the packet, so its address is not asserted by this reconstruction.
}
