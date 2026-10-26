// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048D3E0
// Canonical corpus name: ObjectInitWithVTableCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitWithVTableCleanup_0048d3e0.c

void UnknownObject::ObjectInitWithVTableCleanup()
{
    // Resets the vtable pointer at this+0x0 to the UI widget vtable literal off_5AC1D0, then delegates to sub_485EB0 for further teardown, returning its result. Appears in destructor sequences per its callers.
    // ASSIGNMENT: Writes the vtable pointer literal off_5AC1D0 into the object's vtable slot at this+0x0, replacing whatever vtable was previously installed. [field:this:0x00000000, global:0x005AC1D0]
    // CALL: Calls sub_485EB0(this) to run the shared cleanup/teardown path on the same object after the vtable reset. [source:raw]
    // RETURN: Returns the value produced by sub_485EB0 as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   this->vtable = &off_5AC1D0;
    //   return sub_485EB0(this);
    // UNRESOLVED: sub_485EB0 is called in the raw source but the packet's callees list is empty, so no callee evidence ref exists for it; only source:raw is available.
    // UNRESOLVED: No guard conditions; the function always writes the vtable and runs teardown.
    // UNRESOLVED: Callers are destructor-pattern functions (0x00479E50, 0x0047A230, 0x0047C7F0), consistent with a vtable-reset step inside object teardown, but object identity remains unknown.
}
