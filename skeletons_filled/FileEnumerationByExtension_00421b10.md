## FileEnumerationByExtension_00421b10 — EnumerateAndCopyFilesByExtension

**Summary:** Enumerates files matching scene extension from config directory, constructs source/destination paths, reads source file content and writes to destination. File copy operation based on extension enumeration.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConfigIniParser (00421cd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be828 | aRb | R | FileModeRb [DERIVED] (also: ` — string comparison template) |
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005beb48 | word_5BEB48 | R | PathSepWord [DERIVED] |
| 005c2ab0 | unk_5C2AB0 | R | ConfigDirectoryPath [DERIVED] |
| 005c2ab4 | asc_5C2AB4 | R | FileExtGDBBytes [DERIVED] |
| 005c2ab8 | dword_5C2AB8 | R | SceneExtension [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00565dc0 | AllocateStructWithDefaultValues | Allocate and initialize linked list structure with defaults |
| 00565e20 | LinkedListDestructorWithChildCleanup | Destroy linked list and free all allocated nodes |
| 00565ed0 | LinkedListNodeDataPeek | Get data pointer from current linked list node |
| 00565f20 | LinkedListNodePeek | Advance linked list cursor to next node |
| 00565f50 | LinkedListPopFront_5f50 | Pop front node off linked list into result struct |
| 00565f80 | sub_565F80 | Enumerate directory files matching extension pattern |
| 00587d02 | FileCloseWithLock | Close file handle with mutex lock |
| 00587db0 | sub_587DB0 | Open file for reading (fopen with mode) |
| 0058803f | ThreadSafeReadWrapper_803f | Thread-safe read from file into buffer |
| 0058815f | StringFormatWithBufferOverflowCheck | Format string with buffer overflow check (snprintf equivalent) |
| 00588678 | FileReadWrapperWithLock | Read file content with mutex lock (fread equivalent) |

**Guard conditions:** Entry is a directory (flags & 0x10 set): skip. Entry is "." (matches word_5BEB48): skip. Entry is "..": skip. a1 (source base path) empty string: skip entry. v10 (destination base path) empty string: skip entry. sub_587DB0(v12, aRb) returns NULL (source file cannot be opened): skip entry. sub_587DB0(v15, &unk_5C2AB0) returns NULL (destination file cannot be opened): skip entry.
