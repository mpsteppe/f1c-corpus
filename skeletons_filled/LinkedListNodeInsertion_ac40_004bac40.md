## LinkedListNodeInsertion_ac40_004bac40 — Dual-list spatial structure builder

**Summary:** Inserts a value into a linked list, then builds a second linked list of 8 or 32 nodes with 432-byte stride offsets from the base value. Used in collision object insertion.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionObjectInsertion (004b48e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | First list head pointer |
| this | 0x4 | RW | — | First list tail pointer |
| this | 0x8 | RW | — | First list current/iterator pointer |
| this | 0xC | R | — | First list node count |
| this | 0x10 | RW | — | Second list head pointer (stack-like insert at front) |
| this | 0x14 | RW | — | Second list anchor (set on first insertion) |
| this | 0x18 | RW | — | Second list secondary reference (set on first insertion) |
| this | 0x1C | R | — | Second list node count |

**Written-by note (persistence):**
- this 0x0-0x1C: all written per call; fields persist as list state

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 12-byte node via operator new/malloc |

**Guard conditions:** First list insertion gated on a2 != NULL. Second list nodes created only if computed value v7 != 0.
