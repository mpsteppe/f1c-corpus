## ResourceListCleanup_00404d50 — ResourceListNodeRebuildFromDirectory

**Summary:** When activated (a2 non-zero), frees all nodes in a linked list of resources, clears the list head, then rebuilds the list by enumerating directory entries from a resolved path. When a2 is zero, only sets a flag and returns.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConfigIniParser (00421cd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x40)+0x0) | 0x0 | R | — | linked list node: data pointer (heap-allocated inner buffer) |
| *(*(obj+0x40)+0x4) | 0x4 | R | — | linked list node: next pointer |
| *(obj+0x40) | 0x0 | R | — | first node in linked list |
| *(obj+0x40) | 0x8 | R | — | linked list node: byte flag indicating whether node has sub-data to free |
| obj | 0x24 | RW | — | byte flag set to a2 (trigger for list rebuild) |
| obj | 0x40 | RW | 0 | linked list head pointer (zeroed after cleanup) |
| obj | 0x44 | RW | 0 | linked list tail/count (zeroed after cleanup) |
| obj | 0x48 | RW | 0 | linked list field (zeroed after cleanup) |
| obj | 0x4C | RW | 0 | linked list field (zeroed after cleanup) |
| this | 0x0 | R | — | pointer to target object |

**Written-by note (persistence):**
- obj 0x24: written once per call with a2 value; retains until next call
- obj 0x40: zeroed during rebuild path; retains newly allocated list after
- obj 0x44: zeroed during rebuild path
- obj 0x48: zeroed during rebuild path
- obj 0x4C: zeroed during rebuild path

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be714 | FileName | R | serialization constant [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec410 | lpPathName | R | LoadPath / directory pointer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404e60 | LinkedListNodeInsertion | inserts a new node with given string data into linked list |
| 00565dc0 | AllocateStructWithDefaultValues | allocates and initializes a temporary struct for directory iteration |
| 00565e20 | LinkedListDestructorWithChildCleanup | destructs linked list and frees child nodes |
| 00565f20 | LinkedListNodePeek | peeks at head node of linked list without removing |
| 00565f50 | LinkedListPopFront_5f50 | pops front node from linked list |
| 00565f80 | sub_565F80 | performs file/directory operation with given filename and path |
| 005662d0 | DirectoryEntryIterator | iterates over directory entries, returns each name |
| 00587bcf | FreeWrapper_7bcf | standard heap free wrapper |

**Guard conditions:** Checks a2 parameter == 0. PASSES (a2 != 0): enters rebuild path — frees old list, enumerates directory, rebuilds list. BLOCKED (a2 == 0): sets flag at offset 0x24 to a2 (0) and returns immediately, no list modification.
