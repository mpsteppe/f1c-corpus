// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491F60
// Canonical corpus name: TripleFieldCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TripleFieldCleanup_00491f60.c

void UnknownObject::TripleFieldCleanup()
{
    // Resource cleanup over a three-field handle struct (this[0..2]). Each non-null field is closed or dispatched through its handler (StreamFileTypeCheckWithDispatch for this[0], FileCloseWithLock for this[1] and this[2]), then all three slots are zeroed. Returns 0.
    // GUARD: Check this[0] for non-null before dispatching its stream. [field:this:0x00000000, source:raw]
    // CALL: Dispatch or close the stream held in this[0] via StreamFileTypeCheckWithDispatch. [callee:0x005355A0, field:this:0x00000000, source:raw]
    // GUARD: Check this[1] for non-null before closing it. [field:this:0x00000004, source:raw]
    // CALL: Close the handle held in this[1] via FileCloseWithLock. [callee:0x00587D02, field:this:0x00000004, source:raw]
    // GUARD: Check this[2] for non-null before closing it. [field:this:0x00000008, source:raw]
    // CALL: Close the handle held in this[2] via FileCloseWithLock. [callee:0x00587D02, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Zero the this[0] slot after cleanup. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero the this[1] slot after cleanup. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Zero the this[2] slot after cleanup. [field:this:0x00000008, source:raw]
    // RETURN: Return 0 as the cleanup result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_491F60(int *this) {
    //     if (this[0]) StreamFileTypeCheckWithDispatch(this[0]);
    //     if (this[1]) FileCloseWithLock(this[1]);
    //     if (this[2]) FileCloseWithLock(this[2]);
    //     this[0] = 0; this[1] = 0; this[2] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Concrete resource types behind this[0..2] are unknown; prior analysis suggests audio read/write streams.
    // UNRESOLVED: Both this[1] and this[2] close via FileCloseWithLock; their distinct roles are unresolved.
    // UNRESOLVED: The identity of the owning object is unknown (owner remains UnknownObject).
}
