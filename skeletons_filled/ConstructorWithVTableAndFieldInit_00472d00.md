## ConstructorWithVTableAndFieldInit_00472d00 — UISimpleElementConstructor

**Summary:** Initializes a UI element: calls base init (parameter 2), sets vtable to off_5A2400, and zeros the field at offset 0x31C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (off_5A2400) |
| this | 0x31C | RW | 0 | index/pointer field, zeroed on init |

**Written-by note (persistence):**
- this 0x0: once (constructor vtable); survives external poke
- this 0x31C: once (literal 0); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a2400 | off_5A2400 | R | vtable for this UI element type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048c070 | sub_48C070 | base initialization helper (parameter 2) |

**Guard conditions:** none — straight-line, no branches.
