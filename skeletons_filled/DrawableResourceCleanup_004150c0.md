## DrawableResourceCleanup_004150c0 — DrawableResourceCleanup

**Summary:** Cleans up three linked lists of drawable resources (text format entries, multi-field entries, text format 4fe0 entries) by iterating each, freeing active entries via type-specific destructors, then zeroing list heads and counters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GlobalListTripleCleanupWithTimerRemoval (00414210), ShortComputation_8900 (00418900)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x4) | 0x4 | R | — | Next pointer in list node (offset +4) for traversal |
| *(this+0x14) | 0x4 | R | — | Next pointer in second list node |
| *(this+0x24) | 0x4 | R | — | Next pointer in third list node |
| obj | 0x0 | R | — | Pointer to the actual resource struct stored in the list node |
| obj | 0x8 | R | — | Flag byte at offset +8: 0 = skip, non-zero = active entry |
| this | 0x0 | RW | 0 | First list head pointer, zeroed after cleanup |
| this | 0x4 | RW | 0 | First list tail pointer, zeroed after cleanup |
| this | 0x8 | RW | 0 | First list count/length, zeroed after cleanup |
| this | 0xC | RW | 0 | First list tracking field, zeroed after cleanup |
| this | 0x10 | RW | 0 | Second list head pointer, zeroed after cleanup |
| this | 0x14 | RW | 0 | Second list tail pointer, zeroed after cleanup |
| this | 0x18 | RW | 0 | Second list count/length, zeroed after cleanup |
| this | 0x1C | RW | 0 | Second list tracking field, zeroed after cleanup |
| this | 0x20 | RW | 0 | Third list head pointer, zeroed after cleanup |
| this | 0x24 | RW | 0 | Third list tail pointer, zeroed after cleanup |
| this | 0x28 | RW | 0 | Third list count/length, zeroed after cleanup |
| this | 0x2C | RW | 0 | Third list tracking field, zeroed after cleanup |

**Written-by note (persistence):**
- this 0x0: unconditional after first list cleaned; set to 0
- this 0x4: unconditional after first list cleaned; set to 0
- this 0x8: unconditional after first list cleaned; set to 0
- this 0xC: unconditional after first list cleaned; set to 0
- this 0x10: unconditional after second list cleaned; set to 0
- this 0x14: unconditional after second list cleaned; set to 0
- this 0x18: unconditional after second list cleaned; set to 0
- this 0x1C: unconditional after second list cleaned; set to 0
- this 0x20: unconditional after third list cleaned; set to 0
- this 0x24: unconditional after third list cleaned; set to 0
- this 0x28: unconditional after third list cleaned; set to 0
- this 0x2C: unconditional after third list cleaned; set to 0

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00414370 | ShortComputation_4370 | R | Function pointer used as element-wise array destructor callback for sub-arrays within resource structs |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401030 | ArrayDestructorIterator | Iterates and destroys array elements via callback; used on first and third list sub-arrays |
| 00414370 | ShortComputation_4370 | Element-wise destructor callback for sub-array cleanup |
| 00414380 | MultiFieldPointerFree | Frees multi-field pointer struct for second list entries |
| 004149a0 | TextFormatStructInitializer | Resets/initializes text format struct for first list entries before destruction |
| 00414fe0 | TextFormatStructInitializer_4fe0 | Resets/initializes text format struct variant for third list entries before destruction |
| 00587bcf | FreeWrapper_7bcf | Wrapper around free() for releasing list node allocations and inner resource structs |

**Guard conditions:** Each list node has flag byte at offset +8: if byte == 0, the entry is skipped (inner resource struct not freed); if byte != 0 AND inner pointer at offset +0 is non-null, the inner struct is destructed then freed. All list node allocations are freed regardless of flag. List iteration stops at null next-pointer (offset +4 == 0).
