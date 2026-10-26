## LinkedListTraversalVirtualCall_00477160 — IndexedListVirtualDispatch

**Summary:** Traverses a linked list to reach the node at index `this[92]`, performs a bounds/position check, then dispatches a virtual call at offset 144 on the node's data pointer at offset 0x30.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0xF0)+0x30)+0x0) | 0x90 | R | — | vtable entry at offset 144 for virtual dispatch on inner data pointer |
| *(*(this+0xF0)+0x30) | 0x0 | R | — | vtable of first node's data sub-object at offset 0x30 |
| *(this+0xF0) | 0x30 | R | — | data pointer at offset 0x30 of first list node |
| this | 0xF0 | R | — | linked list head pointer |
| this | 0xF8 | R | — | unknown (cursor/state read) |
| this | 0xFC | R | — | list count/upper bound for index validation |
| this | 0x170 | R | — | target index into linked list |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004773a0 | BoundsCheckWithPositionQuery | validates node position/bounds for the given index |
| 0048f300 | StateResetConditionalVirtualCall | resets state with conditional virtual dispatch |

**Guard conditions:** `this[92]` (offset 0x170) must be >= 0 and < `this[63]` (offset 0xFC) → proceed; traversal: index <= 0 → use head; index > 0 → advance `v3 = v3[1]` (next pointer) until index exhausted; node must be non-null; `*v3` (node data) must be non-null; `BoundsCheckWithPositionQuery()` must return non-zero; `v4+48` (data offset 0x30) must be non-null for virtual call
