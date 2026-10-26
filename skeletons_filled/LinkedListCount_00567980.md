## LinkedListCount_00567980 — count linked list nodes

**Summary:** Counts linked list nodes by traversing from this[2] (offset 0x8), following next pointers at node+4 until null. Returns node count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_47D800 (0047d800), SeasonRacesSceneSorter (004c5940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC) | 0x4 | R | — | next node pointer (followed during traversal) |
| this | 0x8 | R | — | starting node pointer (head/cursor) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If starting node (this+0x8) is NULL → returns 0 immediately.
