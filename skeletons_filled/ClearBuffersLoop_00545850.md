## ClearBuffersLoop_00545850 — Clear scene graph flag across all audio network and linked nodes

**Summary:** Iterates through all audio network nodes and their sub-nodes, then through a second linked list, calling BitmaskClear and SceneGraphFlagPropagation (flag 0x10000000) on each node to clear a scene graph flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_557120 (00557120)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x204)+0xEC)+0x4C) | 0x4C | R | — | Forward link of sub-nodes within each audio network node |
| *(this+0x154) | 0x4C | R | — | Forward link of nodes in second list |
| *(this+0x204) | 0xEC | R | — | Head of sub-node list within each audio network node |
| *(this+0x204) | 0x104 | R | — | Forward link between audio network nodes |
| this | 0x100 | R | — | Head of first list (audio network node chain) |
| this | 0x108 | R | — | Head of second list |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b2c0 | SceneGraphFlagPropagation | Propagate scene graph flag (clear bit 0x10000000) |
| 0054b330 | BitmaskClear | Clear 32-bit bitmask |

**Guard conditions:** No guard — iterates all nodes while non-null. Inner loop skips when sub-list head at offset 0xEC is null.
