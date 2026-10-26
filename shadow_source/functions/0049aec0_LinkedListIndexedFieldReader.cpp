// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049AEC0
// Canonical corpus name: LinkedListIndexedFieldReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListIndexedFieldReader_0049aec0.c

void UnknownObject::LinkedListIndexedFieldReader()
{
    // Reads a pair of 16-bit values from a linked list node at a given index. Validates a2 against the list length at this+0xC; on an out-of-range index it clears this+0x8 and skips traversal. Otherwise it starts this+0x8 at the head (this+0x0) and walks a2 steps following the next-node pointer stored at node+4. If the traversed node and its data pointer are valid, it copies two words into *a3 and *a4 and returns 1; otherwise it zeroes both outputs and returns 0. Used by sub_487060, sub_4870E0, UtilityFunction_7160 and TwoChannel16BitReader.
    // GUARD: Index range check: if a2 < 0 or a2 >= this[3] (length at this+0xC), set this+0x8 to 0 and skip traversal entirely [field:this:0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Seed the traversal cursor at this+0x8 with the head pointer at this+0x0 [field:this:0x00000000, field:this:0x00000008, source:raw]
    // LOOP: Walk loop: while the counter is positive, read the current node at this+0x8, break if it is NULL, decrement the counter, and advance this+0x8 to the next-node pointer stored at node+4 [field:this:0x00000008, source:raw]
    // GUARD: Read guard: the node at this+0x8 (v7) must be non-NULL and its first word (v8, the data pointer) must be non-NULL before the fields are copied out [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Success path: write *a3 = v8[0] and *a4 = v8[1] from the node data and return 1 [source:raw]
    // ASSIGNMENT: Failure path: zero both outputs (*a3 = 0, *a4 = 0) and return the 0 result held in the result variable [source:raw]
    // RETURN: Return 1 when both words were read, otherwise 0; the function is used by sub_487060, sub_4870E0, UtilityFunction_7160 and TwoChannel16BitReader [function:0x0049AEC0, caller:0x00487060, caller:0x004870E0, caller:0x00487160, caller:0x00499F00, source:raw]

    // Conservative worker pseudocode:
    //   result = 0;
    //   if (a2 < 0 || a2 >= this[3]) {
    //     this[2] = 0;
    //   } else {
    //     this[2] = this[0];
    //     while (a2 > 0) {
    //       node = this[2];
    //       if (!node) break;
    //       --a2;
    //       this[2] = *(node + 4);
    //     }
    //   }
    //   data = this[2] ? *this[2] : 0;
    //   if (this[2] && data) {
    //     *a3 = data[0];
    //     *a4 = data[1];
    //     return 1;
    //   }
    //   *a3 = 0; *a4 = 0;
    //   return 0;
    // UNRESOLVED: The meaning of the two 16-bit fields read from the node data is not documented in this packet
    // UNRESOLVED: The next-node pointer at node+4 is dereferenced as a dword; the node layout beyond offsets 0 and 4 is not established
    // UNRESOLVED: The length bound at this+0xC is trusted as-is; a NULL node encountered mid-walk terminates the walk early without updating the bound
}
