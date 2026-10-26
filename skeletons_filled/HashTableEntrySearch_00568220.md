## HashTableEntrySearch_00568220 — HashTableEntryLookupOrCreate

**Summary:** Searches hash table linked list for a string key. If found and its stored value is not -1, returns that value. Otherwise, allocates a new entry with a fresh index, inserts it into the list, and returns the new index. Implements get-or-create semantics.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FileDataProcessor (00567fb0), ObjectIDLookupAcross9Arrays (005684a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x24) | 0x0 | R | — | string pointer stored in first list entry |
| *(this+0x2C) | 0x8 | R | — | stored index value in current walk entry |
| this | 0x24 | RW | — | head pointer of bucket linked list |
| this | 0x28 | RW | — | tail pointer of bucket linked list |
| this | 0x2C | RW | — | current walk pointer during search |
| this | 0x30 | R | — | entry count in bucket |
| this | 0x34 | RW | — | next index/ID to assign to new entry |

**Written-by note (persistence):**
- this 0x24: written once when first entry inserted; survives as persistent list head
- this 0x28: updated on each insert to point to new tail; survives
- this 0x2C: written during search walk; updated on each insert; survives
- this 0x34: incremented on each insert; survives as persistent next-ID counter

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copies search key into newly allocated entry buffer |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 12-byte entry node and 12-byte list wrapper node |
| 00588410 | sub_588410 | compares two strings for equality/match |

**Guard conditions:** if a2 (search key) is NULL, returns -1 immediately. If this[9] (bucket head) or *this[9] is null, skips search and proceeds directly to creation/insertion.
