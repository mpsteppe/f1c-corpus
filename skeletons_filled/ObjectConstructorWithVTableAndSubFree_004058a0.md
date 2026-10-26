## ObjectConstructorWithVTableAndSubFree_004058a0 — ObjectCleanupWithVTableSwapAndSubFree

**Summary:** Releases audio resource, removes node from linked list by key, swaps vtable pointer, and conditionally frees child allocation at offset 0x4.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithConditionalFree (00405880)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer (swapped from ObjectVTable to SwapVTable) |
| this | 0x4 | R | — | Pointer to child allocation, checked before free |

**Written-by note (persistence):**
- this 0x0: once (vtable set, then swapped to different vtable; survives as final value)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e490 | off_59E490 | R | VTable_Object_59E490 [DERIVED] |
| 0059e4b4 | off_59E4B4 | R | VTable_0059e490_Swap [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405b00 | AudioResourceRelease | Release audio resource associated with this object |
| 00407be0 | LinkedListNodeRemovalByKey | Remove this node from linked list key lookup |
| 00587bcf | FreeWrapper_7bcf | Free child allocation at this[1] if non-null |

**Guard conditions:** Checks if `this[1]` (offset 0x4) is non-null. If non-null, PASSES: calls FreeWrapper_7bcf to free the child allocation. If null, BLOCKED: skips free entirely.
