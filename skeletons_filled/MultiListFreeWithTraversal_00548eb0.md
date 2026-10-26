## MultiListFreeWithTraversal_00548eb0 — MultiLinkedListFreeWithTraversal

**Summary:** Frees 5 linked lists rooted at offsets 0xE8, 0xEC, 0xF0, 0xF8, and 0xFC. Each list is traversed, every node freed (via EmptyStub_0170 + FreeWrapper_7bcf, or sub_549110 for the list at offset 0xEC), then the root pointer is zeroed.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestroyFree (0054a240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE8 | RW | 0 | Root pointer for linked list 1 (next ptr at offset 0x14) |
| this | 0xEC | RW | 0 | Root pointer for linked list 5 (next ptr at offset 0x4C, freed via sub_549110) |
| this | 0xF0 | RW | 0 | Root pointer for linked list 2 (next ptr at offset 0x34) |
| this | 0xF8 | RW | 0 | Root pointer for linked list 3 (next ptr at offset 0x14) |
| this | 0xFC | RW | 0 | Root pointer for linked list 4 (next ptr at offset 0x14) |
| this | 0x10C | R | — | unknown |
| this | 0x110 | R | — | unknown |
| this | 0x124 | R | — | unknown |
| this | 0x138 | R | — | unknown |

**Written-by note (persistence):**
- this 0xE8: Set to 0 after freeing list 1; external poke survives
- this 0xEC: Set to 0 after freeing list 5; external poke survives
- this 0xF0: Set to 0 after freeing list 2; external poke survives
- this 0xF8: Set to 0 after freeing list 3; external poke survives
- this 0xFC: Set to 0 after freeing list 4; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | No-op stub called before each node free (likely debug/validation hook) |
| 00549110 | sub_549110 | Free function for list 5 nodes (different allocation scheme from standard heap) |
| 00587bcf | FreeWrapper_7bcf | Standard heap free wrapper for lists 1-4 |

**Guard conditions:** Each list root pointer is checked for non-null before traversal. If null, that list is skipped. Traversal loop reads next pointer at fixed offsets (0x14 for lists 1,3,4; 0x34 for list 2; 0x4C for list 5) until NULL terminates the chain.
