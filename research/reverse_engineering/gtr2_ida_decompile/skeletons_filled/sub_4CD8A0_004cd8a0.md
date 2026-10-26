## sub_4CD8A0_004cd8a0 — list-wide flag broadcast + state-machine kick

**Summary:** `__thiscall` broadcast/update routine: stores the byte passed in `a2` into this+0x64 (byte flag), then iterates the linked list headed at this[0x90] (links at node+0x8C) calling virtual slot +0x24 on every node with `a2`. Afterwards, if `a2` is non-zero it transitions the object itself via virtual slot +0x2C to state 4; if `a2` is zero it derives a flag (1 when the current state this[0x84] is 2 or 3, else 0) and runs the sub_4CD800 dispatcher with it; finally it sweeps the node list once more with the same virtual +0x24 broadcast.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x24 | R | — | Vtable slot +0x24 invoked on each list node (virtual call via node's vtable) with `a2` |
| obj | 0x2C | R | — | Vtable slot +0x2C invoked on `this` with value 4 when `a2` is non-zero |
| this | 0x0 | R | — | Vtable pointer of the object, used to resolve the +0x2C transition call |
| this | 0x64 | RW | — | Byte flag set from `a2` at entry (read by the state-4 gate elsewhere) |
| this | 0x84 | R | — | State index (this[33]); tested `< 2` and `> 3` to derive the pass-through flag for sub_4CD800 |
| this | 0x90 | R | — | Head pointer of the node list broadcast to / swept |
| this | 0x11C | R | — | First `next` link of the list walk (head+0x8C flattened); the loop advances until null |
| this | 0x1A8 | R | — | Deeper `next` link reached during the walk (second chain hop, head+0x8C+0x8C flattened); read as the list is traversed |

**Written-by note (persistence):**
- this 0x64: Written unconditionally from `a2` on every call (before the loops); an external poke is overwritten on the next invocation.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd800 | sub_4CD800 | State-machine transition dispatcher, invoked with flag 1 when current state is 2 or 3, otherwise 0 |

**Guard conditions:** On entry the byte at this+0x64 is unconditionally set to `a2` and all list nodes (from this[0x90]) get virtual +0x24(a2). Then: `a2 != 0` → virtual +0x2C(this, 4) only; `a2 == 0` → flag v8 = 1 only if state this[0x84] is in {2,3} (states 0,1 and 4+ yield 0), then sub_4CD800(this, v8) runs. A final identical node sweep follows in both branches.
