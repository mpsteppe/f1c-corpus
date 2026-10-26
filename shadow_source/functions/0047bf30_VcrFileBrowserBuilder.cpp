// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047BF30
// Canonical corpus name: sub_47BF30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47BF30_0047bf30.c

void UnknownObject::VcrFileBrowserBuilder()
{
    // Rebuilds the VCR replay file browser list. Clears the selection flag at this+0x131, resets the UI list via StateCleanupNotification, primes the search-result linked list, scans the replay directory (lpPathName or default byte_5EA438) with the aVcr_0 pattern through the search API (sub_565F80/sub_566380), iterates the result list creating a UI menu item per stripped file name, then selects the initial/saved file name v6 and resets the list. Matches existing-analysis name VcrFileBrowserBuilder.
    // ASSIGNMENT: Initialize the initial-name buffer: copy the first byte of the default directory string byte_5EA438, zero-fill the remaining 0x3C bytes, and zero the trailing fields v7/v8 [global:0x005EA438, source:raw]
    // CALL: UIScreenTextAccessor(this) retrieves the current screen/path text into v2 [callee:0x00489920, source:raw]
    // ASSIGNMENT: Clear the selection flag/counter at this+0x131 (this[305] = 0) before the scan [field:this:0x00000131, source:raw]
    // GUARD: When UIScreenTextAccessor returned a non-null string (v2), copy up to 63 characters into the initialized buffer via sub_587DD0 and re-clear the trailing flag v8 [callee:0x00587DD0, source:raw]
    // CALL: StateCleanupNotification(this) resets the UI list state before repopulation [callee:0x00489CB0, source:raw]
    // CALL: sub_565EB0(&unk_8AD3B0) initializes/resets the file-search linked list head [callee:0x00565EB0, global:0x008AD3B0, source:raw]
    // GUARD: Select the scan directory: use lpPathName when non-null, otherwise fall back to the default directory byte_5EA438 (v3) [global:0x005EC410, global:0x005EA438, source:raw]
    // CALL: sub_565F80(aVcr_0, 1, v3, 0) starts the file search using the aVcr_0 pattern in the chosen directory [callee:0x00565F80, global:0x005C71D4, source:raw]
    // CALL: sub_566380(0) is invoked with argument 0 [callee:0x00566380, source:raw]
    // CALL: LinkedListPopFront_5f50(&unk_8AD3B0) removes the first node from the search-result list [callee:0x00565F50, global:0x008AD3B0, source:raw]
    // LOOP: Walk the result list: repeatedly peek node data with LinkedListNodeDataPeek(&unk_8AD3B0) until it returns null (i) [callee:0x00565ED0, global:0x008AD3B0, source:raw]
    // ASSIGNMENT: Re-initialize the per-file name buffer: copy the first byte of byte_5EA438, zero-fill the remaining 0x7C bytes, and zero the trailing fields v10/v11 [global:0x005EA438, source:raw]
    // CALL: FileExtensionStripper(i, v9) strips the file extension from the current node's path into v9 [callee:0x0047BEB0, source:raw]
    // GUARD: Only create a menu item when the stripped name v9 is non-empty (strlen > 0) [source:raw]
    // CALL: UIMenuItemCreator(v9, 0, 0, 0, 0) creates a UI menu item named after the stripped file name [callee:0x00489600, source:raw]
    // CALL: LinkedListNodePeek(&unk_8AD3B0) advances to the next node in the result list [callee:0x00565F20, global:0x008AD3B0, source:raw]
    // CALL: UIListSearchAndSelect(v6, 0) selects the initial/saved file name v6 in the repopulated list [callee:0x00489BA0, source:raw]
    // RETURN: Return the result of sub_565EB0(&unk_8AD3B0), which resets the search-result list [callee:0x00565EB0, global:0x008AD3B0, source:raw]

    // Conservative worker pseudocode:
    //   char initial_name[61]; // plus v7/v8 trailing fields
    //   initial_name[0] = byte_5EA438[0];
    //   memset(initial_name + 1, 0, 0x3C);
    //   v7 = 0; v8 = 0;
    //   char *screen_text = UIScreenTextAccessor(this);
    //   this[305] = 0;
    //   if (screen_text) { sub_587DD0(initial_name, screen_text, 63); v8 = 0; }
    //   StateCleanupNotification(this);
    //   sub_565EB0(&unk_8AD3B0);
    //   char *dir = lpPathName ? lpPathName : byte_5EA438;
    //   sub_565F80(aVcr_0, 1, dir, 0);
    //   sub_566380(0);
    //   LinkedListPopFront_5f50(&unk_8AD3B0);
    //   for (int data = LinkedListNodeDataPeek(&unk_8AD3B0); data; data = LinkedListNodeDataPeek(&unk_8AD3B0)) {
    //     char file_name[125]; // plus v10/v11 trailing fields
    //     file_name[0] = byte_5EA438[0];
    //     memset(file_name + 1, 0, 0x7C);
    //     v10 = 0; v11 = 0;
    //     FileExtensionStripper(data, file_name);
    //     if (strlen(file_name)) UIMenuItemCreator(file_name, 0, 0, 0, 0);
    //     LinkedListNodePeek(&unk_8AD3B0);
    //   }
    //   UIListSearchAndSelect(initial_name, 0);
    //   return sub_565EB0(&unk_8AD3B0);
    // UNRESOLVED: The trailing zero-initialized buffer fields v7/v8 (initial-name buffer) and v10/v11 (per-file buffer) are re-cleared in the raw source but their individual roles are not grounded by the packet
    // UNRESOLVED: The directory globals byte_5EA438 (default) and lpPathName (override) are not resolved to concrete paths; aVcr_0 is named only 'VcrString' by the existing analysis
    // UNRESOLVED: The linked-list container/node layout behind unk_8AD3B0 and the internal semantics of sub_565EB0/sub_565F80/sub_566380 are identified only by their call sites and names
    // UNRESOLVED: strlen is a CRT call with no packet callee entry; it is treated as an inline guard on the stripped name
    // UNRESOLVED: This function has no static callers; which UI lifecycle path invokes the browser is unknown
}
