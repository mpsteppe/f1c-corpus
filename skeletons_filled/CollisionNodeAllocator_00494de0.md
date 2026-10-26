## CollisionNodeAllocator_00494de0 — Allocate and append collision node

**Summary:** Allocates a 12-byte collision linked list node (data ptr + next ptr + flag byte), sets its data pointer from parameter, and appends it to the global collision list at dword_7CDDF0. Updates tail pointer and increments counter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StringNormalizeLookup (00495810)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cddf0 | dword_7CDDF0 | RW | CollisionStateCounters [DERIVED] (also: ` through `_DAT_007cddfc` — collision state counters/flags (all zeroed) |
| 007cddf4 | dword_7CDDF4 | RW | CollisionListTailPointer [DERIVED] |
| 007cddf8 | dword_7CDDF8 | W | CollisionListTail [DERIVED] (also: ` — collision list iterator) |
| 007cddfc | dword_7CDDFC | W | CollisionContactCounter [DERIVED] (also: ` — collision state counters/flags (all zeroed) |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053cfe0 | sub_53CFE0 | Looks up existing entry; returns non-zero if duplicate exists (prevents duplicate allocation) |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates 12 bytes for new collision node |

**Guard conditions:** If sub_53CFE0 returns non-zero (duplicate found), no node is allocated and function returns the lookup result. Node allocation only proceeds if a1 (data pointer) is non-null.
