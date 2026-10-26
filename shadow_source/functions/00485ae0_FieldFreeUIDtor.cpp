// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00485AE0
// Canonical corpus name: FieldFreeUIDtor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldFreeUIDtor_00485ae0.c

void UnknownObject::FieldFreeUIDtor()
{
    // Destructor that releases an owned sub-resource, runs a base/contained cleanup, and optionally deallocates the object itself. If the resource pointer at this+0x174 (this[93]) is non-null it is freed via FreeWrapper_7bcf; then FunctionCallWrapper_9440 is invoked on this; finally, when the scalar-deletion flag (a2 & 1) is set, this is freed via FreeWrapper_7bcf. Returns this.
    // GUARD: If the sub-resource pointer at this+0x174 (this[93]) is non-null, free it [field:this:0x00000174, source:raw]
    // CALL: FreeWrapper_7bcf deallocates the sub-resource at this+0x174 via the internal allocator [callee:0x00587BCF, field:this:0x00000174, source:raw]
    // CALL: FunctionCallWrapper_9440 is invoked on this for the base/contained cleanup step [callee:0x00489440, source:raw]
    // GUARD: If the scalar-deletion flag (a2 & 1) is non-zero, deallocate the object itself [source:raw]
    // CALL: FreeWrapper_7bcf deallocates this when the scalar-deletion flag is set [callee:0x00587BCF, source:raw]
    // RETURN: Return this, following the conventional scalar-deleting destructor contract [function:0x00485AE0, source:raw]

    // Conservative worker pseudocode:
    //   if (this[93])
    //     FreeWrapper_7bcf(this[93]);
    //   FunctionCallWrapper_9440(this);
    //   if (a2 & 1)
    //     FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: The type of the sub-resource at this+0x174 and its relationship to this object are not derivable from the packet
    // UNRESOLVED: The semantics of FunctionCallWrapper_9440 (base destructor, contained-object cleanup, or other) are unverified; its internal behaviour is outside this packet
    // UNRESOLVED: No callers are recorded in the packet, so the object class and destruction trigger are unknown
}
