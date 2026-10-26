## CollisionGeometryFreeList_00494e60 — Free collision geometry string list

**Summary:** Processes collision geometry linked list: walks nodes calling StringCompareLinkedListSearch on each data payload, then frees all nodes and their data, and zeroes the four collision global counters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4963D0 (004963d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cddf0 | dword_7CDDF0 | RW | CollisionStateCounters [DERIVED] (also: ` through `_DAT_007cddfc` — collision state counters/flags (all zeroed) |
| 007cddf4 | dword_7CDDF4 | W | CollisionListTailPointer [DERIVED] |
| 007cddf8 | dword_7CDDF8 | RW | CollisionListTail [DERIVED] (also: ` — collision list iterator) |
| 007cddfc | dword_7CDDFC | W | CollisionContactCounter [DERIVED] (also: ` — collision state counters/flags (all zeroed) |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053d130 | StringCompareLinkedListSearch | Searches/comparses string data in collision list nodes |
| 00557470 | EmptyStub_7470 | Pre-free callback or no-op stub for data payload |
| 00587bcf | FreeWrapper_7bcf | Frees node allocation and its data payload |

**Guard conditions:** If list head (dword_7CDDF0) is null, function returns immediately. Node's data payload freed only if byte at node+0x8 (ownership flag) is set and data pointer is non-null.
