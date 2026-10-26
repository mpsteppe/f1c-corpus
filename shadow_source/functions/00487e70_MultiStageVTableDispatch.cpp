// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487E70
// Canonical corpus name: MultiStageVTableDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiStageVTableDispatch_00487e70.c

void UnknownObject::MultiStageVTableDispatch()
{
    // Multi-stage validated vtable dispatch. Reads two DWORD values through DualFieldRead from the object pointer stored at this+0x40 into v4 and v3. Requires all three checks to pass: UIValueValidator(this) non-zero, a vtable offset 48 __thiscall (this, v4, v3) returning non-zero, and a vtable offset 156 __thiscall (this) returning zero. On any failure returns -1. On success calls LinkedListTraversalWithCallback(this) and returns 0.
    // CALL: Call DualFieldRead on the object pointer stored at this+0x40, writing the first read value into v4 and the second into v3. [source:raw, callee:0x00498880, field:this:0x00000040]
    // GUARD: Guard 1: if UIValueValidator(this) returns 0, the combined validation fails (block). [source:raw, callee:0x004874E0]
    // CALL: Dispatch vtable offset 48 as __thiscall (this, v4, v3); if it returns 0, the combined validation fails (block). [source:raw, field:this:0x00000000, field:obj:0x00000030]
    // CALL: Dispatch vtable offset 156 as __thiscall (this); if it returns non-zero, the combined validation fails (block). [source:raw, field:this:0x00000000, field:obj:0x0000009C]
    // RETURN: If any of the three validation checks fails, return -1. [source:raw]
    // CALL: After all checks pass, call LinkedListTraversalWithCallback(this) to traverse the linked list with callback. [source:raw, callee:0x00486630]
    // RETURN: Return 0 on the success path after the linked-list traversal. [source:raw]

    // Conservative worker pseudocode:
    //   int MultiStageVTableDispatch(int this) {
    //     int v3, v4;
    //     DualFieldRead(*(_DWORD**)(this + 64), &v4, &v3);
    //     if (!UIValueValidator((_BYTE*)this)
    //         || !(*(int (__thiscall **)(int,int,int))(*(_DWORD*)this + 48))(this, v4, v3)
    //         || (*(int (__thiscall **)(int))(*(_DWORD*)this + 156))(this)) {
    //       return -1;
    //     }
    //     LinkedListTraversalWithCallback((_DWORD*)this);
    //     return 0;
    //   }
    // UNRESOLVED: Identity of this (object type and vtable layout unknown); vtable slots +48 and +156 are virtual methods without names.
    // UNRESOLVED: Internal offsets of the two fields read by DualFieldRead on the object at this+0x40 are not visible in the raw source; obj+0x30 and obj+0x9C are matched by DERIVED analysis only.
    // UNRESOLVED: Whether vtable offset 156 is a validator or a state-sync method is not established by the raw source.
}
