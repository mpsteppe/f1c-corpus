// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00581A80
// Canonical corpus name: LinkedListCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListCleanup_00581a80.c

void UnknownObject::LinkedListCleanup()
{
    // Walks a singly-linked list from the head stored at this+0, freeing each node's payload when the node+8 flag is set and freeing every node itself, then nulls the four header words at this+0..+0xC and returns the last FreeWrapper_7bcf result.
    // LOOP: Iterate the list from the head pointer at this+0 while the current node pointer is non-null, advancing through the next pointer at node+4. [field:this:0x00000000, field:*(obj+0x4):0x00000004]
    // ASSIGNMENT: Capture the current node pointer v3 and advance the cursor to the next node stored at node+4. [field:*(obj+0x4):0x00000004]
    // GUARD: If the byte flag at node+8 is set, free the node's payload pointer stored at node+0. [field:obj:0x00000008, field:obj:0x00000000, callee:0x00587BCF]
    // CALL: Free the current node's payload pointer at node+0 through FreeWrapper_7bcf when the node+8 flag is set. [callee:0x00587BCF, field:obj:0x00000000, field:obj:0x00000008]
    // CALL: Free the current node itself through FreeWrapper_7bcf as the loop update expression. [callee:0x00587BCF]
    // ASSIGNMENT: Null the list head pointer at this+0. [field:this:0x00000000]
    // ASSIGNMENT: Null the header word at this+4. [field:this:0x00000004]
    // ASSIGNMENT: Null the header word at this+8. [field:this:0x00000008]
    // ASSIGNMENT: Null the header word at this+0xC. [field:this:0x0000000C]
    // RETURN: Return the result of the last FreeWrapper_7bcf call, which is only meaningful after the loop has run. [callee:0x00587BCF]

    // Conservative worker pseudocode:
    //   cursor = *this;
    //   while (cursor != 0) {
    //       node = cursor;
    //       cursor = *(node + 4);
    //       if (*(byte*)(node + 8) != 0)
    //           FreeWrapper_7bcf(*(node + 0));
    //       result = FreeWrapper_7bcf(node);
    //   }
    //   *this = 0;
    //   this[1] = 0;
    //   this[2] = 0;
    //   this[3] = 0;
    //   return result;
    // UNRESOLVED: Exact owner class of the list object and the allocation origin of the nodes are unknown; caller sub_57BCE0 supplies the list pointer.
    // UNRESOLVED: Semantics of the byte flag at node+8 (owns-payload versus in-use) are unconfirmed; it gates payload freeing but not node freeing.
    // UNRESOLVED: The function result is the return value of the final FreeWrapper_7bcf call; its meaning to the caller at 0x0057BCE0 is unresolved.
}
