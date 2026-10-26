## ArithmeticComparisonBinarySearch_005477f0 — String search in linked list

**Summary:** Walks linked list starting at this+0x24 (via node[48] at offset 0xC0), compares each node's string with a2 using strcmp. Returns matching node pointer or 0 if not found. Resource manager name-based lookup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXMeshVertexBufferParsingAndLoading (00547b40), D3DTextureResourceCreation (00548190), sub_54C510 (0054c510)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xE4) | 0xC0 | R | — | next pointer at node+0xC0 (linked list traversal) |
| this | 0x24 | R | — | linked list head pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If this+0x24 (list head) is null, BLOCKED: return 0 immediately (empty list). Otherwise walk list via node[48] (offset 0xC0) comparing strings via strcmp. If match found, PASSES: return node pointer. If traversal ends without match, return 0.
