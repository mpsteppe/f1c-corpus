## LinkedListKeySearch_004c4cb0 — Search linked list for matching key value

**Summary:** Traverses a linked list where each node holds a pointer to an int; returns 1 if any node's value equals the search key `a2`, 0 otherwise. Updates iterator field during traversal.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleFilteringSelection (004c4990), VehicleGridSelection (004c4aa0), FilterPropertiesListBuilder (004c5e50), FilterPropertiesListBuilder_5fd0 (004c5fd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10) | 0x0 | R | — | Data value in iterator's current node (dereferenced for comparison) |
| this | 0x8 | R | — | Head pointer of linked list |
| this | 0x10 | RW | — | Current iteration pointer; advanced through list during search |
| this | 0x14 | R | — | Count of items (read but not used in search logic) |

**Written-by note (persistence):**
- this 0x10: rewritten each step as traversal advances; final value is either the matching node or last node visited

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Returns 0 immediately if `this[2]` (head) is null or `*head` (first node's data pointer) is null. Iterates comparing `a2` against `*node_data`; returns 1 on match, 0 if list exhausted.
