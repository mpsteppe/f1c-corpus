## WideStringComparisonWalkingLinkedList_00551830 — LinkedListNodeStringMatchFind

**Summary:** Walks linked list starting at this+0x13C, comparing each node's name string against the given key, returning the first matching node pointer or 0 if not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A22D0 (004a22d0), VehicleGraphicsSceneLoader (004dfce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x160) | 0x1C | R | — | Node's name field pointer (v2+28 → deref → +28 to name string) |
| *(this+0x160) | 0x24 | R | — | Node's next pointer (v2+36 = 0x24) for list traversal |
| this | 0x13C | R | — | Linked list head pointer (this[79]) — start of walk |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** 
- this[79] == 0: empty list → return 0 immediately. PASS when non-null.
- *(v2+36) == 0 during walk: reached end without match → return 0. PASS when non-null.
- strcmp(a2, *(v2+28)+28) == 0: match found → return v2. PASS when match found (loop exit), BLOCKED while mismatch.
