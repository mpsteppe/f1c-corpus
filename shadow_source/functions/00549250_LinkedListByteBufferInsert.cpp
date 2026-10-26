// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00549250
// Canonical corpus name: LinkedListByteBufferInsert
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListByteBufferInsert_00549250.c

void UnknownObject::LinkedListByteBufferInsert()
{
    // Inserts byte-buffer node a2 into a doubly-linked list. When bit 4 of a2's first byte is set the head pointer is loaded from *(*this + 0x128), otherwise from *a2. If the list is already initialized (this[0xF4] non-null) it walks the next-pointer chain at offset 0x6C to the tail and appends a2; otherwise it stores the head in this[0xF4] and initializes a2's prev (0x68) and next (0x6C) to 0. Returns the head node pointer.
    // GUARD: Select the head pointer source: if bit 4 of a2's first byte is set, use the pointer at *(*this + 0x128); otherwise use *a2. [field:this:0x00000000, field:obj:0x00000128, source:raw]
    // CALCULATION: Load result = *v2, the first/head node pointer of the chain. [field:obj:0x00000128, source:raw]
    // GUARD: Branch on the list-init flag at this[0xF4]: non-null means the list already holds at least one node. [field:this:0x000000F4, source:raw]
    // LOOP: Walk the next-pointer chain at offset 0x6C from the head node until a null link is found, leaving result at the tail node. [field:*(obj+0x128):0x0000006C, source:raw]
    // ASSIGNMENT: Append: write a2 into the tail's next field at offset 0x6C, set a2's prev (offset 0x68) to the tail, and clear a2's next (offset 0x6C). [field:*(*(*(obj+0x128)+0x6C)+0x6C):0x0000006C, source:raw]
    // ASSIGNMENT: First insertion: store the head node into this[0xF4] and clear a2's prev (0x68) and next (0x6C). [field:this:0x000000F4, source:raw]
    // RETURN: Return the head node pointer. [source:raw]

    // Conservative worker pseudocode:
    //   v2 = ((*(BYTE*)a2 & 4) != 0) ? (*this + 0x128) : a2;
    //   result = *v2;
    //   if (this[0xF4]) {
    //       while (*(result + 0x6C))
    //           result = *(result + 0x6C);
    //       *(result + 0x6C) = a2;
    //       a2[0x6C] = 0;
    //       a2[0x68] = result;
    //   } else {
    //       this[0xF4] = result;
    //       a2[0x68] = 0;
    //       a2[0x6C] = 0;
    //   }
    //   return result;
}
