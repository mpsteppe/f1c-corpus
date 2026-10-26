// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486500
// Canonical corpus name: LinkedListTailAppend
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListTailAppend_00486500.c

void UnknownObject::LinkedListTailAppend()
{
    // Appends node a2 to the tail of a singly-linked list whose head lives at this+0xD4 (this[53]). Walks the list via node next-pointer at node+0x18 until the tail, links a2 as the new tail, or sets the head directly when the list is empty. Structural mirror of the sibling append helper on a different list head field. Called from sub_493480.
    // ASSIGNMENT: Load the list head pointer from this[53] (this+0xD4) into the walk variable v2. [field:this:0x000000D4]
    // GUARD: If the head pointer v2 is non-null (list non-empty), proceed to walk to the tail; otherwise fall through to the empty-list branch. [field:this:0x000000D4]
    // LOOP: Walk the list from the head, reading each node's next-pointer at node+0x18 until a null next pointer is found; packet maps the tail-node next access through indirect base this+0xEC. [field:*(*(this+0xEC)+0x18):0x00000018, field:this:0x000000EC]
    // ASSIGNMENT: Set the current tail node's next-pointer (node+0x18) to the new node a2. [field:*(*(this+0xEC)+0x18):0x00000018]
    // ASSIGNMENT: Empty-list branch: set this[53] (this+0xD4) directly to the new node a2. [field:this:0x000000D4]
    // RETURN: Return void after either linking at the tail or setting the head. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_486500(DWORD *this, int a2) {
    //       int head = this[53];  /* list head at this+0xD4 * /
    //       if (head) {
    //           int cur = head;
    //           while (cur) cur = *(int *)(cur + 0x18);
    //           /* cur is the last non-null node; link new tail * /
    //           *(int *)((tail base) + 0x18) = a2;
    //       } else {
    //           this[53] = a2;
    //       }
    //   }
    // UNRESOLVED: The list walk reads node next-pointers at node+0x18, but the packet's field base notation *(*(this+0xEC)+0x18) does not match the raw source's register-based traversal; exact tail-node base is unproven.
    // UNRESOLVED: Node element type and list semantics are not identified; relationship to the sibling append helper (different head offset) is unknown.
}
