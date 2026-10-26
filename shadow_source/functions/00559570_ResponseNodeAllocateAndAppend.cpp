// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00559570
// Canonical corpus name: sub_559570
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_559570_00559570.c

void UnknownObject::ResponseNodeAllocateAndAppend()
{
    // Allocates a new 32-byte response node and appends it to a singly-linked list rooted at this+0x4. First rejects duplicates: if BinaryTreeSearch finds the name already present, it formats 'Response %s already exists' through StringFormatWithBufferOverflowCheck and returns -1. Otherwise it walks the list to the tail using the +0x1C next-pointer field, allocates 32 bytes via OperatorNewNhMallocWrapper, zero-initializes the node via SmallStructInitWithParentCall, links it (as new head if the list was empty, otherwise as the old tail's next), fills the node via StringCopyFieldInit, and returns 0.
    // GUARD: Duplicate guard: if BinaryTreeSearch(a2) returns non-zero, the response name already exists. [callee:0x005597C0]
    // CALL: On duplicate, format the 'Response %s already exists' error string (global 0x005DC1BC) into the local 256-byte stack buffer v11 via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x005DC1BC]
    // RETURN: Return -1 when the response name is already present. [source:raw, function:0x00559570]
    // GUARD: Branch on the response list head pointer stored at this+0x4 (this[1]): if it is non-null the new node is appended to the existing tail; if it is null the new node becomes the list head. [field:this:0x00000004]
    // LOOP: Walk the singly-linked list from the head, following the +0x1C next-pointer field of each node, until the last node is reached. The packet names the tail chain through the container pointer at this+0x20 (field *(*(this+0x20)+0x1C)). [field:this:0x00000020, field:*(*(this+0x20)+0x1C):0x0000001C]
    // CALL: Allocate 32 bytes for the new node via OperatorNewNhMallocWrapper. [callee:0x00587C03]
    // CALL: Zero-initialize the freshly allocated 32-byte node via SmallStructInitWithParentCall. [callee:0x00559330]
    // ASSIGNMENT: Link the node into the list: if the list was empty, store the new node at this+0x4 (this[1] was previously 0); otherwise store it into the old tail node's next-pointer at +0x1C. On allocation failure the tail next is set to 0 and this+0x4 is left at 0. [field:this:0x00000004, field:*(*(this+0x20)+0x1C):0x0000001C]
    // CALL: Copy the response name (a2) and the two integer arguments (a3, a4) into the initialized node via StringCopyFieldInit. [callee:0x00559350]
    // RETURN: Return 0 on successful insertion. [function:0x00559570, source:raw]

    // Conservative worker pseudocode:
    //   int ResponseNodeAllocateAndAppend(this, name, a3, a4) {
    //     char err[256];
    //     if (BinaryTreeSearch(name)) {
    //       StringFormatWithBufferOverflowCheck(err, "Response %s already exists", name);
    //       return -1;
    //     }
    //     node* tail = this->head;
    //     if (tail) {
    //       while (tail->next) tail = tail->next;
    //       node* n = OperatorNewNhMallocWrapper(32);
    //       tail->next = n ? SmallStructInitWithParentCall(n) : 0;
    //     } else {
    //       node* n = OperatorNewNhMallocWrapper(32);
    //       if (n) {
    //         this->head = SmallStructInitWithParentCall(n);
    //       } else {
    //         this->head = 0;
    //       }
    //     }
    //     StringCopyFieldInit(node, name, a3, a4);
    //     return 0;
    //   }
    // UNRESOLVED: The raw source traverses the list from this+0x4 (this[1]), while the packet names the tail chain via the container pointer at this+0x20; the relationship between these two fields is not deterministically established.
    // UNRESOLVED: The meaning of the integer arguments a3 and a4 consumed by StringCopyFieldInit is unknown; they are likely extra per-response fields but no deterministic naming exists.
    // UNRESOLVED: The exact struct layout of the 32-byte response node beyond the +0x1C next-pointer field is unknown.
    // UNRESOLVED: Owner class is UnknownObject with no static caller evidence; the caller graph shows no direct callers for this address.
}
