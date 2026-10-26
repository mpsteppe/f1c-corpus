## F_3DSoundSourceDestructor_00545150 — 3D sound source destructor with scene graph cleanup

**Summary:** Destructor for a 3D sound source object (`a2`) in the audio system (`this`). Recursively frees sub-sound sources, checks scene graph association, cleans up audio buffer/resource at offset 0x230, nulls references in manager's registration array, removes from linked list, and frees memory.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A2220 (004a2220), ArrayResourceCleanup (004a29a0), sub_4D0080 (004d0080), VehicleResetClear (004e09e0), ResourceCleanupDestructionForDirectXObjects (00543bf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14C | R | — | Manager's registration array count (number of registered entries) |
| this | 0x150 | R | — | Pointer to array of registered sound source entries (24 bytes each) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00545150 | F_3DSoundSourceDestructor | Recursive self-call for child/sub-sound sources |
| 005452b0 | LinkedListRemove | Remove sound source from linked list |
| 005459d0 | LinkedListRemove_59d0 | Alternative linked-list removal for buffer resource |
| 0054a710 | TwoFunctionCallChain | Object destructor/cleanup chain |
| 0054a770 | SceneGraph | Scene graph query — non-zero return aborts destruction |
| 00560c00 | StateFlagSetterCleanup | State flag cleanup on buffer resource |
| 00560e50 | MultiFieldObjectDestructorWithCleanupCalls | Multi-field destructor for buffer resource at offset 0x230 |
| 00560f10 | DoublyLinkedListNodeUnlink_0f10 | Unlink buffer resource from doubly-linked list |
| 00587bcf | FreeWrapper_7bcf | Free heap memory |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14C | > | 0 | Array entry count |

**Guard interpretation:** When `this[83] > 0` (manager has registered entries), iterate through array and null any reference matching `a2`. When <= 0, skip array scan entirely.
