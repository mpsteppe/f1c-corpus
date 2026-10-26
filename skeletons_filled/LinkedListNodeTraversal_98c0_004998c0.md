## LinkedListNodeTraversal_98c0_004998c0 — Iterator advance via node offset 0x48

**Summary:** Advances linked-list iterator: reads next node pointer at offset 0x48 from current node, updates iterator position. Returns true if more nodes remain. Part of linked-list iteration utility.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_499910 (00499910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | current iterator node — replaced with next node (via node+0x48) |
| this | 0x5C | R | — | unknown — field read but not visible in decompiled body |

**Written-by note (persistence):**
- this 0x14: updated destructively each call; persists as iterator position

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14 | != | 0 | current node pointer — non-null when more nodes remain |

**Guard interpretation:** PASSES when `this+0x14 != 0` — reads next node via node+0x48, updates iterator, returns true. BLOCKED when `this+0x14 == 0` — returns false (end of list).
