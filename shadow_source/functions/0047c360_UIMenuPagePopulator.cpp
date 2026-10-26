// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047C360
// Canonical corpus name: sub_47C360
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47C360_0047c360.c

void UnknownObject::UIMenuPagePopulator()
{
    // Rebuilds one page of a UI menu list. Frees the previous linked-list of list nodes stored at this+0x44..0x50, notifies state cleanup, stores the page-direction argument a2 (0 = previous page, 1 = next page) at this+0x174, then if the race-standings list (from global dword_7D2DB0) exists, iterates over its entries plus one to build menu item name strings in a stack buffer and create UI menu items for names not already present. Finally installs the red-outline and black-outline title strings and configures the list management handler for the page direction. Returns the last title-setter result, or the string-copy status when no standings list exists.
    // LOOP: Traverse the linked list whose head is this[17] (this+0x44): for each node read the flag byte at node+8 and the next pointer at node+4; if the flag is set and the node payload *node is non-null call ConditionalFreeWithBit0Flag(payload, 1), then free the node itself with FreeWrapper_7bcf. Continues until the next pointer is null. [field:this:0x00000044, field:*(this+0x48):0x00000004, callee:0x00404F70, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear the four list/counter fields this[17], this[18], this[19], this[20] (offsets 0x44, 0x48, 0x4C, 0x50) to 0 after freeing the chain. [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, source:raw]
    // ASSIGNMENT: Initialize the 253-byte stack buffer v40: copy the first byte of byte_5EA438 and zero-fill the remainder, then zero the trailing 2-byte and 1-byte terminators. [global:0x005EA438, source:raw]
    // CALL: Call StateCleanupNotification(this) before rebuilding the page state. [callee:0x00489CB0, source:raw]
    // ASSIGNMENT: Store the page-direction argument: this[93] (this+0x174) = a2, where a2 is 0 for previous page and 1 for next page. [field:this:0x00000174, source:raw]
    // CALL: v6 = LinkedListDereference(&dword_7D2DB0): dereference the standings-list global as a linked list. [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // GUARD: Select the scene-name source by direction: when a2 is nonzero (==1) use this[42] (this+0xA8) as the next-page scene name, when a2==0 use this[40] (this+0xA0) as the previous-page scene name; a null or empty string falls back to byte_5EA438. [field:this:0x000000A8, field:this:0x000000A0, global:0x005EA438, source:raw]
    // CALL: Call StringCopyWithBufferRealloc on the selected scene name (this[42] or this[40], defaulting to byte_5EA438) when it is non-empty; its return becomes the early result. [callee:0x00566650, source:raw]
    // GUARD: If the standings list v6 is null, skip page construction and return the earlier string-copy result. [source:raw]
    // CALL: v13 = ActiveEntityCounter(v6); page entry count v14 = v33 = v13 + 1. [callee:0x004C1370, source:raw]
    // CALL: Write the page scene name with SceneNameLookupBySeason(v37, 32) into the 32-byte buffer, and obtain the first-entry base with FixedOffsetReturn(v6). [callee:0x004C0A20, callee:0x004C1390, source:raw]
    // LOOP: Iterate over the v14 page entries: for counter v15 get entry base v16 via ShortComputation_13a0(v15 - 1) when v15 is nonzero, otherwise via FixedOffsetReturn(v6); v17 = v16. [callee:0x004C13A0, callee:0x004C1390, source:raw]
    // CALL: Format the entry position number: StringFormatWithBufferOverflowCheck(&v25, "%d", *(v16 + 408)) using the percent-d format-string global, get v18 = sub_4C13C0(v34), and format StringFormatWithBufferOverflowCheck(&v29, "%d", v18). [callee:0x0058815F, callee:0x004C13C0, global:0x005C3280, source:raw]
    // CALL: Write the per-entry scene name with SceneNameLookupBySeason(v34, 32) into the 32-byte buffer. [callee:0x004C0A20, source:raw]
    // ASSIGNMENT: Assemble the menu item name in v40: for next page (a2==1) take the entry name from *v17 (default byte_5EA438), StringFormatWithBufferOverflowCheck(v40, "%s", name) with the percent-s format-string global, StrlenOverwrite, append the scene name v34, StrlenOverwrite, then append the position buffer; for previous page (a2==0) copy v34 into v40, StrlenOverwrite, and append the v29 number buffer. [callee:0x0058815F, callee:0x004894D0, global:0x005C2C18, global:0x005EA438, source:raw]
    // GUARD: If UIListSearchByName(v40, 0) returns 0 (name not already present), create the menu item with UIMenuItemCreator(v40, 0, 0, 0, 0). [callee:0x00489A50, callee:0x00489600, source:raw]
    // CALL: Install the red-outline title with UIItemNameSetter(0, aFtim14redoutli). [callee:0x00489C10, global:0x005C6A28, source:raw]
    // GUARD: Configure the list management handler for the page direction: UIListManagementHandler(1, 2) when a2==1 (next page), UIListManagementHandler(1, 1) when a2==0 (previous page). [callee:0x0048A3C0, source:raw]
    // RETURN: Install the black-outline title with UIItemNameSetter(0, aFtim14blkoutli) and return its result as the function return value. [callee:0x00489C10, global:0x005C7118, function:0x0047C360, source:raw]
    // RETURN: Fallthrough return of the string-copy result when the standings list v6 is null. [function:0x0047C360, source:raw]

    // Conservative worker pseudocode:
    //   freeListNodes(this->listHead17);
    //   this->listHead17 = this->field18 = this->field19 = this->field20 = 0;
    //   initBuffer(v40, byte_5EA438);
    //   StateCleanupNotification(this);
    //   this->pageDirection174 = a2;
    //   list = LinkedListDereference(&dword_7D2DB0);
    //   scene = (a2 ? this->sceneNextA8 : this->scenePrevA0) || byte_5EA438;
    //   if (strlen(scene)) result = StringCopyWithBufferRealloc(scene);
    //   if (!list) return result;
    //   count = ActiveEntityCounter(list) + 1;
    //   SceneNameLookupBySeason(pageScene, 32);
    //   for (i = 0; i < count; i++) {
    //       entry = i ? ShortComputation_13a0(i - 1) : FixedOffsetReturn(list);
    //       fmtNumber(posBuf, *(entry + 408));
    //       SceneNameLookupBySeason(entryScene, 32);
    //       n = sub_4C13C0(entryScene);
    //       fmtNumber(nBuf, n);
    //       if (a2 == 1) { name = *entry || byte_5EA438; buildName(v40, name, entryScene, posBuf); }
    //       else buildName(v40, entryScene, nBuf);
    //       if (!UIListSearchByName(v40, 0)) UIMenuItemCreator(v40, 0, 0, 0, 0);
    //   }
    //   UIItemNameSetter(0, aFtim14redoutli);
    //   UIListManagementHandler(1, a2 == 1 ? 2 : 1);
    //   return UIItemNameSetter(0, aFtim14blkoutli);
    // UNRESOLVED: The pairing of the format-string globals aS_4 (0x005C2C18, "%s") and aD_1 (0x005C3280, "%d") with the calls is inferred from IDA naming conventions; the packet does not directly pin which global is the percent-s versus percent-d literal.
    // UNRESOLVED: The linked-list node at this+0x44 stores (payload at offset 0, next pointer at offset 4, flag byte at offset 8); the owner object and the payload type are not identified by the packet.
    // UNRESOLVED: The meaning of the field at entry base + 408 (formatted with "%d" as the position number) and the result of sub_4C13C0 are not established.
    // UNRESOLVED: The page entry count is ActiveEntityCounter(v6) + 1; why one extra entry is produced (e.g. a title row or sentinel) is unknown.
    // UNRESOLVED: The exact meaning of the two UIItemNameSetter title strings (red outline 0x005C6A28, black outline 0x005C7118) and of byte_5EA438 as the empty-name fallback is not confirmed beyond the raw source.
    // UNRESOLVED: The UIListManagementHandler arguments (1, 1) versus (1, 2) are taken literally from raw source; the enum semantics are unknown.
}
