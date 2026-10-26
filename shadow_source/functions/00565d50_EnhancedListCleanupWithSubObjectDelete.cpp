// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00565D50
// Canonical corpus name: EnhancedListCleanupWithSubObjectDelete
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EnhancedListCleanupWithSubObjectDelete_00565d50.c

void UnknownObject::EnhancedListCleanupWithSubObjectDelete()
{
    // Linked-list destructor with per-node sub-object cleanup. Walks a singly linked list starting at *a1, and for each node: if the flag byte at node+8 is set, frees the node's data pointer, first freeing the sub-resource stored at data+0x144 when it is non-NULL; frees every node regardless of the flag; then zeroes the four dword fields of the list head (a1[0..3]) and returns the last FreeWrapper result. When the list head is NULL the walk is skipped but the head fields are still zeroed.
    // ASSIGNMENT: Load list head: v1 = *a1; keep a copy of the list-head pointer in a saved register. [field:this:0x00000000, source:raw]
    // GUARD: Guard on *a1 being non-NULL; the node walk is skipped when the list is empty. [field:this:0x00000000, source:raw]
    // LOOP: do-while traversal over the linked list, advancing to v1[1] (next pointer) until NULL. [field:this:0x00000000, source:raw]
    // GUARD: Per node: only run data cleanup when the flag byte at node+8 is non-zero. [field:obj:0x00000008, source:raw]
    // GUARD: Only free data and its sub-resource when the node's data pointer *v2 is non-NULL. [field:obj:0x00000000, source:raw]
    // GUARD: Only free the sub-resource when data[81] (offset 0x144) is non-NULL. [field:*(obj+0x0):0x00000144, source:raw]
    // CALL: Free the sub-resource at v3[81] (data + 0x144) via FreeWrapper_7bcf when non-NULL. [field:*(obj+0x0):0x00000144, callee:0x00587BCF, source:raw]
    // CALL: Free the node's data pointer v3 via FreeWrapper_7bcf. [field:obj:0x00000000, callee:0x00587BCF, source:raw]
    // CALL: Free the node structure v2 via FreeWrapper_7bcf and store the result; runs for every node, flag or not. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the four list-head fields: *a1 = 0, a1[1] = 0, a1[2] = 0, a1[3] = 0. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Return the result of the last FreeWrapper_7bcf call. [callee:0x00587BCF, source:raw]

    // Conservative worker pseudocode:
    //   int sub_565D50(LPVOID*** a1) {
    //     LPVOID** v1 = *a1;
    //     int result = 0;
    //     if (*a1) {
    //       do {
    //         LPVOID** node = v1;
    //         v1 = (LPVOID**)v1[1];
    //         if (*(BYTE*)node + 8) {
    //           LPVOID* data = *node;
    //           if (data) {
    //             if (data[81]) FreeWrapper_7bcf(data[81]);
    //             FreeWrapper_7bcf(data);
    //           }
    //         }
    //         result = FreeWrapper_7bcf(node);
    //       } while (v1);
    //     }
    //     *a1 = 0; a1[1] = 0; a1[2] = 0; a1[3] = 0;
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of the node+8 flag (which data payloads need cleanup) is not known.
    // UNRESOLVED: Type of the data sub-object at data+0x144 is unknown.
    // UNRESOLVED: Return value of FreeWrapper_7bcf and its downstream meaning to callers is unknown.
}
