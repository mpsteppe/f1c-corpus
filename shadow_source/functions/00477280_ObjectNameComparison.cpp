// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00477280
// Canonical corpus name: ObjectNameComparison
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectNameComparison_00477280.c

void UnknownObject::ObjectNameComparison()
{
    // Compares the name strings of this+0x9C (name pointer at +52) and the object a2 (its name object at +156, name pointer at +52). Null name pointers fall back to byte_5EA438. If the names differ, returns the strcmp result. If they match, scans a doubly linked list (head this+0xF0, count this+0xFC) for a node whose first-list-node data at +0x30 equals a2; if found, calls ViewportRectSizeCalc(a2) and returns. Otherwise allocates a new viewport node (52 bytes), constructs it, runs ViewportRectSizeCalc(a2), invokes a vtable method (offset +16) with argument 0, appends the node to the doubly linked list, and returns UIViewportLayoutCalculator(this).
    // ASSIGNMENT: Load the comparison object pointer from this+0x9C (result) and the target object's name-object pointer from a2+156. [field:this:0x0000009C, source:raw]
    // GUARD: If this+0x9C or the a2 name object is null, skip the body and return the null result. [source:raw]
    // ASSIGNMENT: Load the name pointer at +52 of both objects (this+0x9C object and a2+156 object); substitute byte_5EA438 when either is null. [field:this:0x0000009C, global:0x005EA438, source:raw]
    // CALCULATION: Compare the two name strings with strcmp; store the comparison result. [source:raw]
    // GUARD: If the names are not equal, return the strcmp result without touching the list. [source:raw]
    // LOOP: Iterate the doubly linked list i from 0 to this+0xFC (list count): walk nodes via the next pointer (v10[1]) starting from the head this+0xF0, comparing each first node's data pointer (+0x30) against a2. [field:this:0x000000FC, field:this:0x000000F0, field:*(this+0xF0):0x00000030, source:raw]
    // GUARD: If a list node's data pointer at +0x30 equals a2, call ViewportRectSizeCalc(a2) and return its result. [callee:0x0048FDB0, field:*(this+0xF0):0x00000030, source:raw]
    // CALL: Allocate 52 bytes with OperatorNewNhMallocWrapper for the new viewport node. [callee:0x00587C03, source:raw]
    // CALL: Construct the node via Constructor_fd60 when allocation succeeded; otherwise the node pointer is 0. [callee:0x0048FD60, source:raw]
    // CALL: Run ViewportRectSizeCalc(a2) on the new node. [callee:0x0048FDB0, source:raw]
    // CALL: Invoke a virtual method through the constructed node's vtable at offset +16 with argument 0. [source:raw]
    // CALL: Append the constructed node to the doubly linked list with DoublyLinkedListAppend_f5d0(node, 1). [callee:0x0048F5D0, source:raw]
    // RETURN: Return UIViewportLayoutCalculator(this) to recalculate the viewport layout after the list change. [callee:0x0048F640, function:0x00477280, source:raw]

    // Conservative worker pseudocode:
    //   int result = this->obj;
    //   int other = *(int*)(a2 + 156);
    //   if (result && other) {
    //       const char* n1 = *(const char**)(result + 52); if (!n1) n1 = byte_5EA438;
    //       const char* n2 = *(const char**)(other + 52); if (!n2) n2 = byte_5EA438;
    //       result = strcmp(n2, n1);
    //       if (result == 0) {
    //           for (i = 0; i < this->count; i++) {
    //               int* node = this->head;
    //               for (j = i; node; j--) {
    //                   if (j <= 0) {
    //                       if (node && *node && *(int*)(*node + 48) == a2) return ViewportRectSizeCalc(a2);
    //                       break;
    //                   }
    //                   node = (int*)node[1];
    //               }
    //           }
    //           void* mem = OperatorNewNhMallocWrapper(52);
    //           node = mem ? Constructor_fd60(mem) : 0;
    //           ViewportRectSizeCalc(a2);
    //           (*(vtable_of(node) + 16))(node, 0);
    //           DoublyLinkedListAppend_f5d0(node, 1);
    //           return UIViewportLayoutCalculator(this);
    //       }
    //   }
    //   return result;
    // UNRESOLVED: The fields this+0xD0 and this+0xF8 are referenced by the packet but do not appear directly in the decompiled body; their roles in the name-compare/list flow are unknown.
    // UNRESOLVED: The concrete type of a2's +156 name-object and of the +52 name pointer fields is not evidenced by this packet.
    // UNRESOLVED: The list search indexes a node by walking it i times rather than iterating distinct nodes, which is consistent with a per-index pointer chase but unconfirmed.
}
