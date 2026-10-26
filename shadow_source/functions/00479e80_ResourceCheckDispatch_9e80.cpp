// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479E80
// Canonical corpus name: ResourceCheckDispatch_9e80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceCheckDispatch_9e80_00479e80.c

void UnknownObject::ResourceCheckDispatch_9e80()
{
    // Resource-check dispatcher: initializes this via F_5FieldInit, then calls the vtable slot at offset 28 of the object pointed to by global dword_7CD8C0 with selector argument 12, and if a non-null object is returned, compares its name against this via ObjectNameComparison. Always returns 0.
    // CALL: Initialize this with F_5FieldInit. [callee:0x004883A0, source:raw]
    // CALL: Indirect call through vtable slot 28 of the object at global dword_7CD8C0, passing (dword_7CD8C0, 12); the slot behaves as an allocator/factory taking a selector. [global:0x007CD8C0, source:raw]
    // GUARD: Guard on the object returned by the vtable call being non-null. [source:raw]
    // CALL: If the returned object is non-null, call ObjectNameComparison(returnedObject, this) to compare object names. [callee:0x00477280, source:raw]
    // RETURN: Return 0. [function:0x00479E80, source:raw]

    // Conservative worker pseudocode:
    //   int ResourceCheckDispatch_9e80(Object* this) {
    //       F_5FieldInit(this);
    //       Object* obj = dword_7CD8C0->vtable[28 / 4](dword_7CD8C0, 12);
    //       if (obj != 0) {
    //           ObjectNameComparison(obj, this);
    //       }
    //       return 0;
    //   }
    // UNRESOLVED: Type and contract of the object behind global dword_7CD8C0 and its vtable slot 28 (called with selector 12) are unknown.
    // UNRESOLVED: Semantics of ObjectNameComparison and the meaning of selector 12 are unresolved.
    // UNRESOLVED: No static callers recorded.
}
