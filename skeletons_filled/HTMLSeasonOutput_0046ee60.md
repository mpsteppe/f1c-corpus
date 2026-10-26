## HTMLSeasonOutput_0046ee60 — HTML season output menu builder

**Summary:** Cleans up UI state, creates a path-separator menu item, retrieves vehicle count from module callback table, then creates one menu item per vehicle entry. Builds season output HTML/list UI.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005beb48 | word_5BEB48 | R | PathSepWord — path separator string used as first menu item label |
| 007c73e0 | dword_7C73E0 | R | ModuleCallbackTable — provides vehicle count and indexed list entries |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00432810 | VehicleFieldAccessor | retrieves vehicle count from module callback table |
| 00432820 | IndexedListEntryAccessor | accesses list entry by index from module callback table |
| 00489600 | UIMenuItemCreator | creates UI menu item with label and parameters |
| 00489cb0 | StateCleanupNotification | performs state cleanup/notification on UI object |

**Guard conditions:** No entry guard. Always executes cleanup, creates first menu item, gets vehicle count, loops i from 0 to count-1 creating menu items for each entry.
