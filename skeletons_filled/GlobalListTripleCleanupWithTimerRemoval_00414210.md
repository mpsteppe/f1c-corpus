## GlobalListTripleCleanupWithTimerRemoval_00414210 — GlobalListTripleCleanupWithTimerRemoval

**Summary:** Cleans up three global linked lists (geometries/resources, multi-field pointers, text format entries) by iterating each, freeing valid (flag=1) entries via type-specific destructors, then zeroing all head pointers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00414370 | ShortComputation_4370 | R | Function pointer used as element-wise array destructor callback in third list cleanup |
| 005ea5e8 | dword_5EA5E8 | RW | MemoryCleanupList3 [DERIVED] — first list head (drawable resource entries) |
| 005ea5ec | dword_5EA5EC | W | First list tail pointer, zeroed after cleanup |
| 005ea5f0 | dword_5EA5F0 | W | First list count/length, zeroed after cleanup |
| 005ea5f4 | dword_5EA5F4 | W | First list tracking field, zeroed after cleanup |
| 005ea5f8 | dword_5EA5F8 | RW | ResourceList_Geom [DERIVED] — second list head (multi-field pointer entries) |
| 005ea5fc | dword_5EA5FC | W | Second list tail pointer, zeroed after cleanup |
| 005ea600 | dword_5EA600 | W | Second list count/length, zeroed after cleanup |
| 005ea604 | dword_5EA604 | W | Second list tracking field, zeroed after cleanup |
| 005ea608 | dword_5EA608 | RW | DestroyLinkedListHead1 [DERIVED] — third list head (text format entries) |
| 005ea60c | dword_5EA60C | W | Third list tail pointer, zeroed after cleanup |
| 005ea610 | dword_5EA610 | W | Third list count/length, zeroed after cleanup |
| 005ea614 | dword_5EA614 | W | Third list tracking field, zeroed after cleanup |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401030 | ArrayDestructorIterator | Iterates and destroys array elements via callback; used on third list's sub-arrays |
| 00414370 | ShortComputation_4370 | Element-wise destructor callback for array iteration in third list |
| 00414380 | MultiFieldPointerFree | Frees multi-field pointer struct for second list entries |
| 00414420 | MultiPointerFree | Frees multi-pointer struct for first list entries |
| 004149a0 | TextFormatStructInitializer | Resets/initializes text format struct for third list entries before destruction |
| 004150c0 | DrawableResourceCleanup | Called on first list head to begin cleanup of drawable resources |
| 00587bcf | FreeWrapper_7bcf | Wrapper around free() for releasing list node allocations and inner pointers |

**Guard conditions:** Each list node has flag byte at offset +8: if byte == 0, the entry is skipped (no inner-pointer freeing); if byte != 0, inner pointer at offset +0 is dereferenced and freed. All nodes are freed regardless of flag. List iteration stops at null next-pointer (offset +4 == 0).
