## UIListInitWithDefault_00474a10 — UIListElementMinimalInit

**Summary:** Initializes a UI list element: sets vtable to off_5A3E40, stores literal value 400 at offset 0x31C, and calls additional initialization via sub_474AB0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (off_5A3E40) |
| this | 0x31C | RW | 400 | value / ID / counter preset (direct value, not pointer) |

**Written-by note (persistence):**
- this 0x0: once (constructor vtable); survives external poke
- this 0x31C: once (literal 400); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a3e40 | off_5A3E40 | R | vtable for this UI list element type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00474ab0 | sub_474AB0 | additional initialization for this list element type |
| 0048c070 | sub_48C070 | base initialization helper (parameter 1) |

**Guard conditions:** none — straight-line, no conditional branches.
