## LinkedListRandomAccess_004c6780 — Get random scene entry from filtered list

**Summary:** Generates a random index from internal 64-bit state, bounds-checks it against the linked list count, walks the list to the indexed node, and returns the corresponding scene entry pointer from the global scene array.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameFilterSetup (00477830)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac488 | dword_8AC488 | R | SceneFileCount [DERIVED] |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c6760 | BoundsCheckedIndexSetter_6760 | Set random index after bounds check against list count |
| 005871f0 | ReadFieldAtOffset0x14 | Read 64-bit random state/seed from offset 0x14 |

**Guard conditions:** Returns 0 if `a2 < 0`. Returns 0 if high part of random value >= low part (invalid range). After index setter, returns 0 if index >= list count or list head is null. Returns 0 if scene index from selected node is out of valid range [0, dword_8AC488).
