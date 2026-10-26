// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048F5D0
// Canonical corpus name: DoublyLinkedListAppend_f5d0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListAppend_f5d0_0048f5d0.c

void UnknownObject::DoublyLinkedListAppend()
{
    // Appends a new 16-byte node containing a data pointer and a byte flag to a doubly linked list managed by `this`. Allocates the node via OperatorNewNhMallocWrapper(16); on allocation failure the node is treated as null and only the list tail pointer is moved. When the list is empty the new node becomes both head and cursor; otherwise the old tail's next pointer and the new node's prev pointer are linked. The tail pointer always becomes the new node and the element count is incremented. Nothing is appended when a2 (data pointer) is null.
    // GUARD: Guard on a2 != 0; when the data pointer is null the whole append is skipped and the function returns immediately. [source:raw]
    // CALL: Call OperatorNewNhMallocWrapper(16) to allocate a 16-byte list node; result stored in v4. [callee:0x00587C03]
    // GUARD: Guard on allocation result; when v4 is null it is forced to 0 and the node is treated as absent. [source:raw]
    // ASSIGNMENT: Initialize the allocated node: node+0 = a2 (data pointer), node+4 = 0 (next), node+8 = 0 (prev), node+12 = a3 (byte flag). [source:raw]
    // GUARD: Guard on this+0xF0 (list head) being non-null, i.e. the list is non-empty. [field:this:0x000000F0]
    // ASSIGNMENT: Non-empty list: write old tail's next (this+0xF4 value, +4) = new node, and new node's prev (node+8) = old tail (this+0xF4). [field:this:0x000000F4, source:raw]
    // ASSIGNMENT: Empty list: set this+0xF0 (head) = new node and this+0xF8 (cursor) = new node. [field:this:0x000000F0, field:this:0x000000F8]
    // ASSIGNMENT: Unconditionally set this+0xF4 (tail) = new node; the new node is always the new list end. [field:this:0x000000F4]
    // CALCULATION: Increment this+0xFC (element count) by one. [field:this:0x000000FC]
    // RETURN: Implicit end of the void function after the append completes. [function:0x0048F5D0, source:raw]

    // Conservative worker pseudocode:
    //   void DoublyLinkedListAppend(void* data, char flag) {
    //     if (data == NULL) return;
    //     Node* node = OperatorNewNhMallocWrapper(16);
    //     if (node == NULL) node = NULL;
    //     if (this->head != NULL) {
    //       this->tail->next = node;
    //       node->prev = this->tail;
    //     } else {
    //       this->head = node;
    //       this->cursor = node;
    //     }
    //     this->tail = node;
    //     this->count++;
    //   }
    // UNRESOLVED: Node member semantics (data at +0, next at +4, prev at +8, byte flag at +12) are DERIVED from the raw source; the allocated node is not part of the packet's typed field list.
    // UNRESOLVED: Packet field entry lists this+0xFC as read-only (R) yet the decompiled body increments it (++this[63]); the R/W classification is inconsistent with the observed write.
    // UNRESOLVED: Class owning the four list fields at +0xF0..+0xFC is unknown; only caller names (ObjectNameComparison, GameFilterSetup, ProfileBitmapBrowser) and the ABI label are available.
}
