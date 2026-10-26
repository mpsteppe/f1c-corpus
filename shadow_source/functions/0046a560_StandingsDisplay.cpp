// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046A560
// Canonical corpus name: StandingsDisplay
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StandingsDisplay_0046a560.c

void UnknownObject::StandingsDisplay()
{
    // Career/season standings statistics menu builder (__thiscall on an unknown this object). Prepares local string buffers, notifies the state cleanup path, frees a four-entry linked-list group anchored at this+0x44, re-seeds a list control with nine stat-key strings, then emits nine formatted menu items that pair a UI-list label (UIListIndexedAccessor index 0..8) with a career-scoring value read from the 0x007D2DD4..0x007D2DF8 global block (integer items for indices 0,1,4,5,6,7,8 and one-decimal float items for indices 2,3). Returns the last UIMenuItemCreator result. Called by ShortComputation_0ad0 (0x004A0AD0).
    // ASSIGNMENT: Initialize the local short string buffer: v24 = 0, v25 = 0, v23 = byte_5EA438[0] (first character of the global byte_5EA438 string). [source:raw, global:0x005EA438]
    // CALL: Call sub_4B0B20(v27, 256) to initialize a 256-byte local buffer (v27). [callee:0x004B0B20, source:raw]
    // CALL: Call StateCleanupNotification(this) to notify the surrounding state of a cleanup/rebuild. [callee:0x00489CB0, source:raw]
    // CALL: Call StringCopyWithBufferRealloc(v27) to copy a string into the v27 buffer. [callee:0x00566650, source:raw]
    // CALL: Call StrlenOverwrite(&v23) to write a string (and its length) into the v23 buffer. [callee:0x004894D0, source:raw]
    // LOOP: Traverse the linked list headed at this[17] (this+0x44), reading the next-node pointer at node+4, and free each node via DoublePointerFree then FreeWrapper_7bcf until the next pointer is NULL. [field:this:0x00000044, field:*(this+0x48):0x00000004, callee:0x00434420, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the four list pointers after teardown: this[17]=0 (this+0x44), this[18]=0 (this+0x48), this[19]=0 (this+0x4C), this[20]=0 (this+0x50). [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, source:raw]
    // CALL: Seed the stat list: LinkedListInsertWithNodeAllocation(key, -1) with the nine stat keys in order aExperienceLaps, aStarts, aAvgStartingPos, aAvgFinishPosit, aPolePositions, aPoints, aWins, aLapRecords, aDriversChampii (-1 = empty/default value). [callee:0x00486F30, global:0x005C6900, global:0x005C68F8, global:0x005C68E0, global:0x005C68C8, global:0x005C6888, global:0x005C6880, global:0x005C6878, global:0x005C69A8, global:0x005C6990, source:raw]
    // CALL: Menu item 0: UIListIndexedAccessor(0) label, formatted with the integer format constant aSSI as "label string dword_7D2DD4", then UIMenuItemCreator(text,0,0,0,0). [callee:0x00487010, callee:0x0058815F, callee:0x00489600, global:0x005C6858, global:0x007D2DD4, source:raw]
    // CALL: Menu item 1: UIListIndexedAccessor(1) label formatted as "label string dword_7D2DD8" (integer format aSSI), then UIMenuItemCreator(text,0,0,0,0). [callee:0x00487010, callee:0x0058815F, callee:0x00489600, global:0x005C6858, global:0x007D2DD8, source:raw]
    // CALL: Menu item 2: UIListIndexedAccessor(2) label formatted as "label string flt_7D2DF4" with one-decimal float format aSS1f, then UIMenuItemCreator(text,0,0,0,0). [callee:0x00487010, callee:0x0058815F, callee:0x00489600, global:0x005C684C, global:0x007D2DF4, source:raw]
    // CALL: Menu item 3: UIListIndexedAccessor(3) label formatted as "label string flt_7D2DF8" with one-decimal float format aSS1f, then UIMenuItemCreator(text,0,0,0,0). [callee:0x00487010, callee:0x0058815F, callee:0x00489600, global:0x005C684C, global:0x007D2DF8, source:raw]
    // CALL: Menu item 4: UIListIndexedAccessor(4) label formatted as "label string dword_7D2DEC" (integer format aSSI), then UIMenuItemCreator(text,0,0,0,0). [callee:0x00487010, callee:0x0058815F, callee:0x00489600, global:0x005C6858, global:0x007D2DEC, source:raw]
    // CALL: Menu item 5: UIListIndexedAccessor(5) label formatted as "label string dword_7D2DE0" (integer format aSSI), then UIMenuItemCreator(text,0,0,0,0). [callee:0x00487010, callee:0x0058815F, callee:0x00489600, global:0x005C6858, global:0x007D2DE0, source:raw]
    // CALL: Menu item 6: UIListIndexedAccessor(6) label formatted as "label string dword_7D2DE8" (integer format aSSI), then UIMenuItemCreator(text,0,0,0,0). [callee:0x00487010, callee:0x0058815F, callee:0x00489600, global:0x005C6858, global:0x007D2DE8, source:raw]
    // CALL: Menu item 7: UIListIndexedAccessor(7) label formatted as "label string dword_7D2DF0" (integer format aSSI), then UIMenuItemCreator(text,0,0,0,0). [callee:0x00487010, callee:0x0058815F, callee:0x00489600, global:0x005C6858, global:0x007D2DF0, source:raw]
    // CALL: Menu item 8: UIListIndexedAccessor(8) label formatted as "label string dword_7D2DE4" (integer format aSSI), then UIMenuItemCreator(text,0,0,0,0). [callee:0x00487010, callee:0x0058815F, callee:0x00489600, global:0x005C6858, global:0x007D2DE4, source:raw]
    // RETURN: Return the result of the final UIMenuItemCreator call for item 8. [callee:0x00489600, function:0x0046A560, source:raw]
    // CALL: Invoked by ShortComputation_0ad0 (0x004A0AD0) as part of the standings/statistics display computation path. [caller:0x004A0AD0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_46A560(int *this) {
    //     char tail[4]; char label[256]; char fmt[256]; int node;
    //     tail[0] = byte_5EA438[0]; tail[2] = 0; tail[3] = 0;
    //     sub_4B0B20(fmt, 256);
    //     StateCleanupNotification(this);
    //     StringCopyWithBufferRealloc(fmt);
    //     StrlenOverwrite(tail);
    //     node = this[0x44/4];
    //     while (node) { void *p = node; node = *(int*)(node + 4); DoublePointerFree(p); FreeWrapper_7bcf(p); }
    //     this[0x44/4] = 0; this[0x48/4] = 0; this[0x4C/4] = 0; this[0x50/4] = 0;
    //     LinkedListInsertWithNodeAllocation(aExperienceLaps, -1);
    //     LinkedListInsertWithNodeAllocation(aStarts, -1);
    //     LinkedListInsertWithNodeAllocation(aAvgStartingPos, -1);
    //     LinkedListInsertWithNodeAllocation(aAvgFinishPosit, -1);
    //     LinkedListInsertWithNodeAllocation(aPolePositions, -1);
    //     LinkedListInsertWithNodeAllocation(aPoints, -1);
    //     LinkedListInsertWithNodeAllocation(aWins, -1);
    //     LinkedListInsertWithNodeAllocation(aLapRecords, -1);
    //     LinkedListInsertWithNodeAllocation(aDriversChampii, -1);
    //     StringFormatWithBufferOverflowCheck(label, aSSI, UIListIndexedAccessor(0), tail, dword_7D2DD4);  UIMenuItemCreator(label,0,0,0,0);
    //     StringFormatWithBufferOverflowCheck(label, aSSI, UIListIndexedAccessor(1), tail, dword_7D2DD8);  UIMenuItemCreator(label,0,0,0,0);
    //     StringFormatWithBufferOverflowCheck(label, aSS1f, UIListIndexedAccessor(2), tail, flt_7D2DF4);  UIMenuItemCreator(label,0,0,0,0);
    //     StringFormatWithBufferOverflowCheck(label, aSS1f, UIListIndexedAccessor(3), tail, flt_7D2DF8);  UIMenuItemCreator(label,0,0,0,0);
    //     StringFormatWithBufferOverflowCheck(label, aSSI, UIListIndexedAccessor(4), tail, dword_7D2DEC);  UIMenuItemCreator(label,0,0,0,0);
    //     StringFormatWithBufferOverflowCheck(label, aSSI, UIListIndexedAccessor(5), tail, dword_7D2DE0);  UIMenuItemCreator(label,0,0,0,0);
    //     StringFormatWithBufferOverflowCheck(label, aSSI, UIListIndexedAccessor(6), tail, dword_7D2DE8);  UIMenuItemCreator(label,0,0,0,0);
    //     StringFormatWithBufferOverflowCheck(label, aSSI, UIListIndexedAccessor(7), tail, dword_7D2DF0);  UIMenuItemCreator(label,0,0,0,0);
    //     StringFormatWithBufferOverflowCheck(label, aSSI, UIListIndexedAccessor(8), tail, dword_7D2DE4);
    //     return UIMenuItemCreator(label,0,0,0,0);
    //   }
    // UNRESOLVED: byte_7CE498 is flagged by packet facts but appears nowhere in the raw decompiled source; its role (possibly an unused/compiler-artifact global) is not verifiable here.
    // UNRESOLVED: The exact contents and roles of the v27 buffer and the v23/byte_5EA438-derived string are not documented in the raw source; they act as a label suffix/padding string in every formatted menu item.
    // UNRESOLVED: The mapping between the nine UIListIndexedAccessor indices and the nine inserted stat keys is not evidenced in this function.
    // UNRESOLVED: Semantic meaning of each 0x007D2DD4..0x007D2DF8 career-scoring value is inferred from the stat-key names only; exact stat identities are not confirmed.
    // UNRESOLVED: The this object class (UnknownObject) and the meaning of its 0x44/0x48/0x4C/0x50 list-pointer fields beyond 'linked lists' are unknown.
}
