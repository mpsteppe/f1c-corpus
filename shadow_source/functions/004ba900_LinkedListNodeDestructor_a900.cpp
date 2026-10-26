// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BA900
// Canonical corpus name: LinkedListNodeDestructor_a900
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeDestructor_a900_004ba900.c

void UnknownObject::LinkedListNodeDestructor_a900()
{
    // Linked list node destructor called from DestroyUIWidgetHierarchy. When the byte flag at this+0xC is non-zero the node's data block is torn down: the primary data pointer at this+0x0 is freed, and its secondary pointer at payload+0x4 is freed first if non-null. The node buffer itself is freed via FreeWrapper_7bcf only when a2 bit 0 is set. Returns this unchanged.
    // GUARD: Data teardown runs only when the byte flag at this+0xC is non-zero. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Load the primary data block pointer from this+0x0 into v3. [field:this:0x00000000, source:raw]
    // GUARD: Proceed with the teardown only when the pointer at this+0x0 is non-null. [field:this:0x00000000, source:raw]
    // GUARD: Free the secondary pointer only when the payload's dword at obj+0x4 is non-null. [field:obj:0x00000004, source:raw]
    // CALL: Free the secondary data pointer v3[1] via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // CALL: Free the primary data block v3 via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // GUARD: The node buffer is freed only when a2 bit 0 is set. [source:raw]
    // CALL: Free the node buffer itself via FreeWrapper_7bcf when a2 bit 0 is set. [callee:0x00587BCF, source:raw]
    // RETURN: Return the node pointer this unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   void LinkedListNodeDestructor_a900(void **node, char flags) {
    //     if (((_BYTE *)node)[12]) {
    //       void *payload = *node;
    //       if (payload) {
    //         if (((void **)payload)[1]) FreeWrapper_7bcf(((void **)payload)[1]);
    //         FreeWrapper_7bcf(payload);
    //       }
    //     }
    //     if (flags & 1) FreeWrapper_7bcf(node);
    //   }
    // UNRESOLVED: Owner class and the concrete layout of the payload block (primary and secondary pointers) are unknown.
    // UNRESOLVED: Whether obj+0x4 belongs to the same object as this is not proven; only an equal-offset reading is used.
    // UNRESOLVED: Semantics of the flag at this+0xC beyond enabling the data teardown are unknown.
}
