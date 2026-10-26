// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499CE0
// Canonical corpus name: DestructorWithMultipleConditionalFrees
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithMultipleConditionalFrees_00499ce0.c

void UnknownObject::DestructorWithMultipleConditionalFrees()
{
    // Object destructor: installs the off_5ACAAC vtable pointer at this+0x0, recursively destroys a child tree node, frees a linked list at this+27 (dword index, offset 0x6C), then conditionally frees each non-NULL pointer field from offset 0x58 down to 0x10 via FreeWrapper_7bcf.
    // ASSIGNMENT: Set the vtable pointer at this+0x0 to off_5ACAAC. [field:this:0x00000000, global:0x005ACAAC, source:raw]
    // CALL: TreeNodeRecursiveDestructor(0) recursively destroys the child tree node structure (root argument 0). [callee:0x00499DA0, source:raw]
    // CALL: LinkedListFree(this+27) frees the linked list stored at this+27 (dword index, byte offset 0x6C). [callee:0x0049AF30, source:raw]
    // GUARD: Each pointer field from this+0x58 down to this+0x10 (step 0x8) is freed only when non-NULL. [field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, field:this:0x00000030, field:this:0x00000038, field:this:0x00000040, field:this:0x00000048, field:this:0x00000050, field:this:0x00000058, source:raw]
    // CALL: FreeWrapper_7bcf releases every non-NULL pointer field at this+0x58, +0x50, +0x48, +0x40, +0x38, +0x30, +0x28, +0x20, +0x18 and +0x10. [callee:0x00587BCF, source:raw]
    // RETURN: Return the result of the last conditional free (this[6] freed value, or 0). [source:raw]
    // CALL: Invoked by DestructorWithConditionalFree_9cc0 (0x00499CC0) as part of the teardown path. [caller:0x00499CC0, source:raw]

    // Conservative worker pseudocode:
    //   void DestructorWithMultipleConditionalFrees(void* this) {
    //     *(void**)this = &off_5ACAAC;
    //     TreeNodeRecursiveDestructor(0);
    //     LinkedListFree(this + 27);
    //     if (this[22]) FreeWrapper_7bcf(this[22]);
    //     if (this[20]) FreeWrapper_7bcf(this[20]);
    //     if (this[18]) FreeWrapper_7bcf(this[18]);
    //     if (this[16]) FreeWrapper_7bcf(this[16]);
    //     if (this[14]) FreeWrapper_7bcf(this[14]);
    //     if (this[12]) FreeWrapper_7bcf(this[12]);
    //     if (this[10]) FreeWrapper_7bcf(this[10]);
    //     if (this[8]) FreeWrapper_7bcf(this[8]);
    //     if (this[6]) FreeWrapper_7bcf(this[6]);
    //     if (this[4]) FreeWrapper_7bcf(this[4]);
    //   }
    // UNRESOLVED: The owning class is unknown (UnknownObject/UNKNOWN).
    // UNRESOLVED: The payloads behind each freed pointer field (this+0x10 through this+0x58) are not established.
    // UNRESOLVED: Whether the tree node and linked-list ranges overlap the conditionally freed pointer fields is not established.
}
