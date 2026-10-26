## LinkedListWalkInterlockedDec_005487a0 — Walk linked list calling sub_546450 until match

**Summary:** Walks linked list rooted at this+0x24 via node[48] (offset 0xC0), calls sub_546450(v1, -1) on each node. If sub_546450 returns non-zero (match found), returns -1. Otherwise decrements global Addend via InterlockedDecrement and calls AudioVolumeLoadComputation(0). Resource scanning with system-side-effect.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VertexBufferResourceAllocation (00543fa0), sub_557670 (00557670), sub_557CE0 (00557ce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xE4) | 0xC0 | R | — | next node pointer (offset 0xC0) for linked list walk |
| this | 0x24 | R | — | linked list head pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e234 | InterlockedDecrement | R | atomic decrement target address |
| 008b8eec | Addend | R | AudioHalfBufferSize [DERIVED] (also: ` — half buffer size) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00545f50 | AudioVolumeLoadComputation | audio volume/load computation |
| 00546450 | sub_546450 | node check function called with -1 arg; returns non-zero on match |

**Guard conditions:** (1) If this+0x24 (list head) is null, BLOCKED: return 0 (empty list, nothing to scan). (2) For each node: call sub_546450(node, -1). If returns non-zero, PASSES: return -1 (match found, stop walking). (3) If sub_546450 returns 0: decrement InterlockedDecrement(&Addend), call AudioVolumeLoadComputation(0), continue to next node. (4) If next node (via +0xC0) is null, return 0 (no match in entire list).
