// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00462CE0
// Canonical corpus name: CollisionSpatialQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionSpatialQuery_00462ce0.c

void UnknownObject::CollisionSpatialQuery()
{
    // Issues a spatial/collision query on a sub-object reached through the object pointer stored at this+0x0, calling the sub-object's virtual method at vtable offset 0x6c via VTableCallViaOffset0x6c with arguments a2 and a3. When that call returns non-zero (failure/rejection) the function returns 0 immediately. On success it arms retry state on the object: sets the byte at obj+41 to 1, the float at obj+16 to 5.0, and the dword at obj+16324 to 4, then returns 1. Called by SendJoinRequest (0x00462C00) and AutoJoinRetryLoop (0x004637A0).
    // CALL: VTableCallViaOffset0x6c(*(_DWORD*)(*(_DWORD*)this + 16312), a2, a3): resolve obj = *(this+0), take the sub-object pointer stored at obj+0x3FB8 (16312), and invoke its vtable method at offset 0x6c with a2 and a3. [callee:0x0057A580, field:this:0x00000000, field:obj:0x00003FB8, source:raw]
    // GUARD: Guard on the vtable call result: if it returns non-zero (query failed or rejected) return 0 immediately and do not arm any retry state. [callee:0x0057A580, source:raw]
    // ASSIGNMENT: *((_BYTE*)obj + 41) = 1: set the state flag byte on the object. [field:obj:0x00000029, source:raw]
    // ASSIGNMENT: *(float*)(obj + 16) = 5.0: set the timeout/retry interval float on the object. [field:obj:0x00000010, source:raw]
    // ASSIGNMENT: *(_DWORD*)(obj + 16324) = 4: set the query state enum/dword on the object. [field:obj:0x00003FC4, source:raw]
    // RETURN: Return 1 on the success path. [source:raw]

    // Conservative worker pseudocode:
    //   char CollisionSpatialQuery(void* this, int a2, int a3) {
    //     void* obj = *(void**)this;
    //     if (VTableCallViaOffset0x6c(*(void**)((char*)obj + 16312), a2, a3)) return 0;
    //     *((char*)obj + 41) = 1;
    //     *(float*)((char*)obj + 16) = 5.0f;
    //     *(int*)((char*)obj + 16324) = 4;
    //     return 1;
    //   }
    // UNRESOLVED: The identity and purpose of the vtable method at offset 0x6c on the sub-object at obj+0x3FB8 are unknown; the existing analysis proposes a network collision/query check.
    // UNRESOLVED: The semantics of the armed retry state (byte 1 at +41, float 5.0 at +16, enum 4 at +16324) are not established by the packet alone.
    // UNRESOLVED: Global flt_59F0A0 is listed in the packet but does not appear in the raw source of this function; its role is unknown.
    // UNRESOLVED: The owning object and the two callers' (SendJoinRequest, AutoJoinRetryLoop) expectation of the returned char are not established.
}
