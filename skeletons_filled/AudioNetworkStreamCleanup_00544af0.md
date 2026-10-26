## AudioNetworkStreamCleanup_00544af0 — AudioNetworkStreamCleanup

**Summary:** Cleans up audio network stream resources: releases array of sub-streams (stride 96, count at this[88]) with flag 0x100000, destroys stream handle globals (dword_8B8DBC, dword_8B8DC0), checks tree active states for linked lists at this[64] and this[66], processes texture flags at this[82], and finalizes with sub_540760.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderTargetCleanup (0053f270), ResourceCleanupDestructionForDirectXObjects (00543bf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1EC)+0x4C) | 0x4C | R | — | field on child node at this[123]; checked via TreeActiveCheck |
| *(this+0x154) | 0x4C | R | — | field on node at this[85]; checked via TreeActiveCheck |
| *(this+0x1B0) | 0x68 | R | — | field on node at this[108]; checked via TreeActiveCheck |
| *(this+0x204) | 0x104 | R | — | next pointer +104 at this[129]; iterated for texture flag test |
| this | 0xEC | RW | — | flags field; bit 0x100000 cleared after array cleanup |
| this | 0x100 | R | — | array element count (this[64]) for linked list traversal |
| this | 0x108 | R | — | tree/node count (this[66]) for second traversal |
| this | 0x148 | R | — | linked list head (this[82]) for texture flag iteration |
| this | 0x160 | RW | 0 | array data pointer (this[88]) — sub-stream array to destroy |
| this | 0x164 | RW | 0 | array element count (this[89]) |
| this | 0x1EC | R | — | linked list head (this[123]) for first traversal |

**Written-by note (persistence):**
- this 0xEC: bit 0x100000 cleared each call; other bits survive
- this 0x160: zeroed after array cleanup
- this 0x164: zeroed after array cleanup

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager singleton pointer |
| 008b8dbc | dword_8B8DBC | RW | audio stream handle A — freed and zeroed |
| 008b8dc0 | dword_8B8DC0 | RW | audio stream handle B — freed and zeroed |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540760 | sub_540760 | finalize audio network stream cleanup |
| 00541420 | SubBufferFree | free sub-buffer allocated for stream |
| 00542e50 | sub_542E50 | destroy/release audio emitter handle |
| 00544e20 | TreeActiveCheck | check if tree node is still active (blocks cleanup if active) |
| 005478b0 | DoublyLinkedListNodeRemovalWithArrayCleanup | remove and clean up linked list node for array |
| 005502c0 | DestructorWithConditionalFreeFlagClear | destruct array elements with conditional free |
| 00557470 | EmptyStub_7470 | stub function called before freeing |
| 00557630 | TextureFlagTestWithDispatch | test/clear texture flags on linked list nodes |
| 00587bcf | FreeWrapper_7bcf | free/deallocate memory wrapper |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x160 | > | 0 | this[88] — array data pointer; skip array cleanup when zero |

**Guard interpretation:** BLOCKED array cleanup when this[88] is 0 (no array allocated) or flag 0x100000 not set. BLOCKED first traversal when this[64] is 0 (skipped). BLOCKED second traversal when this[66] is 0 (skipped). TreeActiveCheck returning 0 blocks cleanup (returns -1, node still active).
