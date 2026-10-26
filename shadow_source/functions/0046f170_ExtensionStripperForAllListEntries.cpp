// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046F170
// Canonical corpus name: ExtensionStripperForAllListEntries
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ExtensionStripperForAllListEntries_0046f170.c

void UnknownObject::ExtensionStripperForAllListEntries()
{
    // Iterates every string entry of the module callback table dword_7C73E0, copies each entry into a reallocating buffer, strips the file extension by null-terminating at the last '.' (decimal 46), and creates a UI menu item per base name via UIMenuItemCreator. Falls back to byte_5EA438 when the copied buffer is empty. Frees each allocated buffer and returns the entry count.
    // CALL: Calls StateCleanupNotification(this) to perform state cleanup / notification on the UI object before rebuilding its items. [callee:0x00489CB0, function:0x0046F170]
    // CALL: Calls VirtualPropertyAccessor(dword_7C73E0) to retrieve the entry count from the module callback table. [callee:0x00432920, global:0x007C73E0]
    // LOOP: Iterates over entries from index 0 to count-1, rebuilding each UI menu item from its string entry. [function:0x0046F170, global:0x007C73E0]
    // ASSIGNMENT: Initializes the copy buffer pair v10 to {NULL, -1} before each entry is copied. [source:raw]
    // CALL: Calls IndexedEntryAccessor(dword_7C73E0, entry_index) to obtain the string entry at the current index. [callee:0x00432930, global:0x007C73E0]
    // CALL: Calls StringCopyWithBufferRealloc on the buffer pair v10 with the entry string, copying it into a reallocated heap buffer. [callee:0x00566650, source:raw]
    // GUARD: If the copied buffer is empty, falls back to byte_5EA438 as the default string. [global:0x005EA438, source:raw]
    // CALCULATION: Walks backward from the end of the string looking for the '.' (decimal 46) extension separator. [source:raw]
    // STATE_TRANSITION: If a '.' is found beyond the first character, null-terminates the string there, truncating the file extension. [source:raw]
    // CALL: Calls UIMenuItemCreator(this, base_name, 0, 0, 0, 0) to create a UI menu item labelled with the extension-free base name. [callee:0x00489600, function:0x0046F170]
    // GUARD: If the copy buffer was allocated, frees it via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // RETURN: Returns the entry count after the loop completes. [function:0x0046F170, source:raw]

    // Conservative worker pseudocode:
    //   StateCleanupNotification(this);
    //   count = VirtualPropertyAccessor(dword_7C73E0);
    //   for (i = 0; i < count; ++i) {
    //       copy_buffer = {NULL, -1};
    //       StringCopyWithBufferRealloc(&copy_buffer, IndexedEntryAccessor(dword_7C73E0, i));
    //       base = copy_buffer[0] ? copy_buffer[0] : byte_5EA438;
    //       end = base + strlen(base);
    //       if (end > base) {
    //           while (*end != 46) { if (--end <= base) break; }
    //           if (*end == 46) *end = 0;
    //       }
    //       UIMenuItemCreator(this, base, 0, 0, 0, 0);
    //       if (copy_buffer[0]) FreeWrapper_7bcf(copy_buffer[0]);
    //   }
    //   return count;
    // UNRESOLVED: caller:0x0046EFE0 (ConditionalUpdateOnChangedState) invokes this function; the caller does not otherwise constrain semantics here.
    // UNRESOLVED: byte_5EA438 is the fallback string but its content/role beyond 'default value when buffer is null' is not evidenced in this packet.
}
