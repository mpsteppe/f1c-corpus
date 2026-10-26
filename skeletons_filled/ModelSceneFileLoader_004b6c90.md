## ModelSceneFileLoader_004b6c90 — Model/Scene Binary File Deserializer

**Summary:** Deserializes a binary model/scene file: reads string tables and byte flags from the stream, allocates and links scene-object nodes into two managed linked lists (at this+0x6C0 and this+0x714), processes per-node format headers, and computes bounding extent values. Part of the game-data file I/O system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameDataFileIO (004b7300)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x18)+0x0) | 0x0 | R | — | data payload pointer within first-list node |
| *(*(this+0x6C0)+0x4) | 0x4 | R | — | next-node pointer in second linked list |
| *(*(this+0x714)+0x0) | 0x0 | R | — | data payload pointer within third-list node |
| *(this+0x18) | 0x0 | R | — | head pointer of first linked list (scene-object list A) |
| *(this+0x18) | 0x8 | RW | 0 | byte flag on allocated node: mark as used/taken |
| *(this+0x38) | 0x8 | R | — | byte flag on pre-existing node (free-pool eligibility) |
| *(this+0x6C0) | 0x0 | R | — | head pointer of second linked list (scene-object list B) |
| *(this+0x6C0) | 0xC | R | — | byte flag: node has deep-cleanup sub-data (non-zero=has payload) |
| *(this+0x6C4) | 0x4 | RW | — | tail pointer of second linked list (updated on append) |
| *(this+0x714) | 0x0 | R | — | head pointer of third linked list (scene-object list C) |
| *(this+0x718) | 0x4 | RW | — | tail pointer of third linked list (updated on append) |
| this | 0x18 | R | — | pointer to first-list management block (head/tail/count) |
| this | 0x38 | R | — | free-node pool reference for list-A allocations |
| this | 0x40 | RW | 0 | first-list count / depth counter (reset to 0) |
| this | 0x6C0 | RW | 0 | second-list head pointer (reset to 0 after teardown) |
| this | 0x6C4 | RW | 0 | second-list tail pointer (reset to 0 after teardown) |
| this | 0x6C8 | RW | 0 | second-list secondary sentinel / oldest ptr (reset to 0) |
| this | 0x6CC | RW | 0 | second-list count (reset to 0 after teardown) |
| this | 0x714 | RW | — | third-list head pointer (rebuilt from file) |
| this | 0x718 | RW | — | third-list tail pointer (rebuilt from file) |
| this | 0x71C | RW | — | third-list oldest/sentinel pointer |
| this | 0x720 | R | — | third-list count (read for loop bounds) |
| this | 0xF1C | RW | — | computed bounding min extent (float) |
| this | 0xF20 | RW | — | computed bounding max extent (float) |
| this | 0xF24 | R | — | bounding extent span value (float, compared <= 0 to skip) |
| this | 0xF2C | R | — | per-node sub-data count (uint16, loop bound for format headers) |
| this | 0xF30 | RW | 0 | bounding min (output, set from first valid node) |
| this | 0xF34 | RW | 0 | bounding max (output, computed as min + span) |

**Written-by note (persistence):**
- *(this+0x18) 0x8: written during deserialization — external poke does NOT persist (overwritten per-node)
- *(this+0x6C4) 0x4: written during deserialization — external poke does NOT persist
- *(this+0x718) 0x4: written during deserialization — external poke does NOT persist
- this 0x40: written during deserialization — external poke does NOT persist
- this 0x6C0: written during deserialization (reset after teardown) — external poke does NOT persist
- this 0x6C4: written during deserialization (reset after teardown) — external poke does NOT persist
- this 0x6C8: written during deserialization (reset after teardown) — external poke does NOT persist
- this 0x6CC: written during deserialization (reset after teardown) — external poke does NOT persist
- this 0x714: written during deserialization — external poke does NOT persist
- this 0x718: written during deserialization — external poke does NOT persist
- this 0x71C: written during deserialization — external poke does NOT persist
- this 0xF1C: written during deserialization — external poke does NOT persist
- this 0xF20: written during deserialization — external poke does NOT persist
- this 0xF30: written during deserialization (reset to 0) — external poke does NOT persist
- this 0xF34: written during deserialization (reset to 0) — external poke does NOT persist

**Globals referenced:**

None

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b4250 | FileStreamReader | read a data block from the binary file stream into a buffer |
| 004b43e0 | FileFormatHeaderReader | read per-node format header data from the stream |
| 004b44a0 | sub_4B44A0 | populate a node's data fields from stream data |
| 004b5040 | sub_4B5040 | parse and decode a node's string+flag data block |
| 004b5e50 | sub_4B5E50 | pre-process string tables before node allocation |
| 004b5f60 | LinkedBufferTransfer | transfer linked buffer data between internal lists |
| 004b8090 | BinaryFloatComparison | validate the binary file header/magic (returns bool) |
| 004ba780 | ShortComputation_a780 | reuse or recycle a free node from the internal pool |
| 004ba830 | LinkedListNodeRemoval_a830 | remove a node from the free-pool linked list (with flag) |
| 004bacf0 | LinkedListNodeRemoval_acf0 | remove a node from an alternative free-pool list |
| 004bafc0 | MemoryAllocation_afc0 | trigger memory allocation for a new node batch |
| 004bb0c0 | sub_4BB0C0 | allocate a fresh data node from the pool |
| 004bb200 | MultiLevelAllocation | allocate from multi-level memory pool for scene nodes |
| 004bb460 | DestructorWithConditionalFree_b460 | conditional destructor: free node's sub-data if flag is set |
| 004bb6b0 | sub_4BB6B0 | check and conditionally remove node from free pool |
| 00566650 | StringCopyWithBufferRealloc | copy string from stream buffer into heap (with realloc) |
| 00566c00 | FileWriteWithBackendDispatch | read raw bytes from file stream (misnamed — read, not write) |
| 00587bcf | FreeWrapper_7bcf | generic memory deallocation wrapper |
| 00587c03 | OperatorNewNhMallocWrapper | heap allocation with no-throw guarantee |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x6C0) | 0xC | == | 0 | second-list node has no sub-data payload (skip deep destructor) |
| this | 0xF24 | <= | 0 | bounding span is zero or negative (skip bounding-computation branch) |

**Guard interpretation:** When tearing down the second linked list, if a node's byte at offset 0xC is 0, the node is freed directly (FreeWrapper_7bcf) without calling DestructorWithConditionalFree_b460 — BLOCKED deep cleanup. Non-zero PASSES through to deep destructor. The second guard (this+0xF24 <= 0) skips the bounding extent computation block entirely when the span value is non-positive — the entire bounding-output section is BLOCKED.