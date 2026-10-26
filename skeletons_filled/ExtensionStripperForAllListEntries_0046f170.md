## ExtensionStripperForAllListEntries_0046f170 — Extension stripper for all list entries

**Summary:** Iterates all list entries from module callback table, copies each string, strips file extension (removes characters from last '.' onward), creates a UI menu item with the base name, and frees temporary buffer. Rebuilds UI list with extension-free display names.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalUpdateOnChangedState (0046efe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory path (fallback when buffer is null) |
| 007c73e0 | dword_7C73E0 | R | ModuleCallbackTable — source of entry count and indexed string entries |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00432920 | VirtualPropertyAccessor | retrieves entry count from module callback table |
| 00432930 | IndexedEntryAccessor | accesses string entry by index from module callback table |
| 00489600 | UIMenuItemCreator | creates UI menu item with label and parameters |
| 00489cb0 | StateCleanupNotification | performs state cleanup/notification on UI object |
| 00566650 | StringCopyWithBufferRealloc | copies string into buffer with reallocation |
| 00587bcf | FreeWrapper_7bcf | frees heap-allocated buffer |

**Guard conditions:** No entry guard. Loop: for each entry from 0 to count-1, initializes buffer pair {NULL, -1}, copies entry string, if buffer null uses byte_5EA438 as fallback. Extension strip: searches backward from end for '.' — if found, replaces with null terminator. If before '.' was not found (no extension), keeps original string. Creates UI menu item; if buffer was allocated, frees it.
