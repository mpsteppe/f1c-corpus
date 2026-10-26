// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00433D60
// Canonical corpus name: LinkedListRemovalByName
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListRemovalByName_00433d60.c

void UnknownObject::RemoveNodesByName()
{
    // Walks an intrusive linked list whose head/iterator are stored in the object, removing every node whose name string matches a2. Each removed node is unlinked, the head/iterator/tail bookkeeping fields are repaired, the count is decremented, an owned data object is destroyed when present, and the node is freed. Afterwards the object's own stored name (this+0x10) is compared against a2 and cleared (copied empty) when it matches.
    // LOOP: Initialize the iterator this+0x24 to the head this+0x1C and walk the node chain until a node with a null next link is reached. [field:this:0x0000001C, field:this:0x00000024, source:raw]
    // CALCULATION: Read each node's name string at data+0x14, falling back to the byte_5EA438 string when the pointer is null. [field:*(this+0x1C):0x00000014, global:0x005EA438, source:raw]
    // CALL: Compare the node name against a2 with sub_588410, whose non-zero result marks a match. [callee:0x00588410, source:raw]
    // STATE_TRANSITION: On a match, unlink the node: advance the iterator past it, repoint the predecessor's link, update this+0x1C when the head was removed and this+0x20 when the removed node was the tail. [field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, source:raw]
    // CALCULATION: Decrement the node count this+0x28 once per removed node. [field:this:0x00000028, source:raw]
    // GUARD: When the removed node's owned-data byte flag and data pointer are set, run the data object's destructor PhysicsObjectDestructor_3e60. [callee:0x00433E60, source:raw]
    // CALL: Free the removed node through FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // CALL: After the walk, compare the object's stored name this+0x10 against a2 with sub_588410. [field:this:0x00000010, callee:0x00588410, source:raw]
    // STATE_TRANSITION: When the stored name does not match a2, clear it by copying the empty byte_5EA438 string through StringCopyWithBufferRealloc. [callee:0x00566650, global:0x005EA438, source:raw]
    // RETURN: Return the last comparison result: 0 after the stored-name clear, otherwise the sub_588410 result. [source:raw]

    // Conservative worker pseudocode:
    //   int RemoveNodesByName(this, const char* a2) {
    //     this->iter = this->head;
    //     for (Node* cur = this->head; cur; cur = cur->next) {
    //       const char* name = cur->name ? cur->name : byte_5EA438;
    //       if (sub_588410(a2, name)) {
    //         unlink(cur);               // repair head/tail/iter links, --this->count
    //         if (cur->owned_data_flag && cur->data) PhysicsObjectDestructor_3e60();
    //         FreeWrapper_7bcf(cur);
    //         this->iter = this->head;
    //       }
    //     }
    //     const char* stored = this->stored_name ? this->stored_name : byte_5EA438;
    //     int result = sub_588410(a2, stored);
    //     if (!result) return StringCopyWithBufferRealloc(&byte_5EA438);
    //     return result;
    //   }
    // UNRESOLVED: The list bookkeeping semantics of this+0x1C (head), this+0x20 (tail), this+0x24 (iterator) and this+0x28 (count) are inferred from decompiled field usage and the node layout (link at the first dword, name at 0x14, owned-data flag at 0x8) is decompiler-interpreted.
    // UNRESOLVED: Node struct layout and node ownership rules are not independently confirmed.
}
