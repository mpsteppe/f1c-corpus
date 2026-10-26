## ShortComputation_7dd0_00407dd0 — TraverseListAndTriggerConditional

**Summary:** Traverses a linked list and calls ConditionalMatchTrigger on each node's stored value. Called during settings save to notify each element in the list of a save event.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SettingsSaveWrapper (00405030)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x18)+0x0) | 0x0 | R | — | first DWORD of the data object stored in the head node |
| *(this+0x18) | 0x0 | R | — | value pointer stored in the head node |
| this | 0x18 | R | — | head pointer of linked list |
| this | 0x20 | RW | — | traversal cursor updated as iteration advances |
| this | 0x28 | R | — | unknown (read-only in this function) |

**Written-by note (persistence):**
- this 0x20: overwritten every call — cursor is reset to head, then advanced per node

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00406640 | ConditionalMatchTrigger | triggers conditional logic on each node's value using parameter a2 |

**Guard conditions:** If head pointer (this[6]) is null, function returns null immediately (empty list, no traversal). If cursor becomes null at any point during traversal, loop breaks.
