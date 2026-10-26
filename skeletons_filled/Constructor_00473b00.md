## Constructor_00473b00 — UIElementWithTextEncRefInit

**Summary:** Initializes a UI element: sets vtable to off_5A2DC0, stores pointer to UITextEncodingFlag at offset 0x320, sets literal value 278 at 0x31C, and registers two text-handle nodes (off_5C7084, off_5C7080).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (off_5A2DC0) |
| this | 0x31C | RW | 278 | value / ID / counter preset |
| this | 0x320 | RW | — | pointer to UITextEncodingFlag (byte_7D0474) |

**Written-by note (persistence):**
- this 0x0: once (constructor vtable); survives external poke
- this 0x31C: once (literal 278); survives external poke
- this 0x320: once (pointer to UITextEncodingFlag); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a2dc0 | off_5A2DC0 | R | vtable for this UI element type |
| 005c7080 | off_5C7080 | R | UI text handle for second label |
| 005c7084 | off_5C7084 | R | UI text handle for first label |
| 007d0474 | byte_7D0474 | R | UITextEncodingFlag — text encoding flag referenced by pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486f30 | LinkedListInsertWithNodeAllocation | insert text-handle node into element's linked list |
| 0048c070 | sub_48C070 | base initialization helper (parameter 1) |

**Guard conditions:** none — straight-line, no conditional branches.
