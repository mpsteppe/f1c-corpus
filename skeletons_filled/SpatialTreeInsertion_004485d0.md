## SpatialTreeInsertion_004485d0 — SpatialTreeInsertion

**Summary:** Inserts or locates a node in a 96-byte-node spatial tree data structure. Traverses using float/double key components (offsets 0, 4, 12): exact match returns existing node; float match without double match follows chain child at offset 0x5C; otherwise computes 4-way branch index from float-at-offset-12 comparison and descends into branch slot at offset 0x4C-0x58. Allocates new nodes via OperatorNewNhMallocWrapper when traversal hits a null slot. Called from TriangleMeshAdjacencyBuilder.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TriangleMeshAdjacencyBuilder (004493a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | float key component 0 (compared for match) |
| this | 0x4 | R | — | double key component (compared for exact match) |
| this | 0xC | R | — | float key component 3 (compared for match and branch direction) |
| this | 0x5C | RW | — | chain child pointer (used when floats match but double differs) |

**Written-by note (persistence):**
- this 0x5C: written when new node allocated and linked; persists as tree edge until node freed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00448510 | QuaternionRotationStructureInitialize | initializes newly allocated 96-byte tree node from input |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 96-byte tree node |

**Guard conditions:** Comparison of input key fields against current node: exact match (all three equal) returns current node pointer. Float match (offsets 0 and 12 equal) without double match descends to chain child at 0x5C (if non-null) or allocates new node there. Float mismatch computes branch index (0-3) from float-at-offset-12 comparison using FPU condition flags; descends to branch slot at offset 0x4C+v8*4 if non-null, otherwise allocates new node and links at that slot.
