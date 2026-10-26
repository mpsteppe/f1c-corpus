## sub_4BDF60_004bdf60 — install class vtable / constructor-style helper

**Summary:** Stores the class vtable pointer `off_70E960` at offset 0 of `this` and tail-calls `sub_4D83B0()` (the same shared routine reached from `sub_4BDCE0`). Invoked from the deleting destructor `sub_4BDF40`, so it acts as the class's destructor body that re-points the vtable then runs shared teardown/init logic.

**Called by:** sub_4BDF40 (004bdf40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | C++ vtable/class pointer slot; overwritten with `&off_70E960` |

**Written-by note (persistence):**
- this 0x0: written unconditionally each call; during destruction this slot is transitional — an external poke would not survive destruction/reconstruction of the object.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0070e960 | off_70E960 | R | Vtable/class descriptor; its address is stored into `this[0]` |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — vtable store and callee invocation are unconditional.
