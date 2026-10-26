// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9DA0
// Canonical corpus name: MenuActionDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MenuActionDispatch_004b9da0.c

void UnknownObject::MenuActionDispatch()
{
    // Menu UI action dispatcher. Switches on an integer action id a2. For ids 0-8 the id is stored into the menu state action slot (this->data + 0xF8C). For ids 9-13 it delegates to sorted-list / sprite-overlay / linked-list helper routines on the same menu data block. Every path returns 1.
    // GUARD: Switch dispatch on action id a2 across cases 0-13 with a default path, via the jump table jpt_4B9DB0. [global:0x004B9E04, source:raw]
    // ASSIGNMENT: Cases 0-8: store action id a2 into menu state action slot at (this->data + 0xF8C). [field:obj:0x00000F8C, source:raw]
    // CALL: Case 9: insert a zero-valued node into the sorted list rooted at *this via SortedLinkedListInsert. [callee:0x004B81A0, field:this:0x00000000, source:raw]
    // CALL: Case 10: clean up the sprite overlay display list via SpriteOverlayDisplayListCleanup. [callee:0x004B8360, source:raw]
    // CALL: Case 11: destroy the linked list via LinkedListDestructor_8480. [callee:0x004B8480, source:raw]
    // CALL: Case 12: seek the sorted list by value via SortedListSeekByValue. [callee:0x004B84F0, source:raw]
    // CALL: Case 13: search the list by float threshold via LinkedListPrioritySearchByFloatThreshold, then falls through to the common return. [callee:0x004B85D0, source:raw]
    // RETURN: Return constant 1 on every path, including the default case. [source:raw]

    // Conservative worker pseudocode:
    //   char MenuActionDispatch(int *this, int action_id) {
    //     switch (action_id) {
    //     case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
    //       *(int *)(*this + 3980) = action_id;
    //       break;
    //     case 9:  SortedLinkedListInsert((int *)*this, 0); break;
    //     case 10: SpriteOverlayDisplayListCleanup(*this); break;
    //     case 11: LinkedListDestructor_8480(*this); break;
    //     case 12: SortedListSeekByValue(*this); break;
    //     case 13: LinkedListPrioritySearchByFloatThreshold(*this); break;
    //     default: break;
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: Meaning of action ids 0-13 and the semantics of the stored slot 0xF8C are not established.
    // UNRESOLVED: byte_4B9E1C is adjacent padding or unrelated data; its role is unknown.
}
