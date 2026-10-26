## StringListAppend_00549020 — StringNodeListAppend

**Summary:** Appends a new 24-byte string node to a singly-linked list (next pointer at offset 0x14). Copies input string `a2` into the new node via strcpy, then normalizes it via sub_589901. Lazily allocates head node on first call.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55A790 (0055a790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xFC)+0x14) | 0x14 | RW | — | pNext — forward pointer in the linked list node |
| this | 0xE8 | RW | 0 | Head pointer of the string node linked list |
| this | 0xFC | R | — | Pointer to container struct that holds the list |

**Written-by note (persistence):**
- *(*(this+0xFC)+0x14) 0x14: Written once per append to link tail to new node; external poke breaks list linkage
- this 0xE8: Written once when first node is allocated; external poke survives after execution

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00548e00 | ShortComputation_8e00 | ObjectMultiFieldZeroInit — zero-initializes the 24-byte node |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation of 24 bytes for new node |
| 00589901 | sub_589901 | String normalization (e.g., uppercase/lowercase) applied to the new node's string data |

**Guard conditions:** If this[0xE8] (head) is NULL, allocates first node and sets it as head. Otherwise walks chain via next pointer at offset 0x14 to find tail and appends. If OperatorNewNhMallocWrapper returns NULL, node is 0 and head may be set to 0 on first allocation.
