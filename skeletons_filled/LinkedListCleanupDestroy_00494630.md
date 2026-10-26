## LinkedListCleanupDestroy_00494630 — Destroy collision system linked list

**Summary:** Destroys collision system linked list anchored at dword_7CDDF0: iterates nodes, calls EmptyStub_7470 and frees data payload if ownership flag at node+0x8 is set, frees each node, then zeroes all four collision global counters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cddf0 | dword_7CDDF0 | RW | CollisionStateCounters [DERIVED] (also: ` through `_DAT_007cddfc` — collision state counters/flags (all zeroed) |
| 007cddf4 | dword_7CDDF4 | W | CollisionListTailPointer [DERIVED] |
| 007cddf8 | dword_7CDDF8 | W | CollisionListTail [DERIVED] (also: ` — collision list iterator) |
| 007cddfc | dword_7CDDFC | W | CollisionContactCounter [DERIVED] (also: ` — collision state counters/flags (all zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00557470 | EmptyStub_7470 | Pre-free callback or no-op stub for data payload |
| 00587bcf | FreeWrapper_7bcf | Frees node allocation and optionally its data payload |

**Guard conditions:** If dword_7CDDF0 is null (empty list), loop body never executes. Node data payload is freed only if byte at node+0x8 is non-zero and the first DWORD of node is non-null.
