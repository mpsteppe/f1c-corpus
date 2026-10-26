// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048AAA0
// Canonical corpus name: LinkedListPoolDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListPoolDestructor_0048aaa0.c

void UnknownObject::LinkedListPoolDestructor()
{
    // __thiscall destructor for a pooled linked-list object. Walks the node chain from pool head at offset 0xEC, and for each node frees its data pointer (and, when the node flag byte at node+8 is set, the inner data pointer chain via the node data first field) before freeing the node struct itself. Afterwards zeros pool fields 0xEC/0xF0/0xF4/0xF8 and reinitializes the object via ConstructorWithVTableSet. Frees the object itself when flag a2 bit 0 is set.
    // ASSIGNMENT: Read pool head pointer from offset 0xEC. [field:this:0x000000EC]
    // LOOP: Walk the node chain while the current node pointer is non-zero. [source:raw]
    // ASSIGNMENT: Read node flag byte at node+8 that selects deep freeing. [field:*(this+0xEC):0x00000008]
    // ASSIGNMENT: Advance the walk to the next node via the pointer at node+4. [source:raw]
    // GUARD: When the node flag byte is non-zero, free the node data and its inner data. [source:raw]
    // ASSIGNMENT: Read node data pointer (first field of node struct). [field:*(this+0xEC):0x00000000]
    // GUARD: Only dereference/free node data when the data pointer is non-zero. [source:raw]
    // GUARD: Only free inner data when its first field is non-zero. [field:*(*(this+0xEC)+0x0):0x00000000]
    // CALL: Free inner data pointer via FreeWrapper_7bcf. [callee:0x00587BCF]
    // CALL: Free node data block via FreeWrapper_7bcf. [callee:0x00587BCF]
    // CALL: Free the node struct itself via FreeWrapper_7bcf. [callee:0x00587BCF]
    // ASSIGNMENT: Zero pool head field at offset 0xEC. [field:this:0x000000EC]
    // ASSIGNMENT: Zero pool field at offset 0xF0. [field:this:0x000000F0]
    // ASSIGNMENT: Zero pool field at offset 0xF4. [field:this:0x000000F4]
    // ASSIGNMENT: Zero pool field at offset 0xF8. [field:this:0x000000F8]
    // CALL: Reinitialize the object via ConstructorWithVTableSet. [callee:0x00488B30]
    // GUARD: When flag a2 bit 0 is set, free the object itself. [source:raw]
    // CALL: Free the object memory via FreeWrapper_7bcf. [callee:0x00587BCF]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   int LinkedListPoolDestructor(int this, char flags) {
    //     int cur = *(int*)(this + 0xEC);
    //     while (cur) {
    //       void **node = (void**)cur;
    //       char deep = *(char*)(cur + 8);
    //       cur = *(int*)(cur + 4);
    //       if (deep) {
    //         void *data = *node;
    //         if (data) {
    //           if (*(void**)data) FreeWrapper_7bcf(*(void**)data);
    //           FreeWrapper_7bcf(data);
    //         }
    //       }
    //       FreeWrapper_7bcf(node);
    //     }
    //     *(int*)(this + 0xEC) = 0;
    //     *(int*)(this + 0xF0) = 0;
    //     *(int*)(this + 0xF4) = 0;
    //     *(int*)(this + 0xF8) = 0;
    //     ConstructorWithVTableSet((void*)this);
    //     if (flags & 1) FreeWrapper_7bcf((void*)this);
    //     return this;
    //   }
    // UNRESOLVED: The node next-pointer field at node+4 is not present in the packet field evidence set.
    // UNRESOLVED: Purpose of the zeroed fields 0xF0/0xF4/0xF8 beyond being pool bookkeeping is unknown.
    // UNRESOLVED: Semantic role of the node data field at data+4 is not accessed in this function.
}
