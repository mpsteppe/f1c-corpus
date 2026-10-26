## sub_685BBE_00685bbe — matching-node edge table updater

**Summary:** Walks the node chain (node+8 links, each step redirected through node+0x38 when set) and, for every node whose id at +4 equals a2[0], updates the a2 tables: combined index from a2[0x4C] + a2[0x50] stamped into a2[0x54] and a 12-byte edge record in a2[0x58] keyed by a4, with endpoint pairs taken directly from the node (link tags 0x20700000 / 0x20800000 / 0x11500000) or from the node referenced by the link's +0x10 pointer otherwise; intermediate chain nodes flagged via this[4] object byte+5 sign bit override the stored endpoints and raise the node's +0x58 maximum. Returns a2.

**Called by:** ShortComputation_d4d0 [structural] (00685d41), sub_68E047 (0068e047), sub_68E712 (0068e712)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | array of per-object records (this[4]); the sign bit of byte +5 is checked on nodes encountered during the backward walk |
| this | 0x14 | R | — | node array (this[5]); nodes carry id +4, sibling/next +8, endpoints +0x14/+0x18, link id +0x48, index +0x74, max +0x58 |
| this | 0x18 | R | — | link record array (this[6]); record tag = first dword & 0xFFF00000, +0x10 points to a node index holder |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Loop runs while a3 != -1; at each step a3 is redirected to node[a3]+0x38 when that field != -1. Body work happens only when node+4 == *a2 (id match). The table writes require a2[0x58] (result[22]) != 0. The backward chain walk runs from the stored +4 word while it != node+0x14; an override is applied only for nodes whose object record (this[4][node+4]) has a negative byte at +5 (sign bit set). After the walk a3 continues at node+8; -1 terminates.
