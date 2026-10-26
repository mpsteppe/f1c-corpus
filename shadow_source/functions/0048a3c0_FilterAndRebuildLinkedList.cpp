// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048A3C0
// Canonical corpus name: UIListManagementHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIListManagementHandler_0048a3c0.c

void UnknownObject::FilterAndRebuildLinkedList()
{
    // Filters a linked list of text items by comparing each item's text against a default reference string stored at byte_5EA438. Filter mode a2 selects the comparison (length shorter than, length longer than, lexicographically less, lexicographically greater). Builds a new linked list of the matching nodes via UtilityFunction_6400, appending through the next pointer at +140. Tracks the new index of the previously selected item. When the original list head this[36] was null, installs the new list as head, restores the original count, and selects the tracked item with UIListSelectionHandler.
    // ASSIGNMENT: Save selection index this[90] and item count this[37] into locals; initialize new-list head v25 to 0 and selection tracker v26 to -1. [source:raw, field:this:0x00000168, field:this:0x00000094]
    // GUARD: Guard on saved count this[37] > 0 before entering the outer rebuild loop; a zero count leaves the new list empty. [source:raw, field:this:0x00000094]
    // LOOP: Outer loop runs while the item count is positive; each pass rebuilds the filtered list and decrements the count, resetting the inner index. [source:raw]
    // CALL: ShortComputation_63c0(this, 0) fetches the first list node pointer and selection index this[90] is set to 0. [callee:0x004863C0, field:this:0x00000168]
    // CALL: Obtain reference text: UITextFormatHelper(this, a3) when a3 >= 0, otherwise UIScreenTextAccessor(this); the text is copied with StringCopyWithBufferRealloc. [callee:0x00489970, callee:0x00489920, callee:0x00566650]
    // LOOP: Inner loop walks every list item; each iteration fetches the node at the current index with ShortComputation_63c0(this, v6) and sets selection index this[90] = v6. [callee:0x004863C0, field:this:0x00000168]
    // GUARD: When the item's text string is non-null, dispatch on filter mode a2 through the switch on jump table jpt_48A496. [global:0x0048A634, source:raw]
    // CALCULATION: Modes 0 and 1 compare text length via sub_587ECE of the item text against byte_5EA438; modes 2 and 3 compare lexicographically with sub_588410(v10, byte_5EA438). [callee:0x00587ECE, callee:0x00588410, global:0x005EA438]
    // ASSIGNMENT: On a matching item, remember the node and copy its text with StringCopyWithBufferRealloc; increment the running match counter v22. [callee:0x00566650, source:raw]
    // CALL: UtilityFunction_6400(this, v21) allocates or copies a new list node for the matched item. [callee:0x00486400]
    // LOOP: Walk the rebuilt list through its next pointer at +140 to append the new node at the tail, or install it as head v25 when the list was empty; j tracks the insertion index. [source:raw]
    // ASSIGNMENT: When the matched index equals the previous selection index, record the new position in v26; decrement this[90] after each rebuild pass. [field:this:0x00000168, source:raw]
    // GUARD: After the rebuild, if head this[36] is still null, install v25 as the new head and restore this[37] to the original count. [field:this:0x00000090, field:this:0x00000094]
    // CALL: UIListSelectionHandler(this, v26, 0) selects the tracked item (or first) in the rebuilt list. [callee:0x00489AB0]
    // RETURN: Return the UIListSelectionHandler result when the head was replaced, otherwise 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_48A3C0(int *this, int mode, int fmtArg) {
    //     int oldSel = this[90], count = this[37];
    //     int head = 0, selIdx = -1;
    //     if (count > 0) {
    //       do {
    //         int node = ShortComputation_63c0(this, 0);
    //         this[90] = 0;
    //         char *ref = fmtArg >= 0 ? UITextFormatHelper(this, fmtArg) : UIScreenTextAccessor(this);
    //         StringCopyWithBufferRealloc(ref);
    //         int matchCount = 0;
    //         for (int i = 0; i < count; i++) {
    //           int item = ShortComputation_63c0(this, i);
    //           this[90] = i;
    //           char *text = fmtArg >= 0 ? UITextFormatHelper(this, fmtArg) : UIScreenTextAccessor(this);
    //           if (text && matches(text, byte_5EA438, mode)) {
    //             node = item;
    //             StringCopyWithBufferRealloc(text);
    //             matchCount++;
    //           }
    //         }
    //         int j = 0;
    //         int made = UtilityFunction_6400(this, node);
    //         if (made) { head ? append(head, made) : (head = made); }
    //         if (matchCount == oldSel) selIdx = j;
    //         --this[90];
    //         count = this[37];
    //       } while (count > 0);
    //     }
    //     if (!this[36]) {
    //       this[36] = head;
    //       this[37] = count;
    //       return UIListSelectionHandler(this, selIdx, 0);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: FreeWrapper_7bcf appears in the callee list but no call to it is visible in the raw source; its role here is unknown.
    // UNRESOLVED: byte_5EA438 is treated as a default reference string, but its exact construction and ownership are not proven by this packet.
}
