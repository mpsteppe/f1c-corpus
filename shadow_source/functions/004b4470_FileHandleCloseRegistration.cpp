// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B4470
// Canonical corpus name: FileHandleCloseRegistration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileHandleCloseRegistration_004b4470.c

void UnknownObject::FileHandleCloseRegistration()
{
    // Registration helper: looks up a resource handle for key a2 via ResourceLookupDispatcher and stores it at this+0x4, then routes a 4-byte header (this) and a 2-byte sub-field (this+2) through ConditionalDispatch_6bd0. Returns 1 unconditionally. Called from CollisionObjectListManagement during object registration.
    // CALL: Call ResourceLookupDispatcher(a2) and assign its result to this[1] (this+0x4), the resource handle pointer. [callee:0x00566E20, field:this:0x00000004, source:raw]
    // CALL: Call ConditionalDispatch_6bd0(this, 4) to dispatch the 4-byte header at this. [callee:0x00566BD0, source:raw]
    // CALL: Call ConditionalDispatch_6bd0(this + 2, 2) to dispatch the 2-byte sub-field at this+2. [callee:0x00566BD0, source:raw]
    // RETURN: Return constant 1; the function always completes linearly with no branches. [source:raw]
    // CALL: Called by CollisionObjectListManagement (0x004B4B50) during object registration. [caller:0x004B4B50, source:raw]

    // Conservative worker pseudocode:
    //   char sub_4B4470(void *this, int key) {
    //     this[1] = ResourceLookupDispatcher(key);
    //     ConditionalDispatch_6bd0(this, 4);
    //     ConditionalDispatch_6bd0((char *)this + 2, 2);
    //     return 1;
    //   }
    // UNRESOLVED: Meaning of the 4-byte header and 2-byte sub-field dispatched by ConditionalDispatch_6bd0 is unknown.
    // UNRESOLVED: a2 is used only as a lookup key; its type is unknown.
}
