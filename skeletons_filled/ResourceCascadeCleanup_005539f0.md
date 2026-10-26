## ResourceCascadeCleanup_005539f0 — ResourceCascadeCleanup

**Summary:** Unlinks a node from a doubly-linked list, then conditionally calls cleanup handler and frees the node. Generic resource cleanup cascading through list removal, custom cleanup, and deallocation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionSystemShutdownCleanup (00494900), ConditionalDualCleanup (00499b50), ShortComputation_ec40 (0049ec40), SingleFieldFreeWrapper (0049eca0), AudioResourceReleaseByType (004d9030), ResourceCleanup_cd10 (004dcd10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00553310 | ConditionalResourceCleanup_3310 | Resource-specific cleanup/release handler |
| 0055c2e0 | DoublyLinkedListNodeUnlinkByMatch | Removes node from its doubly-linked list |
| 00587bcf | FreeWrapper_7bcf | Heap deallocation / free |

**Guard conditions:** If a1 is null, only unlink is attempted (would likely crash). The conditional cleanup and free are guarded: only execute if a1 is non-null.
