## CircularBufferRingAdvance_004917c0 — CircularBufferAgeAndEvict

**Summary:** Advances circular buffer index (conditional on race phase timer), destroys two embedded list iterators, then processes the ring slot at current index: increments age counter on each node (up to 3), evicts and frees aged-out nodes, prepends their values elsewhere.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneEntityCleanup (00497100)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Node's value/data pointer (first field of list node) |
| obj | 0x4 | RW | — | Node's next pointer (written during list unlink) |
| obj | 0x8 | R | — | Node's flags byte at +8 (checked before free) |
| this | 0x0 | R | — | Outer struct pointer — *this points to ring buffer header |

**Written-by note (persistence):**
- obj 0x4: written during list unlink for evicted nodes; persists until node freed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer — guards whether index advances |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490aa0 | LinkedListNodePrepend | Prepend evicted node value to another list |
| 004910d0 | ListIteratorFullDestruction | Destroy two embedded list iterators at offsets +28 and +44 |
| 004f9b20 | sub_4F9B20 | Check race phase timer condition for allowing index advance |
| 00587bcf | FreeWrapper_7bcf | Free heap memory for evicted nodes and their values |

**Guard conditions:** If `sub_4F9B20(&unk_8AFE18)` returns non-zero → increment ring index modulo capacity. Then unconditionally destroy iterators. Walk ring slot's linked list: if node value at short[4] (offset 8) < 3 → increment age counter, advance to next node. If >= 3 → remove node from list, free value (if flags indicate active) and node, prepend value elsewhere.
