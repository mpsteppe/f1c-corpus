## sub_4BDDF0_004bddf0 — install destructor vtable / destructor helper

**Summary:** C++ destructor-style routine: swaps the object's vtable pointer at offset 0 to `off_70E6A8`, then tail-calls `sub_4D83F0()` (likely base-class destructor or shared teardown).

**Called by:** sub_4BDDD0 (004bddd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | C++ vtable/class pointer slot; overwritten with `&off_70E6A8` (destructor-state vtable) |

**Written-by note (persistence):**
- this 0x0: written unconditionally on each call; as part of destruction it is not intended to be restored — an external poke here would only persist until the object is destroyed/reconstructed.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0070e6a8 | off_70E6A8 | R | Destructor-state vtable/class descriptor; its address is stored into `this[0]` |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — no branches; vtable swap and teardown call are unconditional.
