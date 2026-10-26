## ProfileBitmapBrowser_00477cb0 — ProfileBitmapBrowser_BuildList

**Summary:** Builds a scrollable list of profile icon bitmaps by enumerating BMP files in a directory, creating a UI widget for each, and linking them into a doubly-linked list for display. Part of the profile/player customization UI system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xF0)+0x0) | 0x0 | R | — | vtable pointer of first linked-list node (used to call destructor on old items) |
| *(this+0xF0) | 0x0 | R | — | head pointer of linked list of bitmap UI items (iterated for cleanup) |
| *(this+0xF4) | 0x4 | R | — | next-pointer field within linked list node (followed during iteration) |
| this | 0xF0 | RW | 0 | linked list head pointer (cleared after freeing old items) |
| this | 0xF4 | RW | 0 | linked list tail/secondary pointer (cleared) |
| this | 0xF8 | RW | 0 | linked list state field (zeroed) |
| this | 0xFC | RW | 0 | item count / list initialized flag (zeroed; guard checks == 0) |
| this | 0x174 | RW | 0 | layout state flag (zeroed before UIViewportLayoutCalculator) |

**Written-by note (persistence):**
- this 0xF0: once (cleared during rebuild; external writes would survive until next rebuild)
- this 0xF4: once (cleared during rebuild; external writes survive)
- this 0xF8: once (cleared during rebuild; external writes survive)
- this 0xFC: once (cleared during rebuild; external writes survive)
- this 0x174: once (zeroed each call before layout; external writes survive)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` — format string for path construction) |
| 005c6658 | lpExistingFileName | W | sProfileIconBmp [DERIVED] |
| 005c66f8 | aProfileiconDft | R | DefaultProfileIconPath [DERIVED] (also: ` — "ProfileIcon_DFT.bmp" default icon) |
| 005c715c | aBmp_0 | R | BmpString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3f8 | dword_5EC3F8 | R | FontIconPathPtr [DERIVED] |
| 008ad3b0 | dword_8AD3B0 | R | FileSearchData [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048ebd0 | UIDimensionCapture | captures/reads current UI dimension values for layout calculation |
| 0048f5d0 | DoublyLinkedListAppend_f5d0 | appends a new node at the end of the bitmap item linked list |
| 0048f640 | UIViewportLayoutCalculator | calculates viewport layout positions for all items in the list |
| 0048fc50 | UIObjectConstructor_fc50 | constructs a UI bitmap display object from raw memory allocation |
| 0048fc80 | StructFieldCopy_fc80 | copies bitmap metadata/field into the UI object structure |
| 00497ad0 | sub_497AD0 | loads a bitmap from file and creates a UI texture object |
| 00565eb0 | sub_565EB0 | cleans up and closes the directory entry iterator |
| 00565f20 | LinkedListNodePeek | advances to the next directory entry in the iterator |
| 00565f80 | sub_565F80 | builds a search path string (directory + "*.bmp" pattern) |
| 005662d0 | DirectoryEntryIterator | returns next filename from the directory search |
| 00566380 | sub_566380 | initializes directory file search with the given path pattern |
| 00566650 | StringCopyWithBufferRealloc | copies a string into a buffer with reallocation if needed |
| 00587bcf | FreeWrapper_7bcf | frees a heap-allocated memory block |
| 00587c03 | OperatorNewNhMallocWrapper | allocates heap memory with error handling (60 bytes per item) |
| 0058815f | StringFormatWithBufferOverflowCheck | formats a full path string: "%s%s" (directory + filename) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xFC | == | 0 | item count: always 0 after reset; no guard-effect on flow — unconditionally proceeds |

**Guard interpretation:** this+0xFC == 0 is always true at that point (just zeroed). No branching depends on it; appears to be a reset-before-rebuild pattern. PASSES trivially (always 0), no BLOCKED path.
