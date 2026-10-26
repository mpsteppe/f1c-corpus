## SceneNodeDecoder_00410f60 — SceneNodeTransformDecoder

**Summary:** Decodes packed transform data from a 36-byte input buffer into 6 scaled float values, then dispatches to an indexed scene node object via sub_54B4D0. The 6-bit type field selects one of 6 node groups (offsets 0x24-0x68), validates the node index, looks up a target pointer (computed as base + 792/808*idx + 208), and if non-null, unpacks position/rotation floats.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListIteratorWithStateUpdate (004b5760)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | node group 1 count (type 1) |
| this | 0x2C | R | — | node group 1 base plus 208 offset (type 1) |
| this | 0x30 | R | — | node group 2 count (type 2) |
| this | 0x38 | R | — | node group 2 base (type 2) |
| this | 0x3C | R | — | node group 3 count (type 3) |
| this | 0x44 | R | — | node group 3 base plus 208 offset (type 3) |
| this | 0x48 | R | — | node group 4 count (type 4) |
| this | 0x50 | R | — | node group 4 base (type 4, stride 808) |
| this | 0x54 | R | — | node group 5 count (type 5) |
| this | 0x5C | R | — | node group 5 base plus 208 offset (type 5) |
| this | 0x60 | R | — | node group 6 count (type 6) |
| this | 0x68 | R | — | node group 6 base (type 6) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00411100 | jpt_410F7B | R | jump table for switch on 6-bit type field (cases 1-6) |
| 0059e77c | flt_59E77C | R | ShortVertexScale [DERIVED] — scale factor 0.00048828125 for rotation floats |
| 0059e780 | flt_59E780 | R | VertexScaleFactor [DERIVED] — scale factor 0.000030517578 for position floats |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b4d0 | sub_54B4D0 | processes decoded transform data (6 floats: position + rotation) on target node |

**Guard conditions:** if 6-bit type not in 1-6 → early return (default). Within each case: node index at a2+8 bounds-checked against group count. If target pointer resolve yields null → skip transform decode entirely.
