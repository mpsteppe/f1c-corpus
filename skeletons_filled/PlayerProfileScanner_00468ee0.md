## PlayerProfileScanner_00468ee0 — PlayerProfileIconScanner

**Summary:** Scans the settings directory for *.PLR player profile files, loads each profile's icon bitmap (falling back to default "ProfileIcon_DFT.bmp"), and builds a linked list of loaded icon bitmaps with associated path strings for UI selection.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_92a0 (004692a0), ProfileIconBmpLoader (004692b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x448) | 0x4 | R | — | "next" pointer of tail node in linked list — used to append newly allocated node |
| this | 0x444 | RW | 0 | linked list head pointer — cleared on init, set to first icon/string node pair |
| this | 0x448 | RW | 0 | linked list tail pointer — tracks last node for O(1) append |
| this | 0x44C | RW | 0 | linked list cursor (currently selected item) — set to head if count>0, else 0 |
| this | 0x450 | RW | 0 | linked list item count — incremented per profile file found |

**Written-by note (persistence):**
- this 0x444: written once per scan call — external poke survives until next scan, then overwritten
- this 0x448: written once per scan call — external poke survives until next scan, then overwritten
- this 0x44C: written once per scan call — external poke survives until next scan, then overwritten
- this 0x450: written once per scan call — external poke survives until next scan, then overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | "%s%s" format string for path construction (directory + filename) |
| 005c66f8 | aProfileiconDft | R | "ProfileIcon_DFT.bmp" — default icon file path, used as fallback when profile icon load fails |
| 005c6950 | aProfileiconBmp | R | "ProfileIcon.bmp" string — icon filename searched for in string table and copied to message buffer |
| 005c6960 | aPlr_0 | R | "*.PLR" wildcard search pattern for enumerating player profile files |
| 005ea438 | byte_5EA438 | R | default application directory fallback (empty string), used when directory pointer is NULL |
| 005ec440 | dword_5EC440 | R | settings directory path — root directory where *.PLR files are searched |
| 005ec4c0 | byte_5EC4C0 | R | empty string buffer used as reference in binary string table search |
| 005ec4cc | byte_5EC4CC | RW | message/display buffer — written with "ProfileIcon.bmp" filename for path concatenation |
| 008ad3b0 | dword_8AD3B0 | R | file search/enumeration data structure used by DirectoryEntryIterator |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f70 | ConditionalFreeWithBit0Flag | Frees a pointer only if bit 0 of the associated flag byte is clear |
| 00423a00 | BinarySearchInStringTable | Searches for a string in a string table; used to check if "ProfileIcon.bmp" is already known |
| 00469630 | SetupFileLoadAndFinalize | Finalizes setup after profile scanning completes and returns result |
| 0048d230 | LinkedListDestructionWithVTableCall | Destroys existing linked list (frees all nodes and their string data) before rebuilding |
| 0048d2b0 | LinkedListNodeAppend | Appends a bitmap handle (loaded icon) to the linked list |
| 00497ad0 | sub_497AD0 | Loads a bitmap/image file from disk; returns handle or 0 on failure |
| 00565eb0 | sub_565EB0 | Cleans up / closes the file search enumeration |
| 00565f20 | LinkedListNodePeek | Advances directory iterator to next file entry |
| 00565f80 | sub_565F80 | Initiates file search with wildcard pattern ("*.PLR") in given directory |
| 005662d0 | DirectoryEntryIterator | Returns next directory entry from the file search results |
| 00566380 | sub_566380 | Sets file attribute filter for directory enumeration (filter=2) |
| 00566650 | StringCopyWithBufferRealloc | Copies a string with dynamic buffer reallocation (used to duplicate directory path for node) |
| 00587bcf | FreeWrapper_7bcf | Frees allocated memory (custom free wrapper) |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates memory with no-throw new |
| 0058815f | StringFormatWithBufferOverflowCheck | sprintf with overflow protection; builds full path "directory\filename" |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x44C | == | 0 | cursor reset: when item count <= 0, set cursor to null (no items to select) |
| this | 0x450 | <= | 0 | count check: if no profile files found, cursor set to 0; otherwise cursor = head |

**Guard interpretation:** After scanning completes, if the linked list item count (this+0x450) is <= 0 (no profiles found), the cursor (this+0x44C) is set to 0 (null). If count > 0, the cursor is set to the head of the list so the first profile icon is selected. This is a post-scan state adjustment, not a blocking guard.