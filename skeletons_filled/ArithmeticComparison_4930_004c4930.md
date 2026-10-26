## ArithmeticComparison_4930_004c4930 — SceneListAndDataCleanup

**Summary:** Destructor that cleans up scene list and associated data. Calls SceneListCleanup on primary pointer, then walks a linked list at this+0x8 freeing nodes and their data payloads (guarded by ownership flag at node+8). Zeros all list pointers at offsets 0x8 through 0x14 and frees the primary pointer at offset 0x0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | primary scene list pointer, freed via SceneListCleanup then FreeWrapper |
| this | 0x8 | RW | 0 | linked list head pointer, walked for per-node cleanup |
| this | 0xC | RW | 0 | list auxiliary pointer, zeroed after walk |
| this | 0x10 | RW | 0 | list auxiliary pointer, zeroed after walk |
| this | 0x14 | RW | 0 | list auxiliary pointer, zeroed after walk |

**Written-by note (persistence):**
- this 0x8: set to 0 unconditionally — external poke survives (invalidated after cleanup)
- this 0xC: set to 0 unconditionally — external poke survives
- this 0x10: set to 0 unconditionally — external poke survives
- this 0x14: set to 0 unconditionally — external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c4cf0 | SceneListCleanup | cleanup/release scene list resources |
| 00587bcf | FreeWrapper_7bcf | deallocate memory block |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | == | 0 | auxiliary pointer, zeroed as part of cleanup completion |

**Guard interpretation:** Linked list walk at this+0x8 runs only if head pointer is non-null. Each node's ownership flag at node+8 guards data pointer cleanup (non-zero = free data). The auxiliary pointer at this+0x10 being zero indicates cleanup has been performed. BLOCKED: null head pointer at this+0x8 skips entire list walk.
