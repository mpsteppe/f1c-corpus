## LinkedListNodeSearchAllocation_00559630 — LinkedListNodeSearchAllocation

**Summary:** Search singly-linked list for node matching tuple keys (a2, a3). If found, return node pointer. If not found, allocate new node (32 bytes), init, append at tail, set keys via StructFieldInit_9390.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5598B0 (005598b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | Head pointer of linked list |
| this | 0x24 | R | — | unknown |
| this | 0x38 | R | — | unknown |
| this | 0x3C | R | — | unknown |
| this | 0x40 | R | — | unknown |
| this | 0x5C | RW | — | unknown |

**Written-by note (persistence):**
- this 0x8: Written once when list was empty (set to first node); updated on removal
- this 0x5C: unknown

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00559330 | SmallStructInitWithParentCall | Zero-initialize new 32-byte node |
| 00559390 | StructFieldInit_9390 | Initialize node key fields from parameters a2, a3 |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocate 32 bytes for new node |

**Guard conditions:**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| (search) | node[5] | == | a2 | Match key field 1 |
| (search) | node[6] | == | a3 | Match key field 2 |

**Guard interpretation:** Loop searches list comparing node fields at +0x14 (key1) and +0x18 (key2) against a2, a3. PASS if both match (return found node). BLOCKED if walk reaches null (node not found — fall through to allocation path).
