## LinkedListTraversalWithVirtualCall_00496e40 — TraverseLinkedListAndProcessNodes

**Summary:** Traverses a singly-linked list starting from head pointer at this+0x18DC. For each node, reads item pointer at node+0x0 and calls its virtual method at vtable offset 0x6C. Advances via next pointer at node+0x4.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_485B90 (00485b90), UIConditionalVirtualDispatch (0048e860), CUBESceneLoaderEntry (0048e8d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x18DC)+0x0) | 0x6C | R | — | Virtual method pointer at vtable+0x6C called on each list item |
| *(this+0x18DC) | 0x0 | R | — | First node's item pointer (head of list) |
| this | 0x18DC | R | — | Head pointer to linked list |
| this | 0x18E4 | RW | — | Current node pointer during traversal |
| this | 0x18E8 | R | — | Loop condition or boundary value |
| this | 0x18EC | R | — | Loop condition or boundary value |

**Written-by note (persistence):**
- this 0x18E4: Written each call (head on entry, next node each iteration). External poke does not survive — always overwritten.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Head pointer this[1591] (0x18DC) checked for non-null. If null, entire traversal skipped. During loop, current node (this[1593]) checked for null before advancing — null causes break.
