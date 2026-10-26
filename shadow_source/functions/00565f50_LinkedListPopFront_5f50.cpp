// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00565F50
// Canonical corpus name: LinkedListPopFront_5f50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListPopFront_5f50_00565f50.c

void UnknownObject::LinkedListPopFront_5f50()
{
    // Reads the list head pointer from this, positions the list cursor at the first node (overwriting the cursor at node offset 8 with the first node pointer), and returns true only when the list is non-empty and the first node holds a non-null data pointer. Used to begin file/directory enumeration.
    // ASSIGNMENT: Load the list head structure pointer from this+0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Load the first node pointer from the head structure at offset 0 and its data pointer. [field:obj:0x00000000, field:*(obj+0x0):0x00000000, source:raw]
    // GUARD: Test whether the first node pointer is null (empty list). [guard:0, field:obj:0x00000000, source:raw]
    // ASSIGNMENT: Overwrite the cursor at node offset 8 with the first node pointer. [field:obj:0x00000008, source:raw]
    // RETURN: Return true only if the list is non-empty and the first node's data pointer is non-null. [field:*(obj+0x0):0x00000000, field:obj:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   node = *this;
    //   data = *(int*)node;
    //   is_empty = (*(int*)node == 0);
    //   *(int*)(node + 8) = *(int*)node;
    //   return !is_empty && data != 0;
    // UNRESOLVED: The caller-side interpretation of the returned boolean beyond 'cursor positioned at first node' is not derivable from this function alone.
}
