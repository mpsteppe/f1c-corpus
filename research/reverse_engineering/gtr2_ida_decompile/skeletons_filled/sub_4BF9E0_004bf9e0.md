## sub_4BF9E0_004bf9e0 — destructor: resets vtable, destroys embedded list, chains cleanup

**Summary:** Destructor body: re-installs the class vtable pointer off_710FB8 at object offset 0, tears down the embedded linked list at this+0x11C via LinkedListDestroy, then returns the result of the chain cleanup call sub_4D82A0 on this object.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Object vtable pointer; overwritten with off_710FB8 (base-class dtor vtable) |

**Written-by note (persistence):**
- this 0x0: written by the destructor once per destruction (vtable re-install). An external poke survives until this destructor runs, at which point the store overwrites it; not a per-frame recalculated field.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e2ee8 | SEH_4BF9E0 | R | Exception-handling (SEH) scope record for this function |
| 00710fb8 | off_710FB8 | R | Vtable/offset-table pointer stored to object offset 0 by the destructor |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d5d40 | LinkedListDestroy [structural] | Destroys the linked list embedded at this+0x11C (this+71 dwords) |
| 004d82a0 | sub_4D82A0 | Subsequent destructor-chain/final cleanup call on the object; its return value becomes this function's result |

**Guard conditions:** No branches — the vtable store at offset 0, the linked-list destroy and the final cleanup call execute unconditionally; nothing is checked or blocked.
