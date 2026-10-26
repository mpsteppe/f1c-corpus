// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004698C0
// Canonical corpus name: DestructorWithSubObjectFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithSubObjectFree_004698c0.c

void UnknownObject::DestructorWithSubObjectFree()
{
    // Destructor that conditionally frees a heap sub-object referenced at this+0x180 (this[96]) when non-null, calls a cleanup wrapper (FunctionCallWrapper_9440, 0x00489440) on the object itself, then, when the a2&1 flag is set, frees the containing object through FreeWrapper_7bcf (0x00587BCF). Returns the this pointer. Part of the object destruction system.
    // GUARD: Proceed to free the sub-object only when this[96] (this+0x180) is non-null [field:this:0x00000180, source:raw]
    // CALL: FreeWrapper_7bcf frees the sub-object at this+0x180 when the null guard passes [callee:0x00587BCF, field:this:0x00000180, source:raw]
    // CALL: FunctionCallWrapper_9440 performs additional cleanup/deinitialization on this object [callee:0x00489440, source:raw]
    // GUARD: When the a2 & 1 flag is set, the containing this object is freed after cleanup [source:raw]
    // CALL: FreeWrapper_7bcf frees the containing object when the a2&1 guard passes [callee:0x00587BCF, source:raw]
    // RETURN: Return the this pointer [function:0x004698C0, source:raw]

    // Conservative worker pseudocode:
    //   if (this[96] != 0) FreeWrapper_7bcf(this[96]);
    //   FunctionCallWrapper_9440(this);
    //   if ((a2 & 1) != 0) FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: The specific cleanup performed by FunctionCallWrapper_9440 and the meaning of the freed sub-object at this+0x180 are outside this function's evidence
}
