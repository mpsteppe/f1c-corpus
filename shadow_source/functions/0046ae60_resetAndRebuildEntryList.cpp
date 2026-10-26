// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046AE60
// Canonical corpus name: SessionEntryListCleanup
// Owner: SessionEntryList [DERIVED]
// Raw source: functions/SessionEntryListCleanup_0046ae60.c

void SessionEntryList::resetAndRebuildEntryList()
{
    // Resets and rebuilds a session entry list on the calling object. Notifies state cleanup (StateCleanupNotification), frees the existing node list headed at this+0x44 (walking next pointers at node+4 and, when the node flag byte at +8 is set, releasing the node's sub-object chain via FreeWrapper_7bcf), zeroes the four list pointers at this+0x44..0x50, then rebuilds the list by inserting one node per entry count dword_7D1424, fetching each module reference from the ppvOut array (ArrayIndexedAccessor) with insert value -1 (LinkedListInsertWithNodeAllocation) and building the display-name buffer per entry (MessageNameBufferUpdate). Returns the entry count.
    // CALL: Notify state cleanup for this object via StateCleanupNotification. [callee:0x00489CB0]
    // LOOP: Free the existing node list headed at this+0x44: walk nodes via the next pointer at node+4; if the node flag byte at +8 is set, release the node's sub-object chain (node+0, and node+0's first member when present) via FreeWrapper_7bcf, then free the node itself. [field:this:0x00000044, field:*(this+0x44):0x00000000, field:*(this+0x48):0x00000004, callee:0x00587BCF]
    // ASSIGNMENT: Zero the list head and associated pointers this+0x44, this+0x48, this+0x4C, this+0x50 after freeing. [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050]
    // LOOP: Rebuild the list: for each index from 0 up to the entry count dword_7D1424, fetch the module reference from the ppvOut array via ArrayIndexedAccessor, insert a new node with value -1 via LinkedListInsertWithNodeAllocation, and build the entry display-name buffer via MessageNameBufferUpdate. [global:0x007D1424, callee:0x00455560, global:0x007CA590, callee:0x00486F30, callee:0x0046AD50]
    // RETURN: Return the entry count dword_7D1424 as the result. [global:0x007D1424, source:raw]

    // Conservative worker pseudocode:
    //   StateCleanupNotification(this)
    //   for node in list(this+0x44): if node.flag(+8): free node[0] chain; free node
    //   zero this+0x44/0x48/0x4C/0x50
    //   for i in [0, dword_7D1424): node = LinkedListInsertWithNodeAllocation(ArrayIndexedAccessor(ppvOut, i), -1); MessageNameBufferUpdate(i, nameBuffer, 1)
    //   return dword_7D1424
    // UNRESOLVED: The node flag byte at +8 and the node[0] sub-object structure are observed only through the deref pattern, not as reconstructed field evidence.
    // UNRESOLVED: The insert value -1 semantics (likely a sentinel/placeholder slot index) are inferred, not proven.
    // UNRESOLVED: The exact role of the ppvOut module-reference array relative to the entry list is not fully established.
}
