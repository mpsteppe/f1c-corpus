## CircularCounterIncrement_004b69a0 — Circular Buffer Write Advance

**Summary:** Increments the circular buffer write index (this[0x9B8]) by 1 with modulo wrap. Returns the PhysicsObjectListManager result for the newly pointed entry.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitstopActionSet (004b6940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9B0 | R | — | Pointer to circular buffer data array |
| this | 0x9B4 | R | — | Buffer size/modulus for wrap calculation |
| this | 0x9B8 | RW | — | Current write index (incremented and wrapped) |

**Written-by note (persistence):**
- this 0x9B8: Updated each call with (old_index + 1) % modulus; persists.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always advances index and returns result.
