## BufferCopyViaVirtualTypeDispatch_00587930 — Parse typed buffer entries with vtable dispatch

**Summary:** Iterates `a3` times through buffer `a2`, using vtable dispatch (offset 0x58) on sub-struct at this+0x414 to create typed objects. For each entry: compares size byte against expected type size, optionally copies data into object, reads next length byte, copies variable data via MemcpyLikeWithRealloc, sets config value `a4` on object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_584230 (00584230)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x414) | 0x58 | R | — | Vtable function offset 0x58 on sub-struct; creates typed handler object |
| this | 0x414 | R | — | Pointer to sub-struct with vtable dispatched per entry |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00585400 | VTableDispatchWithConditionalBranch | Dispatches handler object for each parsed entry |
| 00587510 | MemcpyLikeWithRealloc | Copies variable-length data into handler object at offset 0x8 |

**Guard conditions:** No early-out guards — always loops `a3` times (`i` goes from 0 to `a3`). Inner condition `v8 == expected_size` controls whether data is copied directly or not.
