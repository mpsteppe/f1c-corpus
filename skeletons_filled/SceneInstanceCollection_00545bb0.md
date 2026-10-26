## SceneInstanceCollection_00545bb0 — Rebuild filtered array of scene instance nodes

**Summary:** Rebuilds a filtered array of 24-byte entries from audio network and second list nodes, filtering where a sub-chain at offset 0x204 has flag 0x20000 set at offset 0x14. Frees old array, allocates new one sized to `this[93]`, then populates with matching nodes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VertexBufferResourceAllocation (00543fa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(*(this+0x204)+0xEC)+0x204)+0x10) | 0x10 | R | — | Forward link in sub-chain (offset 0x10) |
| *(*(*(*(this+0x204)+0xEC)+0x204)+0x10) | 0x14 | R | — | Flags at offset 0x14 in chain node (checked for 0x20000) |
| *(*(*(this+0x204)+0xEC)+0x4C) | 0x4C | R | — | Next pointer within sub-nodes of audio network |
| *(*(this+0x204)+0xEC) | 0x204 | R | — | Sub-chain start within each sub-node |
| *(*(this+0x30C)+0x10) | 0x10 | R | — | Forward link in sub-chain from second list |
| *(*(this+0x30C)+0x10) | 0x14 | R | — | Flags at offset 0x14 in chain node (checked for 0x20000) |
| *(this+0x154) | 0x4C | R | — | Next pointer of nodes in second list |
| *(this+0x204) | 0x4 | R | — | Flags at offset 4 in audio network node (bit 0x40 skips node) |
| *(this+0x204) | 0xEC | R | — | Sub-list head within audio network node |
| *(this+0x204) | 0x104 | R | — | Forward link between audio network nodes |
| this | 0x100 | R | — | Head of first list (audio network nodes) |
| this | 0x108 | R | — | Head of second list |
| this | 0x174 | R | — | Scene instance entry count (guard — sized to this value) |
| this | 0x178 | RW | — | Array of 24-byte scene instance entries (rebuilt each call) |
| this | 0x30C | R | — | Path to sub-chain start from second list head |

**Written-by note (persistence):**
- this 0x178: Written once per call — set to new allocation; cleared to 0 on allocation failure

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | Per-entry cleanup during old array teardown (empty stub) |
| 00548e00 | ShortComputation_8e00 | Initialize each 24-byte array entry |
| 00587bcf | FreeWrapper_7bcf | Free old array allocation |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate new array (24 * count + 4 bytes) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x174 | > | 0 | Scene instance entry count |

**Guard interpretation:** When `this[93] > 0`: enter processing (free old array, alloc new, walk lists, filter entries). When <= 0: skip everything, return 0 immediately.
