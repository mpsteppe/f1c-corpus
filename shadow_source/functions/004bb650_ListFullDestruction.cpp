// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BB650
// Canonical corpus name: ListFullDestruction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ListFullDestruction_004bb650.c

void UnknownObject::ListFullDestruction()
{
    // Linked-list destructor with a two-level data free. Walks the list from the head in *this, reading each node's next pointer at +0x4 and free-data flag at +0x8. For each node whose flag is non-zero and whose outer data pointer at +0x0 is non-null, it frees the inner allocation referenced by data[0] and then the outer data block itself via FreeWrapper_7bcf. Every node is then freed. Finally the list bookkeeping fields (head, tail, current, count) are zeroed and 0 is returned.
    // LOOP: Traverse the singly-linked list from the head stored at *this while the current node pointer is non-null. [field:this:0x00000000, source:raw]
    // CALCULATION: Capture the node's outer data pointer (v5 = *v3) and free flag (node+0x8) before advancing to the next node via node+0x4. [field:obj:0x00000000, field:*(obj+0x4):0x00000004, field:obj:0x00000008, source:raw]
    // GUARD: Per node: free the attached data only when the free-data flag at node+0x8 is non-zero AND the outer data pointer at node+0x0 is non-null. [field:obj:0x00000000, field:obj:0x00000008, source:raw]
    // CALL: Free the inner allocation referenced by data[0] (*(*v3)) via FreeWrapper_7bcf. [field:*(obj+0x0):0x00000000, callee:0x00587BCF, source:raw]
    // CALL: Free the outer data block v5 via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // CALL: Free the node itself via FreeWrapper_7bcf on every iteration. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the list head, tail, current and count fields at this+0x0, +0x4, +0x8 and +0xC. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Return 0 after the list is emptied. [source:raw]

    // Conservative worker pseudocode:
    //   int ListFullDestruction(int *this) {
    //     int node = *this;
    //     while (node) {
    //       LPVOID **cur = (LPVOID **)node;
    //       char free_flag = *(char *)(node + 8);
    //       node = *(int *)(node + 4);
    //       if (free_flag && *cur) {
    //         LPVOID *outer = *cur;
    //         FreeWrapper_7bcf(*outer);
    //         FreeWrapper_7bcf(outer);
    //       }
    //       FreeWrapper_7bcf(cur);
    //     }
    //     this[0] = 0; this[1] = 0; this[2] = 0; this[3] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Node object type and the two-level data layout (outer block pointing to an inner allocation) are not established.
    // UNRESOLVED: Relationship between this list and the caller's widget hierarchy is not established.
}
