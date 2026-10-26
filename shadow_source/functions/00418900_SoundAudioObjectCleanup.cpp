// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00418900
// Canonical corpus name: ShortComputation_8900
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_8900_00418900.c

void UnknownObject::SoundAudioObjectCleanup()
{
    // Sound-exit cleanup: runs global vtable dispatch queries for indices 0 and 1, frees drawable resources from the global cleanup list at dword_5EA5E8, then releases the audio object stored at this+0xAF4 through its vtable and nulls the pointer. Called from Sound_Exit.
    // CALL: Dispatch global vtable query with index 0. [callee:0x00411740, source:raw]
    // CALL: Dispatch global vtable query with index 1. [callee:0x00411740, source:raw]
    // CALL: Free drawable resources from the global cleanup list at dword_5EA5E8. [callee:0x004150C0, global:0x005EA5E8, source:raw]
    // GUARD: If the audio object pointer stored at this+0xAF4 is non-null, release it and clear the slot; otherwise the release is skipped. [field:this:0x00000AF4, source:raw]
    // CALL: Invoke the release virtual method on the object at this+0xAF4 with argument 1. [field:*(this+0xAF4):0x00000000, source:raw]
    // ASSIGNMENT: Null the audio object slot this[701] after the release call. [field:this:0x00000AF4, source:raw]
    // RETURN: Return the last result value (release result, or the drawable cleanup result when the object was null). [source:raw]

    // Conservative worker pseudocode:
    //   void sub_418900(DWORD *this) {
    //     GlobalVTableDispatchWithQuery(0);
    //     GlobalVTableDispatchWithQuery(1);
    //     DrawableResourceCleanup(&dword_5EA5E8);
    //     if (this[701]) {
    //       (*(void (**)(DWORD *, int))this[701])(this[701], 1);
    //       this[701] = 0;
    //     }
    //   }
    // UNRESOLVED: Semantics of the two global vtable dispatch queries (indices 0 and 1) and their side effects are not known here.
    // UNRESOLVED: Purpose of the release-call argument 1 is unknown.
    // UNRESOLVED: Class identity of the audio object at this+0xAF4 is not established.
}
