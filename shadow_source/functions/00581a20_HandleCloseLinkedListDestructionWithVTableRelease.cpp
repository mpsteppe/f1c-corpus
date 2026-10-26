// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00581A20
// Canonical corpus name: HandleCloseLinkedListDestructionWithVTableReleas
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HandleCloseLinkedListDestructionWithVTableReleas_00581a20.c

void UnknownObject::HandleCloseLinkedListDestructionWithVTableRelease()
{
    // Linked-list destructor for a container at this. Optionally closes the handle stored at this+0x10 (gated by the byte flag at this+0x18, and only cleared on CloseHandle success), then walks the node list from the head at this+0x0. For each node, when the byte flag at node+0x8 is set and the node's data pointer at node+0x0 is non-null, invokes the second vtable destructor (vtable+0x4) on the data object as a __thiscall with argument 1, then frees the node wrapper with FreeWrapper_7bcf. Finally zeroes the list head, tail, cursor and element count.
    // GUARD: Guard on byte flag at this+0x18; when set, close the handle stored at this+0x10 via CloseHandle. [field:this:0x00000018, field:this:0x00000010, global:0x0059E1A8]
    // GUARD: CloseHandle must report success for the handle field to be cleared. [global:0x0059E1A8, source:raw]
    // ASSIGNMENT: Clear the handle field at this+0x10 to 0 after a successful CloseHandle. [field:this:0x00000010, global:0x0059E1A8]
    // LOOP: Walk the linked list from the head pointer at this+0x0, following each node's next-link (node+0x4) until null. [field:this:0x00000000, field:*(obj+0x4):0x00000004]
    // GUARD: Per node: if the byte flag at node+0x8 is set and the node's data pointer at node+0x0 is non-null, invoke the vtable destructor. [field:obj:0x00000008, field:obj:0x00000000]
    // CALL: Invoke the second vtable destructor (entry at vtable+0x4) on the node's data object as a __thiscall with argument 1. [field:*(*(obj+0x0)+0x0):0x00000004, field:*(obj+0x0):0x00000000]
    // CALL: Free the node wrapper via FreeWrapper_7bcf. [callee:0x00587BCF]
    // ASSIGNMENT: Zero the list head pointer at this+0x0 after destruction. [field:this:0x00000000]
    // ASSIGNMENT: Zero the list tail pointer at this+0x4 after destruction. [field:this:0x00000004]
    // ASSIGNMENT: Zero the cursor/iterator pointer at this+0x8 after destruction. [field:this:0x00000008]
    // ASSIGNMENT: Zero the element count at this+0xC after destruction. [field:this:0x0000000C]
    // RETURN: Void return: the list is fully destroyed and all container fields are cleared. [function:0x00581A20, source:raw]

    // Conservative worker pseudocode:
    //   void __thiscall HandleCloseLinkedListDestructionWithVTableRelease(int *this) {
    //     if (*(byte*)this + 24 && CloseHandle((HANDLE)this[4]))
    //       this[4] = 0;
    //     node = *this;
    //     while (node) {
    //       cur = node;
    //       node = *(node + 4);
    //       if (cur[8] && *(dword*)cur)
    //         (vtable_dtor(**(dword**)cur + 4))(*(dword*)cur, 1);
    //       FreeWrapper_7bcf(cur);
    //     }
    //     this[0] = 0; this[1] = 0; this[2] = 0; this[3] = 0;
    //   }
    // UNRESOLVED: Exact node structure (data pointer, byte flag, next-link layout) and the identity of the released data object type are inferred from layout only.
    // UNRESOLVED: Whether the vtable+0x4 destructor called with argument 1 is the primary or a secondary destructor of the data object is unresolved.
}
