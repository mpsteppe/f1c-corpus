// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C5D0
// Canonical corpus name: LinkedListAppend_c5d0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListAppend_c5d0_0053c5d0.c

void UnknownObject::LinkedListAppend()
{
    // Appends node a1 to a global doubly-linked list whose head is dword_8B8F28, using prev/next pointers at node offsets +0x1E4 and +0x1E8. When the head is null the new node becomes the head with both links cleared; otherwise the next-pointer chain is walked to the tail, the old tail's next is linked to a1, and a1's prev/next are set to the old tail and 0. In the non-empty case the function returns the old tail node; in the empty case it returns the node itself.
    // ASSIGNMENT: Read the list head dword_8B8F28 into result before the branch. [global:0x008B8F28, source:raw]
    // GUARD: Branch on the head dword_8B8F28: non-null takes the walk-and-append path, null makes a1 the new head. [global:0x008B8F28, source:raw]
    // LOOP: Walk the next-pointer chain (field +0x1E8) from the head until a node whose next is 0 (the tail) is reached. [field:this:0x000001E8, global:0x008B8F28, source:raw]
    // ASSIGNMENT: Link the old tail's next field (+0x1E8) to the new node a1. [field:this:0x000001E8, source:raw]
    // ASSIGNMENT: Set the new node's prev field (+0x1E4) to the old tail. [field:this:0x000001E4, source:raw]
    // ASSIGNMENT: Terminate the new node's next field (+0x1E8) with 0, making it the new tail. [field:this:0x000001E8, source:raw]
    // ASSIGNMENT: Empty-list path: make a1 the new head dword_8B8F28 and clear both its prev (+0x1E4) and next (+0x1E8) fields. [field:this:0x000001E4, field:this:0x000001E8, global:0x008B8F28, source:raw]
    // RETURN: Return result: the old tail node after an append, or a1 when the list was empty. [function:0x0053C5D0, source:raw]

    // Conservative worker pseudocode:
    //   result = dword_8B8F28;
    //   if (dword_8B8F28) {
    //     for (i = *(int*)(dword_8B8F28 + 0x1E8); i; i = *(int*)(i + 0x1E8)) result = i;
    //     *(int*)(result + 0x1E8) = a1;
    //     *(int*)(a1 + 0x1E4) = result;
    //     *(int*)(a1 + 0x1E8) = 0;
    //   } else {
    //     result = a1; dword_8B8F28 = a1;
    //     *(int*)(a1 + 0x1E4) = 0; *(int*)(a1 + 0x1E8) = 0;
    //   }
    //   return result;
    // UNRESOLVED: The node type behind offsets +0x1E4/+0x1E8 and the owner of list head dword_8B8F28 are caller-defined; the packet shows only the node-structure pattern.
    // UNRESOLVED: The asymmetric return (old tail in the non-empty case, the node itself when the list was empty) is structural; the caller AudioEngineInitialization's use of it is not evidenced.
}
