## LinkedListRemovalByName_00433d60 — LinkedListRemovalByName

**Summary:** Removes linked list nodes whose entry name matches a given name string. Also clears stored name in object if it matches. Unlinks node, fixes head/tail/iterator pointers, decrements count, and frees node memory.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LoadAIDriverNamesFromConfig (004336f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x14 | R | — | entry struct name string at data+0x14 (compared against a2) |
| this | 0x10 | R | — | stored name string in object (compared against a2 after loop) |
| this | 0x1C | RW | — | pHead: head pointer (updated when removing first node) |
| this | 0x20 | RW | — | pTail: tail pointer (updated when removing last node) |
| this | 0x24 | RW | — | pIter: iterator pointer (advanced on skip, reset on removal) |
| this | 0x28 | R | — | nCount: decremented on each removal |

**Written-by note (persistence):**
- this 0x1C: updated when removed node was head. Survives.
- this 0x20: updated when removed node was tail. Survives.
- this 0x24: advanced on no-match, reset to head after each removal. Survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory path (used as fallback null string) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00433e60 | PhysicsObjectDestructor_3e60 | destructor for node's data struct before freeing node |
| 00566650 | StringCopyWithBufferRealloc | copy string with buffer reallocation (clear stored name) |
| 00587bcf | FreeWrapper_7bcf | free heap memory (freed node) |
| 00588410 | sub_588410 | compare two strings (returns 0 on equality) |

**Guard conditions:** Head pointer `this[7]` (0x1C) must be non-null to enter loop. First node's data pointer `*v3` must be non-null. Per entry: compares `*(data+0x14)` (name field) with a2 using `sub_588410`. If match (returns 0): scans list to find owning node, unlinks it, decrements count, frees node, resets iterator to head. If no match: advances iterator to next. Loop terminates when iterator becomes null or its data pointer is null. After list iteration, checks `this[4]` (0x10) against a2: if match (returns 0), clears stored name to empty string.
