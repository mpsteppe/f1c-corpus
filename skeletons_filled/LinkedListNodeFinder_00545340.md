## LinkedListNodeFinder_00545340 — Find Nth node across two hierarchical linked lists

**Summary:** Walks two linked lists — first a chain of audio network nodes (head at 0x100) with per-node sub-lists, then a second list (head at 0x108) — and returns the pointer to the node at index `a2`. Returns 0 if index exceeds total nodes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40FE50 (0040fe50), AnimationPlaybackSequence (0044acb0), VehicleSceneLoadAndPositionTires (004681b0), SceneExtentComputation (004bdc10), NetworkMessageReceiveAndDispatch (004c7ca0), SpecialFX_Init (004cf070), sub_4FBA10 (004fba10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1EC)+0x4C) | 0x4C | R | — | Forward link of sub-nodes within each audio network node |
| *(this+0x154) | 0x4C | R | — | Forward link of nodes in second list |
| *(this+0x204) | 0x104 | R | — | Forward link between audio network nodes |
| this | 0x100 | R | — | Head of first list (audio network node chain) |
| this | 0x108 | R | — | Head of second list (standalone nodes) |
| this | 0x1EC | R | — | Intermediate traversal pointer to sub-list root |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `this[64]` (head of first list) non-null check: PASSES (traverse first list + sub-lists) when head exists; BLOCKED (skip to second list traversal) when null. Sub-list null check: PASSES (walk sub-nodes) when sub-list head at offset 0xEC is non-null; BLOCKED (go to next audio network node) when null.
