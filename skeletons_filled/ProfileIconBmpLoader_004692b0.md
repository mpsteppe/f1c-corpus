## ProfileIconBmpLoader_004692b0 — ProfileIconBmpLoader

**Summary:** Constructs a file path to "ProfileIcon.bmp" from the settings directory and a profile filename retrieved from a linked list, then removes the old linked list entry by that path and triggers profile scanner refresh. Belongs to profile/settings icon loading system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6950 | aProfileiconBmp | R | ProfileIconBmpStr [DERIVED] (also: ` — "ProfileIcon.bmp" string) |
| 005c6968 | aSS_5 | R | FormatString_SS [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec440 | dword_5EC440 | R | SettingsDirectory [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | searches for "ProfileIcon.bmp" in a string table to determine its display name |
| 00468ee0 | PlayerProfileScanner | scans/rescans player profiles |
| 004693e0 | FilenameFromLinkedList | retrieves a profile filename from a linked list by index |
| 0048d360 | GuardedAccessor | obtains the linked list handle/index for profile entries |
| 00497c40 | LinkedListNodeRemovalByStringKey | removes a node from linked list matching the constructed path |
| 0058815f | StringFormatWithBufferOverflowCheck | safe string format for path construction ("%s%s\\") |

**Guard conditions:** Checks dword_5EC440 (settings directory) for null (defaults to byte_5EA438). Checks path string length > 0 before stripping trailing backslash and filename. Checks BinarySearchInStringTable result to conditionally copy "ProfileIcon.bmp" to display buffer. No early return — always calls PlayerProfileScanner.
