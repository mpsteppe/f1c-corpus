// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567E10
// Canonical corpus name: HashTableListInsert
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HashTableListInsert_00567e10.c

void UnknownObject::HashTableListInsertOrFind()
{
    // Searches a hash-table bucket linked list for the string key at a2+4. If a matching node is found the walk stops and 0 is returned; otherwise a 12-byte entry node (string copied via StringCopyWithBufferRealloc) plus a 12-byte wrapper node are allocated with OperatorNewNhMallocWrapper and appended to the bucket, updating the head/tail/walk pointers, the count, and the next-ID counter. Called from AudioFileLoadDecode.
    // ASSIGNMENT: Initialize the walk pointer (this+0x2C) from the bucket head (this+0x24). [field:this:0x00000024, field:this:0x0000002C, source:raw]
    // GUARD: If the bucket head (this+0x24) is null or its first node pointer is null, skip the search walk and go directly to insertion. [field:this:0x00000024, source:raw]
    // LOOP: Walk the bucket list: compare the key (a2+4, defaulting to byte_5EA438 when null) against each node string via sub_588410, breaking the walk on equality. [callee:0x00588410, global:0x005EA438, field:this:0x0000002C, source:raw]
    // CALCULATION: Advance the walk pointer to the next node: this+0x2C = *(this+0x2C + 4). [field:this:0x0000002C, source:raw]
    // CALL: Allocate a 12-byte entry node via OperatorNewNhMallocWrapper(12). [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the entry node: *node = 0, node[1] = -1, node[2] = current next-id (this+0x34), then increment this+0x34; copy the key string (defaulting to byte_5EA438) into the node via StringCopyWithBufferRealloc. [callee:0x00566650, field:this:0x00000034, global:0x005EA438, source:raw]
    // CALL: If the entry node was allocated, allocate a 12-byte list wrapper node via OperatorNewNhMallocWrapper(12); set wrapper[0] = entry, wrapper[1] = 0, wrapper[2] = 1. [callee:0x00587C03, source:raw]
    // STATE_TRANSITION: If the bucket head (this+0x24) is non-null, append the wrapper: *(tail+4) = wrapper, tail (this+0x28) = wrapper, increment count (this+0x30). [field:this:0x00000024, field:this:0x00000028, field:this:0x00000030, source:raw]
    // STATE_TRANSITION: Else (empty bucket): head (this+0x24), walk (this+0x2C) and tail (this+0x28) all become the wrapper, and count (this+0x30) becomes 1. [field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, source:raw]
    // RETURN: Return 0 when the key was found during the walk; otherwise return the newly allocated wrapper node pointer. [callee:0x00588410, source:raw]

    // Conservative worker pseudocode:
    //   this->walk = this->head;
    //   node = this->head;
    //   if (node && (first = *node)) {
    //     while (first) {
    //       if (compare(first->key, a2->key ?: default) == 0) return 0;
    //       this->walk = this->walk->next;
    //       first = this->walk;
    //       if (!first) break;
    //     }
    //   }
    //   entry = malloc(12);
    //   if (entry) {
    //     this->next_id++;
    //     entry->next = 0; entry->id = -1; entry->key_index = next_id - 1;
    //     copy_string(entry, a2->key ?: default);
    //   }
    //   wrapper = malloc(12);
    //   if (wrapper) { wrapper->entry = entry; wrapper->next = 0; wrapper->flag = 1; }
    //   if (this->head) { this->tail->next = wrapper; this->tail = wrapper; this->count++; }
    //   else { this->head = this->walk = this->tail = wrapper; this->count = 1; }
    //   return wrapper;
    // UNRESOLVED: a2+4 is the key string pointer inside the caller's structure; the exact input struct layout is unknown.
    // UNRESOLVED: sub_588410 is assumed to be a strcmp-like equality test (0 = match) from the decompiler usage; not independently confirmed.
    // UNRESOLVED: Wrapper node +8 byte set to 1 is likely an owned-data flag; semantics DERIVED only.
    // UNRESOLVED: Bucket-list node layout (key@0, next@4, flag@8) inferred from access patterns only.
}
