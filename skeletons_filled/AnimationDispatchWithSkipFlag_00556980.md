## AnimationDispatchWithSkipFlag_00556980 — AnimationChannelDispatchWithFlagFilter

**Summary:** Iterates a linked list of animation nodes from `this+0x204`. Calls sub_54B570 for setup; if skip flag at this+0x3C bit 4 is clear, processes each node: optionally clears flag bits (0x20000028) based on sub_54B570 result, then dispatches to SceneNodeStateUpdateWithTransform or sub_556B10 depending on node property at offset 0x13C. Part of animation/scene update system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RecursiveStateTraversalWithFlagCheck (00556930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x204) | 0x20 | R | — | flags field in animation node (bit 0x200000 checked as skip condition) |
| *(this+0x204) | 0x24 | RW | — | flags field cleared of bits 0x20000028 when sub_54B570 result is set |
| *(this+0x204) | 0x14C | R | — | node capability flag: non-zero means use SceneNodeStateUpdateWithTransform, else sub_556B10 |
| this | 0x3C | R | — | skip flag byte; bit 4 set means skip entire animation dispatch |
| this | 0x204 | R | — | pointer to linked list of animation channel nodes |

**Written-by note (persistence):**
- *(this+0x204) 0x24: flag bits 0x20000028 cleared if sub_54B570 returns non-zero (conditional per-frame modification)

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b570 | sub_54B570 | setup/check function; return value controls flag clearing |
| 005569f0 | SceneNodeStateUpdateWithTransform | update scene node with transform (used when node has property at offset 0x13C) |
| 00556b10 | sub_556B10 | update scene node without transform (fallback when offset 0x13C is zero) |

**Guard conditions:** 
1. `(*(_BYTE *)(this + 60) & 4) != 0` (bit 4 set at this+0x3C) → skip entire dispatch, return early
   PASSES: bit 4 clear → enter loop
2. Node pointer `i` (from *(this+0x204)) is null → loop ends (empty list)
3. `(i[5] & 0x200000) != 0` → skip this node (bit 0x200000 set means node is skipped)
   PASSES: bit clear → dispatch to SceneNodeStateUpdateWithTransform or sub_556B10
4. `v4` (sub_54B570 return) non-zero → clear bits 0x20000028 from node flags at offset 0x24