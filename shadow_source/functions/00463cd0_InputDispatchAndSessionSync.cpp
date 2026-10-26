// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00463CD0
// Canonical corpus name: CollisionResponseStatus
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionResponseStatus_00463cd0.c

void UnknownObject::InputDispatchAndSessionSync()
{
    // Per-call state machine: when the session state guard DWORD at obj+0x3FC4 is non-zero, dispatches input commands to entities and synchronizes the session using a scoring default-return float; then unconditionally clears the flag byte at obj+0x374 to 0. Returns the guard value when zero, otherwise the object pointer.
    // ASSIGNMENT: Load the object pointer from this+0. [field:this:0x00000000]
    // ASSIGNMENT: Read the state guard DWORD at obj+0x3FC4 (v2[4081]) into the result value. [field:obj:0x00003FC4]
    // GUARD: If the guard is zero, skip input dispatch and session sync but still clear the +0x374 flag below. [field:obj:0x00003FC4]
    // CALL: Dispatch input commands to entities via InputCommandDispatchToEntities. [callee:0x0045F4A0, field:this:0x00000000]
    // ASSIGNMENT: Load the default scoring return float from dbl_8AFE98 into the SessionSynchronizer argument. [global:0x008AFE98]
    // CALL: Synchronize session state via SessionSynchronizer using the object pointer and the scoring default return float. [callee:0x0045F950, field:this:0x00000000, global:0x008AFE98]
    // ASSIGNMENT: Set the result to the object pointer after a successful sync. [field:this:0x00000000]
    // ASSIGNMENT: Unconditionally clear the flag byte at obj+0x374 to 0. [field:obj:0x00000374]
    // RETURN: Return the guard value on the zero path or the object pointer on the sync path. [source:raw]

    // Conservative worker pseudocode:
    //   v2 = *this;
    //   result = v2[4081];
    //   if (result) {
    //     InputCommandDispatchToEntities(v2);
    //     v4 = dbl_8AFE98;
    //     SessionSynchronizer(*this, v4);
    //     result = *this;
    //   }
    //   *(_BYTE *)(*this + 884) = 0;
    //   return result;
    // UNRESOLVED: Object type, the meaning of the +0x374 flag and +0x3FC4 guard, and the exact semantics of the SessionSynchronizer float argument are unresolved.
}
