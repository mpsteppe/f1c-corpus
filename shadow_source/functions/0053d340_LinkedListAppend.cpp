// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D340
// Canonical corpus name: LinkedListAppend_d340
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListAppend_d340_0053d340.c

void UnknownObject::LinkedListAppend()
{
    // Appends node a1 to the global registry doubly-linked list whose head is dword_8B8E20 (008B8E20). Prev/next node links live at node+0x86C and node+0x870. When the list is empty the new node becomes the head with both links cleared; otherwise it walks the next-pointer chain to the tail, links the tail's next (+0x870) to the new node and sets the new node's prev (+0x86C) to the old tail. Returns the new tail (or the new head when the list was empty). Called by sub_53CFE0 (0053CFE0) and SceneFileTopLevelParser (0055B200).
    // GUARD: Branches on the list head global dword_8B8E20 being non-null: non-empty list takes the walk-to-tail path, empty list takes the become-head path [global:0x008B8E20, source:raw]
    // LOOP: Walks the next-pointer chain (node+0x870) starting from the head dword_8B8E20 until it reaches the tail whose next is zero [field:this:0x00000870, global:0x008B8E20, source:raw]
    // ASSIGNMENT: Links the old tail's next pointer (+0x870) to the new node a1 [field:this:0x00000870, source:raw]
    // ASSIGNMENT: Seals the new node as tail: prev (+0x86C) set to the old tail and next (+0x870) cleared to 0 [field:this:0x0000086C, field:this:0x00000870, source:raw]
    // ASSIGNMENT: Empty-list path: stores the new node as the head global dword_8B8E20 and clears both of its links (+0x86C and +0x870) [global:0x008B8E20, field:this:0x0000086C, field:this:0x00000870, source:raw]
    // RETURN: Returns the appended tail node, or the new head when the list was previously empty [source:raw]
    // CALL: Invoked by sub_53CFE0 (0053CFE0) and SceneFileTopLevelParser (0055B200) to register parsed entries into the global list [caller:0x0053CFE0, caller:0x0055B200, source:raw]

    // Conservative worker pseudocode:
    //   head = dword_8B8E20;
    //   if (head != NULL) {
    //     tail = head;
    //     while (tail[0x870/4] != NULL)
    //       tail = tail[0x870/4];
    //     tail[0x870/4] = a1;
    //     a1[0x86C/4] = tail;
    //     a1[0x870/4] = NULL;
    //     return tail;
    //   } else {
    //     dword_8B8E20 = a1;
    //     a1[0x86C/4] = NULL;
    //     a1[0x870/4] = NULL;
    //     return a1;
    //   }
    // UNRESOLVED: The node element layout beyond the prev/next links at +0x86C/+0x870 is undefined by this packet; stride and payload shape are unknown
    // UNRESOLVED: The semantic role of dword_8B8E20 (labeled EntryRegistryHead in prior analysis) is DERIVED only and is not confirmed by this packet alone
}
