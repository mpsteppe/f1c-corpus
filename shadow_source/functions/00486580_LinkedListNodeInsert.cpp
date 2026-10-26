// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486580
// Canonical corpus name: LinkedListNodeInsert_6580
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeInsert_6580_00486580.c

void UnknownObject::LinkedListNodeInsert()
{
    // Inserts a new string node at the tail of a linked list rooted on the receiver. Allocates an 8-byte data buffer, copies the source string into it, allocates a 12-byte node pointing at the buffer, then appends the node: linking the previous tail's next pointer, or initializing head and an alternate pointer on first insertion, updating tail and incrementing the node count.
    // CALL: Allocate an 8-byte string data buffer via OperatorNewNhMallocWrapper(8). [callee:0x00587C03, source:raw]
    // GUARD: Guard on the data allocation result being non-zero; a null result forces v4 to 0 and skips the whole insertion. [source:raw]
    // ASSIGNMENT: Initialize the data buffer: value 0 at offset 0 and -1 at offset 4. [source:raw]
    // CALL: Copy the source string a2 into the data buffer via StringCopyWithBufferRealloc. [callee:0x00566650, source:raw]
    // CALL: Allocate a 12-byte node via OperatorNewNhMallocWrapper(12). [callee:0x00587C03, source:raw]
    // GUARD: Guard on the node allocation result being non-zero; a null result yields 0 and the node is not linked. [source:raw]
    // ASSIGNMENT: Initialize the node: data-buffer pointer at offset 0, next pointer 0 at offset 4, and flag byte 1 at offset 8. [source:raw]
    // GUARD: Branch on head this[21] being non-zero to choose tail-append versus first-insertion linking. [field:this:0x00000054, source:raw]
    // ASSIGNMENT: Tail-append: write the new node into the previous tail's next pointer at offset 4 (this[22] + 4). [field:this:0x00000058, source:raw]
    // ASSIGNMENT: First insertion: set head this[21] and alternate pointer this[23] to the new node. [field:this:0x00000054, field:this:0x0000005C, source:raw]
    // ASSIGNMENT: Update tail this[22] to the new node. [field:this:0x00000058, source:raw]
    // CALCULATION: Increment the node count at this[24]. [field:this:0x00000060, source:raw]
    // RETURN: Return the new node pointer, or 0 when a relevant allocation failed. [source:raw]

    // Conservative worker pseudocode:
    //   int LinkedListNodeInsert(int* this, int a2) {
    //     int data = OperatorNewNhMallocWrapper(8);
    //     int node;
    //     if (data) { *(int*)data = 0; *(int*)(data + 4) = -1; StringCopyWithBufferRealloc(a2); node = data ? 1 : 0; }
    //     else { node = 0; }
    //     int result = 0;
    //     if (node) {
    //       result = OperatorNewNhMallocWrapper(12);
    //       if (result) { *(int*)result = data; *(int*)(result + 4) = 0; *(char*)(result + 8) = 1; }
    //       if (this[21]) *(int*)(this[22] + 4) = result;
    //       else { this[21] = result; this[23] = result; }
    //       this[22] = result;
    //       ++this[24];
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Receiver identity and the list head/tail/alternate pointer semantics (this[21]/this[22]/this[23]) are inferred from the insertion pattern.
    // UNRESOLVED: Purpose of the flag byte at node offset 8 and of the -1 value at data offset 4 is unknown.
    // UNRESOLVED: Caller sub_492A40 supplies the string and the list owner; no owner type is grounded.
}
