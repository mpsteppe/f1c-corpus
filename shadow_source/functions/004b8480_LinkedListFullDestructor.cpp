// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B8480
// Canonical corpus name: LinkedListDestructor_8480
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListDestructor_8480_004b8480.c

void UnknownObject::LinkedListFullDestructor()
{
    // Full linked-list teardown: sets a dirty flag, walks every node via the next pointer, frees each node's inner data (string buffer then struct) when the per-node byte flag is set, frees the node frame itself, then zeroes head, tail, cursor and count. Returns 0.
    // ASSIGNMENT: Set the byte at this+0x6D0 to 1 before tearing down the list. [field:this:0x000006D0]
    // ASSIGNMENT: Load the head pointer from this+0x6C0 into the traversal cursor. [field:this:0x000006C0]
    // LOOP: While the traversal cursor is non-null, capture the current node, save the byte flag at node+0xC, advance the cursor through the next pointer at node+0x4, and process the captured node. [field:this:0x000006C0, field:*(this+0x6C0):0x0000000C, source:raw]
    // GUARD: When the node's byte flag at +0xC is non-zero, read the inner data pointer from node+0x0 and free it. [field:*(this+0x6C0):0x0000000C, field:*(this+0x6C0):0x00000000]
    // GUARD: If the inner data pointer is non-null, free the string stored at +0x4 inside it and then free the inner struct itself. [field:*(*(this+0x6C0)+0x0):0x00000004, field:*(*(this+0x6C0)+0x4):0x00000004, callee:0x00587BCF]
    // CALL: Free the node frame that was just walked. [callee:0x00587BCF]
    // ASSIGNMENT: Reset the list state to empty: zero head at this+0x6C0, tail at this+0x6C4, cursor at this+0x6C8 and count at this+0x6CC. [field:this:0x000006C0, field:this:0x000006C4, field:this:0x000006C8, field:this:0x000006CC]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int LinkedListFullDestructor(int this) {
    //     *(BYTE*)(this + 0x6D0) = 1;
    //     void* cur = *(void**)(this + 0x6C0);
    //     while (cur) {
    //       void* node = cur;
    //       char flag = *(BYTE*)((BYTE*)cur + 0xC);
    //       cur = *(void**)((BYTE*)cur + 0x4);
    //       if (flag) {
    //         void* data = *(void**)node;
    //         if (data) {
    //           if (*(void**)((BYTE*)data + 0x4)) FreeWrapper_7bcf(*(void**)((BYTE*)data + 0x4));
    //           FreeWrapper_7bcf(data);
    //         }
    //       }
    //       FreeWrapper_7bcf(node);
    //     }
    //     *(DWORD*)(this + 0x6C0) = 0;
    //     *(DWORD*)(this + 0x6C4) = 0;
    //     *(DWORD*)(this + 0x6C8) = 0;
    //     *(DWORD*)(this + 0x6CC) = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The list's own node type and the meaning of the +0xC byte flag (inner data present?) are not established.
    // UNRESOLVED: Whether the head/tail/cursor/count fields belong to a dedicated linked-list container class is unknown.
    // UNRESOLVED: Called from MenuActionDispatch (0x004B9DA0); the concrete owning object is unknown.
}
