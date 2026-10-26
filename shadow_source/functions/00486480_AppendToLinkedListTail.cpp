// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486480
// Canonical corpus name: AppendToLinkedListTail
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AppendToLinkedListTail_00486480.c

void UnknownObject::AppendToLinkedListTail()
{
    // Appends node a2 to the tail of a singly-linked list whose head lives at this+0xCC (this[51]). Walks the list via node next-pointer at node+0x18 until the tail, links a2 as the new tail, or sets the head directly when the list is empty. Called from sub_493480.
    // ASSIGNMENT: Load the list head pointer from this[51] (this+0xCC) into the walk variable v2. [field:this:0x000000CC]
    // GUARD: If the head pointer v2 is non-null (list non-empty), proceed to walk to the tail; otherwise fall through to the empty-list branch. [field:this:0x000000CC]
    // LOOP: Walk the list from the head, reading each node's next-pointer at node+0x18 until a null next pointer is found; packet maps the tail-node next access through indirect base this+0xE4. [field:*(*(this+0xE4)+0x18):0x00000018, field:this:0x000000E4]
    // ASSIGNMENT: Set the current tail node's next-pointer (node+0x18) to the new node a2. [field:*(*(this+0xE4)+0x18):0x00000018]
    // ASSIGNMENT: Empty-list branch: set this[51] (this+0xCC) directly to the new node a2. [field:this:0x000000CC]
    // RETURN: Return void after either linking at the tail or setting the head. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_486480(DWORD *this, int a2) {
    //       int head = this[51];  /* list head at this+0xCC * /
    //       if (head) {
    //           int cur = head;
    //           while (cur) cur = *(int *)(cur + 0x18);
    //           /* cur is the last non-null node; link new tail * /
    //           *(int *)((tail base) + 0x18) = a2;
    //       } else {
    //           this[51] = a2;
    //       }
    //   }
    // UNRESOLVED: The list walk reads node next-pointers at node+0x18, but the packet's field base notation *(*(this+0xE4)+0x18) does not match the raw source's register-based traversal; exact tail-node base is unproven.
    // UNRESOLVED: Node element type and list semantics are not identified.
}
