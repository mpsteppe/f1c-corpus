## HashTableListInsert_00567e10 — HashTableListInsertOrFind

**Summary:** Searches a hash table linked list for a string key (offset +4 in input structure). If found, returns match indicator. If not found, allocates a new entry and appends it to the linked list, updating list pointers and counters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioFileLoadDecode (00567f40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | RW | — | head pointer of bucket linked list |
| this | 0x28 | RW | — | tail pointer of bucket linked list |
| this | 0x2C | RW | — | current walk pointer during search |
| this | 0x30 | RW | — | count of entries in bucket (incremented on insert) |
| this | 0x34 | RW | — | next index/ID to assign to new entry |

**Written-by note (persistence):**
- this 0x24: written once when first entry inserted; survives as persistent list head
- this 0x28: updated on each insert to point to new tail; survives
- this 0x2C: written during search walk; updated on each insert; survives
- this 0x30: incremented on each insert; survives as persistent count
- this 0x34: incremented on each insert; survives as persistent next-ID counter

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copies string into newly allocated entry buffer |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 12-byte entry node and 12-byte list wrapper node |
| 00588410 | sub_588410 | compares two strings for equality/match |

**Guard conditions:** if this[9] (bucket list head) is null or *this[9] is null, skips search and goes directly to allocation/insertion code.
