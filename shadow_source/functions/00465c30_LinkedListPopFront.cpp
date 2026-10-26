// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00465C30
// Canonical corpus name: LinkedListPopFront
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListPopFront_00465c30.c

void UnknownObject::LinkedListPopFront()
{
    // Pops the front node of a linked list whose head pointer lives at *this+0xE5C8, writes the node's first dword (the payload) to the caller's out parameter *a2, and advances the head to the node's next pointer. Returns 1 on success, 0 when the list is empty or the head node's first dword is zero.
    // GUARD: Return 0 when the list head at *this+0xE5C8 is NULL (empty list). [field:this:0x00000000, field:obj:0x0000E5C8]
    // GUARD: Return 0 when the head node's first dword (node payload) is 0. [field:*(obj+0xE5C8):0x00000000, source:raw]
    // ASSIGNMENT: Write the head node's first dword (node payload) to the caller's out parameter *a2. [field:*(obj+0xE5C8):0x00000000, source:raw]
    // ASSIGNMENT: Advance the list head at *this+0xE5C8 to the head node's second dword (+4, the next pointer) when the head node is present. [field:*(obj+0xE5C8):0x00000004, field:obj:0x0000E5C8, source:raw]
    // RETURN: Return 1 after a successful pop. [function:0x00465C30, source:raw]
    // CALL: Invoked by InputCommandDispatchToEntities (0045F4A0) to consume entries from the list. [caller:0x0045F4A0, source:raw]

    // Conservative worker pseudocode:
    //   char LinkedListPopFront(int *this, _DWORD *out_data) {
    //     void **head = *(void ***)(*this + 0xE5C8);
    //     if (head == 0) return 0;
    //     if (head[0] == 0) return 0;
    //     *out_data = head[0];
    //     head = *(void ***)(*this + 0xE5C8);
    //     if (head != 0) {
    //       *(void ***)(*this + 0xE5C8) = (void **)head[1];
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: The enclosing object referenced through *this is not identified; the list head at *this+0xE5C8 has no known containing class.
    // UNRESOLVED: The head node's first dword is returned as the popped payload, and the zero guard makes a payload of 0 indistinguishable from an invalid node.
}
