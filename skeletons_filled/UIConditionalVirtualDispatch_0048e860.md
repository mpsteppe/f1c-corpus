## UIConditionalVirtualDispatch_0048e860 — ConditionalLinkedListTraversalDispatch

**Summary:** Guarded dispatch: if field at offset 0xE8 (this[58]) is zero, traverses child linked list via LinkedListTraversalWithVirtualCall and invokes virtual method at vtable+160; otherwise returns the field value as-is (blocking dispatch).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA0 | R | — | virtual method offset for dispatch callback |
| this | 0x0 | R | — | vtable pointer |
| this | 0x40 | R | — | child linked list pointer |
| this | 0xE8 | R | — | guard condition flag: zero = allow dispatch |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00496e40 | LinkedListTraversalWithVirtualCall | traverse linked list and call virtual method on each child |

**Guard conditions:** if (this[58] == 0) → PASS (traverse linked list and dispatch virtual method at vtable+160); if non-zero → BLOCKED (return field value early, no dispatch).
