## sub_4FCA50_004fca50 — LinkedPointerListRelease

**Summary:** Walks a linked list starting at this+0x54, freeing each node's internal pointer (if flag at node+8 is non-zero) and the node itself via FreeWrapper_7bcf. Clears all four tracking fields at offsets 0x54-0x60 after cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x58) | 0x4 | R | — | node's next pointer (offset 4 within node) |
| this | 0x54 | RW | 0 | linked list head pointer (iterated, then cleared) |
| this | 0x58 | RW | 0 | linked list / node field (cleared to 0) |
| this | 0x5C | RW | 0 | guard / state field (cleared to 0 after cleanup) |
| this | 0x60 | RW | 0 | linked list tracking field (cleared to 0) |

**Written-by note (persistence):**
- this 0x54: conditionally iterated then unconditionally set to 0
- this 0x58: unconditionally set to 0
- this 0x5C: unconditionally set to 0
- this 0x60: unconditionally set to 0

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | heap memory deallocation (frees nodes and internal pointers) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x5C | == | 0 | guard / state flag indicating cleanup needed |

**Guard interpretation:** PASSES (cleanup executes) when this+0x5C is non-zero (not equal to 0) — list needs cleanup. BLOCKED (early skip) when this+0x5C == 0 — list already cleaned. Loop itself guards on this+0x54 (head pointer) being non-null.
