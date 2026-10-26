// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00405B00
// Canonical corpus name: AudioResourceRelease
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioResourceRelease_00405b00.c

void UnknownObject::AudioResourceRelease()
{
    // Audio resource release: invokes the vtable destructor at vtable+8, decrements the reference count of a shared audio resource block pointed to by this[23] (offset 0x5C), frees the block when the count reaches zero, clears the pointer, and removes the node from a linked list key lookup. Called by ObjectConstructorWithVTableAndSubFree (0x004058A0).
    // CALL: Invoke vtable destructor at vtable+8 (slot 2) on this [field:obj:0x00000008, field:this:0x00000000, source:raw]
    // GUARD: If this[23] (offset 0x5C) resource block pointer is non-null [field:this:0x0000005C, source:raw]
    // CALCULATION: Decrement the resource block reference count this[23][1] [field:this:0x00000060, field:this:0x0000005C, source:raw]
    // GUARD: If the reference count is <= 0 after decrement [guard:0, field:this:0x00000060]
    // CALL: Free the resource memory via AIL_mem_free_lock (0x0059E3CC) [global:0x0059E3CC, field:this:0x0000005C, source:raw]
    // CALL: Free the resource block allocation via FreeWrapper_7bcf (0x00587BCF) if still non-null [callee:0x00587BCF, field:this:0x0000005C, source:raw]
    // ASSIGNMENT: Clear this[23] (offset 0x5C) to 0 [field:this:0x0000005C, source:raw]
    // CALL: Remove this node from the linked list key lookup via LinkedListNodeRemovalByKey (0x00407BE0) [callee:0x00407BE0, field:this:0x00000000, source:raw]
    // RETURN: Return the result of LinkedListNodeRemovalByKey [callee:0x00407BE0, source:raw]

    // Conservative worker pseudocode:
    //   (*this->vtable[2])(this);
    //   if (this[23]) {
    //     if (--this[23][1] <= 0) {
    //       AIL_mem_free_lock(this[23]);
    //       if (this[23]) FreeWrapper_7bcf(this[23]);
    //     }
    //     this[23] = 0;
    //   }
    //   return LinkedListNodeRemovalByKey(this);
    // UNRESOLVED: Exact class of the audio resource block not established.
    // UNRESOLVED: Return semantics of LinkedListNodeRemovalByKey not grounded.
}
