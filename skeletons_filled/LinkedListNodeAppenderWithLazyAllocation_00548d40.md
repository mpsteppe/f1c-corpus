## LinkedListNodeAppenderWithLazyAllocation_00548d40 — LazyLinkedListNodeAppend

**Summary:** Appends a new 28-byte node to a singly-linked list (next pointer at offset 0x18). Lazily allocates the head node on first call. Each new node is initialized via ArithmeticComparison_8aa0 then sub_548AD0 (VehicleReflectionMapInit). Increments node counter at this[0x16C].

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_546450 (00546450)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x188)+0x18) | 0x18 | RW | — | pNext — forward pointer in the linked list node |
| this | 0x16C | R | — | Node counter — incremented each time a node is appended |
| this | 0x170 | RW | 0 | Head/tail pointer — first node in the list (lazily allocated) |
| this | 0x188 | R | — | Intermediate pointer to container struct that holds the list head |

**Written-by note (persistence):**
- *(*(this+0x188)+0x18) 0x18: Written once per append to link new node; external poke to offset 0x18 breaks the chain
- this 0x170: Written once when first node is allocated; external poke survives after execution

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00548aa0 | ArithmeticComparison_8aa0 | Initializes the 28-byte allocated block as a new linked list node |
| 00548ad0 | sub_548AD0 | VehicleReflectionMapInit — populates node with reflection map data |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation of 28 bytes for the new node |

**Guard conditions:** If this[0x170] is NULL, allocates the first node and sets it as head (this[0x170]=newNode). Otherwise walks existing chain via offset 0x18 to find tail and appends. If OperatorNewNhMallocWrapper returns NULL, node is 0 and list head may be set to 0 on first allocation. If sub_548AD0 returns non-zero, function returns -1 (failure).
