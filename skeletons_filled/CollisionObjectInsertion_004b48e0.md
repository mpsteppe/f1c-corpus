## CollisionObjectInsertion_004b48e0 — CollisionObjectTypeDispatchInsert

**Summary:** Inserts a collision object into one of 4 type-specific sub-lists based on its 3-bit type tag (extracted from header bits [31:29]). Allocates or reuses a free node from the pool, creates a 12-byte linked list entry, links into sub-list at offset 112 + index*64. Called from PitStallProximityCheck for pit collision zone management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitStallProximityCheck (004b5da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Enable/disable flag — if zero, function returns 0 immediately |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004b4a10 | jpt_4B4900 | R | Jump table for type tag → list index mapping |
| 008ab6f0 | dword_8AB6F0 | R | AudioBucketListHead — active list head (checked for existing nodes) |
| 008ab700 | dword_8AB700 | R | FreeListHead — free pool list for node reuse |
| 008ab708 | dword_8AB708 | R | GlobalAllocPoolNode — anchor node for free list allocation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3a90 | ArithmeticComparison_3a90 | Process/compare collision data into the allocated node buffer |
| 004b4760 | ArithmeticComparison_4760 | Validate insertion — returns non-zero to block/abort |
| 004b47a0 | ArithmeticComparison_47a0 | Finalize insertion (increment count, update list metadata) |
| 004ba780 | ShortComputation_a780 | Check free list availability |
| 004ba950 | ConditionalAllocation | Allocate new data buffer for node (when free list empty) |
| 004bac40 | LinkedListNodeInsertion_ac40 | Insert freshly allocated node into free list |
| 004bacf0 | LinkedListNodeRemoval_acf0 | Remove node from free list for use |
| 004bb6b0 | sub_4BB6B0 | Validate/initialize free list node buffer |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 4-byte header block or 12-byte linked list node struct |

**Guard conditions:**
1. If this[0] flag is zero: return 0 immediately (subsystem disabled).
2. Type tag from a2[0] bits [31:29]: maps to index 0-3; if tag is invalid (case 0, 5, 7): index -1, which ArithmeticComparison_4760 rejects (returns 0).
3. If ArithmeticComparison_4760 returns non-zero: return 0 (insertion blocked by validation).
4. Free node allocation: first tries pool reuse via dword_8AB708; if fails, allocates new block. If v4 ends up null after all attempts: return 0.
5. If 12-byte linked list node allocation (v7) fails: node not linked, but v6 list pointers still advance.
