## TGATextureFileScanner_004c3a00 — TGATextureDirectoryScanner

**Summary:** Scans a directory for TGA texture files matching a given filename. Iterates directory entries, compares base filenames (stripping directory paths and extensions), and builds a linked list of matching results with path match priority (exact path matches appended, others prepended). Returns a list destructor result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FileINILoader (004c38d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | input file path string pointer, read as base directory for scanning |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3074 | byte_5D3074 | R | TgaFileFilterString [DERIVED] — "*.tga" filter constant |
| 005ea438 | byte_5EA438 | R | default application directory, fallback when input path is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00565dc0 | AllocateStructWithDefaultValues | allocate/init directory scan structure |
| 00565e20 | LinkedListDestructorWithChildCleanup | destroy directory scan structure and children |
| 00565eb0 | sub_565EB0 | initialize directory scan with parameters |
| 00565ef0 | ReversePathSearchForBackslashSeparator | find last backslash in path from current entry |
| 00565f20 | LinkedListNodePeek | peek at next node in scan list |
| 00565f50 | LinkedListPopFront_5f50 | pop front node from scan list |
| 00565f80 | sub_565F80 | set file filter pattern ("*.tga") |
| 005662d0 | DirectoryEntryIterator | iterate to next directory entry |
| 00566380 | sub_566380 | finalize/commit directory scan setup |
| 00566650 | StringCopyWithBufferRealloc | realloc-copy string into result node |
| 00566810 | sub_566810 | resolve/compare path against base directory |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory (8-byte data object, 12-byte list node) |
| 00587dd0 | sub_587DD0 | copy string with length limit |
| 00588410 | sub_588410 | string comparison function |

**Guard conditions:** Input path at *this defaults to byte_5EA438 if null. Directory entry loop continues while DirectoryEntryIterator returns non-null. Each entry's filename is compared against target via sub_588410 — only matching entries produce result nodes. Bounds checks on string buffers prevent overflows during path parsing.
