// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563160
// Canonical corpus name: ConditionalNetworkUtility
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalNetworkUtility_00563160.c

void UnknownObject::ConditionalNetworkUtility()
{
    // Null-guarded allocator/dispatcher. Returns 0 immediately when this is null. Otherwise allocates a struct via StructAllocInitWithSwitchBasedType using the type selector at this+0x94, places the result in a3, then dispatches through the callback pointer at this+0x4 via SingleFunctionCallWrapper_48c0(v6, &a3). Returns the (possibly callback-rewritten) a3. Invoked by NetworkConnection (00563260) and sub_563410.
    // GUARD: Guard: if this is null, return 0 without allocating or dispatching. [source:raw]
    // CALL: Allocate and initialize a struct: v5 = StructAllocInitWithSwitchBasedType(a3, this[37]). [callee:0x005642F0, field:this:0x00000094, source:raw]
    // ASSIGNMENT: Read the dispatch callback: v6 = this[1]. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Place the allocated struct into the output slot: a3 = v5. [source:raw]
    // CALL: Dispatch through the callback via SingleFunctionCallWrapper_48c0(v6, &a3); the callback may rewrite a3. [callee:0x005648C0, field:this:0x00000004, source:raw]
    // RETURN: Return a3 (the allocated struct, possibly rewritten by the dispatched callback). [source:raw]
    // CALL: Invoked by NetworkConnection (00563260) and sub_563410 for network struct allocation and dispatch. [caller:0x00563260, caller:0x00563410, source:raw]

    // Conservative worker pseudocode:
    //   if (!this) return 0;
    //   v5 = StructAllocInitWithSwitchBasedType(a3, this[37]);
    //   v6 = this[1];
    //   a3 = v5;
    //   SingleFunctionCallWrapper_48c0(v6, &a3);
    //   return a3;
    // UNRESOLVED: Identity of the object type selected by this+0x94 and the purpose of the dispatch callback this+0x4.
    // UNRESOLVED: Parameter a2 is accepted by the signature but never referenced in the body; its role is unknown.
}
