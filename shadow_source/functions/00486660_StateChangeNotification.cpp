// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486660
// Canonical corpus name: StateChangeNotification
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateChangeNotification_00486660.c

void UnknownObject::StateChangeNotification()
{
    // UI state propagation. Stores the incoming state byte a2 into the byte state field at this+0x64 (this[100]); when the new value differs from the previously stored value, first fires the pre-change notification (vtable offset 44, __thiscall) with argument 1. It then walks the subscriber linked list headed at this+0x90, invoking each node's vtable offset 56 (__thiscall) with a2 and advancing via StructFieldAccessor until the list ends.
    // GUARD: Guard on state change: if (BYTE)a2 != this[100] (byte at this+0x64), call the vtable offset 44 __thiscall virtual with (this, 1) as the pre-change notification. [source:raw, field:this:0x00000064, field:obj:0x0000002C, field:this:0x00000000]
    // ASSIGNMENT: Unconditionally store a2 into the byte state field at this+0x64 (this[100]). [source:raw, field:this:0x00000064]
    // LOOP: For the subscriber linked list headed at this+0x90: for each node, call the node's vtable offset 56 __thiscall virtual with (node, a2), then advance to the next node via StructFieldAccessor; iterate until the next-node pointer is null. [source:raw, field:this:0x00000090, field:*(this+0x90):0x00000000, field:*(*(this+0x90)+0x0):0x00000038, callee:0x00486320]

    // Conservative worker pseudocode:
    //   void StateChangeNotification(_BYTE* this, int a2) {
    //     if ((BYTE)a2 != this[100])
    //       (*(void (__thiscall **)(_BYTE*,int))(*(_DWORD*)this + 44))(this, 1);
    //     this[100] = (BYTE)a2;
    //     _DWORD* i = *(_DWORD**)((_DWORD*)this + 36);
    //     while (i) {
    //       (*(void (__thiscall **)(_DWORD*,int))(*i + 56))(i, a2);
    //       i = (_DWORD*)StructFieldAccessor(i);
    //     }
    //   }
    // UNRESOLVED: Identity of this (object type and vtable layout unknown); vtable slot +44 is the pre-change notification and slot +56 is the subscriber notification method, both without names.
    // UNRESOLVED: Subscriber node structure at this+0x90: node field +0x0 doubles as vtable/header and StructFieldAccessor traverses via offset +0x38; exact node type unknown.
}
