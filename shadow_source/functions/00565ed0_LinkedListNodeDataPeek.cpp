// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00565ED0
// Canonical corpus name: LinkedListNodeDataPeek
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeDataPeek_00565ed0.c

void UnknownObject::LinkedListNodeDataPeek()
{
    // Peek accessor on a linked-list head: reads the first node pointer stored at (*this + 8), then returns a pointer to that node's data payload (first 4-byte field plus 4) when both the node pointer and its data pointer are non-null, otherwise returns 0. Used by FileEnumerationByExtension (00421B10) and sub_47BF30 (0047BF30) as a lite accessor for file/directory enumeration.
    // ASSIGNMENT: Load the first node pointer from offset 8 of the list head structure pointed to by this. [field:this:0x00000000, field:obj:0x00000008]
    // GUARD: If the first node pointer is null (empty list), return 0. [field:obj:0x00000008, source:raw]
    // ASSIGNMENT: Read the node's data pointer from the first 4 bytes of the node (the 4-byte node header). [field:*(obj+0x8):0x00000000]
    // GUARD: If the node's data pointer is null, return 0. [field:*(obj+0x8):0x00000000]
    // RETURN: Return data + 4, the pointer to the payload that follows the node's 4-byte header. [function:0x00565ED0, source:raw]
    // CALL: Called as a data-peek accessor by FileEnumerationByExtension (00421B10) and sub_47BF30 (0047BF30). [caller:0x00421B10, caller:0x0047BF30]

    // Conservative worker pseudocode:
    //   void *LinkedListNodeDataPeek(void *this) {
    //     int *node = *(int **)(*(int *)this + 8);
    //     if (node == NULL) return 0;
    //     int *data = *node;
    //     if (data == NULL) return 0;
    //     return data + 4;
    //   }
    // UNRESOLVED: The list head layout beyond offset 8 and the node layout beyond its first 4 bytes are not described by this function.
    // UNRESOLVED: The exact node header semantics (why the payload starts at +4) are inferred from the return arithmetic only.
}
