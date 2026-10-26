// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005818E0
// Canonical corpus name: ListDestructionWithHandleClose
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ListDestructionWithHandleClose_005818e0.c

void UnknownObject::ListDestructionWithHandleClose()
{
    // Destroys a linked list whose owner object also optionally owns a Windows handle. First, if the byte flag at this+0x18 is non-zero, CloseHandle is invoked on the handle at this+0x10 and the handle field is zeroed when the close succeeds. The linked list rooted at this+0x0 is then walked: for each node, if the node's byte flag at node+0x8 is non-zero and the node's data pointer at node+0x0 is non-null, the data object's first vtable entry (a __thiscall release/delete method) is invoked on the data with argument 1. Every node wrapper is freed via FreeWrapper_7bcf. Finally the head, tail, cursor and count fields (this+0x0, this+0x4, this+0x8, this+0xC) are zeroed.
    // GUARD: The handle close path runs only when the byte flag at this+0x18 is non-zero. [field:this:0x00000018, source:raw]
    // CALL: CloseHandle is called on the handle value at this+0x10. [field:this:0x00000010, global:0x0059E1A8, source:raw]
    // ASSIGNMENT: When CloseHandle returns success, the handle field at this+0x10 is zeroed. [field:this:0x00000010, global:0x0059E1A8, source:raw]
    // LOOP: Walks the singly linked list starting from the head pointer at this+0x0; each node's next pointer lives at node+0x4 and the walk continues while a next node exists. [field:this:0x00000000, source:raw]
    // GUARD: For each node the destructor dispatch runs only when the node's byte flag at node+0x8 is non-zero and the node's data pointer at node+0x0 is non-null. [field:obj:0x00000008, field:obj:0x00000000, source:raw]
    // CALL: The data object's first vtable entry (a __thiscall method) is invoked on the data pointer with argument 1, releasing/deleting the data when the node requires it. [field:*(*(obj+0x0)+0x0):0x00000000, field:*(obj+0x0):0x00000000, field:obj:0x00000000, source:raw]
    // CALL: FreeWrapper_7bcf frees the node wrapper itself. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: The list head at this+0x0 is zeroed after the list is freed. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: The list tail at this+0x4 is zeroed after the list is freed. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: The cursor/iterator field at this+0x8 is zeroed after the list is freed. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: The element count at this+0xC is zeroed after the list is freed. [field:this:0x0000000C, source:raw]
    // RETURN: The function returns void after the list structure fields are reset. [source:raw]

    // Conservative worker pseudocode:
    //   void ListDestructionWithHandleClose(void *this) {
    //     if (*(_BYTE *)((char *)this + 0x18) && CloseHandle(*(HANDLE *)((char *)this + 0x10)))
    //       *(_DWORD *)((char *)this + 0x10) = 0;
    //     _DWORD *node = *(_DWORD **)this;
    //     while (node) {
    //       _DWORD *current = node;
    //       node = (_DWORD *)node[1];
    //       if (*(_BYTE *)((char *)current + 0x8) && *current)
    //         (**(void (__thiscall ***)(_DWORD, int))*current)(*current, 1);
    //       FreeWrapper_7bcf(current);
    //     }
    //     *(_DWORD *)this = 0;
    //     *(_DWORD *)((char *)this + 0x4) = 0;
    //     *(_DWORD *)((char *)this + 0x8) = 0;
    //     *(_DWORD *)((char *)this + 0xC) = 0;
    //   }
    // UNRESOLVED: The owning class of the list object (head/tail/cursor/count at this+0x0..+0xC, handle at this+0x10, close flag at this+0x18) is unknown.
    // UNRESOLVED: The exact vtable method invoked on each node's data (release versus delete) is unresolved; only its position as vtable entry 0 and its single argument value 1 are grounded.
    // UNRESOLVED: The node's next pointer at node+0x4 has no typed field evidence ref in the packet.
    // UNRESOLVED: No static callers were found in the packet; the invocation context is unresolved.
}
