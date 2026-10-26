// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00581B30
// Canonical corpus name: sub_581B30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_581B30_00581b30.c

void UnknownObject::DestroyDualLinkedLists()
{
    // Destroys two embedded singly-linked lists with node wrappers. Optionally closes a Win32 handle stored at this+0x20 when the flag at this+0x28 is set, zeroing the handle field. First pass frees list1 (head at this+0x10): for each node, if the node flag at node+0x8 is set and node+0x0 holds a data pointer, calls the data object's vtable[0] with argument 1, then frees the data via FreeWrapper_7bcf. Second pass frees list2 (head at this+0x0): for each node with flag set, frees the wrapped data object via its vtable[0] with argument 3 and frees both data and node. Both lists' head/tail/cursor/count fields (this+0x0..0x1C) are zeroed.
    // GUARD: If the flag at this+0x28 is non-zero and CloseHandle(this+0x20) succeeds, the handle field this+0x20 is zeroed [field:this:0x00000028, field:this:0x00000020, global:0x0059E1A8, source:raw]
    // LOOP: Iterate list1 starting at head this+0x10, following node link at node+0x0, until a null cursor [field:this:0x00000010, field:*(this+0x10):0x00000000, field:*(*(this+0x10)+0x0):0x00000000, field:obj:0x00000000, source:raw]
    // GUARD: For each list1 node: if the node flag at node+0x8 is set and the node's data pointer at node+0x0 is non-null, invoke the data object's vtable[0] with argument 1 [field:obj:0x00000008, field:*(obj+0x0):0x00000000, field:*(*(obj+0x0)+0x0):0x00000000, field:*(*(*(obj+0x0)+0x0)+0x0):0x00000000, source:raw]
    // CALL: Free each list1 node wrapper via FreeWrapper_7bcf [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero list1 fields this+0x10, this+0x14, this+0x18, this+0x1C after the pass [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // LOOP: Iterate list2 starting at head this+0x0, following node link at node+0x0, until a null cursor [field:this:0x00000000, field:*(this+0x10):0x00000000, field:obj:0x00000000, source:raw]
    // GUARD: For each list2 node with the flag at node+0x8 set: if the node holds a data pointer at node+0x0, and that data object's vtable is non-null, invoke the data object's vtable[0] with argument 3 and free the data object via FreeWrapper_7bcf [field:obj:0x00000008, field:obj:0x00000000, field:*(obj+0x0):0x00000000, field:*(*(obj+0x0)+0x0):0x00000000, field:*(*(*(obj+0x0)+0x0)+0x0):0x00000000, callee:0x00587BCF, source:raw]
    // CALL: Free each list2 node wrapper itself via FreeWrapper_7bcf [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero list2 fields this+0x0, this+0x4, this+0x8, this+0xC after the pass [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Returns after both lists are emptied and all list fields are zeroed [function:0x00581B30, source:raw]

    // Conservative worker pseudocode:
    //   if (*(BYTE*)(this+0x28) && CloseHandle(*(HANDLE*)(this+0x20))) {
    //     *(DWORD*)(this+0x20) = 0;
    //   }
    //   for (node = *(this+0x10); node; node = node->next) {
    //     if (node->flag8 && node->data) {
    //       node->data->vtable[0](node->data, 1);
    //     }
    //     FreeWrapper_7bcf(node);
    //   }
    //   *(this+0x10) = 0; *(this+0x14) = 0; *(this+0x18) = 0; *(this+0x1C) = 0;
    //   for (node = *(this+0x0); node; node = node->next) {
    //     if (node->flag8) {
    //       data = node->data;
    //       if (data && *data) {
    //         data->vtable[0](data, 3);
    //         FreeWrapper_7bcf(data);
    //       }
    //     }
    //     FreeWrapper_7bcf(node);
    //   }
    //   *(this+0x0) = 0; *(this+0x4) = 0; *(this+0x8) = 0; *(this+0xC) = 0;
    // UNRESOLVED: SEH registration global SEH_581B30 (0x0059CB50) is referenced by packet facts but appears nowhere in the raw decompiled source; its exact role is not verifiable here
    // UNRESOLVED: The concrete types of the two node wrappers, the data objects, and the object owning 'this' are unknown; only the two vtable[0] dispatch conventions (arg 1 for list1 data, arg 3 for list2 data) are observable
}
