// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047DAF0
// Canonical corpus name: sub_47DAF0
// Owner: ReplayControlsMenu [DERIVED]
// Raw source: functions/sub_47DAF0_0047daf0.c

void ReplayControlsMenu::ReplayControlsMenuInit()
{
    // Constructor for a replay/VCR playback-controls menu object. Calls ConstructorInitVTable, installs the vtable off_5A6B20, stores a mode selector at this+0xEC, and when the mode is 480 populates a linked list with playback command entries (Begin, play, stop, forward/reverse scan, play back, bookmarks). Returns this.
    // CALL: Run base constructor initialization ConstructorInitVTable with arguments (1, -1). [callee:0x00488B00, source:raw]
    // ASSIGNMENT: Install the vtable pointer: *this = &off_5A6B20 (this+0x0). [field:this:0x00000000, global:0x005A6B20, source:raw]
    // ASSIGNMENT: Store the mode selector argument: this[59] (this+0xEC) = a2. [field:this:0x000000EC, source:raw]
    // GUARD: Guard: only when a2 == 480 does the function populate the playback command list; other mode values skip population entirely. [source:raw, function:0x0047DAF0]
    // CALL: LinkedListInsertWithNodeAllocation(aBegin, -1): insert the 'Begin' command entry (string at 0x005C7368). [callee:0x00486F30, global:0x005C7368, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(&off_5C7364, -1): insert the non-string data entry at 0x005C7364. [callee:0x00486F30, global:0x005C7364, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(aReverseScanFas, -1): insert the 'Reverse Scan Fast' command entry (string at 0x005C7350). [callee:0x00486F30, global:0x005C7350, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(aReverseScan, -1): insert the 'Reverse Scan' command entry (string at 0x005C7340). [callee:0x00486F30, global:0x005C7340, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(aPlaybackwards, -1): insert the 'Play Backwards' command entry (string at 0x005C7330). [callee:0x00486F30, global:0x005C7330, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(aStop, -1): insert the 'Stop' command entry (string at 0x005C7328). [callee:0x00486F30, global:0x005C7328, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(aPlay, -1): insert the 'Play' command entry (string at 0x005C7320). [callee:0x00486F30, global:0x005C7320, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(aForwardScan, -1): insert the 'Forward Scan' command entry (string at 0x005C7310). [callee:0x00486F30, global:0x005C7310, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(aForwardScanFas, -1): insert the 'Forward Scan Fast' command entry (string at 0x005C72FC). [callee:0x00486F30, global:0x005C72FC, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(aDropBookmark, -1): insert the 'Drop Bookmark' command entry (string at 0x005C72EC). [callee:0x00486F30, global:0x005C72EC, source:raw]
    // CALL: LinkedListInsertWithNodeAllocation(aRemoveBookmark, -1): insert the 'Remove Bookmark' command entry (string at 0x005C72DC). [callee:0x00486F30, global:0x005C72DC, source:raw]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   // ReplayControlsMenu constructor
    //   ConstructorInitVTable(1, -1);
    //   this->vtable = &off_5A6B20;
    //   this->mode = a2;  // this+0xEC
    //   if (a2 == 480) {
    //       LinkedListInsertWithNodeAllocation(aBegin, -1);
    //       LinkedListInsertWithNodeAllocation(&off_5C7364, -1);
    //       LinkedListInsertWithNodeAllocation(aReverseScanFas, -1);
    //       LinkedListInsertWithNodeAllocation(aReverseScan, -1);
    //       LinkedListInsertWithNodeAllocation(aPlaybackwards, -1);
    //       LinkedListInsertWithNodeAllocation(aStop, -1);
    //       LinkedListInsertWithNodeAllocation(aPlay, -1);
    //       LinkedListInsertWithNodeAllocation(aForwardScan, -1);
    //       LinkedListInsertWithNodeAllocation(aForwardScanFas, -1);
    //       LinkedListInsertWithNodeAllocation(aDropBookmark, -1);
    //       LinkedListInsertWithNodeAllocation(aRemoveBookmark, -1);
    //   }
    //   return this;
    // UNRESOLVED: Meaning of the mode literal 480 is caller-defined; it selects which command set this menu object populates.
    // UNRESOLVED: off_5C7364 is a non-string data pointer inserted into the same list; its role within the command list is unknown.
    // UNRESOLVED: Exact menu framework consuming the constructed command list is unknown.
}
