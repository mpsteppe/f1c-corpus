// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00535660
// Canonical corpus name: GuardedFunctionCallCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedFunctionCallCleanup_00535660.c

void UnknownObject::GuardedFunctionCallCleanup()
{
    // Cleanup/teardown for a guarded deferred-call record. Returns -2 when this is null or when the stored handler pointer (this+0x1C) or callback pointer (this+0x24) is null. When the handler's own field at +20 is non-null it forwards to TripleVTableCall(handler+20, this); then invokes the stored callback at this+0x24 as a fastcall function with (this+0x28, this+0x1C), clears this+0x1C to 0, and returns 0. Invoked from file-handle teardown and two other call sites.
    // GUARD: Return -2 immediately when this is null. [source:raw]
    // GUARD: Return -2 when the stored handler pointer at this+0x1C is null or the stored callback pointer at this+0x24 is null; both must be present to run the cleanup. [field:this:0x0000001C, field:this:0x00000024, source:raw]
    // CALL: When the handler's own field at (this+0x1C)+20 is non-null, call TripleVTableCall(handler+20, this) as a guarded three-slot vtable dispatch. [callee:0x00537CE0, field:this:0x0000001C, source:raw]
    // CALL: Invoke the stored callback at this+0x24 as a __fastcall function with arguments (this+0x28, this+0x1C), firing the deferred call with its captured context. [field:this:0x00000024, field:this:0x00000028, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Clear the handler pointer this+0x1C to 0, marking the record as consumed. [field:this:0x0000001C, source:raw]
    // RETURN: Return 0 (success) after the cleanup has run. [source:raw]
    // CALL: Invoked from FileHandleDestructorWithModeCheck (0x00534EE0), sub_5356A0 (0x005356A0) and sub_59B260 (0x0059B260). [caller:0x00534EE0, caller:0x005356A0, caller:0x0059B260, source:raw]

    // Conservative worker pseudocode:
    //   int GuardedFunctionCallCleanup(int* this) {
    //     if (!this) return -2;
    //     int handler = this[7]; /* this+0x1C * /
    //     if (!handler || !this[9]) return -2; /* this+0x24 * /
    //     int slot = *(int*)(handler + 20);
    //     if (slot) TripleVTableCall(slot, this);
    //     ((void (__fastcall*)(int, int))this[9])(this[10], this[7]);
    //     this[7] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The record semantics are DERIVED: this+0x1C is read as the handler/context pointer, this+0x24 as a stored callback and this+0x28 as its first argument; the packet's prelabel flags this as a structural twin of sub_5179A2 (cluster_rep 005179a2), which is consistent but not confirmed.
    // UNRESOLVED: The field this+0x30 is listed in the packet as a read but does not appear in the raw body; its purpose is unknown.
    // UNRESOLVED: The triple-slot vtable dispatch performed by TripleVTableCall is named by the packet callee symbol; the shape of the vtable is not evidenced here.
}
