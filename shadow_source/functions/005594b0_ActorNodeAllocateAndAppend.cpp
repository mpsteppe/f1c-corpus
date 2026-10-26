// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005594B0
// Canonical corpus name: sub_5594B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5594B0_005594b0.c

void UnknownObject::ActorNodeAllocateAndAppend()
{
    // Allocates a new 32-byte actor node and appends it to a singly-linked list rooted at this+0x0. First rejects duplicates: if UTF16StringSearchInLinkedList finds the name already present, it formats 'Actor %s already exists' through StringFormatWithBufferOverflowCheck and returns -1. Otherwise it walks the list to the tail using the +0x1C next-pointer field, allocates 32 bytes via OperatorNewNhMallocWrapper, zero-initializes the node via SmallStructInitWithParentCall, links it (as new head if the list was empty, otherwise as the old tail's next), fills the node via StringCopyFieldInit, and returns 0.
    // GUARD: Duplicate guard: if UTF16StringSearchInLinkedList(a2) returns non-zero, the actor name already exists in the list. [callee:0x00559760]
    // CALL: On duplicate, format the 'Actor %s already exists' error string (global 0x005DC1A4) into the local 256-byte stack buffer v11 via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x005DC1A4]
    // RETURN: Return -1 when the actor name is already present. [source:raw, function:0x005594B0]
    // GUARD: Branch on the list head pointer stored at this+0x0: if it is non-null the new node is appended to the existing tail; if it is null the new node becomes the list head. [field:this:0x00000000]
    // LOOP: Walk the singly-linked list from the head, following the +0x1C next-pointer field of each node (obj+0x1C), until the last node is reached. [field:obj:0x0000001C]
    // CALL: Allocate 32 bytes for the new node via OperatorNewNhMallocWrapper. [callee:0x00587C03]
    // CALL: Zero-initialize the freshly allocated 32-byte node via SmallStructInitWithParentCall. [callee:0x00559330]
    // ASSIGNMENT: Link the node into the list: if the list was empty, store the new node at this+0x0 (this was previously 0); otherwise store it into the old tail node's next-pointer at +0x1C, i.e. *(*(obj+0x1C)+0x1C) = new node. On allocation failure the tail next is set to 0 and this+0x0 is left at 0. [field:this:0x00000000, field:*(*(obj+0x1C)+0x1C):0x0000001C]
    // CALL: Copy the actor name (a2) and the two integer arguments (a3, a4) into the initialized node via StringCopyFieldInit. [callee:0x00559350]
    // RETURN: Return 0 on successful insertion. [function:0x005594B0, source:raw]

    // Conservative worker pseudocode:
    //   int ActorNodeAllocateAndAppend(this, name, a3, a4) {
    //     char err[256];
    //     if (UTF16StringSearchInLinkedList(name)) {
    //       StringFormatWithBufferOverflowCheck(err, "Actor %s already exists", name);
    //       return -1;
    //     }
    //     node* tail = *this;
    //     if (tail) {
    //       while (tail->next) tail = tail->next;
    //       node* n = OperatorNewNhMallocWrapper(32);
    //       tail->next = n ? SmallStructInitWithParentCall(n) : 0;
    //     } else {
    //       node* n = OperatorNewNhMallocWrapper(32);
    //       if (n) {
    //         *this = SmallStructInitWithParentCall(n);
    //       } else {
    //         *this = 0;
    //       }
    //     }
    //     StringCopyFieldInit(node, name, a3, a4);
    //     return 0;
    //   }
    // UNRESOLVED: The meaning of the integer arguments a3 and a4 consumed by StringCopyFieldInit is unknown; they are likely extra per-actor fields but no deterministic naming exists.
    // UNRESOLVED: The exact struct layout of the 32-byte actor node beyond the +0x1C next-pointer field is unknown.
    // UNRESOLVED: Owner class is UnknownObject with no static caller evidence; the caller graph shows no direct callers for this address.
}
