// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C8210
// Canonical corpus name: ListDestructorWithSubFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ListDestructorWithSubFree_004c8210.c

void UnknownObject::ListDestructorWithSubFree()
{
    // __thiscall linked-list destructor. Walks a singly linked list rooted at *this (next pointer at node+4), and for every node: if the flag byte at node+8 is set, frees the node's data object at node+0 (and, when that data object's first member at +0 is non-null, frees that member first), then frees the node itself via FreeWrapper_7bcf. The body appears as two successive walk/free passes (decompiler duplication), each followed by zeroing the four header slots this[0..3] (+0x0/+0x4/+0x8/+0xC). Between the passes the code calls ArithmeticComparison_8350 and returns its result. Object class and the meaning of the flag byte are unknown.
    // LOOP: Walk the linked list: read the head *this and follow next pointers at node+4 until the null sentinel; each iteration keeps the current node in v3 and advances v2 to node->next. [field:this:0x00000000, field:*(obj+0x4):0x00000004]
    // GUARD: Test the flag byte at node+8 (v4); only when set is the node's data object freed. [field:obj:0x00000008]
    // ASSIGNMENT: Capture the node's data pointer v5 = *v3 from offset 0 of the node. [field:obj:0x00000000]
    // GUARD: Skip the inner free when the data pointer v5 is null. [field:obj:0x00000000]
    // GUARD: Test the data object's first member *v5 (offset 0 of the data object); free it only when non-null. [field:*(obj+0x0):0x00000000]
    // CALL: Free the data object's first member *v5 via FreeWrapper_7bcf. [field:*(obj+0x0):0x00000000, callee:0x00587BCF]
    // CALL: Free the data object v5 via FreeWrapper_7bcf. [field:obj:0x00000000, callee:0x00587BCF]
    // CALL: Free the node v3 itself via FreeWrapper_7bcf (first walk pass). [callee:0x00587BCF]
    // ASSIGNMENT: Zero the four header slots this[0..3] at offsets 0x0, 0x4, 0x8 and 0xC after the first pass. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // CALL: Call ArithmeticComparison_8350 between the two passes and keep its return value as the function result. [callee:0x004C8350]
    // LOOP: Second walk/free pass over the (already zeroed) root, structurally identical to the first; the node is freed by the loop increment expression result = FreeWrapper_7bcf(v8). [field:this:0x00000000, field:*(obj+0x4):0x00000004, callee:0x00587BCF]
    // ASSIGNMENT: Zero the four header slots this[0..3] again after the second pass. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // RETURN: Return the result captured from the ArithmeticComparison_8350 call. [function:0x004C8210, source:raw]

    // Conservative worker pseudocode:
    //   void freeNodeData(void* node) {
    //     if (*(char*)((char*)node + 8)) {
    //       void* data = *(void**)node;
    //       if (data) {
    //         if (*(void**)data) FreeWrapper_7bcf(*(void**)data);
    //         FreeWrapper_7bcf(data);
    //       }
    //     }
    //   }
    //   int sub_4C8210(void* this) {
    //     void* node = *(void**)this;
    //     while (node) { void* next = *(void**)((char*)node + 4); freeNodeData(node); FreeWrapper_7bcf(node); node = next; }
    //     this->slot0 = this->slot4 = this->slot8 = this->slotC = 0;
    //     int result = ArithmeticComparison_8350();
    //     node = *(void**)this;
    //     while (node) { void* next = *(void**)((char*)node + 4); freeNodeData(node); result = FreeWrapper_7bcf(node); node = next; }
    //     this->slot0 = this->slot4 = this->slot8 = this->slotC = 0;
    //     return result;
    //   }
    // UNRESOLVED: Why the walk/free body appears twice (genuine duplicate pass vs decompiler loop duplication) is unresolved; both passes are recorded from raw source.
    // UNRESOLVED: Identity and purpose of the ArithmeticComparison_8350 call between the passes is unknown; its result becomes the return value.
    // UNRESOLVED: Meaning of the flag byte at node+8 (owns-data / refcount) and the node header layout (data at +0, next at +4, flag at +8) are inferred from access patterns, not confirmed.
    // UNRESOLVED: Object class owning this list header is unknown; the cluster prelabel (structural twin of 004bb4f0) is DERIVED only.
}
