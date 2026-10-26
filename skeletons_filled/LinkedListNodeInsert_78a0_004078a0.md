## LinkedListNodeInsert_78a0_004078a0 — MutexSyncObjectLinkedListInsert

**Summary:** Allocates and initializes a mutex/synchronization object (96 bytes) via MutexSynchronizationObjectInit and inserts it into a linked list. Part of a thread synchronization management system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | RW | — | head pointer of linked list |
| this | 0x1C | RW | — | tail pointer of linked list |
| this | 0x20 | RW | — | persistent reference to first node (set once on first insertion) |
| this | 0x24 | R | — | count of nodes in linked list |
| this | 0x88 | R | — | enable/disable gate flag; function returns 0 if zero |

**Written-by note (persistence):**
- this 0x18: set once on first insertion when list was empty (this[6] = v4)
- this 0x1C: updated on every successful insertion (this[7] = v4)
- this 0x20: set once on first insertion, same as head (this[8] = v4)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00406130 | MutexSynchronizationObjectInit | initializes 96-byte mutex/synchronization object with parent context `this` |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 96-byte sync object or 12-byte linked list node |

**Guard conditions:** If `this[34]` (offset 0x88, enable flag) is zero, function returns 0 immediately. If 96-byte allocation fails or MutexSynchronizationObjectInit returns null, returns 0. If 12-byte linked list node allocation fails, the initialized sync object is still returned (node is null) — list is not updated but return value is non-null.
