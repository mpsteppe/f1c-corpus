## AudioNetworkNodeCount_005452f0 — Count nodes across two audio/scene linked lists

**Summary:** Walks two linked lists — first a chain of audio network nodes (head at 0x100) counting all sub-nodes in each, then a second list (head at 0x108) counting standalone nodes. Returns total count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40FE50 (0040fe50), AnimationPlaybackSequence (0044acb0), SceneExtentComputation (004bdc10), NetworkMessageReceiveAndDispatch (004c7ca0), SpecialFX_Init (004cf070), sub_4FBA10 (004fba10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x204)+0xEC)+0x4C) | 0x4C | R | — | Forward link of child/sub-nodes within each audio network node |
| *(this+0x154) | 0x4C | R | — | Forward link of nodes in second list |
| *(this+0x204) | 0xEC | R | — | Head of sub-node list within each audio network node |
| *(this+0x204) | 0x104 | R | — | Forward link between audio network nodes |
| this | 0x100 | R | — | Head of first linked list (audio network node chain) |
| this | 0x108 | R | — | Head of second linked list (standalone nodes) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — both lists traversed unconditionally until null terminator reached.
