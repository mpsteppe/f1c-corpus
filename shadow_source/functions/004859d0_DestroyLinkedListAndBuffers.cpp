// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004859D0
// Canonical corpus name: LinkedListDtor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListDtor_004859d0.c

void UnknownObject::DestroyLinkedListAndBuffers()
{
    // Destructor that walks a linked list rooted at this+0x164, freeing each node's data pointer (when the node flag byte at node+0x8 is non-zero) and each node itself, then clears the four list fields at this+0x164/0x168/0x16C/0x170 to 0. Frees a standalone buffer pointer at this+0x15C when non-null, runs ConditionalDualCleanup on sub-objects at this+0x11C and this+0xE0, chains to the base destructor sub_485EB0, and frees the object itself when the least-significant bit of the flag argument a2 is set.
    // LOOP: Walk the linked list rooted at this+0x164 while the current node pointer is non-null, reading the next-node pointer at node+0x4 to advance the traversal. [field:*(*(this+0x164)+0x4):0x00000004, field:this:0x00000164, source:raw]
    // GUARD: Read the flag byte at node+0x8; when it is zero the node's data pointer is not freed, otherwise the data pointer at node+0x0 is freed first. [field:*(this+0x164):0x00000000, field:*(this+0x164):0x00000008, guard:0, source:raw]
    // CALL: Free the node data pointer at node+0x0 via FreeWrapper_7bcf when the flag byte at node+0x8 is non-zero. [field:*(this+0x164):0x00000000, guard:0, callee:0x00587BCF, source:raw]
    // CALL: Free each list node object itself via FreeWrapper_7bcf during the traversal. [field:this:0x00000164, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear the four list fields this+0x164, this+0x168, this+0x16C and this+0x170 to 0 after the traversal completes. [field:this:0x00000164, field:this:0x00000168, field:this:0x0000016C, field:this:0x00000170, source:raw]
    // GUARD: When the standalone buffer pointer at this+0x15C is non-null, free it via FreeWrapper_7bcf. [field:this:0x0000015C, source:raw]
    // CALL: Free the standalone buffer pointed to by this+0x15C via FreeWrapper_7bcf. [field:this:0x0000015C, callee:0x00587BCF, source:raw]
    // CALL: Invoke ConditionalDualCleanup on the sub-object at this+0x11C (decimal 284). [callee:0x00499B50, source:raw]
    // CALL: Invoke ConditionalDualCleanup on the sub-object at this+0xE0 (decimal 224). [callee:0x00499B50, source:raw]
    // CALL: Chain to the base-class destructor sub_485EB0 with this as its argument. [callee:0x00485EB0, source:raw]
    // GUARD: When the least-significant bit of the flag argument a2 is set, free the object itself via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // CALL: Free the object itself via FreeWrapper_7bcf when a2 bit 0 is set (the virtual-delete path). [callee:0x00587BCF, source:raw]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   void DestroyLinkedListAndBuffers(int this, char a2) {
    //     int node = *(int*)(this + 0x164);
    //     while (node) {
    //       int cur = node;
    //       bool skipData = *(byte*)(node + 8) == 0;
    //       node = *(int*)(node + 4);
    //       if (!skipData) FreeWrapper_7bcf(*(void**)cur);
    //       FreeWrapper_7bcf((void*)cur);
    //     }
    //     *(int*)(this + 0x164) = 0;
    //     *(int*)(this + 0x168) = 0;
    //     *(int*)(this + 0x16C) = 0;
    //     *(int*)(this + 0x170) = 0;
    //     if (*(int*)(this + 0x15C)) FreeWrapper_7bcf(*(void**)(this + 0x15C));
    //     ConditionalDualCleanup(this + 0x11C);
    //     ConditionalDualCleanup(this + 0xE0);
    //     sub_485EB0(this);
    //     if (a2 & 1) FreeWrapper_7bcf((void*)this);
    //   }
    // UNRESOLVED: The owner class of this object and the purpose of the cleared fields at this+0x168/0x16C/0x170 (list tail/count/state) are not evidenced in this packet.
    // UNRESOLVED: What ConditionalDualCleanup frees inside the sub-objects at this+0x11C and this+0xE0 is outside this function's evidence.
    // UNRESOLVED: The base destructor sub_485EB0's behavior and the object layout it expects are not evidenced here.
}
