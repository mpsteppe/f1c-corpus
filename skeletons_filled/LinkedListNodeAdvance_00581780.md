## LinkedListNodeAdvance_00581780 — Linked list iterator advance

**Summary:** Advances linked list iteration cursor. Reads current node pointer from this+0x8, advances it to next node via offset-0xC link, returns data value at offset 0 of new current node. Returns 0 if cursor reaches end.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_490D00 (00490d00), CollisionBroadphaseBuilder (00490ee0), NetworkConnectionListDuplication (0057b330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | Current iteration node pointer. Set to next node during advance |
| this | 0xC | R | — | Node link/next field (read from current node at offset 0x4 relative to node) to advance cursor |

**Written-by note (persistence):**
- this 0x8: Updated per call to point to next node. Persists between calls for iteration state.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks this+0x8 (current node) for null. If non-null, advances to next node via link at node+0x4. Checks new current for null before returning data; returns 0 when list exhausted.
