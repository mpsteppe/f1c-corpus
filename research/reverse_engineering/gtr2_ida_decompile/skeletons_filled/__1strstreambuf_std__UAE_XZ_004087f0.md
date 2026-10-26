## ??1strstreambuf@std@@UAE@XZ_004087f0 — std::strstreambuf destructor

**Summary:** MSVC std::strstreambuf destructor: installs the destruction-time vtable, tears down the object's three owned linked lists via sub_408630, then runs the teardown helper and frees/nulls the three heap blocks owned by the object.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Object vptr; overwritten with the destruction-time vtable off_6F1C78 |
| this | 0x4 | RW | 0 | Heap pointer slot freed by the destructor; set to 0 after the free |
| this | 0x14 | RW | 0 | Heap pointer slot freed by the destructor (j__free(v1[5])); set to 0 after the free |
| this | 0x20 | RW | 0 | Heap pointer slot freed by the destructor (j__free(v1[8])); set to 0 after the free |

**Written-by note (persistence):**
- this 0x0: written once at destructor entry (vtable swap); only meaningful during destruction of this object.
- this 0x4: zeroed unconditionally when the destructor runs — once per object lifetime; no per-frame recalculation.
- this 0x14: zeroed unconditionally when the destructor runs — once per object lifetime.
- this 0x20: zeroed unconditionally when the destructor runs — once per object lifetime.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e0d81 | ??1strstreambuf@std@@UAE@XZ_SEH | R | IDA-generated SEH handler associated with this destructor's exception machinery |
| 006f1c78 | off_6F1C78 | R | Destruction-time vtable pointer installed at this+0x0 at destructor entry |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00407640 | sub_407640 | No-argument helper invoked immediately before each j__free; part of the strstreambuf teardown sequence (exact role not evident from this function alone) |
| 00408630 | sub_408630 | Three-list teardown helper; destroys payloads and frees all list nodes |
| 006308d3 | j__free | CRT free thunk; releases each of the object's three heap blocks |

**Guard conditions:** None — the function contains no branches. The vtable swap, the sub_408630 call, and all three free/null sequences (this+0x20, this+0x14, this+0x4) execute unconditionally on every invocation.
