## SceneGraph_0054a770 — Scene graph node destructor / resource cleanup

**Summary:** Destructor/cleanup for a scene graph node. Frees three separate linked lists/arrays: (1) nodes at this+0x204 with next at +0x10 — each unlinked and freed via QueueResourceCleanup, DoublyLinkedListUnlink, FreeWrapper; (2) conditionally calls FieldCleanupWithNullCheck and LinkedNodeDestruction on child resources; (3) nodes at this+0x224 with next at +0x04 — freed in a loop; (4) array at this+0x22C (56-byte stride) — iterates calling EmptyStub_0170 per element then freed. All pointers zeroed after cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_3DSoundSourceDestructor (00545150), sub_549110 (00549110), sub_557670 (00557670), SceneNode (0055a910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1E0 | R | — | Check for child resource requiring LinkedNodeDestruction |
| this | 0x1EC | R | — | Check for child resource requiring FieldCleanupWithNullCheck |
| this | 0x204 | R | — | Head of first linked list of resources to clean up |
| this | 0x214 | R | — | Accessed by callee during cleanup |
| this | 0x224 | RW | 0 | Head of second linked list of resources to clean up; zeroed after |
| this | 0x228 | R | — | Accessed by callee during cleanup |
| this | 0x22C | RW | 0 | Pointer to 56-byte stride array of structures; freed and zeroed |

**Written-by note (persistence):**
- this 0x224: set to 0 after second linked list is drained and freed (destructor, not persistent)
- this 0x22C: set to 0 after array is freed (destructor, not persistent)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | Called per element of 56-byte stride array during cleanup |
| 0054ac30 | DoublyLinkedListUnlink_ac30 | Unlink node from doubly linked list before freeing |
| 0054c410 | QueueResourceCleanup | Queue resource for deferred cleanup before unlinking |
| 0054fa50 | LinkedNodeDestruction | Destroy linked child node structure |
| 00561940 | FieldCleanupWithNullCheck | Clean up field with null safety check |
| 00587bcf | FreeWrapper_7bcf | Free allocated memory via deallocation wrapper |

**Guard conditions:** Each cleanup step guarded by null check: `this[0x204]` must be non-null for first list walk; `this[0x1EC]` for FieldCleanupWithNullCheck; `this[0x1E0]` for LinkedNodeDestruction; `this[0x224]` for second list walk; `this[0x22C]` for array cleanup. Null field BLOCKS that cleanup step entirely.
