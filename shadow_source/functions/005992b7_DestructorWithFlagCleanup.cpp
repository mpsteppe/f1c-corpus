// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005992B7
// Canonical corpus name: DestructorWithFlagCleanup_92b7
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithFlagCleanup_92b7_005992b7.c

void UnknownObject::DestructorWithFlagCleanup()
{
    // Deleting-destructor: first invokes SetLocaleVTableCall on the object (vtable/cleanup fix-up), then conditionally frees the object when the a2 flag's low bit is set. Returns this.
    // CALL: Call SetLocaleVTableCall(this), the vtable/call fix-up that must run before teardown. [callee:0x00598CC1, source:raw]
    // GUARD: If (a2 & 1) != 0, the object owns its storage and must be freed. [source:raw]
    // CALL: Call FreeWrapper_7bcf(this) to release the object memory. [callee:0x00587BCF, source:raw]
    // RETURN: Return this to the caller. [source:raw]

    // Conservative worker pseudocode:
    //   SetLocaleVTableCall(this);
    //   if (a2 & 1)
    //       FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: What SetLocaleVTableCall mutates (vtable, locale bindings) is not visible in this frame.
}
