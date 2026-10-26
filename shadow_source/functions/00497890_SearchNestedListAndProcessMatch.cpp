// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497890
// Canonical corpus name: UtilityFunction_7890
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_7890_00497890.c

void UnknownObject::SearchNestedListAndProcessMatch()
{
    // Searches an outer doubly-linked list (head at this+0x4, current-node cursor at this+0xC) and, for each outer node, walks its inner list via FieldGetter_8e30 (next link at +0x48) looking for an item equal to a2. On a match: optionally calls sub_4977E0 (when the byte flag at this+0x1574 is set), appends the outer node with DoublyLinkedListAppend_5a80, calls the vtable+0x2C virtual method on the outer node with argument 1, calls SetterVirtualCall, and sets the result flag. Wraps the traversal in ListIterationWithVTableDispatch / LinkedListIterationVirtualCall when the guard dword at this+0x18 is non-zero. Returns 1 if any match was processed, else 0.
    // GUARD: If the dword at this+0x18 is non-zero, call ListIterationWithVTableDispatch before beginning the traversal. [field:this:0x00000018, callee:0x00498FB0]
    // ASSIGNMENT: Initialize the result flag v5 to 0, read the outer list head pointer from this+0x4, and store it into the current-node cursor this+0xC. [field:this:0x00000004, field:this:0x0000000C]
    // LOOP: Iterate the outer linked list: the current outer node object v6 is the first field of the current list node (this+0x4 dereferenced); the loop advances while the next node pointer is non-null. [field:*(this+0x4):0x00000000, field:*(*(this+0xC)+0x4):0x00000000, field:*(this+0xC):0x00000004, field:this:0x0000000C]
    // CALL: For the current outer node v6, call FieldGetter_8e30 to obtain the head i of its inner list. [callee:0x00498E30]
    // LOOP: Walk the inner list from i through its +0x48 next-link until null, testing each item. [source:raw]
    // GUARD: When the current inner-list item i equals a2, the item matches. [source:raw]
    // GUARD: On a match, if the byte flag at this+0x1574 is set, call sub_4977E0(this, a2, a3). [field:this:0x00001574, callee:0x004977E0]
    // CALL: On a match, append the current outer node v6 to a list via DoublyLinkedListAppend_5a80(this, v6). [callee:0x00495A80]
    // CALL: On a match, invoke the virtual method at vtable+0x2C of the outer node v6 with argument 1 (vtable pointer is the first dword of v6). [field:*(*(*(this+0x4)+0x0)+0x0):0x0000002C, field:*(*(this+0x4)+0x0):0x00000000]
    // CALL: On a match, call SetterVirtualCall(i) for the matched inner item. [callee:0x00498F40]
    // ASSIGNMENT: On a match, set the result flag v5 to 1. [source:raw]
    // LOOP: Advance the outer traversal: read the next node pointer from the current node at +0x4, store it into this+0xC, and break if either the read pointer chain becomes null; the next outer node object is the first field of that node. [field:*(this+0xC):0x00000004, field:*(*(this+0xC)+0x4):0x00000000, field:this:0x0000000C]
    // GUARD: After the traversal, if the dword at this+0x18 is non-zero, call LinkedListIterationVirtualCall with that value. [field:this:0x00000018, callee:0x00498F80]
    // RETURN: Return the result flag v5 (1 if any inner item matched, else 0). [source:raw]

    // Conservative worker pseudocode:
    //   int SearchNestedListAndProcessMatch(int this, int a2, int a3) {
    //     if (*(int*)(this + 0x18)) ListIterationWithVTableDispatch();
    //     int v5 = 0;
    //     int* cur = *(int**)(this + 0x4);
    //     *(int*)(this + 0xC) = (int)cur;
    //     while (cur) {
    //       int v6 = *cur;
    //       if (!v6) break;
    //       do {
    //         for (int i = FieldGetter_8e30(v6); i; i = *(int*)(i + 0x48)) {
    //           if (i == a2) {
    //             if (*(BYTE*)(this + 0x1574)) sub_4977E0(this, a2, a3);
    //             DoublyLinkedListAppend_5a80(this, v6);
    //             ((void (__thiscall**)(int, int))(*(int*)v6 + 0x2C))(v6, 1);
    //             SetterVirtualCall(i);
    //             v5 = 1;
    //           }
    //         }
    //         int v8 = *(int*)(this + 0xC);
    //         if (!v8) break;
    //         int* v9 = *(int**)(v8 + 0x4);
    //         *(int*)(this + 0xC) = (int)v9;
    //         if (!v9) break;
    //         v6 = *v9;
    //       } while (*v9);
    //     }
    //     int v10 = *(int*)(this + 0x18);
    //     if (v10) LinkedListIterationVirtualCall(v10);
    //     return v5;
    //   }
    // UNRESOLVED: FieldGetter_8e30's exact contract (whether it returns an inner-list head pointer) is assumed from its name and the loop usage; not independently proven.
    // UNRESOLVED: The outer nodes are treated as objects with a vtable at their first dword; the semantics of the vtable+0x2C method and its argument 1 are unknown.
    // UNRESOLVED: The purpose of the byte flag at this+0x1574 gating sub_4977E0, and the meaning of a3 forwarded to it, are unknown.
    // UNRESOLVED: What DoublyLinkedListAppend_5a80 appends v6 into (which target list) is not visible in this function.
    // UNRESOLVED: The guard dword at this+0x18 selects between two list-iteration entry/exit dispatch helpers; the meaning of its non-zero state is unknown.
    // UNRESOLVED: The inner-list +0x48 next-link offset is read but not represented in the packet field table.
}
