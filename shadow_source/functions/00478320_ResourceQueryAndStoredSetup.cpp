// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00478320
// Canonical corpus name: ResourceQueryAndStoredSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceQueryAndStoredSetup_00478320.c

void UnknownObject::ResourceQueryAndStoredSetup()
{
    // Queries a game command dispatch interface (global dword_7CD8C0) for resource ID 18 by calling a vtable slot at interface+28. When the returned pointer is non-null it stores it at this[56] (this+0xE0) and runs ProfileIconPathSetter on this to update the profile icon path. Returns 0 unconditionally.
    // CALL: Virtual dispatch on the interface at global dword_7CD8C0: call vtable slot 28 (interface+28) with argument 18 as the resource ID query [global:0x007CD8C0, source:raw]
    // GUARD: Only store and run path setup when the dispatch result v2 is non-null [field:this:0x000000E0, source:raw]
    // ASSIGNMENT: this[56] = v2: store the queried resource pointer at this+0xE0 [field:this:0x000000E0, source:raw]
    // CALL: Call ProfileIconPathSetter (00478390) with this to update the profile icon file path from the stored resource [callee:0x00478390, field:this:0x000000E0, source:raw]
    // RETURN: Return 0 unconditionally (the query outcome is reported through this[56], not the return value) [function:0x00478320, source:raw]

    // Conservative worker pseudocode:
    //   v2 = (*(__thiscall **)(int,int))(*(DWORD*)dword_7CD8C0 + 28)(dword_7CD8C0, 18);
    //   if (v2) {
    //     this[56] = v2;
    //     ProfileIconPathSetter(this);
    //   }
    //   return 0;
    // UNRESOLVED: The identity of resource ID 18 and what the vtable slot at interface+28 semantically represents are not defined here
    // UNRESOLVED: No static caller is recorded, so when this query runs in the profile/options flow is unknown
    // UNRESOLVED: The relationship between the stored resource pointer and the profile icon path is only implied by the callee name
}
