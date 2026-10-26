## DoublyLinkedListRemove_005455f0 — Remove drawable node from category-linked list and decrement counter

**Summary:** Removes node `a2` from a doubly-linked list in the drawable object manager. Uses `*a2 & 7` to select the category-specific counter and head pointer. Decrements category count after unlinking.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5454A0 (005454a0), LinkedListWalkWithDispatch (005492b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x124 | R | — | Counter for drawable category 4 (decremented on removal) |
| this | 0x128 | RW | — | Head of category 4 linked list (updated if head node removed) |

**Written-by note (persistence):**
- this 0x128: Conditional — set to `node->next` when head equals node being removed; unchanged otherwise

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `*a2 & 7` switch: case 1/2/4 selects category-specific counter and head; default uses node itself. `a2[26]` (prev) null check: PASSES (prev->next = node->next) when non-null; BLOCKED (skip) when null. `a2[27]` (next) null check: PASSES (next->prev = node->prev) when non-null; BLOCKED (skip) when null. Head match (`*v3 == a2`): PASSES (head = node->next) on match; BLOCKED otherwise.
