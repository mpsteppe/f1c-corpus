// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C9820
// Canonical corpus name: VirtualStateCheckViaIndex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VirtualStateCheckViaIndex_004c9820.c

void UnknownObject::VirtualStateCheckViaIndex()
{
    // Thiscall boolean check over a dynamically indexed child object. Reads the index at field 0x1C of this (this[7]), loads the child object pointer at this[this[7]+8], returns 0 when that pointer is null, otherwise dispatches a virtual call (thiscall on the child, method pointer read at child+28) and returns 0 when that call's result equals 2, else returns 1. Called from RendererSceneNodeUpdate (0x004C97B0). The prelabel's 'returns field 0x1C' description does not match the raw source and is not used.
    // GUARD: Read the index field at this+0x1C (this[7]); when the child object at this[this[7]+8] is null, return 0. [field:this:0x0000001C, source:raw]
    // CALL: Invoke the virtual thiscall method whose pointer is stored at offset 28 of the child object's vtable (*(*child + 28)), passing child as the this pointer; compare its result against 2. [source:raw]
    // RETURN: Return 0 when the virtual call result equals 2; otherwise return 1. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_4C9820(this) {
    //     v1 = this[this[7] + 8];
    //     if (!v1)
    //       return 0;
    //     if ((*(*(int**)v1 + 28))(v1) == 2)
    //       return 0;
    //     return 1;
    //   }
    // UNRESOLVED: Semantics of the virtual method result: value 2 selects the false/0 path, but the meaning of the enumeration (state 2) is unknown.
    // UNRESOLVED: Identity of the child object's class and of the virtual method at vtable offset 28.
    // UNRESOLVED: Which this-object layout is indexed by this[7]; the index selects the child at this[this[7]+8], but the container semantics are unproven.
    // UNRESOLVED: The 'ai' subsystem tag and canonical name VirtualStateCheckViaIndex suggest an AI state check, but no evidence ties the value 2 to a concrete AI state.
}
