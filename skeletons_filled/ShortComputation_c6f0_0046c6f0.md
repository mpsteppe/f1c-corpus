## ShortComputation_c6f0_0046c6f0 — ByteFieldConstructorWithVTable

**Summary:** Constructor. Calls base initializer sub_4893C0, stores parameter a2 as byte at offset 0x174, sets vtable to off_59FB58.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer |
| this | 0x174 | RW | — | byte field initialized from parameter a2 |

**Written-by note (persistence):**
- this 0x0: set to vtable once during construction; survives
- this 0x174: set from a2 parameter once; survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059fb58 | off_59FB58 | R | vtable for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004893c0 | sub_4893C0 | base/sub-object constructor |

**Guard conditions:** None — unconditional constructor.
