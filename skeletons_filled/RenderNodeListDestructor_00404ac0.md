## RenderNodeListDestructor_00404ac0 — RenderNodeListDestructor

**Summary:** Destructor that frees a linked list of render nodes (each with optional conditional data cleanup), followed by freeing up to three auxiliary buffers at offsets 0x28/0x30/0x38, then frees the main object itself.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x40)+0x4) | 0x4 | R | — | linked list node: next pointer |
| *(obj+0x40) | 0x0 | R | — | linked list node: data pointer (checked for conditional free) |
| *(obj+0x40) | 0x8 | R | — | linked list node: byte flag indicating whether data needs conditional cleanup |
| obj | 0x28 | R | — | auxiliary buffer pointer 1 (freed if non-null) |
| obj | 0x30 | R | — | auxiliary buffer pointer 2 (freed if non-null) |
| obj | 0x38 | R | — | auxiliary buffer pointer 3 (freed if non-null) |
| obj | 0x40 | RW | 0 | linked list head pointer (zeroed after traversal) |
| obj | 0x44 | RW | 0 | linked list tail or count (zeroed after traversal) |
| obj | 0x48 | RW | 0 | linked list field (zeroed after traversal) |
| obj | 0x4C | RW | 0 | linked list field (zeroed after traversal) |
| this | 0x0 | R | — | pointer to the main object to destroy |

**Written-by note (persistence):**
- obj 0x40: zeroed once during destruction (list head)
- obj 0x44: zeroed once during destruction
- obj 0x48: zeroed once during destruction
- obj 0x4C: zeroed once during destruction

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f70 | ConditionalFreeWithBit0Flag | conditionally frees memory based on bit-0 flag check |
| 00587bcf | FreeWrapper_7bcf | standard heap free wrapper |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(obj+0x40) | 0x8 | == | 0 | byte flag on each list node: 0 = skip conditional data free, non-zero = check and free data |

**Guard interpretation:** For each node in the linked list: if node byte at +8 != 0 AND node data at +0 is non-null, calls ConditionalFreeWithBit0Flag(1). Nodes with byte at +8 == 0 skip the conditional data free. All nodes are always freed via FreeWrapper_7bcf regardless. Auxiliary buffers at offsets 0x28/0x30/0x38 are freed only if non-null.
