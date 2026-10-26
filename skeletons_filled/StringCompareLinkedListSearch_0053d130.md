## StringCompareLinkedListSearch_0053d130 — RegistryMatchAndCleanupNode

**Summary:** Searches the registry linked list for a node whose name string (offset 0x14) matches a1's name. If match found, unlinks a1 from the list, calls resource cleanup, and frees memory.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionGeometryFreeList (00494e60), MultiStageCleanupWithRepeatedCallCycle (0049d150), sub_4D8FB0 (004d8fb0), FrameRateCounterInitReset (004f8ea0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8e20 | dword_8B8E20 | R | EntryRegistryHead [DERIVED] (also: ` â€” global linked list head (entry registry) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053d3a0 | DoublyLinkedListNodeRemoval_d3a0 | Unlinks a node from the registry linked list |
| 00552760 | AudioResourceCleanup | Cleans up audio resource fields within the node |
| 00557470 | EmptyStub_7470 | Empty stub (debug/logging hook) |
| 00587bcf | FreeWrapper_7bcf | Heap free wrapper |

**Guard conditions:** Checks list head (dword_8B8E20) non-null before traversal. Each node's next pointer (offset 0x870) checked during walk; if null (end of list), returns without action. Only proceeds to unlink/cleanup/free if name string match is found.
